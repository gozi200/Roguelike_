#include"Actor_Manager.h"
#include"DxLib.h"
#include"Player.h"
#include"Enemy.h"

//�R���X�g���N�^
Actor_Manager::Actor_Manager(char* set_key) : is_gameover_flag(false) {}

//�f�X�g���N�^
Actor_Manager::~Actor_Manager() {}

void Actor_Manager::Update() {}

bool Actor_Manager::Get_Gameover_Flag() {
	return is_gameover_flag;
}

void Actor_Manager::Actor_Array() {}

void Actor_Manager::Render() {}