#include "Actor.h"

// コンストラクタ
Actor::Actor() {

}

// デストラクタ
Actor::~Actor(){ 

}

// 座標を設定
void Actor::Set_Position(int set_x, int set_y) {
	x = set_x;
	y = set_y;
}

// 座標を取得
void Actor::Get_Position(int * set_x, int * set_y, eDIRECTION * set_direction) {
	if (set_x) {
		*set_x = x;
	}

	if (set_y) {
		*set_y = y;
	}
}

// HPを増減する
int Actor::Variation_HP(int value) {
	int old = hit_point;
	hit_point += value;

	if (Get_Max_HP() < hit_point) {
		hit_point = Get_Max_HP();
	}
	else if (hit_point < 0) {
		hit_point = 0;
	}

	// 効果値を返す
	return hit_point - old;
}

// HPの最大値を取得
int Actor::Get_Max_HP()
{
	int hp;

	//基本最大HPを代入
	hp = max_hit_point;

	// TODO: アイテムを装備していたら

	return hp;
}

// 素の攻撃力を取得
int Actor::Get_Attack()
{
	int atk;

	//基本攻撃力を代入
	atk = attack;

	// TODO: 武器を装備していたら
	// TODO: アイテムをを装備していたら
	return atk;
}

// 素の防御力を取得
int Actor::Get_Defence()
{
	int def;

	// 基本防御力を代入
	def = defence;

	// TODO: 盾を装備していたら
	// TODO: アイテムを装備していたら
	return def;
}

// 死亡判定
bool Actor::Is_Dead()
{
	if (hit_point <= 0) {
		hit_point = 0;

		return true;
	}

	return false;
}

void Actor::Turn_End() {

}
