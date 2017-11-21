#pragma once

#include"Ally.h"
#include"Vector2D.h"
#include"Player_Data.h"
#include"Player_Key_Contloroller.h"

/*------------------
Actor�N���X���p��

���@���Ǘ�����N���X
-------------------*/

class Player : public Ally {


/*--------
�����o�ϐ�
---------*/
public:
	Player_Key_Controller* player_key_controller;
	Player_Data player_data;

	int loop_count;
/*--------
�����o�֐�
---------*/
public:
	//�R���X�g���N�^
	Player();

	//�f�X�g���N�^
	~Player();

	//�ʒu�̐ݒ�A�擾
	void Set_Position(int x, int y);
	void Get_Position(int *px, int*py, DIRECTION *direction = NULL);

	/*���̉摜��`�悷��
	�@@param call_ID ID�ɍ������摜���Ă�
	 @param x �`�悷��ꏊ��x��
	 @param y �`�悷��ꏊ��y��
	 */
	void Render(int call_ID, int x, int y);
};