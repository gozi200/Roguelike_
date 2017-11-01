#pragma once

#include"Player.h"
#include"Enemy.h"
#include"Dungeon01.h"
#include"Dungeon_Base.h"

class Game {
/*////
�萔
*/////
	enum ACTION {
		ACTION_MOVE, //�ړ�����
		ACTION_STEP, //�K�i�ړ��m�F
		ACTION_MAX, //GAme�N���X�Ő錾�����Ă���ACTION�̍ő�l
	};

/*////////
�����o�ϐ�
*/////////
public:
	Player player; //�v���C���[�̃f�[�^
	Dungeon_Base* dungeon_base = new Dungeon_Base;
	Dungeon01* dungeon01 = new Dungeon01; //TODO: new�͂ǂ��ɁH

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
	Game() {

	}

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

};