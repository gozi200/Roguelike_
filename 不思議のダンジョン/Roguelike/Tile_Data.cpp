#include"Tile_Data.h"

Tile_Data::Tile_Data() {
	tile_graphic.Load();
}

Tile_Data::~Tile_Data() {}

void Tile_Data::Set_File_Pass(const std::string & open_file_pass) {
	file_pass = open_file_pass;
}

bool Tile_Data::Open_File() {
	auto ifs = std::ifstream();
	ifs.open(file_pass);

	Convenient_Function* convenient_function = new Convenient_Function;

	if (!ifs.is_open()) {
		return false;
	}

	std::string line;
	std::getline(ifs, line); //csv�t�@�C���̎g��Ȃ��s��ǂݔ�΂�
	std::getline(ifs, line); //����

	ifs.clear();

	while (!std::getline(ifs, line).eof()) {
		SETTING_TILE_DATA data;
		auto values = convenient_function->Split(line, ","); //','�ŋ�؂��ēǂݍ���
		data.ID = std::stoi(values[0]); //�i���o�[
		data.name = values[1];
		data.width = std::stoi(values[2]); //�摜(����)	
		data.height = std::stoi(values[3]); //�摜(�c��)
		//load
		data.graphic_handle = std::stoi(values[4]); //�摜�t�@�C��
		
		Load_Graph();

		set_tile_data.push_back(data); //�P�s���Ƃɔz��ɒǉ����Ă���
	}
}

//�摜�t�@�C���ɉ摜�f�[�^�̂���p�X��ǂݍ��܂���
void Tile_Data::Load_Graph() {
	for (auto& data : set_tile_data) { //TODO: �ԍ��ɍ������摜������
		data.graphic_handle = LoadGraph(tile_graphic.tile_graphic[0]);
	}
}