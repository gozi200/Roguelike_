#pragma once

#include"Game.h"
#include"DxLib.h"
#include"Define.h"
#include"Tile_Data.h"
#include"Wall_Data.h"
#include"Tile_Judge.h"
#include"Tile_Function.h"
#include"Enemy_Manager.h"

#include<vector>

/*/////////////////////////////
�e�L�X�g�x�[�X�ł̃Q�[����{�N���X
/*/////////////////////////////

class Game_Cui : public Game {
/*///////
�����o�ϐ�
*////////
public:
	 const Tile_Judge* tile_judge; 
	 Tile_Function* tile_function;

	 Tile_Data Tile_data;
	 Wall_Data wall_data;

	 int loop_count = 0; //���[�v�񐔂𐔂���

/*////////
�����o�֐�
*////////
	 //�R���X�g���N�^/
	 Game_Cui();
	 //�f�X�g���N�^
	~Game_Cui();

	//�Q�[���̎��s
	int Run();

	//�R���\�[���̏�����
	void Console_Init();

	//��ʂ̕`��
	virtual void Render() override;
};