#pragma once

#include"Player.h"

/*
プレイヤーの動きを制御
*/

class Player_Controller {
public:
	Player* player;

	Player_Controller();

	bool Action_Move();

};