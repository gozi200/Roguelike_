#include"Dungeon_Base.h"

Dungeon_Base::Dungeon_Base() {
	width = DUNGEON_WIDTH; //define定数使用
	height = DUNGEON_HEIGHT; //define定数使用
	rectangle_count = 0;

	tile_judge = new Tile_Judge[width * height]();

	enemy_data.Set_File_Pass("CSV/Actor/Enemy/Enemy.csv"); //CSVファイルから情報を読み込む
	enemy_data.Open_File(); //ファイルを開いて読み込む
}

//デストラクタ
Dungeon_Base::~Dungeon_Base() {
	delete[] tile_judge;
}

bool Dungeon_Base::Alloc(int set_width, int set_height) {
	tile_judge = new Tile_Judge[width*height];
	if (tile_judge == NULL)
		return true;

	// メンバをすべてゼロ初期化
	memset(tile_judge, 0, sizeof(Tile_Judge)*width*height);

	// ダンジョンサイズを保存
	width = set_width;
	height = set_height;

	return false;
}

Tile_Judge* Dungeon_Base::Get_Tile(int set_x, int set_y) {
	if (tile_judge == NULL) {
		return NULL;
	}

	if (set_x < 0 || set_x >= width || set_y < 0 || set_y >= height) {
		return NULL;
	}

	return &tile_judge[set_x + set_y * width];
}

int Dungeon_Base::Get_Rectangle_Count() {
	return rectangle_count;
}

int Dungeon_Base::Get_Room_Count() {
	return rectangle_count;
}

int Dungeon_Base::Get_Romm_Count() {
	return Get_Rectangle_Count();
};

bool Dungeon_Base::Is_Move(int set_x, int set_y) {
	//範囲外は移動不可
	if (set_x < 0 || set_x >= width || set_y < 0 || set_y >= height) {
		return true;
	}

	//壁があったら移動不可
	if (Get_Tile(set_x, set_y)->is_wall) {
		return true;
	}

	//移動不可
	return false;
}

//部屋の範囲+部屋の連結部分のみ壁フラグをfalseに 
void Dungeon_Base::Fill_Rectangle(int left, int top, int right, int bottom, bool is_wall) {
	int x, y;

	if (left > right)
	{
		int tmp = left;
		left = right;
		right = tmp;
	}
	if (top > bottom)
	{
		int tmp = top;
		top = bottom;
		bottom = tmp;
	}

	for (y = top; y<bottom; y++)
	{
		for (x = left; x<right; x++)
		{
			Get_Tile(x, y)->is_wall = is_wall;
		}
	}
};

void Dungeon_Base::Fill_Horizontal_Line(int left, int right, int y, bool is_wall) {
	int x;

	if (left > right) {
		int tmp = left;
		left = right;
		right = tmp;
	}

	for (x = left; x <= right; x++) {
		Get_Tile(x, y)->is_wall = is_wall;
	}
};

void Dungeon_Base::Fill_Vertical_Line(int top, int bottom, int x, bool is_wall) {
	int y;

	if (top > bottom) {
		int tmp = top;
		top = bottom;
		bottom = tmp;
	}

	for (y = top; y <= bottom; y++) {
		Get_Tile(x, y)->is_wall = is_wall;
	}
};

//指定した部屋内からランダムに座標を取得
void Dungeon_Base::Random_Room_Point(int index, int *x, int *y) {
	RECT* room = &dungeon_rectangle[index].room;

	*x = room->left + random.Dungeon_Random(RECTANGLE_WIDTH(*room));
	*y = room->top  + random.Dungeon_Random(RECTANGLE_HEIGHT(*room));
}


bool Dungeon_Base::Check_Move(int set_ax, int set_ay, int set_bx, int set_by) {
	//MEMO: 現在いる位置 = A,　新しく移動する位置 = B

	//A,Bが同一かどうか
	if (set_ax == set_bx && set_ay == set_by) {
		return false; //同一は周囲８マス
	}

	//A,Bは周囲8マスにいないか　(？)
	if (abs(set_ax - set_bx) > 1 || abs(set_ay - set_by) > 1) {
		return false; //離れている
	}

	//Bは移動可能な地形か
	if (Is_Move(set_bx, set_by)) {
		return false;
	}

	//Aから見てBは左上にあるか
	if (set_ax - 1 == set_bx && set_ay - 1 == set_by) {
		//左と上の双方が移動不可かどうか
		if (Is_Move(set_ax - 1, set_ay) && Is_Move(set_ax, set_ay - 1)) {
			return false;
		}
		return true;
	}

	//Aから見てBは右上にあるか
	if (set_ax + 1 == set_bx && set_ay - 1 == set_by) {
		//右と上の双方が移動不可かどうか
		if (Is_Move(set_ax + 1, set_ay) && Is_Move(set_ax, set_ay - 1)) {
			return false;
		}
		return true;
	}

	//Aから見てBは左下にあるか
	if (set_ax - 1 == set_bx && set_ay + 1 == set_by) {
		//右と下の双方が移動不能かどうか
		if (Is_Move(set_ax - 1, set_ay) && Is_Move(set_ax, set_ay + 1)) {
			return false;
		}
		return true;
	}

	//Aから見てBは右下にあるか
	if (set_ax + 1 == set_bx && set_ay + 1 == set_by) {
		//右と下の双方が移動不能かどうか
		if (Is_Move(set_ax + 1, set_ay) && Is_Move(set_ax, set_ay + 1)) {
			return false;
		}
		return true;
	}
	return false;
};

void Dungeon_Base::Delete_Enemy() {
	while (enemy_count)
	{
		--enemy_count;
		delete m_enemy[enemy_count];
		m_enemy[enemy_count] = NULL;
	}
};

Actor* Dungeon_Base::Get_Point_Enemy(int x, int y) {
	// すべてのモンスターを調べる
	for (int i = 0; i < enemy_count; i++)
	{
		int mx, my;
		Actor *actor = m_enemy[i];
		actor->Get_Position(&mx, &my);
		if (actor->Is_Dead() && mx == x && my == y)
			return actor;
	}
	return NULL;
};


Actor* Dungeon_Base::Get_Mob_From_Index(int index) {
	// パラメーターチェック
	if (index < 0 || index >= enemy_count)
		return NULL;

	return m_enemy[index];
	return 0;
};

void Dungeon_Base::Create_Enemy(int set_floor) {
	int x, y;

	//それぞれの部屋に１体配置する
	for (int i = 1; i <= rectangle_count; ++i) {
		Enemy* p_enemy; //メンバ変数と名前の重複を避ける
		
		//エネミーのオブジェクトを作成
		p_enemy = Get_Enemy(set_floor);

		if (p_enemy) {
			//部屋内の座用をランダムに取得
			Random_Room_Point(i, &x, &y);

			//エネミーを配置
			p_enemy->Set_Position(x, y);

			//エネミー配置情報の取得
			m_enemy[enemy_count] = p_enemy;
			++enemy_count;
		}
	}
}

void Dungeon_Base::Drop_Item(int x, int y, Item* item) {
	Tile_Judge *tile;

	tile = Get_Tile(x, y);
	if (tile == NULL)
		return;

	// タイルのアイテム情報に追加する
	if (tile->drop_item == NULL) {
		item->next = NULL;
	}

	else
		item->next = tile->drop_item;

	tile->drop_item = item;
}

void Dungeon_Base::Remove_Item(int x, int y, Item* remove_item) {
	Tile_Judge *tile;
	Item *item, *preview;

	tile = Get_Tile(x, y);
	if (tile == NULL)
		return;

	// タイルの情報から消すアイテムを探す
	preview = item = tile->drop_item;
	while (item)
	{
		if (item == remove_item)
		{
			// リンクリストから外す
			if (preview == item) {
				tile->drop_item = item->next;
			}

			else {
				preview->next = item->next;
			}

			// アイテム情報の削除
			item->Erase();

			delete item;

			return;
		}
		preview = item;
		item = item->next;
	}
}

//指定位置の部屋インデックスを返す(道、壁なら -1 を返す)
int Dungeon_Base::Get_Room_Index(int x, int y) {
	const POINT position = { x, y }; //TODO: 機能

	for (int i = 0; i < rectangle_count; i++)
	{
		// 部屋の矩形内に引数の座標は入っているか？
		// ※PiInRect はWinAPI で、指定矩形内に指定した点が入るなら 0 以外を返す
		if (PtInRect(&dungeon_rectangle[i].room, position))
			return i;
	}
	return -1;
}

int Dungeon_Base::Get_Rectangle_Index(int x, int y)
{
	const POINT position = { x, y };

	for (int i = 0; i < rectangle_count; i++)
	{
		// 矩形内に引数の座標は入っているか？
		// ※PiInRect はWinAPI で、指定矩形内に指定した点が入るなら 0 以外を返す
		if (PtInRect(&dungeon_rectangle[i].rect, position))
			return i;
	}

	return -1;
}

int Dungeon_Base::Attack(Actor* attacker, Actor* target) {
	int damage;

	damage = attacker->Attack(target);

	// 相手を退治した？
	if (target->actor_status.Is_Dead())
	{
		// 倒したのでアイテムドロップ判定
		if (random.Dungeon_Random(100) < target->actor_status.drop_item_ID)
		{
			// ドロップ確定
			Item* item = new Item;
			item->Copy(&target->actor_status.drop_item);

			// モンスターの位置にアイテムを落とす
			int x, y;
			target->Get_Position(&x, &y);
			Drop_Item(x, y, item);

			//メッセージの表示 //SEND
		}
	}
		return damage;
}

bool Dungeon_Base::Make_Enemy(int paturn, Enemy** enemy) {
	if (enemy == NULL) {
		return true;
	}

	*enemy = new Enemy_01;

	return false;
}

int Dungeon_Base::Get_Enemy_Count() {
	return enemy_count;
}

void Dungeon_Base::Random_Create_Enemy(int floor) {
	int x, y;
	int player_romm_index, room_index;

	//プレイヤーの座標を取得
	player->Get_Position(&x, &y);
	player_romm_index = Get_Room_Index(x, y);

	//モンスターの出現最大数に達していたら終了
	if (enemy_count >= MAX_ENEMY) {
		return;
	}

	//配置が完了するまでループを回す
	for (;;) {
		//適当な部屋番号を選ぶ
		room_index = random.Dungeon_Random(Get_Romm_Count());

		//プレイヤーのいる部屋はダメ
		if (room_index == player_romm_index) {
			continue;
		}

		//その区画内でt系統な座標を取得
		Random_Room_Point(room_index, &x, &y);
		
		//その座標にほかのエネミーがいたらダメ
		if (Get_Point_Enemy(x, y) != NULL) {
			continue;
		}

		/*-------------
		エネミーを配置する
		---------------*/
		//エネミーオブジェクトの作成
		Enemy* p_enemy = Get_Enemy(floor);

		if (p_enemy) {
			//エネミーの配置
			p_enemy->Set_Position(x, y);

			//エネミー配置情報の保存
			m_enemy[enemy_count] = p_enemy;
			++enemy_count;

			//配置が終わったので終了
			return;
		}
	}
};

void Dungeon_Base::Set_Enemy_Parameter(Enemy* enemy, SETTING_ENEMY_DATA* enemy_data) {
	enemy->actor_status.Set_Parameter(enemy_data, &ITEM_DATA_BASE[enemy_data->drop_item_ID]);

	enemy->Reset();

	//名前の設定
	enemy->Set_Name(enemy_data->name);
};

Enemy* Dungeon_Base::Get_Enemy(int floor) {
	Enemy* enemy;
	SETTING_ENEMY_DATA* sample;

	//適合モンスターに当たるまで検索を繰り返す
	while (true) {
		int index;

		//ランダムにデータベースから引いてくる
		index = random.Dungeon_Random(0/*ENMY_DATA_NUMBER*/); /*TODO: エネミーステータス要素数だがなぜこの数字？ 
																	  要素数 < エネミーの種類なので一先ずは0*/
		sample = &enemy_data.set_enemy_data.at(index); 

		//現在の階層に適合するなら採用する
		if (sample->first_floor <= floor && sample->last_floor >= floor) {
			break;
		}

		//指定したAIのモンスタークラスを作成
		if (Make_Enemy(sample->paturn, &enemy)) {
			return NULL;
		}

		//パラメータの設定
		Set_Enemy_Parameter(enemy, sample);
		
		return enemy;
	}
}

