#pragma once

#include"Ally.h"
#include"Vector2D.h"
#include"Player_Data.h"
#include"Player_Key_Contloroller.h"

/*//////////////////
Actor�N���X���p��

���@���Ǘ�����N���X
//////////////////*/

class Player : public Ally {


	/*////////
	�����o�ϐ�
	*/////////
public:
	char* player_name;
	PLAYER_STATUS_DATA* player_data;
	Player_Key_Controller* player_key_controller;

	//Player_Data* player_data;

	//Ally_Status status; //��{�X�e�[�^�X

/*////////
�����o�֐�
*/////////

public:
	/*�v���C���[�̃R���X�g���N�^
	*/
	Player();

	//�v���C���[�̃f�X�g���N�^
	~Player();

	/* �X�|�[�������v���C���[��z�u
	   @param x x���W
	   @param y y���W
	*/
	void Arrange(int x, int y); //QUESTION: Vector2D�g���H

	//���t���[���Ăяo������������
	void Update();

	//���݂̏�Ԃɂɂ������摜�ɐ؂�ւ���B
	void Current_Graphic();

	//�ʒu�̐ݒ�A�擾
	void Set_Position(int x, int y);
	void Get_Position(int *px, int*py, DIRECTION *direction = NULL);


	///////////////////////////////�ʂ̂Ƃ���ŏ�������H(hp,����,���x��,�o���l�Ȃǂ̉����ł�����̂͂܂Ƃ߂�H)
	void Render_Hit_Point();

	void Render_Experiece_Point();

	void Render_Stmach(); //���Ȃ��Q�[�W�̕`��
	////////////////////////////////
};