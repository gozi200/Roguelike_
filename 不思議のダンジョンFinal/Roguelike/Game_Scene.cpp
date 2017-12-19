#include "Game_Scene.h"

// コンストラクタ
Game_Scene::Game_Scene() {
	make_dungeon = std::make_shared<Make_Dungeon>();
}

// デストラクタ
Game_Scene::~Game_Scene() {
	
}

// 毎フレームごとに更新
void Game_Scene::Update() {

}

// 更新した内容を毎フレームごとに描画
void Game_Scene::Render() {
	make_dungeon->Render();

	DrawFormatString(0, 0, GetColor(255, 255, 255), "ゲーム画面");
	DrawFormatString(WINDOW_X - 300, 300, GetColor(255, 255, 255), "DELETEを押すと終了");
}
