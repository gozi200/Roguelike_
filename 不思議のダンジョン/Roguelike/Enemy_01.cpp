#include "Enemy_01.h"

Enemy_01::Enemy_01() {
	random = new Random;
}

Enemy_01::~Enemy_01() {

}

void Enemy_01::Move(Dungeon_Base * dungeon_base) {
	//現在の位置を取得
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

	//新しい座標にプレイヤーがいれば攻撃を行い、エネミーがいれば何もしない
	Move_Action(dungeon_base, x, y);

	//ステータスの時間を進める
	actor_status.Turn();
}
