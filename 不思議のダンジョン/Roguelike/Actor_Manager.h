#pragma once

#include"Actor.h"
#include"Player.h"
#include"Partner.h"
#include"Enemy.h"
#include"Define.h"

/*/////////////////////////
Actor�̌��Ǘ�����N���X
////////////////////////*/

class Actor_Manager {
private:
	bool is_gameover_flag;

public:
	//�R���X�g���N�^
	Actor_Manager(char*); //�v���C���[�𓮂������߃L�[�m�F

	//�f�X�g���N�^
	~Actor_Manager();

	void Update(); //���t���[���Ăяo����鏈��

	void Render();

	bool Get_Gameover_Flag();

	void Actor_Array();

};
