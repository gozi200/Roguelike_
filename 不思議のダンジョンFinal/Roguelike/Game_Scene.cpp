#include "Game_Scene.h"

// コンストラクタ
Game_Scene::Game_Scene() {
	dungeon_GUI = new Dungeon_GUI();

	Initialize();
}

// デストラクタ
Game_Scene::~Game_Scene() {
	delete dungeon_GUI;
}

void Game_Scene::Initialize() {
	dungeon_GUI->Create_Floor(); //TODO: ダンジョンに移動したとき、階層移動の時に呼ばれるようにする。

	//player->Render(player->x, player->y, OKITA); //TODO: Runのようなものを作る?
}

// 毎フレームごとに更新
void Game_Scene::Update() {
	
}

// 更新した内容を毎フレームごとに描画
void Game_Scene::Render() {
	dungeon_GUI->Render();

	DrawFormatString(0, 0, GetColor(255, 255, 255), "ゲーム画面");
	DrawFormatString(WINDOW_X - 300, 300, GetColor(255, 255, 255), "DELETEを押すと終了");
}
