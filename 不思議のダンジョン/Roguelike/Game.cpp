#include"Game.h"
#include"Define.h"
#include"Key_Update.h"

//�R���X�g���N�^
Game::Game() {
	dungeon_base = new Dungeon_Base;
	dungeon01 = new Dungeon01;
}

//�f�X�g���N�^
Game::~Game() {
	delete dungeon_base;
	delete dungeon01;
}

void Game::Init() {

}

bool Game::Cycle() {
	////�L�[���͂̎擾	//KEY_UPDATE
	//Key_Update* key_update; //���͂���Ă���L�[�̃f�[�^
	//key_update = new Key_Update(); //�������ɏ���
	//key_update->Get_Key(key);

	Run_Action();

	//��ʍX�V
	Render();

	return false;
}

//�ʂ�߂����_���W����(�K)��j������
void Game::Create_Floor() {
	if (dungeon_base) {
		delete dungeon_base;
	}

	dungeon01->Alloc(DUNGEON_WIDTH, DUNGEON_HEIGHT); //Define�萔�g�p

	dungeon01->Make(&player, floor);

	dungeon_base = dungeon01;

}


void Game::Set_Action(ACTION set_action) {

}

void Game::Run_Action() {

}

bool Game::Action_Step() {
	return true;
}