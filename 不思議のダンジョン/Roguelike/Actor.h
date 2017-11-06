#pragma once

#include"Object.h"
#include"Define.h"
#include"Actor_State.h"

/*////////////////////////
Object���p��

Actor�S�̂��Ǘ�����N���X
////////////////////////*/

class Actor : public Object {
/*////////
�����o�ϐ�
*////////
protected:
	int level;

	int hit_point;

	int state; //���݂̏��

	int attack; //�f�̍U���� ����ɕ���̍U���͂𔽉f

	int defense; //�f�̖h��� ����ɖh��̖h��͂𔽉f

	int Energy; //�P�^�[���ɍs���ł��鐔

	int Speed; //1�^�[���Ɉړ��ł��鐔

	int change_state;

	char* name;

public:

/*////////
�����o�֐�
*/////////
public:
	//�R���X�g���N�^
	Actor();
	
	//�f�X�g���N�^
	~Actor() {};

	void Render_Charactor(); //����H

	void Change_State();

#pragma region State_Paturn

	bool isWait();
	bool isAttack();

#pragma endregion
};