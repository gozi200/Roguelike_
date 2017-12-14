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
void Actor::Get_Position(int* set_x, int* set_y, eDIRECTION* set_direction) {
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

	if (Get_Max_HP(0) < hit_point) {
		hit_point = Get_Max_HP(0);
	}
	else if (hit_point < 0) {
		hit_point = 0;
	}

	// 効果値を返す
	return hit_point - old;
}

// HPの最大値を取得
int Actor::Get_Max_HP(int set_max_HP) {
	//基本最大HPを代入
	max_hit_point += set_max_HP;

	// TODO: アイテムを装備していたら

	return max_hit_point;
}

// 素の攻撃力を取得
int Actor::Get_Attack(int set_ATK) {
	//基本攻撃力を代入
	attack = set_ATK;

	// TODO: 武器を装備していたら
	// TODO: アイテムをを装備していたら
	return attack;
}

// 素の防御力を取得
int Actor::Get_Defence(int set_DEF) {
	// 基本防御力を代入
	defence = set_DEF;

	// TODO: 盾を装備していたら
	// TODO: アイテムを装備していたら
	return defence;
}

//// カウンターを回す
//int Actor::Get_Loop_Counter(int set_counter)
//{
//	loop_counter += set_counter;
//
//	return loop_counter;
//}

// ターンカウントを回す
int Actor::Get_Turn_Count(int set_turn_count)
{
	turn_count += set_turn_count;

	return turn_count;
}

// 死亡判定
bool Actor::Is_Dead() {
	if (hit_point <= 0) {
		hit_point = 0;

		return true;
	}

	return false;
}

void Actor::Turn_End() {
	Get_Turn_Count(1);
}
