#pragma once

#include"DxLib.h"
#include"Define.h"

static const struct MOVE_CHECK {
	char k1, k2; //���̓L�[
	int vx, vy; //�ړ��������
	DIRECTION direction; //�L�����N�^�[�̌���
} move_check[8]{
	{ KEY_INPUT_UP,    0, -1,  DIRECTION_UP },
	{ KEY_INPUT_DOWN,  0,  1,  DIRECTION_DOWN },
	{ KEY_INPUT_LEFT, -1,  0,  DIRECTION_LEFT },
	{ KEY_INPUT_RIGHT, 1,  0,  DIRECTION_RIGHT },
	{ KEY_INPUT_UP   &&	 KEY_INPUT_LEFT, -1, -1, DIRECTION_UPLEFT },
	{ KEY_INPUT_UP   &&  KEY_INPUT_RIGHT, 1, -1, DIRECTION_UPRIGHT },
	{ KEY_INPUT_DOWN &&  KEY_INPUT_LEFT, -1,  1, DIRECTION_DOWNLEFT },
	{ KEY_INPUT_DOWN &&  KEY_INPUT_RIGHT, 1,  1, DIRECTION_DOWNLEFT },
}