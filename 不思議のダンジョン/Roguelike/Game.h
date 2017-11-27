#pragma once

#include"Define.h"
#include"Actor.h"
#include"Enemy.h"
//#include"Player.h"
#include"Dungeon01.h"
#include"Dungeon_Base.h"
#include"Actor_Status.h"

class Game {
/*////
�萔
*/////
	//enum ACTION {
	//	ACTION_MOVE, //�ړ�����
	//	ACTION_STEP, //�K�i�ړ��m�F
	//	ACTION_MAX, //GAme�N���X�Ő錾�����Ă���ACTION�̍ő�l
	//};

/*////////
�����o�ϐ�
*/////////
public:
	Dungeon_Base* dungeon_base;
	Dungeon01* dungeon01;
	Actor player;

	Enemy* enemy_;

	Actor_Status actor_status;

	int floor; //���݂̊K�w

	char key[KEY_NUMBER]; //�S�ẴL�[

private:
	ACTION action; //���݂̃��C������

	int action_count; //���C�������ėp�ϐ�

/*////////
�����o�֐�
*/////////
public:
	//�R���X�g���N�^
	Game();

	//�f�X�g���N�^
	virtual ~Game();

	//�Q�[���̏�����
	void Init();

	//�Q�[���̃��C�����[�v���s(�T�C�N�����s)
	bool Cycle();

	//�t���A�̍쐬
	void Create_Floor();

	//��ʂ̕`��
	virtual void Render() = 0;

private:
	//�����̐؂�ւ�
	void Set_Action(ACTION action);

	//�����̎��s
	void Run_Action();

	//�ړ�����
	bool Action_Step();


	//private�ł����H
	bool Move_Check_Enemy(int x, int y);

	bool Move_Check_Command();

	void Enemy_Move();

};