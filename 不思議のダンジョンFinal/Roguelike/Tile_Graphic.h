#pragma once

#include<vector>

/*--------------------------
���̉摜��z��Ɋi�[����N���X
----------------------------*/

class Tile_Graphic {
public:
/*-------
�����o�ϐ�
--------*/
	std::vector<char*> graphics;

/*--------
�����o�֐�
---------*/
	void Load();
};