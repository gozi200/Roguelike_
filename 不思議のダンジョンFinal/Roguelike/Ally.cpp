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

int Ally::Get_Level()
{
	return 0;
}

void Ally::Add_Experience_Point(int add_EXP) {
	experience_point += add_EXP;
	// �J���X�g����
	if (experience_point > MAX_EXP)
		experience_point = MAX_EXP;

	// SEND

	// ���x���A�b�v�H
	if (EXP_DATA[level - 1] <= experience_point)
	{
		int new_Lv = Get_Level();

		// ��x�ŉ������������Ă����v�Ȃ悤�ɁA�オ�������������s��
		for (; level < new_Lv; ++level)
		{
			int add_hp;
			int add_atk;
			int add_def;
			int add_agi;

			// SEND

			// MaxHP�������_��(3~5�j�ő��₷
			add_hp = random.Dungeon_Random(3) + 3;
			// �������A�ő�HP�𑝉�
			max_hit_point += add_hp;

			// �U���͂������_��(3~5)�ő��₷
			add_atk = random.Dungeon_Random(3) + 3;
			attack += add_atk;

			// �h��͂������_��(3~5)�ő��₷
			add_def = random.Dungeon_Random(3) + 3;
			defence += add_def;
		}
	}
}
