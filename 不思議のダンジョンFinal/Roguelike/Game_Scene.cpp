#include "Game_Scene.h"

// コンストラクタ
Game_Scene::Game_Scene() {
	player = new Player();
	dungeon_GUI = new Dungeon_GUI();
	create_dungeon = new Create_Dungeon();

	Initialize();
}

// デストラクタ
Game_Scene::~Game_Scene() {
	delete player;
	delete dungeon_GUI;
	delete create_dungeon;
}

void Game_Scene::Initialize() {
	dungeon_GUI->Create_Floor(); //TODO: ダンジョンに移動したとき、階層移動の時に呼ばれるようにする。
	
	player->Set_Parametor();     // パラメータのセット
}

// 毎フレームごとに更新
void Game_Scene::Update() {
	
}

// 更新した内容を毎フレームごとに描画
void Game_Scene::Render() {
	dungeon_GUI->Render();

	DrawFormatString(0, 0, GetColor(255, 255, 255), "ゲーム画面");
	DrawFormatString(WINDOW_X - 1000, 300, GetColor(255, 255, 255), "DELETEを押すと終了");
}
