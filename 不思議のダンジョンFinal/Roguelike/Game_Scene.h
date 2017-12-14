#pragma once

#include"DxLib.h"
#include"Define.h"
#include"Dungeon_Sycle.h"
#include"Dungeon_GUI.h"

/*-------------------------
�Q�[���V�[�����Ǘ�����N���X
-------------------------*/

class Game_Scene {
/*--------
�����o�ϐ�
--------*/
private:
	Dungeon_GUI* dungeon_GUI;

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