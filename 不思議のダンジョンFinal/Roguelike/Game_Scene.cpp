#include "Game_Scene.h"

// �R���X�g���N�^
Game_Scene::Game_Scene() {
	make_dungeon = std::make_shared<Make_Dungeon>();
}

// �f�X�g���N�^
Game_Scene::~Game_Scene() {
	
}

// ���t���[�����ƂɍX�V
void Game_Scene::Update() {

}

// �X�V�������e�𖈃t���[�����Ƃɕ`��
void Game_Scene::Render() {
	make_dungeon->Render();

	DrawFormatString(0, 0, GetColor(255, 255, 255), "�Q�[�����");
	DrawFormatString(WINDOW_X - 300, 300, GetColor(255, 255, 255), "DELETE�������ƏI��");
}
