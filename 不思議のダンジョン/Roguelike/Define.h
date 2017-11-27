#pragma once

#include"DxLib.h"

/*----------------------
�萔�����肵�Ă����N���X
-----------------------*/

#pragma region ��ʃT�C�Y

const int WINDOW_X = 1170; //��ʃT�C�Y(��) 

const int WINDOW_Y = 720; //��ʃT�C�Y(�c)

#pragma endregion

#pragma region �v�Z�Ɏg���萔

const double PI = 3.14159265358979323846; //�~����

#pragma endregion

#pragma region ID�̊Ǘ�

#pragma region �_���W�����̊e�v�f�̌Ăяo���pID

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


#pragma region �A�N�^�[�̊e�v�f�̌Ăяo��ID

#pragma region �v���C���[��ID

const int ARTRIA = 1;

#pragma endregion


#pragma region �G�l�~�[��ID

const int TEST_1 = 1;

#pragma endregion

#pragma endregion


#pragma region �A�C�e���̊e�v�f�̌Ăяo��ID



#pragma endregion

#pragma endregion

#pragma region �A�N�^�[�Ɋւ���萔

const int ACTOR_SIZE_X = 90; //�L�����N�^�[�̃T�C�Y(��)

const int ACTOR_SIZE_Y = 90; //�L�����N�^�[�̃T�C�Y(�c)

const int ENERGY = 1; //�P�^�[���ɍs���ł��鐔

const int ALLY_NUMBER = 2; //�����������ɏo���ł��鐔

const int MAX_ACTOR = 35; //Actor�������ɏo���ł��鐔

const int ACTOR_MOVEMENT = 5; //1�}�X���̈ړ��� �ЂƂ܂�

const int COLLISION = 20; //�����Ȃ�΃L�����̑傫���@�ЂƂ܂�

const int MAX_ENEMY = 500; //�G�l�~�[�̗� �ЂƂ܂�

const int MAX_STOCK_ITEM = 30; //�����؂��A�C�e���̍ő�l

#pragma endregion


#pragma region �ړ��Ɋւ���萔

const int CHARACTOR_DIRECTION = 8; //�L�����N�^�[�̌������� �㉺���E�{�΂߂̂W����




#pragma endregion


#pragma region �A�C�e���Ɋւ���萔

const int ITEM_MAX = 500; //�A�C�e���������ɏo���ł��鐔�@�ЂƂ܂�

#pragma endregion


#pragma region �_���W�����Ɋւ���萔

const int DUNGEON_WIDTH = 25; //�_���W�����̉��}�X�̐� //�ŏI��50

const int DUNGEON_HEIGHT = 25; //�_���W�����̏c�}�X�̐�

const int RECTANGLE = 50; //�ЂƂ܂��̒l ��`�A�����` �g���ĂȂ�

const int MAX_RECTANGLE = 10; //���̍ő�l

const int MIN_ROOM_SIZE = 4; //�ŏ��̕����̃T�C�Y

const int TILE_SIZE = 30; //�P�}�X�̑傫��

#pragma endregion


#pragma region �L�[���͂�萔�Ɋi�[����

const int UP = CheckHitKey(KEY_INPUT_UP);		//���������
const int RIGHT = CheckHitKey(KEY_INPUT_RIGHT); //�E��������
const int DOWN = CheckHitKey(KEY_INPUT_DOWN);   //����������
const int LEFT = CheckHitKey(KEY_INPUT_LEFT);   //����������

const int GET_ITEM  = CheckHitKey(KEY_INPUT_G); //�A�C�e�����E�� 
const int EQIP_ITEM = CheckHitKey(KEY_INPUT_E); //�A�C�e���𑕔�����
const int DROP_ITEM = CheckHitKey(KEY_INPUT_D);	//�A�C�e�����̂Ă�
const int USE_ITEM  = CheckHitKey(KEY_INPUT_U);	//�A�C�e�����g��
const int STEP      = CheckHitKey(KEY_INPUT_S);	//�K�i�ňړ�����

#pragma endregion


#pragma region ���֘A�̒�`

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


#pragma region �Q�[���̐ݒ�Ɋւ���萔

const int MAX_SCORE = 1000000;

const int TILE_NUMBER = 2; //���̎��(�����A���A�Ȃ�)

#pragma endregion


#pragma region ���̑�

const int KEY_NUMBER = 256; //�S�ẴL�[

const float HALF_WINDOW_X = WINDOW_X / 2;

const float HALF_WINDOW_Y = WINDOW_Y / 2;

#pragma endregion

#pragma region �񋓌^

//�ړ������ƃL�����N�^�[�̌������֘A�t����
typedef enum DIRECTION {
	DIRECTION_NONE,      //��������
	DIRECTION_DOWN,      //������(����)
	DIRECTION_UP,        //�����(�w��)
	DIRECTION_LEFT,      //������
	DIRECTION_RIGHT,     //�E����
	DIRECTION_UPLEFT,    //����
	DIRECTION_UPRIGHT,   //�E��
	DIRECTION_DOWNLEFT,	 //����
	DIRECTION_DOWNRIGHT, //����
};

typedef enum ACTION {
	ACTION_MOVE, //�ړ�����
	ACTION_GET_ITEM, //�A�C�e�����E��
	ACTION_EQIOP, //�A�C�e���𑕔�
	ACTION_DROP_ITEM, //�A�C�e�����̂Ă�
	ACTION_USE_ITEM, //�A�C�e�����̂Ă�
	ACTION_PROVE, //�Ӓ肷��A�C�e����I��
	ACTION_GAMEOVER, //�Q�[���I�[�o�[
	ACTION_STEP, //�K�i�ړ��m�F

	ACTION_MAX, //ACTION�̍ő�l
};

#pragma endregion