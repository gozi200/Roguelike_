#include"Actor_Manager.h"
#include"DxLib.h"
#include"Player.h"
#include"Enemy.h"

//コンストラクタ
Actor_Manager::Actor_Manager(char* set_key) : is_gameover_flag(false) {}

//デストラクタ
Actor_Manager::~Actor_Manager() {}

void Actor_Manager::Update() {}

bool Actor_Manager::Get_Gameover_Flag() {
	return is_gameover_flag;
}

void Actor_Manager::Actor_Array() {}

void Actor_Manager::Render() {}