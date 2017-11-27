#pragma once

#include"Vector2D.h"

#include<string>

/*///////////////////////
�A�N�^�[�H��̊��N���X
*////////////////////////

class Actor_Abstract_Factory {
public:
	//���z�f�X�g���N�^
	virtual ~Actor_Abstract_Factory() {}

	//�A�N�^�[�̐���(���z�֐�)
	virtual Actor* Create_Actor(const std::string& name) = 0;
};