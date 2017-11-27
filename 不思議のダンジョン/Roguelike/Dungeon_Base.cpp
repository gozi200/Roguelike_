#include"Dungeon_Base.h"

Dungeon_Base::Dungeon_Base() {
	width = DUNGEON_WIDTH; //define定数使用
	height = DUNGEON_HEIGHT; //define定数使用
	rectangle_count = 0;

	enemy_manager = new Enemy_Manager;
	tile_judge = new Tile_Judge[width * height]();

	enemy_data.Set_File_Pass("CSV/Actor/Enemy/Enemy.csv"); //CSVファイルから情報を読み込む
	enemy_data.Open_File(); //ファイルを開いて読み込む
}

//デストラクタ
Dungeon_Base::~Dungeon_Base() {
	delete enemy_manager;
	delete[] tile_judge;
}

bool Dungeon_Base::Alloc(int set_x, int set_y) {
	return true;
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
	return 0;
}

int Dungeon_Base::Get_Room_Count() {
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
void Dungeon_Base::Fill_Rectangle(int set_left, int set_top, int set_right, int set_bottom, bool set_is_wall) {
	for (int y = set_top; y < set_bottom; ++y) {
		for (int x = set_left; x < set_right; ++x) {
			Get_Tile(x, y)->is_wall = set_is_wall;
		}
	}
};

void Dungeon_Base::Fill_Horizontal_Line(int set_left, int set_right, int set_y, bool set_is_wall) {
	if (set_left < set_right) {
		for (int x = set_left; x <= set_right; ++x) {
			Get_Tile(x, set_y)->is_wall = set_is_wall;
		}
	}

	else {
		for (int x = set_right; x <= set_left; ++x) {
			Get_Tile(x, set_y)->is_wall = set_is_wall;
		}
	}
};

void Dungeon_Base::Fill_Vertical_Line(int set_top, int set_bottom, int set_x, bool set_is_wall) {
	if (set_top < set_bottom) {
		for (int y = set_top; y <= set_bottom; ++y) {
			Get_Tile(set_x, y)->is_wall = set_is_wall;
		}
	}

	else
		for (int y = set_bottom; y <= set_top; ++y) {
			Get_Tile(set_x, y)->is_wall = set_is_wall;
		}
};

void Dungeon_Base::Random_Room_Point(int index, int *set_x, int *set_y) {
	RECT* room = &dungeon_rectangle[index].room;

	*set_x = room->left + random.Dungeon_Random(RECTANGLE_WIDTH(*room));
	*set_y = room->top + random.Dungeon_Random(RECTANGLE_HEIGHT(*room));
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

};

int Dungeon_Base::Get_Enemy_Count() {
	return 0;
};

Actor* Dungeon_Base::Get_Point_Enemy(int set_x, int set_y) {
	return 0;
};


Actor* Dungeon_Base::Get_Mob_From_Index(int index) {
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

void Dungeon_Base::Drop_Item(int set_x, int set_y, Item* set_item) {

}

void Dungeon_Base::Remove_Item(int set_x, int set_y, Item* set_item) {

}

int Dungeon_Base::Get_Room_Index(int set_x, int set_y) {
	return 0;
}

int Dungeon_Base::Attack(Actor* set_player, Actor* set_target) {
	return 0;
}

bool Dungeon_Base::Make_Enemy(int paturn, Enemy** enemy) {
	if (enemy == NULL) {
		return true;
	}
	*enemy = new Enemy_01;

	return false;
};

void Dungeon_Base::Set_Enemy_Parameter(Enemy* enemy, SETTING_ENEMY_DATA* enemy_data) {
	enemy->actor_status.Set_Parameter(enemy_data, &ITEM_DATA_BASE[enemy_data->drop_item_ID]);

	//enemy->Reset(); //NEXT 代わりの機能を調べる

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
		index = random.Dungeon_Random(22); //TODO: エネミーの要素数だがなぜこの数字？
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
		
		return enemy;;
	}
}

