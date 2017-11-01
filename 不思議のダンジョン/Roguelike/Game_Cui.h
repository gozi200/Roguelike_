#pragma once

#include"Game.h"
#include"DxLib.h"
#include"Tile_Judge.h"
#include"Tile_Data.h"
#include"Wall_Data.h"
#include"Enemy_Manager.h"

#include<vector>

/*/////////////////////////////
�e�L�X�g�x�[�X�ł̃Q�[����{�N���X
/*/////////////////////////////

class Game_Cui : public Game {
public:
	 const Tile_Judge* tile_judge; 

	 Tile_Data tile_data;
	 Wall_Data wall_data;
/*////////
�����o�֐�
*/////////
	 Game_Cui();

	~Game_Cui();

	//�Q�[���̎��s
	int Run();

	//�R���\�[���̏�����
	void Console_Init();

	//��ʂ̕`��
	virtual void Render() override;
};