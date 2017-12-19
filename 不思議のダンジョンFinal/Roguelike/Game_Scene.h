#pragma once

#include"DxLib.h"
#include"Define.h"
#include"Make_Dungeon.h"

#include<memory>

/*-------------------------
�Q�[���V�[�����Ǘ�����N���X
-------------------------*/

class Game_Scene {
/*--------
�����o�ϐ�
--------*/
private:
	std::shared_ptr<Make_Dungeon> make_dungeon;

/*--------
�����o�֐�
--------*/
public:
	// �R���X�g���N�^
	Game_Scene();
	
	// �f�X�g���N�^
	~Game_Scene();

	// ���t���[�����ƂɍX�V
	void Update();

	// �X�V�������e�𖈃t���[�����Ƃɕ`��
	void Render();
};