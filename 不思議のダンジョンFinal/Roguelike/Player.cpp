#include "Player.h"

// �R���X�g���N�^
Player::Player() {
	set = std::make_shared<Set_File>();
	player_graphic = std::make_shared<Player_Graphic>();

	player_graphic->Load(); // �摜�f�[�^��ǂݍ���
	Set_Parametor();        // �p�����[�^�̃Z�b�g
}

// �f�X�g���N�^
Player::~Player() {
	
}

void Player::Set_Parametor() {
	auto ifs = std::ifstream();
	ifs.open(set->Set_File_Pass(file_pass, "csv/Actor/Player/Player.csv")); // csv�t�@�C���̏ꏊ��^���Ăяo��

	std::string line;
	std::getline(ifs, line); // csv�t�@�C���̎g��Ȃ��s��ǂݔ�΂�
	std::getline(ifs, line); // ����
	ifs.clear();             // �ǂݔ�΂����f�[�^��j������

	loop_count = 0;

	// ���ꂼ��̗v�f��CSV�f�[�^�Ɖ摜�f�[�^��ǂݍ���
	while (!std::getline(ifs, line).eof()) {
		PLAYER_DATA player_data;

		auto values = Split::Split_(line, ","); // ','�ŋ�؂��ēǂݍ���

		player_data.ID                 = std::stoi(values[0]);  // ID
		player_data.name               = values[1];			    // ���O
		player_data.level              = std::stoi(values[2]);  // ���x��
		player_data.attack             = std::stoi(values[3]);  // �U����
		player_data.defence            = std::stoi(values[4]);  // �h���
		player_data.hit_point          = std::stoi(values[5]);  // �̗�
		player_data.max_hit_point      = std::stoi(values[6]);  // �̗͂̍ő�l
		player_data.activity           = std::stoi(values[7]);  // �s����(1�^�[���ɓ������)
		player_data.experience_point   = std::stoi(values[8]);  // �o���l
		player_data.turn_count         = std::stoi(values[9]);  // �o�߃^�[��
		player_data.power              = std::stoi(values[10]); // ��(�U���͂ւ̃{�[�i�X)
		player_data.max_power          = std::stoi(values[11]); // �͂̍ő�l
		player_data.hunger_point       = std::stoi(values[12]); // �����x
		player_data.noble_phantasm     = std::stoi(values[13]); // ���������߂̃|�C���g
		player_data.max_noble_phantasm = std::stoi(values[14]); // ���������߂̃|�C���g�̍ő�l
		player_data.width              = std::stoi(values[15]); // �摜�̕�
		player_data.height             = std::stoi(values[16]); // �摜�̍���

		// �摜�̃p�X���i�[
		auto graphic_handle = LoadGraph(player_graphic->graphics[loop_count++]);
		player_data.graphic_handle = graphic_handle;

		player_datas.push_back(player_data); //�P�s���Ƃɔz��ɒǉ����Ă���
	}
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

//�@������ID�Ɠ���ID�̉摜���A�����̍��W�֕`�悷��
void Player::Render(int call_ID, int x, int y) {
	switch (call_ID) {
		//���c����`��
	case OKITA:
		DrawExtendGraph(x,
						y,
						x + player_datas.at(call_ID).width,
						y + player_datas.at(call_ID).height,
						player_datas.at(call_ID).graphic_handle, TRUE);
		break;
	}
}
