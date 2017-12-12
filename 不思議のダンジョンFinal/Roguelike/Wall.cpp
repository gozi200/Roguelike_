#include "Wall.h"

// �R���X�g���N�^
Wall::Wall() {
	set = std::make_shared<Set_File>();
	wall_graphic = std::make_shared<Wall_Graphic>();

	wall_graphic->Load(); // �摜�f�[�^��ǂݍ���
	Set_Parametor();      // �p�����[�^�̃Z�b�g
}

// �f�X�g���N�^
Wall::~Wall() {
}

// csv�œǂݍ��񂾏����\���̂Ɋi�[���Ă���
void Wall::Set_Parametor() {
	auto ifs = std::ifstream();
	ifs.open(set->Set_File_Pass(file_pass, "csv/Stage/Wall/Wall.csv")); // csv�t�@�C���̏ꏊ��^���Ăяo��

	std::string line;
	std::getline(ifs, line); // csv�t�@�C���̎g��Ȃ��s��ǂݔ�΂�
	std::getline(ifs, line); // ����
	ifs.clear();             // �ǂݔ�΂����f�[�^��j������

	loop_count = 0;

	// ���ꂼ��̗v�f��CSV�f�[�^�Ɖ摜�f�[�^��ǂݍ���
	while (!std::getline(ifs, line).eof()) { //�������C��
		WALL_DATA wall_data;

		auto values = Split::Split_(line, ","); // ','�ŋ�؂��ēǂݍ���

		wall_data.ID = std::stoi(values[0]); // �i���o�[
		wall_data.name = values[1];            // ���O
		wall_data.width = std::stoi(values[2]); // �摜�̃T�C�Y(��)
		wall_data.height = std::stoi(values[3]); // �摜�̃T�C�Y(����)

		// �摜�̃p�X���i�[
		auto graphic_handle = LoadGraph(wall_graphic->graphics[loop_count++]);
		wall_data.graphic_handle = graphic_handle;

		wall_datas.push_back(wall_data); //�P�s���Ƃɔz��ɒǉ����Ă���
	}
}

//�@������ID�Ɠ���ID�̉摜���A�����̍��W�֕`�悷��
void Wall::Render(int call_ID, int x, int y) {
	switch (call_ID) {
	//�����p�̕ǂ�`��
	case WALL_GRASS: //Define�萔�g�p
		DrawExtendGraph(x,
						y,
						x + wall_datas.at(call_ID).width,
						y + wall_datas.at(call_ID).height,
						wall_datas.at(call_ID).graphic_handle, TRUE);
		break;

	//�����p�̂��Ǖǂ�`��
	case CORNER_WALL_GRASS: //Define�萔�g�p
		DrawExtendGraph(x,
						y,
						x + wall_datas.at(call_ID).width,
						y + wall_datas.at(call_ID).height,
						wall_datas.at(call_ID).graphic_handle, TRUE);
		break;

	//���A�p�̕ǂ�`��
	case WALL_CAVE: //Define�萔�g�p
		DrawExtendGraph(x,
						y,
						x + wall_datas.at(call_ID).width,
						y + wall_datas.at(call_ID).height,
						wall_datas.at(call_ID).graphic_handle, TRUE);
		break;

	//���A�p�̂��Ǖǂ�`�� 
	case CORNER_WALL_CAVE: //Define�萔�g�p
		DrawExtendGraph(x,
						y,
						x + wall_datas.at(call_ID).width,
						y + wall_datas.at(call_ID).height,
						wall_datas.at(call_ID).graphic_handle, TRUE);
		break;
	}
}
