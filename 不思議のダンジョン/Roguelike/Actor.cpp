#include "Actor.h"

Actor::Actor() {
	is_dead_frag = false;
}

Actor::~Actor() {
}

void Actor::Set_Name(char* set_name) {
	*set_name = *actor_status.name; //stringからcharへの変換
}

char* Actor::Get_Name()
{
	return nullptr;
}


void Actor::Set_Position(int set_x, int set_y) {

}

void Actor::Get_Position(int* set_x, int* set_y, eDIRECTION* set_dir) {
	*set_x = actor_status.x;
	*set_y = actor_status.y;
}

bool Actor::Is_Dead() {
	return false;
}

int Actor::Attack(Actor* target) {
	int damage;
	int rnd; //これ何？

	rnd = actor_status.Get_Attack() / 5 - target->actor_status.Get_Activity();

	if (rnd < 0) {
		rnd = 0;
	}

	damage = actor_status.Get_Attack() * 2 - target->actor_status.Get_Defence() + random.Dungeon_Random(rnd);

	//ダメージが与えられた
	if (damage > 0) {
		//退職を減らす
		target->actor_status.hit_point -= damage;

		//死亡したら無効にする
		if (target->actor_status.Is_Dead()) {
			target->is_dead_frag = true;
		}
	}

	else {
		damage = 0;
	}

	return damage;

}
