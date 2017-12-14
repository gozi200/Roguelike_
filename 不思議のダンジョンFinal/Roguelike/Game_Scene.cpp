#include "Game_Scene.h"

// �R���X�g���N�^
Game_Scene::Game_Scene() {
	dungeon_GUI = new Dungeon_GUI();

	Initialize();
}

// �f�X�g���N�^
Game_Scene::~Game_Scene() {
	delete dungeon_GUI;
}

void Game_Scene::Initialize() {
	dungeon_GUI->Create_Floor(); //TODO: �_���W�����Ɉړ������Ƃ��A�K�w�ړ��̎��ɌĂ΂��悤�ɂ���B

	//player->Render(player->x, player->y, OKITA); //TODO: Run�̂悤�Ȃ��̂����?
}

// ���t���[�����ƂɍX�V
void Game_Scene::Update() {
	
}

// �X�V�������e�𖈃t���[�����Ƃɕ`��
void Game_Scene::Render() {
	dungeon_GUI->Render();

	DrawFormatString(0, 0, GetColor(255, 255, 255), "�Q�[�����");
	DrawFormatString(WINDOW_X - 300, 300, GetColor(255, 255, 255), "DELETE�������ƏI��");
}
