#pragma once

#include"Game.h"
#include"DxLib.h"
#include"Define.h"
#include"Tile_Data.h"
#include"Wall_Data.h"
#include"Tile_Judge.h"
#include"Wall_Function.h"
#include"Tile_Function.h"
#include"Enemy_Manager.h"

#include<vector>

/*/////////////////////////////
�e�L�X�g�x�[�X�ł̃Q�[����{�N���X
/*/////////////////////////////

class Game_Gui : public Game {
/*///////
�����o�ϐ�
*////////
public:
	 //const Tile_Judge* tile_judge; 
	 //const Tile_Judge* tile_down;
	 Tile_Function* tile_function;
	 Wall_Function* wall_function;

	 int x, y; //���
	 int mx, my; //�}�b�v
	 int cx, cy; //�L����
	 int dx, dy; //�_���W����
	 int loop_count = 0; //���[�v�񐔂𐔂���

/*////////
�����o�֐�
*////////
	 //�R���X�g���N�^/
	 Game_Gui();
	 //�f�X�g���N�^
	~Game_Gui();

	//�Q�[���̎��s
	int Run();

	//�R���\�[���̏�����
	void Console_Init();

	//��ʂ̕`��
	virtual void Render() override;
};