#include "Game_Scene.h"

// コンストラクタ
Game_Scene::Game_Scene() {
	dungeon_sycle = new Dungeon_Sycle();

	dungeon_GUI = new Dungeon_GUI();
}

// デストラクタ
Game_Scene::~Game_Scene() {
	delete dungeon_sycle;
	delete dungeon_GUI;
	delete create_dungeon;
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
