#pragma once

#include"Tile.h"
#include"Wall.h"
#include"Game.h"
#include"DxLib.h"

#include"Enemy.h"
#include"Player.h"

#include"Define.h"
#include"Tile_Data.h"
#include"Wall_Data.h"
#include"Tile_Judge.h"
#include"Enemy_Manager.h"

#include<vector>

/*-------------
�Q�[����{�N���X
---------------*/
class Game_Gui : public Game {
/*-------
�����o�ϐ�
--------*/
public:
	 Tile* tile;
	 Wall* wall;
	 Enemy* enemy;
	 Player* player_;

	 int x, y; //���
	 int mx, my; //�}�b�v
	 int cx, cy; //�L����
	 int dx, dy; //�_���W����
	 int loop_count = 0; //���[�v�񐔂𐔂���

/*--------
�����o�֐�
---------*/
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