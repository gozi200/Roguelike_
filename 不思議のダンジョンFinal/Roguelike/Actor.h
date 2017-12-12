#pragma once

#include"DxLib.h"
#include"Set_File.h"
#include"Define.h"

#include<memory>
#include<string>

/*-------------------------------------
Enemy,Player�̃Z�b�g�p���R���X�g���N�^
--------------------------------------*/
struct ACTOR_DATA {
	int ID;				  // �i���o�[
	char* name;			  // ���O
						  
	int level;			  // ���x��
	int attack;			  // �U����
	int defence;		  // �h���
	int agility;		  // �q����(�����ł͉��)
	int hit_point;		  // �q�b�g�|�C���g(0�Ŏ��S)
	int max_hit_point;	  // �q�b�g�|�C���g�̍ő�l
	int activity;		  // �s����(�����ł͂P�^�[���ɍs���ł��鐔)
	int turn_count;		  // �o�߃^�[�����J�E���g
	int experience_point; // �o���l(�G����^����A�G����Ⴆ��l)
						 
	int graphic_handle;	  // �摜�̃n���h��
	int width;			  // �\������镝
	int height;			  // �\������鍂��
};

/*----------------------
Player,Enemy�̊��N���X
-----------------------*/
class Actor {
/*--------
�����o�ϐ�
--------*/
protected:
	int ID;               // �i���o�[
	char* name;           // ���O

	int x;                // ���̍��W
	int y;                // �c�̍��W

	int level;            // ���x��
	int power;            // ������ (�U���͂ɉ��Z����{�[�i�X)
	int max_power;        // �͂̍ő�l
	int attack;           // �U���� (�f�̍U���́B�����ɕ���̍U���́A
	int defence;          // �h���
	int agility;          // �q����(�����ł͉��)
	int hit_point;        // �q�b�g�|�C���g(0�Ŏ��S)
	int max_hit_point;    // �q�b�g�|�C���g�̍ő�l
	int activity;         // �s����(�����ł͂P�^�[���ɍs���ł��鐔)
	int turn_count;       // �o�߃^�[�����J�E���g
	int experience_point; // �o���l(�G����^����A�G����Ⴆ��l)

	int graphic_handle;   // �摜�̃n���h��
	int width;            // �\������镝
	int height;           // �\������鍂��

	std::shared_ptr<Set_File> set;
	std::string file_pass; //�t�@�C���̃p�X

/*--------
�����o�֐�
--------*/
public:
	// �R���X�g���N�^
	Actor();

protected:
	// �f�X�g���N�^
	~Actor();

	// ���W�̃Z�b�g
	virtual void Set_Position(int x, int y) = 0;

	// ���W�̎擾
	virtual void Get_Position(int* x, int* y, eDIRECTION* direction = NULL) = 0;

	//�X�e�[�^�X���Z�b�g
	virtual void Set_Parametor() = 0;

	// hit_point�̑���
	virtual int Variation_HP(int value) = 0;

	// �^�[���̏I��
	virtual void Turn_End() = 0;

	// �ő��HP�̎擾
	virtual int Get_Max_HP() = 0;

	// �U���͂̎擾
	virtual int Get_Attack() = 0;

	// �h��͂̎擾
	virtual int Get_Defence() = 0;

	// ��𗦂��擾
	virtual int Get_Agility() = 0;

	// ���S����
	virtual bool Is_Dead() = 0;
};