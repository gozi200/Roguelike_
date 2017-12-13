#include "Enemy.h"

// コンストラクタ
Enemy::Enemy() {

}

// デストラクタ
Enemy::~Enemy() {

}

// ターンの終了
void Enemy::Turn_End() {
	Get_Turn_Count(1);

	if (Is_Dead()) {
		//TODO: アイテムを落とす
	}
}