#include "Game_Scene.h"

// �R���X�g���N�^
Game_Scene::Game_Scene() {
	make_dungeon_map = new Make_Dungeon_Map();

	Initialize();
}

// �f�X�g���N�^
Game_Scene::~Game_Scene() {
	delete make_dungeon_map;
}

void Game_Scene::Initialize() {
	make_dungeon_map->Create_Floor(); //TODO: �_���W�����Ɉړ������Ƃ��A�K�w�ړ��̎��ɌĂ΂��悤�ɂ���B

	//player->Render(player->x, player->y, OKITA); //TODO: Run�̂悤�Ȃ��̂����?
}

// ���t���[�����ƂɍX�V
void Game_Scene::Update() {
	
}

// �X�V�������e�𖈃t���[�����Ƃɕ`��
void Game_Scene::Render() {
	make_dungeon_map->Render();

	DrawFormatString(0, 0, GetColor(255, 255, 255), "�Q�[�����");
	DrawFormatString(WINDOW_X - 300, 300, GetColor(255, 255, 255), "DELETE�������ƏI��");
}
