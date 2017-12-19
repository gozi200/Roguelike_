#pragma once

#include"Split.h"
#include"Define.h"
#include"Set_File.h"

#include<vector>
#include<memory>
#include<string>
#include<fstream>

/*-------------------
Enemy,Ally�̐e�N���X
-------------------*/
struct ACTOR_DATA {
	int ID;				  // �i���o�[
	std::string  name;    // ���O

	int calss;            // �N���X
	int saint_graph;      // �ėՏ��
	int level;			  // ���x��
	int attack;			  // �U����
	int defence;		  // �h���
	int hit_point;		  // �q�b�g�|�C���g(0�Ŏ��S)
	int max_hit_point;	  // �q�b�g�|�C���g�̍ő�l
	int activity;		  // �s����(�����ł͂P�^�[���ɍs���ł��鐔)
	int experience_point; // �o���l(�G����^����A�G����Ⴆ��l)
	int turn_count;       // �o�߃^�[�����J�E���g
	int sukill;           // �X�L��

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
public:
	int x;                // ���̍��W
	int y;                // �c�̍��W
	int level;            // ���x��
	int loop_counter;     // �J�E���^�[

	std::string file_pass; 
	std::shared_ptr<Set_File> set;

private:
	int ID;               // �i���o�[
	std::string* name;    // ���O

	int power;            // ������ (�U���͂ɉ��Z����{�[�i�X)
	int max_power;        // �͂̍ő�l
	int attack;           // �U���� (�f�̍U���́B�����ɕ���̍U���́A
	int defence;          // �h���
	int hit_point;        // �q�b�g�|�C���g(0�ȉ��Ŏ��S)
	int max_hit_point;    // �q�b�g�|�C���g�̍ő�l
	int activity;         // �s����(�����ł͂P�^�[���ɍs���ł��鐔)
	int skill;            // �X�L��
	int turn_count;       // �o�߃^�[�����J�E���g

	int graphic_handle;   // �摜�̃n���h��
	int width;            // �\������镝
	int height;           // �\������鍂��

	
protected:
	int experience_point; // �o���l(�G����^����A�G����Ⴆ��l)

/*--------
�����o�֐�
--------*/
public:
	// �R���X�g���N�^
	Actor();
	
	// ���W�̃Z�b�g
	virtual void Set_Position(int x, int y);

	// ���W�̎擾
	virtual void Get_Position(int* x, int* y, eDIRECTION* direction = NULL);
protected:
	// �f�X�g���N�^
	~Actor();

	// hit_point�̑���
	virtual int Variation_HP(int value);

	// �ő��HP�̎擾
	virtual int Get_Max_HP(int set_max_HP);

	// �U���͂̎擾
	virtual int Get_Attack(int set_ATK);

	// �h��͂̎擾
	virtual int Get_Defence(int set_DEF);

	//// �J�E���^�[����
	//virtual int Get_Loop_Counter(int set_counter);

	// �^�[���J�E���g����
	virtual int Get_Turn_Count(int set_turn_count);

	// ���S����
	virtual bool Is_Dead();

	// �^�[���̏I��
	virtual void Turn_End();

	//�X�e�[�^�X���Z�b�g
	virtual void Set_Parametor() = 0;

	// �`��
	virtual void Render(int x, int y, int call_ID) = 0;
};