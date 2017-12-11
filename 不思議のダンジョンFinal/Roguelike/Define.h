#pragma once

#include"DxLib.h"

/*----------------------
�萔�����肵�Ă����N���X
-----------------------*/

#pragma region ��ʃT�C�Y

const int WINDOW_X = 1170; //��ʃT�C�Y(��) 

const int WINDOW_Y = 720;  //��ʃT�C�Y(�c)

const float HALF_WINDOW_X = WINDOW_X / 2; // �^��

const float HALF_WINDOW_Y = WINDOW_Y / 2; // �^��

#pragma endregion

#pragma region �v�Z�Ɏg���萔

const double PI = 3.14159265358979323846; //�~����

#pragma endregion

#pragma region ID�̊Ǘ�

#pragma region �_���W�����̊e�v�f�̌Ăяo���pID

#pragma region ����ID

const int UP_STAIRS   = 0;

const int DOWN_STAIRS = 1;

const int TILE_GRASS  = 2;

const int TILE_CAVE   = 3;

#pragma endregion


#pragma region �ǂ�ID

const int WALL_GRASS        = 0;
const int CORNER_WALL_GRASS = 1;
const int WALL_CAVE         = 2;
const int CORNER_WALL_CAVE  = 3;

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

const int ACTOR_SIZE_X     = 90; //�L�����N�^�[�̃T�C�Y(��)
						   
const int ACTOR_SIZE_Y     = 90; //�L�����N�^�[�̃T�C�Y(�c)
						   
const int ALLY_NUMBER      = 2; //�����������ɏo���ł��鐔
						   
const int MAX_ACTOR        = 35; //Actor�������ɏo���ł��鐔
						   
const int ACTOR_MOVEMENT   = 5; //1�}�X���̈ړ��� �ЂƂ܂�
						   
const int COLLISION        = 20; //�L�����̑傫���@�ЂƂ܂�

const int MAX_ENEMY        = 500; //�G�l�~�[�̗� �ЂƂ܂�

const int MAX_STOCK_ITEM   = 30; //�����؂��A�C�e���̍ő�l

const int ENMY_DATA_NUMBER = 22; //�G�l�~�[�̎����Ă���X�e�[�^�X�̐� ���������̍ۂɎg�p

#pragma endregion

#pragma region �v���C���[�Ɋւ���萔

const int MAX_LEVEL = 25; //�ЂƂ܂�

const int MAX_EXP   = 800000; //�ЂƂ܂�

#pragma region ���x���A�b�v�ɕK�v�Ȍo���l��

const int EXP_DATA[MAX_LEVEL] = {
	5,		 //2���x���ɂȂ邽�߂ɕK�v�Ȍo���l��
	10,		 //3�ȉ�����
	20,		 //4
	40,		 //5
	80,		 //6
	160,	 //7
	320,	 //8
	640,	 //9
	1300,	 //10
	2600,	 //11
	5200,	 //12
	10000,	 //13
	20000,	 //14
	39000,	 //15
	70000,	 //16
	130000,	 //17
	250000,	 //18
	480000,	 //19
	900000,	 //20
	160000,	 //21
	250000,	 //22
	4600000, //23
	6700000, //24
	MAX_EXP, //25
};

#pragma endregion

#pragma endregion



#pragma region �ړ��Ɋւ���萔

const int CHARACTOR_DIRECTION = 8; //�L�����N�^�[�̌������� �㉺���E�{�΂߂̂W����

#pragma endregion


#pragma region �A�C�e���Ɋւ���萔

const int ITEM_MAX = 500; //�A�C�e���������ɏo���ł��鐔�@�ЂƂ܂�

#pragma endregion


#pragma region �_���W�����Ɋւ���萔

const int DUNGEON_WIDTH  = 25; //�_���W�����̉��}�X�̐� //�ŏI��50

const int DUNGEON_HEIGHT = 25; //�_���W�����̏c�}�X�̐�

const int MAX_RECTANGLE  = 10; //���̍ő�l

const int MIN_ROOM_SIZE  = 4; //�ŏ��̕����̃T�C�Y

const int TILE_SIZE      = 30; //�P�}�X�̑傫��

#pragma endregion


#pragma region �L�[���͂�萔�Ɋi�[����

const int PUSH_UP_KEY    = CheckHitKey(KEY_INPUT_UP);	 //���������
const int PUSH_RIGHT_KEY = CheckHitKey(KEY_INPUT_RIGHT); //�E��������
const int PUSH_DOWN_KEY  = CheckHitKey(KEY_INPUT_DOWN);  //����������
const int PUSH_LEFT_KEY  = CheckHitKey(KEY_INPUT_LEFT);  //����������

const int PUSH_G_KEY = CheckHitKey(KEY_INPUT_G); //�A�C�e�����E�� 
const int PUSH_E_KEY = CheckHitKey(KEY_INPUT_E); //�A�C�e���𑕔�����
const int PUSH_D_KEY = CheckHitKey(KEY_INPUT_D); //�A�C�e�����̂Ă�
const int PUSH_U_KEY = CheckHitKey(KEY_INPUT_U); //�A�C�e�����g��
const int PUSH_S_KEY = CheckHitKey(KEY_INPUT_S); //�K�i�ňړ�����

const int PUSH_0_KEY = CheckHitKey(KEY_INPUT_0); //�L�����Z���{�^��
const int PUSH_A_KEY = CheckHitKey(KEY_INPUT_A); //�������݂ăR�����g������

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

#pragma endregion

#pragma region �񋓌^

enum eITEM_TYPE {
	ITEM_TYPE_NONE = 0,		     //�Ȃ�
	ITEM_TYPE_USEITEM = (1 << 1),   //���Օi
	ITEM_TYPE_WEAPON = (1 << 2),    //����
	ITEM_TYPE_SHIELD = (1 << 3),    //�c
	ITEM_TYPE_ACCESSORIE = (1 << 4),//�����i
	ITEM_TYPE_UNIDENTIFIED = (1 << 5)// ���Ӓ�A�C�e���̂݁iCGame::messageItems �̈����ɂ̂ݎg�p�j

};

//�ړ������ƃL�����N�^�[�̌������֘A�t����
typedef enum eDIRECTION {
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

//�g�p�A�C�e���̃J�e�S���[
enum eUSE_ITEM_CATEGORY {
	HP_CURE, //HP�� 
	MP_CURE, //MP��
	HUNGER_CURE, //������
};

//�L�����N�^�[�̍s����A�N�V����
typedef enum eACTION {
	ACTION_MOVE,	  //�ړ�����
	ACTION_GET_ITEM,  //�A�C�e�����E��
	ACTION_EQIOP,	  //�A�C�e���𑕔�
	ACTION_DROP_ITEM, //�A�C�e�����̂Ă�
	ACTION_USE_ITEM,  //�A�C�e�����̂Ă�
	ACTION_PROVE,	  //�Ӓ肷��A�C�e����I��
	ACTION_GAMEOVER,  //�Q�[���I�[�o�[
	ACTION_STEP,	  //�K�i�ړ��m�F

	ACTION_MAX,		  //ACTION�̍ő�l
};

#pragma endregion

#pragma region ���b�Z�[�W�ɂ��Ă̒萔

//���b�Z�[�W�̎��
enum eMESTYPE
{
	MESTYPE_INFO					// ���
	, MESTYPE_ATTACK					// �_���[�W�n
	, MESTYPE_SELECT					// �I����
	, MESTYPE_NEGATIVE				// �l�K�e�B�u�ȏ��
};

// ���b�Z�[�W�o�b�t�@
typedef struct tagMESDATA
{
	eMESTYPE	type;
	char		*pLine;
}MESDATA;

#pragma endregion
