#include "Enemy.h"

// コンストラクタ
Enemy::Enemy() {

}

// デストラクタ
Enemy::~Enemy() {

}

// ターンの終了
void Enemy::Turn_End() {
	++turn_count;

	if (Is_Dead()) {
		//TODO: アイテムを落とす
	}
}