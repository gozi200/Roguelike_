#pragma once

#include"Define.h"
#include"Wall_Data.h"

/*//////////////////////////
�ǂɊւ���֐���ݒ肷��N���X
*//////////////////////////

class Wall_Function {
public:
	Wall_Data wall_data;

	int loop_count = 0; //���[�v�񐔂𐔂���

						//�R���X�g���N�^
	Wall_Function();

	//�f�X�g���N�^
	~Wall_Function();

	/*���̉摜��`�悷��
	 @param call_ID ID�ɍ������摜���Ă�
	 @param x �`�悷��ꏊ��x��
	 @param y �`�悷��ꏊ��y��
	 */
	void Draw_Wall(int call_ID, int x, int y);

};