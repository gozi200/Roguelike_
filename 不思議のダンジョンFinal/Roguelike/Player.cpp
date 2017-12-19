#include "Player.h"

// �R���X�g���N�^
Player::Player() {
	//set = std::make_shared<Set_File>();
	//player_graphic  = std::make_shared<Player_Graphic>();
	////dungeon_manager = std::make_shared<Dungeon_Manager>();

	//spawn_point_x = 0;
	//spawn_point_y = 0;
	//loop_counter  = 0;

	//player_graphic->Load(); // �摜�f�[�^��ǂݍ���
}

Player::Player(std::shared_ptr<Make_Dungeon_Map> manager)
{
	set = std::make_shared<Set_File>();
	player_graphic = std::make_shared<Player_Graphic>();
	
	dungeon_manager = manager;

	x = 0;
	y = 0;
	loop_counter = 0;

	player_graphic->Load(); // �摜�f�[�^��ǂݍ���
}

// �f�X�g���N�^
Player::~Player() {
	
}

void Player::Set_Player_Position() {
	dungeon_manager->Random_Room_Point(
		random.Dungeon_Random(dungeon_manager->rectangle_count),
		&x,
		&y);
}

void Player::Set_Parametor() {
	Set_Player_Position();

	auto ifs = std::ifstream();
	ifs.open(set->Set_File_Pass(file_pass, "csv/Actor/Player/Player.csv")); // csv�t�@�C���̏ꏊ��^���Ăяo��

	std::string line;
	std::getline(ifs, line); // csv�t�@�C���̎g��Ȃ��s��ǂݔ�΂�
	std::getline(ifs, line); // ����
	std::getline(ifs, line);
	ifs.clear();             // �ǂݔ�΂����f�[�^��j������

	// ���ꂼ��̗v�f��CSV�f�[�^�Ɖ摜�f�[�^��ǂݍ���
	while (!std::getline(ifs, line).eof()) {
		PLAYER_DATA player_data;

		auto values = Split::Split_(line, ","); // ','�ŋ�؂��ēǂݍ���

		player_data.ID                  = std::stoi(values[0]);  // ID
		player_data.name                = values[1];             // ���O
		player_data.calss               = std::stoi(values[2]);  // �N���X
		player_data.saint_graph         = std::stoi(values[3]);  // �ė�
		player_data.level               = std::stoi(values[4]);  // ���x��
		player_data.hit_point           = std::stoi(values[5]);  // �̗�(�O�ɂȂ�Ǝ��S)
		player_data.max_hit_point       = std::stoi(values[6]);  // �ő�̗�
		player_data.power               = std::stoi(values[7]);  // ������(�U���͂ւ̃{�[�X)
		player_data.max_power           = std::stoi(values[8]);  // ������̍ő�l
		player_data.attack              = std::stoi(values[9]);  // �f�̍U����
		player_data.defence             = std::stoi(values[10]); // �f�̖h���
		player_data.hunger_point        = std::stoi(values[11]); // �͂�ւ�|�C���g
		player_data.activity            = std::stoi(values[12]); // �s����(�����ł͂P�^�[���ɍs���ł����)
		player_data.sukill              = std::stoi(values[13]); // �X�L��
		player_data.star_generater      = std::stoi(values[14]); // �X�^�[������
		player_data.keep_star           = std::stoi(values[15]); // �X�^�[�ێ���
		player_data.command_card        = std::stoi(values[16]); // �R�}���h�J�[�h����
		player_data.arts_card           = std::stoi(values[17]); // �A�[�c�J�[�h�̖���
		player_data.arts_attack_count   = std::stoi(values[18]); // �A�[�c�J�[�h��I�񂾎��̍U���̃q�b�g��
		player_data.quick_card          = std::stoi(values[19]); // �N�C�b�N�J�[�h�̖���
		player_data.quick_attack_count  = std::stoi(values[20]); // �N�C�b�N�J�[�h��I�񂾎��̍U���̃q�b�g��
		player_data.buster_card         = std::stoi(values[21]); // �o�X�^�[�J�[�h�̖���
		player_data.buster_attack_count = std::stoi(values[22]); // �o�X�^�[�J�[�h��I�񂾎��̍U���̃q�b�g��
		player_data.extra_attack        = std::stoi(values[23]); // �G�N�X�g���A�^�b�N
		player_data.noble_weapom        = std::stoi(values[24]); // ���
		player_data.noble_phantasm      = std::stoi(values[25]); // ���������߂̃|�C���g
		player_data.max_noble_phantasm  = std::stoi(values[26]); // ���������߂̃|�C���g�̍ő�l
		player_data.attack_rise_NP      = std::stoi(values[27]); // �U���ɂ���ē�����NP�̌���
		player_data.defence_rise_NP     = std::stoi(values[28]); // �h��(��_��)�ɂ���ē�����NP�̌���
		player_data.experience_point    = std::stoi(values[29]); // �l�������o���l
		player_data.turn_count          = std::stoi(values[30]); // �o�߂����^�[�����J�E���g
		player_data.width               = std::stoi(values[31]); // �摜�̕�
		player_data.height              = std::stoi(values[32]); // �摜�̍���

		// �摜�̃p�X���i�[
		auto graphic_handle = LoadGraph(player_graphic->graphics[loop_counter++]);
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

int Player::Get_Hunger_Percent() {
	return (hunger_point * 100) / FILL_HUNGER_POINT;
}

// �^�[���̏I��
void Player::Turn_End() {
	Get_Turn_Count(1);

	//TODO: ���݂̍ő�HP�ɔ�Ⴕ�ĉ񕜗ʂ��グ��B����͂T�^�[���ɂP��
	if (Get_Turn_Count(0) % 5 == 0) {
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

// ������ID�Ɠ���ID�̉摜���A�����̍��W�֕`�悷��
void Player::Render(int call_ID, int x, int y) {
	switch (call_ID) {
	// ���c����`��
	case OKITA:
		DrawExtendGraph(x,
						y,
						x + player_datas.at(call_ID).width,
						y + player_datas.at(call_ID).height,
						player_datas.at(call_ID).graphic_handle, TRUE);
		break;
	}
}
