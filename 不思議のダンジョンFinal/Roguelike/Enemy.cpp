#include "Enemy.h"

// コンストラクタ
Enemy::Enemy() {

}

// デストラクタ
Enemy::~Enemy() {

}

// 座標のセット
void Enemy::Set_Position(int x, int y) {

}

// 座標の取得
void Enemy::Get_Position(int * x, int * y, eDIRECTION * direction) {

}

// 体力の増減
int Enemy::Variation_HP(int value) {
	return 0;
}

// ターンの終了
void Enemy::Turn_End() {

}

//最大HPの取得
int Enemy::Get_Max_HP() {
	return 0;
}

// 攻撃力の取得
int Enemy::Get_Attack() {
	return 0;
}

// 防御力の取得
int Enemy::Get_Defence() {
	return 0;
}

// 回避率の取得
int Enemy::Get_Agility() {
	return 0;
}

// 死亡判定の取得
bool Enemy::Is_Dead() {
	return false;
}