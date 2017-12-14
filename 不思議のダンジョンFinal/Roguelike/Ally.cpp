#include "Ally.h"

// �R���X�g���N�^
Ally::Ally() {

}

// �f�X�g���N�^
Ally::~Ally() {

}

int Ally::Get_Max_Power() {
	int max_pow;

	//�͂̊�{�l����
	max_pow = max_power;

	// TODO: �A�C�e���𑕔����Ă�����

	return max_pow;
}

int Ally::Get_Max_NP() {
	int np;

	//��{�ő�HP����
	np = max_noble_phantasm;

	// TODO: �A�C�e���𑕔����Ă�����

	return np;
}

int Ally::Variation_NP(int value) {
	int old = noble_phantasm;
	noble_phantasm += value;

	if (Get_Max_NP() < noble_phantasm) {
		noble_phantasm = Get_Max_NP();
	}
	else if (noble_phantasm < 0) {
		noble_phantasm = 0;
	}

	// ���ʒl��Ԃ�
	return noble_phantasm - old;
}

int Ally::Variation_Power(int value) {
	int old = power;
	power += value;

	if (Get_Max_Power() < power) {
		power = Get_Max_Power();
	}
	else if (power < 0) {
		power = 0;
	}

	// ���ʒl��Ԃ�
	return power - old;
}

int Ally::Get_EXP_Level() {
	int Lv;

	for (Lv = 0; Lv < MAX_LEVEL; Lv++)
	{
		if (EXP_DATA[Lv] > Get_Experience_Point(0))
			break;
	}

	return Lv + 1;
}

int Ally::Get_Level(int set_level)
{
	//���݂̃��x������
	level = set_level;

	return level;
}

void Ally::Add_Experience_Point(int add_EXP) {
	Get_Experience_Point(add_EXP);
	// �J���X�g����
	if (Get_Experience_Point(0) > MAX_EXP) {
		Get_Experience_Point(MAX_EXP);
	}

	// SEND

	// ���x���A�b�v�H
	if(EXP_DATA[level -1] <= Get_Experience_Point(0)) {
		int new_Lv = Get_EXP_Level();

		// ��x�ŉ������������Ă����v�Ȃ悤�ɁA�オ�������������s��
		for (; level < new_Lv; ++level) {
			int add_hp;
			int add_atk;
			int add_def;
			int add_agi;

			// SEND

			// MaxHP�������_��(3~5�j�ő��₷
			add_hp = random.Dungeon_Random(3) + 3;
			// �������A�ő�HP�𑝉�
			Get_Max_HP(add_hp);

			// �U���͂������_��(3~5)�ő��₷
			add_atk = random.Dungeon_Random(3) + 3;
			Get_Attack(add_atk);

			// �h��͂������_��(3~5)�ő��₷
			add_def = random.Dungeon_Random(3) + 3;
			Get_Defence(add_def);
		}
	}
}

int Ally::Get_Experience_Point(int set_EXP) {
	// �l���o���l����
	experience_point += set_EXP;

	return experience_point;
}