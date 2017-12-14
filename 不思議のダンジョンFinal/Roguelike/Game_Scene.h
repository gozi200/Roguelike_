#pragma once

#include"DxLib.h"
#include"Define.h"
#include"Dungeon_Sycle.h"
#include"Make_Dungeon_Map.h"

/*-------------------------
�Q�[���V�[�����Ǘ�����N���X
-------------------------*/

class Game_Scene {
/*--------
�����o�ϐ�
--------*/
private:
	Make_Dungeon_Map* make_dungeon_map;

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