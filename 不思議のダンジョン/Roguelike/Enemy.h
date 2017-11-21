#pragma once

#include"Actor.h"
#include"DxLib.h"
#include"Define.h"
#include"Vector2D.h"
#include"Enemy_Data.h"

/*----------------
Actor�N���X���p��

�G���Ǘ�����N���X
-----------------*/

class Enemy : public Actor {
/*--------
�����o�ϐ�
---------*/
Enemy_Data enemy_data;

int loop_count;

/*--------
�����o�֐�
--------*/
public:
	//�G�l�~�[�̃R���X�g���N�^
	Enemy();

	//�v���C���[�̃f�X�g���N�^
	~Enemy();

	//�ʒu�̐ݒ�A�擾
	void Set_Position(int x, int y);
	void Get_Position(int* px, int* py, DIRECTION* direction = NULL);

	/*�v���C���[�̉摜��`�悷��
	 @param call_ID ID�ɍ������摜���Ă�
	 @param x �`�悷��ꏊ��x��
	 @param y �`�悷��ꏊ��y��
	 */
	void Render(int call_ID, int x, int y);
};