#pragma once

#include"Player.h"

/*
�v���C���[�̓����𐧌�
*/

class Player_Controller {
public:
	Player* player;

	Player_Controller();

	bool Action_Move();

};