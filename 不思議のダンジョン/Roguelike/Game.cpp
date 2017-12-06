#include"Game.h"

//コンストラクタ
Game::Game() {
	dungeon_base = new Dungeon01;
	dungeon01 = dynamic_cast<Dungeon01*>(dungeon_base);
}

//デストラクタ
Game::~Game() {
	bool isSameDungeon = dungeon_base == dungeon01;

	if (dungeon_base != nullptr) {
		delete dungeon_base;
		dungeon_base = nullptr;
	}
	if (!isSameDungeon && dungeon01 != nullptr) {
		delete dungeon01;
		dungeon01 = nullptr;
	}
}

void Game::Init() {

}

//サイクル実行
bool Game::Cycle() {
	Run_Action();

	//画面更新
	Render();

	return false;
}

//処理の実行
void Game::Run_Action() {
	////動作によって処理を振り分ける
	//switch (action) {
	//case ACTION_MOVE: Action_Move(); break;
	//
	//case ACTION_STEP: Action_Step(); break;
	//}
}

int Game::Message_Items(eITEM_TYPE filter) //NEXT
{
	int count;
	char sz_buffer[128];
	Item* item;

	count = 0;

	sz_buffer[0] = '\0';

	for (int i = 0; i < MAX_STOCK_ITEM; i++) {
		item = &player.actor_status.items[i];

		if (item->type == ITEM_TYPE_NONE) {
			continue;
		}

		// 未鑑定抽出か？
		if (filter & ITEM_TYPE_UNIDENTIFIED) {
			// 鑑定済みアイテムなら無視
			if (item->unidentified == false) {
				continue;
			}
		}

		else {
			// 表示アイテムが異なれば無視
			if (filter != ITEM_TYPE_NONE && (item->type & filter) == 0) {
				continue;
		}
	}
		//文字列の表示 SEND sprintf_s(sz_buffer + strlen(sz_buffer), sizeof(sz_buffer) - strlen(sz_buffer), "%c:%s ", 'A' + count, item->Get_Name());
		count++;

		// １行５個でまとまれば表示
		if ((count % 5) == 0) {
			//message(MESTYPE_SELECT, sz_buffer);
			sz_buffer[0] = '\0';
		}
	}

	// アイテムがない？
	if (count == 0) {
		return 0;
	}

	// バッファの残りも表示
	if (strlen(sz_buffer)) {
		//message(MESTYPE_SELECT, sz_buffer);
	}

	// 選択文を表示
	if (count == 1) {
		//message(MESTYPE_INFO, "0/A キーでアイテムを選択。0 キーでキャンセル");
	}

	else {
		//message(MESTYPE_INFO, "0/A-%c キーでアイテムを選択。0 キーでキャンセル", 'A' + count - 1);
	}
	return count;
}

//通り過ぎたダンジョン(階)を破棄する
void Game::Create_Floor() {
	if (dungeon_base) {
		delete dungeon_base;
	}

	dungeon01->Alloc(DUNGEON_WIDTH, DUNGEON_HEIGHT); //Define定数使用

	dungeon01->Make(&player, floor);

	dungeon_base = dungeon01;
}

/*-----------
アイテムを拾う
------------*/
void Game::Action_Get_Item() {
	int index;
	Item* item;
	int mx, my;

	if (action_count == 0) {
		char sz_buffer[256];
		//プレイヤーの現在の座標を取得
		player.Get_Position(&mx, &my);

		//落ちているアイテムを列挙
		item = dungeon_base->Get_Tile(mx, my)->drop_item;

		sz_buffer[0] = '\0';

		//バッファの戦闘のもののみ表示する
		while (item && action_count < 15) { //MAGICNUMBER
			//バッファに１行分のアイテムリストを作る
			//文字を表示 //SAID
			++action_count;

			//５アイテム分で１行表示
			if ((action_count % 5) == 0); {
				//文字を表示 //SAID
				sz_buffer[0] = '\0';
			}
			item = item->next;
		}

		//拾うものがなかった時の処理
		if (action_count == 0) {
			//移動処理に戻る
			Set_Action(ACTION_MOVE);
			//文字を表示 //SAID
			return;
		}

		//バッファの残りも表示
		if (strlen(sz_buffer)) {
			//文字の表示 //SAID
		}

		//選択文を表示
		if (action_count == 1) {
			//文字の表示 //SEND
		}

		else {
			//文字の表示 //SEND
		}
		return;
	}

	//"0"キーはキャンセル
	if (PUSH_0_KEY) {
		//移動処理に戻る
		Set_Action(ACTION_MOVE);
		//文字の表示 //SEND
		return;
	}

	index = -1;
	for (int i = 0; i < action_count; ++i) {
		if (PUSH_A_KEY); { // Amended キー入力の処理   本では if(keys['A'+i] & 0x80 )
			index = i;
			break;
		}
	}
	
	if (index == 1) {
		return;
	}

	//選択したアイテムを床のアイテムから探す
	player.Get_Position(&mx, &my);
	item = dungeon_base->Get_Tile(mx, my)->drop_item;
	
	while (item) {
		if (--index == 0) {
			//アイテムを拾う
			if (player.actor_status.Get_Item(item) == false) {
				//文字の表示 //SEND
				
				//床からアイテムを取り除く
				dungeon_base->Remove_Item(mx, my, item);
			}

			else {
				//文字の表示 //SEND
				Set_Action(ACTION_MOVE);
				return;
			}
			//移動処理に戻る
			Set_Action(ACTION_MOVE);
			return;
		}
		item = item->next;
	}
}

void Game::Action_Equip() {
	int index;
	Item* item;
	const eITEM_TYPE item_filter = (eITEM_TYPE)(ITEM_TYPE_WEAPON | ITEM_TYPE_SHIELD | ITEM_TYPE_ACCESSORIE);

	if (action_count == 0) {
		//アイテム一覧を表示し、該当アイテムを持っているか調べる
		action_count = Message_Items(item_filter);

		if (action_count == 0) {
			//文字の表示　SEND
			Set_Action(ACTION_MOVE);
			return;
		}
	}

	//０キーはキャンセル
	if (PUSH_0_KEY) {
		//移動処理に戻る
		//文字の表示　SEND
		Set_Action(ACTION_MOVE);
		return;
	}

	index = -1;
	for (int i = 0; i < action_count; ++i) {
		if (PUSH_A_KEY) { //Amended Action_Get_Item参照
			index = i;
			break;
		}
	}
	
	if (index == -1) {
		return;
	}

	//選択したアイテムを取得
	item = player.actor_status.Get_Item_Flom_Index(item_filter, index);

	//選択したアイテムを装備する
	//文字の表示　SEND

	//On_Equip_Chanfe();

	//選択処理に移動
	Set_Action(ACTION_MOVE);
}

void Game::Action_Drop_Item() {
	int index;
	int mx, my;
	Item* item;
	const eITEM_TYPE item_filter = ITEM_TYPE_NONE;

	if (action_count == 0) {
		//アイテム一覧を表示し、該当アイテムを持っているか調べる
		action_count = Message_Items(item_filter);

		if (action_count == 0) {
			//移動処理に戻る
			//文字の表示
			Set_Action(ACTION_MOVE);
		}
		//表示を行ったら一旦抜ける
	}

	//０キーはキャンセル
	if (PUSH_0_KEY) {
		//移動処理に戻る
		//文字の表示
		Set_Action(ACTION_MOVE);
		return;
	}

	index = -1;
	for (int i = 0; i < action_count; ++i) {
		if (PUSH_A_KEY) { //ActionGet_Item参照
			index = i; 
			break;
		}
	}

	if (index == -1) {
		return;
	}

	//選択したアイテムを取得
	item = player.actor_status.Get_Item_Flom_Index(item_filter, index);
	
	//プレイヤーの座標と取得
	player.Get_Position(&mx, &my);

	//選択したアイテムをダンジョンに捨てる
	Item* drop_item = new Item;
	drop_item->Copy(item);
	dungeon_base->Drop_Item(mx, my, drop_item);

	//文字の表紙 SEND
	item->Erase();

	//選択処理に移動
	Set_Action(ACTION_MOVE);
}

/*------------
アイテムを使う
-------------*/
void Game::Action_Use_Item() {
	int index;
	const eITEM_TYPE item_filter = ITEM_TYPE_USEITEM;
	bool used;

	if (action_count == 0) {
		//アイテム一覧を表示し、該当アイテムを持っているか調べる
		action_count = Message_Items(item_filter);

		if (action_count == 0) {
			//移動処理に戻る
			//文字の表示 SEND
			Set_Action(ACTION_MOVE);
			return;
		}
	}

	//0キーはキャンセル
	if (PUSH_0_KEY) {
		//移動処理に戻る
		//文字の表示 SEND
		Set_Action(ACTION_MOVE);
		return;
	}

	index = -1;
	for (int i = 0; i < action_count; ++i) {
		if (PUSH_A_KEY) {
			index = i;
			break;
		}
	}
		if (index == -1) {
			return;
		}
	
	//選択したアイテムを取得
	use_item = player.actor_status.Get_Item_Flom_Index(item_filter, index);
	
	//文字の表示 SEND

	//選択したアイテムのカテゴリで処理を分ける
	switch (use_item->parameter[0]) {
	//HP回復
	case HP_CURE:
			//アイテムの効果を発動
			used = Use_Item_HP_Cure(use_item);

	//食料
	case HUNGER_CURE:
			//アイテムの効果を発動
			used = Use_Item_Food(use_item);
			break;
	}

	//アイテムを使用したかどうか
	if (used) {
		//アイテムを消す
		use_item->Erase();

		//行動を起こしたので、ターン終了
		Enemy_Move();
	}

	//選択処理に移動
	Set_Action(ACTION_MOVE);
}

void Game::Set_Action(ACTION set_action) {
	//識別変数の変更
	action = set_action;

	//汎用変数のゼロリセット
	action_count = 0;
}

bool Game::Action_Step() {
	return true;
}

bool Game::Use_Item_HP_Cure(Item * item) {
	int value = item->parameter[1];

	//HPを回復
	value = player.actor_status.Cure_Hit_Point(value);

	if (value < 0) {
		//文字の表示 SEND
	}

	else {
		//文字の表示 SEND
	}

	return true;
}

bool Game::Use_Item_Food(Item * item) {
	//満腹度の回復
	player.actor_status.Add_Hunger_Point(item->parameter[1]);

	//文字の表示 SEND

	return true;
}

bool Game::Move_Check_Enemy(int set_x, int set_y) {
	Actor* enemy;

	//座標移動をするときにその先にエネミーがいるかを取得
	enemy = dungeon_base->Get_Point_Enemy(set_x, set_y);

	//移動先にモンスターがいる場合
	if (enemy) {
		int damage;

		//攻撃を行う
		damage = dungeon_base->Attack(&player, enemy);

		//メッセージを追加
		//Draw_String hogeの攻撃！
		//fugaにpiyoダメージ！

		//その攻撃で倒したか
		if (enemy->actor_status.Is_Dead()) {
			//メッセージの追加
			//hogeはfugaを倒した

			//経験値をえる TODO:
			//player.actor_status.Add_Experience_Point(enemy_.enemy_data.getExp(0));
		}
	}

	return false;
}

bool Game::Move_Check_Command() {
	//アイテムを拾う
	if (PUSH_G_KEY) {

	}
	return true;
}

void Game::Enemy_Move() {
	bool moved;
	int player_count;

	//プレイヤーの持っているターンカウントを進める
	player.actor_status.Turn();

	//モンスターのターンをプレイヤーの行動力分行う
	player_count = player.actor_status.activity;

	do {
		moved = false;

		for (int i = 0; i < dungeon_base->enemy_count; ++i) {
			Enemy* enemy = dungeon_base->m_enemy[i];
			//無効なエネミーはスキップ
			if (enemy->Is_Dead() == false) {
				continue;
			}

			//行動を行う
			if (enemy->Turn(dungeon_base, player_count) <= 0) {
				moved = true;
			}
		}
			//doループ１週目のEnemy::Turnの時で、プレイヤーの行動分を与えているのでクリアしておく
			player_count = 0;
	
	} while (moved);


	//On_Enemy_Moved();


}