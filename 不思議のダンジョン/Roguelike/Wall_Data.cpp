#include "Wall_Data.h"

Wall_Data::Wall_Data() {
	wall_graphic.Load();

}

Wall_Data::~Wall_Data() {
}

void Wall_Data::Set_File_Pass(const std::string & open_file_path) {
	file_pass = open_file_path;
}

bool Wall_Data::Open_File() {
	auto ifs = std::ifstream();
	ifs.open(file_pass);


	if (!ifs.is_open()) {
		return false;
	}

	std::string line;
	std::getline(ifs, line); //csv�t�@�C���̎g��Ȃ��s��ǂݔ�΂�
	std::getline(ifs, line); //����

	ifs.clear();

	//���ꂼ��̗v�f��csv�f�[�^��ǂݍ���
	int count = 0;
	while (!std::getline(ifs, line).eof()) {
		SETTING_WALL_DATA wall_data;
		auto values = Split::Split_(line, ","); //','�ŋ�؂��ēǂݍ���
	
		wall_data.ID			 = std::stoi(values[0]); //�i���o�[
		wall_data.name			 = values[1];			 //���O
		wall_data.width			 = std::stoi(values[2]); //�摜(����)	
		wall_data.height		 = std::stoi(values[3]); //�摜(�c��)
		
		//load
		auto graphic_handle		 = LoadGraph(wall_graphic.wall_graphic[count++]);
		wall_data.graphic_handle = graphic_handle;

		set_wall_data.push_back(wall_data); //�P�s���Ƃɔz��ɒǉ����Ă���
	}
}