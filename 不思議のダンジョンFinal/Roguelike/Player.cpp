#include "Player.h"

// �R���X�g���N�^
Player::Player() {
	set = std::make_shared<Set_File>();
	player_graphic = std::make_shared<Player_Graphic>();

	player_graphic->Load(); // �摜�f�[�^��ǂݍ���
	Set_Parametor();      // �p�����[�^�̃Z�b�g
}

// �f�X�g���N�^
Player::~Player() {
	
}

// ���W�̃Z�b�g
void Player::Set_Position(int set_x, int set_y) {
	x = set_x;
	y = set_y;
}

// ���W�̎擾
void Player::Get_Position(int * set_x, int * set_y, eDIRECTION *set_direction) {
	if (set_x) {
		*set_x = x;
	}

	if (set_y) {
		*set_y = y;
	}
}

void Player::Set_Parametor() {

}

// HP�̑���
int Player::Variation_HP(int value) {
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

// NP�̑���
int Player::Variation_NP(int value) {
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

// ���Ȃ��Q�[�W�̑���
void Player::Variation_Hunger_Point(int value) {
	int old = hunger_point;
	hunger_point += value;

	//�i�K�ɕ������b�Z�[�W��\��
	if (hunger_point <= HUNGER_HAZARD) {
		// SEND: �󕠎��̃��b�Z
	}
	// TODO: �Q�ȏ�̌����ɂ͑Ή��ł��Ȃ��H
	else if (old < HUNGER_DANGER && hunger_point <= HUNGER_DANGER) {
		// SEND: �󕠃��b�Z
	}
}

// �^�[���̏I��
void Player::Turn_End() {
	++turn_count;

	//TODO: ���݂̍ő�HP�ɔ�Ⴕ�ĉ񕜗ʂ��グ��B����͂T�^�[���ɂP��
	if (turn_count % 5 == 0) {
		Variation_HP(1);
	}

	// �󕠎��̏���
	if (hunger_point <= 0) {
		Variation_HP(-1);

		// ���S�����ꍇ
		if (Is_Dead()) {
			// SEND: �쎀�̃��b�Z�[�W
		}
	}
	else {
		Variation_Hunger_Point(-1);
	}
}

// HP�̍ő�l���擾
int Player::Get_Max_HP() {
	int hp;

	//��{�ő�HP����
	hp = max_hit_point;

	// TODO: �A�C�e���𑕔����Ă�����
	
	return hp;
}

// NP�̍ő�l���擾
int Player::Get_Max_NP() {
	int np;

	//��{�ő�NP����
	np = max_noble_phantasm;

	// TODO: �A�C�e���𑕔����Ă�����

	return np;
}

// �U���͂̎擾
int Player::Get_Attack() {
	int atk;

	//��{�U���͂���
	atk = attack;

	// TODO: ����𑕔����Ă�����
	// TODO: �A�C�e�����𑕔����Ă�����
	return atk;
}

int Player::Get_Power() {
	int pow;

	//��{�̗͂̒l����
	pow = power;

	// TODO: �A�C�e���𑕔����Ă�����

	return pow;
}

// �h��͂̎擾
int Player::Get_Defence() {
	int def;

	// ��{�h��͂���
	def = defence;

	// TODO: ���𑕔����Ă�����
	// TODO: �A�C�e���𑕔����Ă�����
	return def;
}

// ��𗦂̎擾
int Player::Get_Agility() {
	int agi;
	
	// ��{��𗦂���
	agi = agility;

	return agi;
}

// ���S����̎擾
bool Player::Is_Dead() {
	if (hit_point <= 0) {
		hit_point = 0;

		return true;
	}

	return false;
}

// �o���l���𓾂�
void Player::Add_Experience_Point(int add_experience_point) {
	experience_point += add_experience_point;

	// �ő�l�ɒB������
	if (experience_point > MAX_EXP) {
		experience_point = MAX_EXP;
	}

	// SEND �o���l�𓾂�

	// ���x�����オ������
	if (EXP_DATA[level - 1] <= experience_point) {
		int new_level = Get_Level();

		//��x�ɂQ�ȏ゠�����Ă����v�Ȃ悤��
		for (; level < new_level; ++level) {
			int add_hp;
			int add_atk;
			int add_def;

			// SEND: ���x�����ɂȂ���

			// �̗͂̍ő�l�������_����(3~5)���₷
			add_hp = random.Dungeon_Random(3) + 3;
			// �ő�HP�𑝉�
			max_hit_point += add_hp;

			// �U���͂������_����(3~5)���₷
			add_atk = random.Dungeon_Random(3) + 3;
			// �U���͂𑝉�
			attack += add_atk;

			// �h��͂������_���ɑ��₷
			add_def = random.Dungeon_Random(3) + 3;
			defence = add_def;
		}
	}
}

// �A�C�e���̑���
void Player::Set_Equipment(Item * item) {

}

// �A�C�e���̎擾�B�J�o���������ς��Ȃ� true ��Ԃ�
bool Player::Get_Item(Item * item) {
	return false;
}

// �w�肵���t�B���^�Ŏw�肵���C���f�b�N�X�̃A�C�e�����擾
Item * Player::Get_Item_From_Index(eITEM_TYPE filter, int index) {
	return nullptr;
}

// �󕠗��� 0 ~ 100% �ŕԂ� 
int Player::Get_Hunger_Percent() {
	return hunger_point * 100 / FILL_HUNGER_POINT;
}

// �o���l���烌�x�������߂�
int Player::Get_Level() {
	int lv;

	for (lv = 0; lv < MAX_LEVEL; ++lv) {
		if (EXP_DATA[lv] > experience_point) {
			break;
		}
	}

	return lv + 1;
}
