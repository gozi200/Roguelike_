#pragma once

#include"Actor.h"
#include"Vector2D.h"

/*/////////////////
Actor�N���X���p��

�G���Ǘ�����N���X
////////////////*/

class Enemy : public Actor {
public:
	//�G�l�~�[�̃R���X�g���N�^
	Enemy();

	//�v���C���[�̃f�X�g���N�^
	~Enemy();

	//�ʒu�̐ݒ�A�擾
	void Set_Position(int x, int y);
	void Get_Position(int *px, int*py, DIRECTION *direction = NULL);

};