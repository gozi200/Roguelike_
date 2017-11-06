#include"Construction_Data.h"

Construction_Data::Construction_Data() {
	//	Construction_graphic.Load();
}

Construction_Data::~Construction_Data() {}

//�J���t�@�C���̃p�X���w�肷��
void Construction_Data::Set_File_Pass(const std::string & open_file_pass) {
	file_pass = open_file_pass;
}

//�w�肳�ꂽ�p�X�ɂ���t�@�C�����J���A�ǂݍ��ށ@TODO: Load_File�Ƃ����H
bool Construction_Data::Open_File() {
	auto ifs = std::ifstream();
	ifs.open(file_pass);

	Convenient_Function* convenient_function = new Convenient_Function;

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
		auto values = convenient_function->Split(line, ","); //','�ŋ�؂��ēǂݍ���
		data.ID = std::stoi(values[0]); //�i���o�[
		data.name = values[1];
		data.width = std::stoi(values[2]); //�摜(����)	
		data.height = std::stoi(values[3]); //�摜(�c��)
											//load
		data.graphic_handle = std::stoi(values[4]); //�摜�t�@�C��

		Load_Graph();

		set_construction_data.push_back(data); //�P�s���Ƃɔz��ɒǉ����Ă���
	}
}

//�摜�t�@�C���ɉ摜�f�[�^�̂���p�X��ǂݍ��܂���
void Construction_Data::Load_Graph() {
	for (auto& data : set_construction_data) { //TODO: �ԍ��ɍ������摜������
											   //data.graphic_handle = LoadGraph(Construction_graphic.Construction_graphic[0]);
	}
}