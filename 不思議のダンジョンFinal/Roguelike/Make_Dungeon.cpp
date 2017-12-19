#include "Make_Dungeon.h"

// �R���X�g���N�^
Make_Dungeon::Make_Dungeon() {
	make_dungeon_map = std::make_shared<Make_Dungeon_Map>();
	player = std::make_shared<Player>(make_dungeon_map);

	Initialize_Dungeon();
}

// �f�X�g���N�^
Make_Dungeon::~Make_Dungeon() {
}

// �_���W�����̍X�V (�_���W�����i�����A�K�w�ړ����ɌĂ΂��)
void Make_Dungeon::Initialize_Dungeon() {
	make_dungeon_map->Create_Floor();
	player->Set_Parametor();
	//make_dungeon_map->DebugOutput();
}

// �_���W���������
void Make_Dungeon::Render() {
	make_dungeon_map->Render();
	player->Render(OKITA, player->x * TILE_SIZE, player->y * TILE_SIZE);
}