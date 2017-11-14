#include"Tile_Data.h"

Tile_Data::Tile_Data() {
	tile_graphic.Load();

}

Tile_Data::~Tile_Data() {
}

//�J���t�@�C���̃p�X���w�肷��
void Tile_Data::Set_File_Pass(const std::string & open_file_pass) {
	file_pass = open_file_pass;
}

//�w�肳�ꂽ�p�X�ɂ���t�@�C�����J���A�ǂݍ��ށ@TODO: Load_File�Ƃ����H
bool Tile_Data::Open_File() {
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
	int count = 0;
	while (!std::getline(ifs, line).eof()) {
		SETTING_TILE_DATA data;
		auto values = Convenient_Function::Split(line, ","); //','�ŋ�؂��ēǂݍ���
		data.ID = std::stoi(values[0]); 
		data.name = values[1];

		data.width = std::stoi(values[2]); 
		data.height = std::stoi(values[3]);

		//load
		auto graphic_handle = LoadGraph(tile_graphic.tile_graphic[count++]);
		data.graphic_handle = graphic_handle;

		set_tile_data.push_back(data); //�P�s���Ƃɔz��ɒǉ����Ă���
	}
}