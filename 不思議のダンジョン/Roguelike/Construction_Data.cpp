#include"Construction_Data.h"

Construction_Data::Construction_Data() {
	//	Construction_graphic.Load();
}

Construction_Data::~Construction_Data() {
}

//�J���t�@�C���̃p�X���w�肷��
void Construction_Data::Set_File_Pass(const std::string & open_file_pass) {
	file_pass = open_file_pass;
}

//�w�肳�ꂽ�p�X�ɂ���t�@�C�����J���ǂݍ���
bool Construction_Data::Open_File() {
	auto ifs = std::ifstream();
	ifs.open(file_pass);

	//�t�@�C�����J���Ȃ�������false
	if (!ifs.is_open()) {
		return false;
	}

	std::string line;
	std::getline(ifs, line); //csv�t�@�C���̎g��Ȃ��s��ǂݔ�΂�
	std::getline(ifs, line); //����
	ifs.clear(); //�ǂݔ�΂����f�[�^��j������

				 //���ꂼ��̗v�f��csv�f�[�^��ǂݍ���
	while (!std::getline(ifs, line).eof()) {
		SETTING_CONSTRUCTION_DATA data;
		auto values = Split::Split_(line, ","); //','�ŋ�؂��ēǂݍ���
		data.ID = std::stoi(values[0]); //�i���o�[
		data.name = values[1];
		data.width = std::stoi(values[2]); //�摜(����)	
		data.height = std::stoi(values[3]); //�摜(�c��)
											//load
		data.graphic_handle = std::stoi(values[4]); //�摜�t�@�C��

		set_construction_data.push_back(data); //�P�s���Ƃɔz��ɒǉ����Ă���
	}
}