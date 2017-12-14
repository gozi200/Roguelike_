#include "Game_Scene.h"

// コンストラクタ
Game_Scene::Game_Scene() {
	make_dungeon_map = new Make_Dungeon_Map();

	Initialize();
}

// デストラクタ
Game_Scene::~Game_Scene() {
	delete make_dungeon_map;
}

void Game_Scene::Initialize() {
	make_dungeon_map->Create_Floor(); //TODO: ダンジョンに移動したとき、階層移動の時に呼ばれるようにする。

	//player->Render(player->x, player->y, OKITA); //TODO: Runのようなものを作る?
}

// 毎フレームごとに更新
void Game_Scene::Update() {
	
}

// 更新した内容を毎フレームごとに描画
void Game_Scene::Render() {
	make_dungeon_map->Render();

	DrawFormatString(0, 0, GetColor(255, 255, 255), "ゲーム画面");
	DrawFormatString(WINDOW_X - 300, 300, GetColor(255, 255, 255), "DELETEを押すと終了");
}
