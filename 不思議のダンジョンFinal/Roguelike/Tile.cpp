#include "Tile.h"

// �R���X�g���N�^
Tile::Tile() {
	set = std::make_shared<Set_File>();
	tile_graphic = std::make_shared<Tile_Graphic>();	

	tile_graphic->Load(); // �摜�f�[�^��ǂݍ���
	Set_Parametor();      // �p�����[�^�̃Z�b�g
}

// �f�X�g���N�^
Tile::~Tile() {
}

// csv�œǂݍ��񂾏����\���̂Ɋi�[���Ă���
void Tile::Set_Parametor() {
	auto ifs = std::ifstream();
	ifs.open(set->Set_File_Pass(file_pass, "csv/Stage/Tile/Tile.csv")); // csv�t�@�C���̏ꏊ��^���Ăяo��

	std::string line;
	std::getline(ifs, line); // csv�t�@�C���̎g��Ȃ��s��ǂݔ�΂�
	std::getline(ifs, line); // ����
	std::getline(ifs, line);
	ifs.clear();             // �ǂݔ�΂����f�[�^��j������

	loop_count = 0;

	// ���ꂼ��̗v�f��CSV�f�[�^�Ɖ摜�f�[�^��ǂݍ���
	while (!std::getline(ifs, line).eof()) { //�������C��
		TILE_DATA tile_data;

		auto values = Split::Split_(line, ","); // ','�ŋ�؂��ēǂݍ���

		tile_data.ID     = std::stoi(values[0]); // �i���o�[
		tile_data.name   = values[1];            // ���O
		tile_data.width  = std::stoi(values[2]); // �摜�̃T�C�Y(��)
		tile_data.height = std::stoi(values[3]); // �摜�̃T�C�Y(����)

		// �摜�̃p�X���i�[
		auto graphic_handle = LoadGraph(tile_graphic->graphics[loop_count++]);
		tile_data.graphic_handle = graphic_handle;

		tile_datas.push_back(tile_data); //�P�s���Ƃɔz��ɒǉ����Ă���
	}
}

//�@������ID�Ɠ���ID�̉摜���A�����̍��W�֕`�悷��
void Tile::Render(int call_ID, int x, int y) {
	switch(call_ID){
	//����K�i��`��
	case UP_STAIRS: //Define�萔�g�p
		DrawExtendGraph(x,
						y, 
						x + tile_datas.at(call_ID).width, 
						y + tile_datas.at(call_ID).height, 
						tile_datas.at(call_ID).graphic_handle, TRUE);
		break;

	//����K�i��`��
	case DOWN_STAIRS: //Define�萔�g�p
		DrawExtendGraph(x,
						y,
						x + tile_datas.at(call_ID).width,
						y + tile_datas.at(call_ID).height,
						tile_datas.at(call_ID).graphic_handle, TRUE);
		break;

	//�����̏���`��
	case TILE_GRASS: //Define�萔�g�p
		DrawExtendGraph(x,
						y,
						x + tile_datas.at(call_ID).width,
						y + tile_datas.at(call_ID).height,
						tile_datas.at(call_ID).graphic_handle, TRUE);
		break;

	//���A�̏���`�� 
	case TILE_CAVE: //Define�萔�g�p
		DrawExtendGraph(x,
						y,
						x + tile_datas.at(call_ID).width,
						y + tile_datas.at(call_ID).height,
						tile_datas.at(call_ID).graphic_handle, TRUE);
		break;
	}
}