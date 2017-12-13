#pragma once

#include"DxLib.h"
#include"Define.h"
#include"Dungeon_Sycle.h"
#include"Dungeon_GUI.h"

#include"Player.h" // Amended
#include"Create_Dungeon.h"

/*-------------------------
�Q�[���V�[�����Ǘ�����N���X
-------------------------*/

class Game_Scene {
/*--------
�����o�ϐ�
--------*/
private:
	Player* player;
	Dungeon_GUI* dungeon_GUI;
	Create_Dungeon* create_dungeon;

/*--------
�����o�֐�
--------*/
public:
	// �R���X�g���N�^
	Game_Scene();
	
	// �f�X�g���N�^
	~Game_Scene();

	// ������
	void Initialize();

	// ���t���[�����ƂɍX�V
	void Update();

	// �X�V�������e�𖈃t���[�����Ƃɕ`��
	void Render();
};