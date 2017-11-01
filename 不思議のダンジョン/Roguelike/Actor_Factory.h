#pragma once

#include"Actor_Abstract_Factory.h"
#include"Player.h"
#include"Partner.h"
#include"Enemy.h"

#include<string>

/*///////////////////
�A�N�^�[�̍H��

�A�N�^�[�𐶐�������
///////////////////*/

class Actor_Factory : public Actor_Abstract_Factory {
public:
	virtual Actor* Create_Actor(const std::string& name) override {

		if (name == "player") return new Player(); //{}�ŏ����H

		//if (name == "partner") return new Partner(position);
		
		//if (name == "enemy") return new Enemy(position);

		return nullptr;
	}
};