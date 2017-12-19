#include "Make_Dungeon.h"

// コンストラクタ
Make_Dungeon::Make_Dungeon() {
	make_dungeon_map = std::make_shared<Make_Dungeon_Map>();
	player = std::make_shared<Player>(make_dungeon_map);

	Initialize_Dungeon();
}

// デストラクタ
Make_Dungeon::~Make_Dungeon() {
}

// ダンジョンの更新 (ダンジョン進入時、階層移動時に呼ばれる)
void Make_Dungeon::Initialize_Dungeon() {
	make_dungeon_map->Create_Floor();
	player->Set_Parametor();
	//make_dungeon_map->DebugOutput();
}

// ダンジョンを作る
void Make_Dungeon::Render() {
	make_dungeon_map->Render();
	player->Render(OKITA, player->x * TILE_SIZE, player->y * TILE_SIZE);
}