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
void Actor::Get_Position(int* set_x, int* set_y, eDIRECTION* set_direction) {
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

	if (Get_Max_HP(0) < hit_point) {
		hit_point = Get_Max_HP(0);
	}
	else if (hit_point < 0) {
		hit_point = 0;
	}

	// ���ʒl��Ԃ�
	return hit_point - old;
}

// HP�̍ő�l���擾
int Actor::Get_Max_HP(int set_max_HP) {
	//��{�ő�HP����
	max_hit_point += set_max_HP;

	// TODO: �A�C�e���𑕔����Ă�����

	return max_hit_point;
}

// �f�̍U���͂��擾
int Actor::Get_Attack(int set_ATK) {
	//��{�U���͂���
	attack = set_ATK;

	// TODO: ����𑕔����Ă�����
	// TODO: �A�C�e�����𑕔����Ă�����
	return attack;
}

// �f�̖h��͂��擾
int Actor::Get_Defence(int set_DEF) {
	// ��{�h��͂���
	defence = set_DEF;

	// TODO: ���𑕔����Ă�����
	// TODO: �A�C�e���𑕔����Ă�����
	return defence;
}

//// �J�E���^�[����
//int Actor::Get_Loop_Counter(int set_counter)
//{
//	loop_counter += set_counter;
//
//	return loop_counter;
//}

// �^�[���J�E���g����
int Actor::Get_Turn_Count(int set_turn_count)
{
	turn_count += set_turn_count;

	return turn_count;
}

// ���S����
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
