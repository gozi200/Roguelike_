#include "Actor.h"

// �R���X�g���N�^
Actor::Actor() {

}

// �f�X�g���N�^
Actor::~Actor(){ 

}

// ���W��ݒ�
void Actor::Set_Position(int set_x, int set_y) {
	x = set_x;
	y = set_y;
}

// ���W���擾
void Actor::Get_Position(int * set_x, int * set_y, eDIRECTION * set_direction) {
	if (set_x) {
		*set_x = x;
	}

	if (set_y) {
		*set_y = y;
	}
}

// HP�𑝌�����
int Actor::Variation_HP(int value) {
	int old = hit_point;
	hit_point += value;

	if (Get_Max_HP() < hit_point) {
		hit_point = Get_Max_HP();
	}
	else if (hit_point < 0) {
		hit_point = 0;
	}

	// ���ʒl��Ԃ�
	return hit_point - old;
}

// HP�̍ő�l���擾
int Actor::Get_Max_HP()
{
	int hp;

	//��{�ő�HP����
	hp = max_hit_point;

	// TODO: �A�C�e���𑕔����Ă�����

	return hp;
}

// �f�̍U���͂��擾
int Actor::Get_Attack()
{
	int atk;

	//��{�U���͂���
	atk = attack;

	// TODO: ����𑕔����Ă�����
	// TODO: �A�C�e�����𑕔����Ă�����
	return atk;
}

// �f�̖h��͂��擾
int Actor::Get_Defence()
{
	int def;

	// ��{�h��͂���
	def = defence;

	// TODO: ���𑕔����Ă�����
	// TODO: �A�C�e���𑕔����Ă�����
	return def;
}

// ���S����
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
