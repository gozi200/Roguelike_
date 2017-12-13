#pragma once

#include"Item.h"
#include"Ally.h"
#include"Split.h"
#include"Define.h"
#include"Player_Graphic.h"

#include<vector>
#include<string>
#include<fstream>
#include<memory>

/*------------------------------
�v���C���[�Ɏ����������ݒ肷��
------------------------------*/
struct PLAYER_DATA : public ALLY_DATA {
	int hunger_point;       // �󕠃|�C���g
};

/*--------------------------------------
�v���C���[���Ǘ�����N���X
---------------------------------------*/

class Player : public Actor {
/*--------
�����o�ϐ�
--------*/
public:
	std::shared_ptr<Player_Graphic> player_graphic;
	std::vector<PLAYER_DATA> player_datas; // �L�������Ɋi�[
	
	int hunger_point;       // �󕠃|�C���g
	int noble_phantasm;     // ���������߂̃|�C���g

private:
	int max_noble_phantasm; // np�̍ő�l

/*--------
�����o�֐�
---------*/
public:
	// �R���X�g���N�^
	Player();

	// �f�X�g���N�^
	~Player();

	// �p�����[�^���Z�b�g
	void Set_Parametor() override;

	// �^�[���̏I��
	void Turn_End() override;

	// �`��
	void Render(int x, int y, int call_ID) override;

	// ���Ȃ��Q�[�W�̑���
	void Variation_Hunger_Point(int value);

	// �A�C�e���̎擾�B�J�o���������ς��Ȃ� true ��Ԃ�
	bool Get_Item(Item* item);

	// �w�肵���t�B���^�Ŏw�肵���C���f�b�N�X�̃A�C�e�����擾
	Item* Get_Item_From_Index(eITEM_TYPE filter, int index);

	// �󕠗��� 0~100% �ŕԂ�
	int Get_Hunger_Percent();
};