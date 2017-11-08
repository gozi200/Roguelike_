#pragma once

#include"DxLib.h"

/*//////////////////////////
�l�X�Ȓ萔�����肵�Ă����N���X
//////////////////////////*/

#pragma region ��ʃT�C�Y

const int WINDOW_X = 1170; //��ʃT�C�Y(��) 

const int WINDOW_Y = 720; //��ʃT�C�Y(�c)

#pragma endregion

#pragma region �v�Z�Ɏg���萔

const double PI = 3.14159265358979323846; //�~����

#pragma endregion

#pragma region �A�N�^�[�Ɋւ���萔
const int ACTOR_SIZE_X = 90; //�L�����N�^�[�̃T�C�Y(��)

const int ACTOR_SIZE_Y = 90; //�L���������[�̃T�C�Y(�c)

const int ENERGY = 1; //�P�^�[���ɍs���ł��鐔

const int ALLY_NUMBER = 2; //�����������ɏo���ł��鐔

const int MAX_ACTOR = 35; //Actor�������ɏo���ł��鐔

const int ACTOR_MOVEMENT = 5; //1�}�X���̈ړ��� �ЂƂ܂�

const int COLLISION = 20; //�����Ȃ�΃L�����̑傫���@�ЂƂ܂�

const int MAX_ENEMY = 500; //�G�l�~�[�̗� �ЂƂ܂�

#pragma endregion


#pragma region �A�C�e���Ɋւ���萔

const int ITEM_MAX = 500; //�A�C�e���������ɏo���ł��鐔�@�ЂƂ܂�

#pragma endregion


#pragma region �_���W�����Ɋւ���萔
//�Ƃ肠�����͂�����

const int DUNGEON_WIDTH = 50; //�_���W�����̉��}�X�̐�

const int DUNGEON_HEIGHT = 50; //�_���W�����̏c�}�X�̐�

const int RECTANGLE = 100; //�ЂƂ܂��̒l ��`�A�����`

const int MAX_RECTANGLE = 10; //���̍ő�l

const int MIN_ROOM_SIZE = 4; //�ŏ��̕����̃T�C�Y

#pragma endregion

//�����\���� �֐���------------------------------------------------
typedef struct tagDUNGEON_RECTANGLE {

	RECT rect; //���͈�

	RECT room; //�����͈�

} DUNEON_RECTANGLE;

//-----------------------------------------------------------------

//RECT�\���̂̌v�Z
#define RECTANGLE_WIDTH(r) ((r).right-(r).left) //RECT�̍������v�Z

#define RECTANGLE_HEIGHT(r) ((r).bottom-(r).top) //RECT�̕����v�Z

#pragma endregion

#pragma region �e�v�f�̌Ăяo���pID

#pragma region ����ID

const int UP_STAIRS = 1;

const int DOWN_STAIRS = 2;

const int TILE_GRASS = 3;

const int TILE_CAVE = 4;

#pragma endregion


#pragma region �ǂ�ID

const int WALL_GRASS = 1;
const int CORNER_WALL_GRASS = 2;

const int WALL_CAVE = 3;
const int CORNER_WALL_CAVE = 4;

#pragma endregion


#pragma endregion

#pragma region �Q�[���̐ݒ�Ɋւ���萔

const int MAX_SCORE = 1000000;

const int TILE_NUMBER = 2; //���̎��(�����A���A�Ȃ�) TODO: �Ƃ肠����

#pragma endregion

#pragma region ���̑�

const int KEY_NUMBER = 256; //�S�ẴL�[

const float HALF_WINDOW_X = WINDOW_X / 2;

const float HALF_WINDOW_Y = WINDOW_Y / 2;

typedef enum DIRECTION {
	DIRECTION_NONE, //��������
	DIRECTION_DOWN, //������(����)
	DIRECTION_UP, //�����(�w��)
	DIRECTION_LEFT, //������
	DIRECTION_RIGHT, //�E����
	DIRECTION_UPLEFT, //����
	DIRECTION_UPRIGHT, //�E��
	DIRECTION_DOWNLEFT, //����
	DIRECTION_DOWNRIGHT, //����
};

#pragma endregion
