#pragma once

#include"Enemy.h"
#include"Random.h"

class Enemy_01 : public Enemy {
/*--------
�����o�ϐ�
--------*/
public:
	int x, y; //���W
	Random* random;
	eDIRECTION direciton;

/*--------
�����o�֐�
---------*/
public:
	//�R���X�g���N�^
	Enemy_01();

	//�f�X�g���N�^
	virtual ~Enemy_01();

	//�s������
	virtual void Move(Dungeon_Base* dungeon_base);
};