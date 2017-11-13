#include"Game.h"
#include"Define.h"
#include"Key_Update.h"

//コンストラクタ
Game::Game() {
	dungeon_base = new Dungeon_Base;
	dungeon01 = new Dungeon01;
}

//デストラクタ
Game::~Game() {
	delete dungeon_base;
	delete dungeon01;
}

void Game::Init() {

}

bool Game::Cycle() {
	////キー入力の取得	//KEY_UPDATE
	//Key_Update* key_update; //入力されているキーのデータ
	//key_update = new Key_Update(); //初期化に書く
	//key_update->Get_Key(key);

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

}

bool Game::Action_Step() {
	return true;
}