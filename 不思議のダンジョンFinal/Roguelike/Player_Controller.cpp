#include "Player_Controller.h"

Player_Controller::Player_Controller() {
	player = new Player();
}

bool Player_Controller::Action_Move()
{
	int mx, my;
	player->Get_Position(&mx, &my);

	return false;
}
