#pragma once

#include"Ally.h"
#include"Player_Graphic.h"
#include"Make_Dungeon_Map.h"

/*------------------------------
�v���C���[�Ɏ����������ݒ肷��
------------------------------*/

struct PLAYER_DATA : public ALLY_DATA {
	int keep_star;    // �N���e�B�J���X�^�[�̕ێ���
	int hunger_point; // �󕠃|�C���g
};

/*----------------------
�v���C���[���Ǘ�����N���X
-----------------------*/
class Make_Dungeon;

class Player : public Ally {
/*--------
�����o�ϐ�
--------*/
private:
	std::shared_ptr<Player_Graphic> player_graphic;
	std::shared_ptr<Make_Dungeon_Map> dungeon_manager;
	
	int* player_x;    // �v���C���[�̍��W(��)
	int player_y;     // �v���C���[�̍��W(�c)
	int keep_star;    // �N���e�B�J���X�^�[�̕ێ���
	int hunger_point; // �󕠃|�C���g

	std::vector<PLAYER_DATA> player_datas; // �L�������Ɋi�[

public:
	int spawn_point_x; // �����̍��W(��)
	int spawn_point_y; // �����̍��W(�c)

/*--------
�����o�֐�
---------*/
public:
	// �R���X�g���N�^
	Player();

	Player(std::shared_ptr<Make_Dungeon_Map> manager);

	// �f�X�g���N�^
	~Player();

	// �p�����[�^���Z�b�g
	void Set_Parametor() override;
	

private:
	// ���W���擾
	void Set_Player_Position();

	// �^�[���̏I��
	void Turn_End() override;

	// ���Ȃ��Q�[�W�̑���
	void Variation_Hunger_Point(int value);

	//// �A�C�e���̎擾�B�J�o���������ς��Ȃ� true ��Ԃ�
	//bool Get_Item(Item* item);

	//// �w�肵���t�B���^�Ŏw�肵���C���f�b�N�X�̃A�C�e�����擾
	//Item* Get_Item_From_Index(eITEM_TYPE filter, int index);

	// �󕠗��� 0~100% �ŕԂ�
	int Get_Hunger_Percent();

public:
	// �`��
	void Render(int x, int y, int call_ID) override;
};