#include "Enemy_01.h"

Enemy_01::Enemy_01() {
	random = new Random;
}

Enemy_01::~Enemy_01() {

}

void Enemy_01::Move(Dungeon_Base * dungeon_base) {
	//���݂̈ʒu���擾
	Get_Position(&x, &y);

	switch (random->Dungeon_Random(CHARACTOR_DIRECTION)) { 
	case 0: 
		--y;
		direciton = DIRECTION_UP; 
		break;

	case 1:
		++y;
		direciton = DIRECTION_DOWN;
		break;

	case 2:
		--x;
		direciton = DIRECTION_LEFT;
		break;

	case 3:
		++x;
		direciton = DIRECTION_RIGHT;
		break;

	case 4:
		--x; --y;
		direciton = DIRECTION_UPLEFT;
		break;

	case 5:
		++x; --y;
		direciton = DIRECTION_UPRIGHT;
		break;

	case 6:
		--x; ++y;
		direciton = DIRECTION_DOWNLEFT;
		break;
	
	case 7:
		++x; ++y;
		direciton = DIRECTION_DOWNRIGHT;
		break;
	}

	//�V�������W�Ƀv���C���[������΍U�����s���A�G�l�~�[������Ή������Ȃ�
	Move_Action(dungeon_base, x, y);

	//�X�e�[�^�X�̎��Ԃ�i�߂�
	actor_status.Turn();
}
