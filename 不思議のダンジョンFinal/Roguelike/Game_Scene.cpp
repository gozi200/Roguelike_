#include "Game_Scene.h"

// �R���X�g���N�^
Game_Scene::Game_Scene() {
	dungeon_sycle = new Dungeon_Sycle();

	dungeon_GUI = new Dungeon_GUI();
}

// �f�X�g���N�^
Game_Scene::~Game_Scene() {
	delete dungeon_sycle;
	delete dungeon_GUI;
	delete create_dungeon;
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
