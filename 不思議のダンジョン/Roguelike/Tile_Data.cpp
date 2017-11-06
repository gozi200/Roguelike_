#include"Tile_Data.h"

Tile_Data::Tile_Data() {
	Tile_graphic.Load();
}

Tile_Data::~Tile_Data() {}

//�J���t�@�C���̃p�X���w�肷��
void Tile_Data::Set_File_Pass(const std::string & open_file_pass) {
	file_pass = open_file_pass;
}

//�w�肳�ꂽ�p�X�ɂ���t�@�C�����J���A�ǂݍ��ށ@TODO: Load_File�Ƃ����H
bool Tile_Data::Open_File() {
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
	int i = 0;
	while (!std::getline(ifs, line).eof()) {
		SETTING_Tile_DATA data;
		auto values = convenient_function->Split(line, ","); //','�ŋ�؂��ēǂݍ���
		data.ID = std::stoi(values[0]); //�i���o�[
		data.name = values[1];
		data.width = std::stoi(values[2]); //�摜(����)	
		data.height = std::stoi(values[3]); //�摜(�c��)
		//load		
		auto hoge = LoadGraph(Tile_graphic.Tile_graphic[i++]);
		data.graphic_handle = hoge;
		//Load_Graph();

		set_Tile_data.push_back(data); //�P�s���Ƃɔz��ɒǉ����Ă���
	}
}

//�摜�t�@�C���ɉ摜�f�[�^�̂���p�X��ǂݍ��܂���
void Tile_Data::Load_Graph() {
	for (auto& data : set_Tile_data) { //TODO: �ԍ��ɍ������摜������
		data.graphic_handle = LoadGraph(Tile_graphic.Tile_graphic[0]);

		if (data.graphic_handle == -1) {
			OutputDebugString("���s");
		}
	}
}