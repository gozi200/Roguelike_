#pragma once

#include"Define.h"
#include"Player.h"
#include"Make_Dungeon_Map.h"

#include<memory>

/*--------------------------
���ꂽ�f�[�^�����ɉ摜��`��
--------------------------*/

class Make_Dungeon {
/*--------
�����o�ϐ�
--------*/
private:
	std::shared_ptr<Player> player;
	std::shared_ptr<Make_Dungeon_Map> make_dungeon_map;

/*-------
�����o�֐�
--------*/
public:
	// �R���X�g���N�^
	Make_Dungeon();

	// �f�X�g���N�^
	~Make_Dungeon();

	// �_���W���������
	void Render();

	// �_���W�����̏����� (�_���W�����i�����A�K�w�ړ����ɌĂ΂��)
	void Initialize_Dungeon();
};