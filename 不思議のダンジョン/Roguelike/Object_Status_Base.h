#pragma once

#include<string>

struct Object_Status_Base {
	int ID;						//�i���o�[
	std::string name;			//���O
	int x;						//���̍��W
	int y;						//�c�̍��W
								
	int level;					//���x��
	int power;					//������ (�f�̍U���́B�����ɕ���̍U���́A���x���ŕϓ�����U���͂��v�Z)
	int attack;					//�U����
	int defence;				//�h���
	int hit_point;				//�q�b�g�|�C���g(0�Ŏ��S)
	int activity;				//�s����(�����ł͂P�^�[���ɍs���ł��鐔)
	int turn_count;				//�o�߃^�[�����J�E���g
	int experience_point;		//�o���l(���l���ƂɃ��x�����オ��)
	Item items[MAX_STOCK_ITEM]; //�����؂��A�C�e���̐�
								
					  			
	int width;					//�\������镝
	int height;					//�\������鍂��
	int graphic_handle;			//�摜�̃n���h��
};