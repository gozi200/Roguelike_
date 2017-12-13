#include "Game_Scene.h"

// �R���X�g���N�^
Game_Scene::Game_Scene() {
	player = new Player();
	dungeon_GUI = new Dungeon_GUI();
	create_dungeon = new Create_Dungeon();

	Initialize();
}

// �f�X�g���N�^
Game_Scene::~Game_Scene() {
	delete player;
	delete dungeon_GUI;
	delete create_dungeon;
}

void Game_Scene::Initialize() {
	dungeon_GUI->Create_Floor(); //TODO: �_���W�����Ɉړ������Ƃ��A�K�w�ړ��̎��ɌĂ΂��悤�ɂ���B
	
	player->Set_Parametor();     // �p�����[�^�̃Z�b�g
}

// ���t���[�����ƂɍX�V
void Game_Scene::Update() {
	
}

// �X�V�������e�𖈃t���[�����Ƃɕ`��
void Game_Scene::Render() {
	dungeon_GUI->Render();

	DrawFormatString(0, 0, GetColor(255, 255, 255), "�Q�[�����");
	DrawFormatString(WINDOW_X - 1000, 300, GetColor(255, 255, 255), "DELETE�������ƏI��");
}
