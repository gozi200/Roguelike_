#pragma once

#include"Vector2D.h"

/*//////////////////////////////////
Actor�̌p�����N���X�ł���A���N���X
//////////////////////////////////*/

class Actor_Manager; //���N���X�ɐ錾���Ă���
class Item_Manager; //����

class Object {
	Actor_Manager* actor_manager;
	Item_Manager* item_manager;
	Vector2D position; //���W�@QESTION: position���g���Ȃ�x,y�́H
	
/*/////////
�����o�ϐ�
*//////////
protected:

	int x;

	int y;

	bool is_exist; //���݃t���O

	float collision; //��ѓ���Ȃǂ̃q�b�g�m�F�̂��߂̓����蔻��

	bool is_hostility_flag; //�G�� true��false�̂ݍU���\�B�t���R��


/*////////
�����o�֐�
*/////////
public:
	Object();

	bool Get_Exist() const;

	int Get_X() const;

	int Get_Y() const;

	double Get_Collision() const;

	double Get_Hostility_Flag() const;
};
