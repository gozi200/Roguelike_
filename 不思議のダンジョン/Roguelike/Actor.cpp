#include "Actor.h"

Actor::Actor() {
	is_dead_frag = false;
}

Actor::~Actor() {
}

void Actor::Set_Name(char* set_name) { //NEXT
	
}


void Actor::Set_Position(int set_x, int set_y) {

}

void Actor::Get_Position(int* set_x, int* set_y, DIRECTION* set_dir) {
	set_x = &actor_status.x;
	set_y = &actor_status.y;
}

bool Actor::Is_Dead() { //NEXT
	return false;
}

int Actor::reset() { //NEXT
	return 0;
}

int Actor::Attack(Actor * target) {
	int damage;
	int rnd; //‚±‚ê‰½H

	rnd = actor_status.Get_Attack() / 5 - target->actor_status.Get_Activity();
	
	if (rnd < 0) {
		rnd = 0;
	}

	damage = actor_status.Get_Attack() * 2 - target->actor_status.Get_Defence() + random.Dungeon_Random(rnd);

	//ƒ_ƒ[ƒW‚ª—^‚¦‚ç‚ê‚½
	if (damage > 0) {
		//‘ŞE‚ğŒ¸‚ç‚·
		target->actor_status.hit_point -= damage;

		//€–S‚µ‚½‚ç–³Œø‚É‚·‚é
		if (target->Is_Dead()) {
			target->is_dead_frag = false;
		}
	}

		else {
			damage = 0;
		}
	
	return damage;
}
