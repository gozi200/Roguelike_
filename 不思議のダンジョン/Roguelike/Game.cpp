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

bool Game::Cycle() {
	Run_Action();

	//画面更新
	Render();

	return false;
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

void Game::Set_Action(ACTION set_action) {

}

void Game::Run_Action() {
	////動作によって処理を振り分ける
	//switch (action) {
	//case ACTION_MOVE: Action_Move(); break;
	//
	//case ACTION_STEP: Action_Step(); break;
	//}
}

bool Game::Action_Step() {
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

			//経験値をえる
			//player.actor_status.Add_Experience_Point(enemy_.enemy_data.getExp(0));
		}
	}

	return false;
}

bool Game::Move_Check_Command() {
	//アイテムを拾う
	if (GET_ITEM) {

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


	//On_Enemy_Moved(); //NEXT
}