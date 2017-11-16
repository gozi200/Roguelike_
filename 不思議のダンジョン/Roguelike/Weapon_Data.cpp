#include"Weapon_Data.h"

Weapon_Data::Weapon_Data() {
	weapon_graphic.Load();

}

Weapon_Data::~Weapon_Data() {
}

//�J���t�@�C���̃p�X���w�肷��
void Weapon_Data::Set_File_Pass(const std::string & open_file_pass) {
	file_pass = open_file_pass;
}

//�w�肳�ꂽ�p�X�ɂ���t�@�C�����J���A�ǂݍ��ށ@TODO: Load_File�Ƃ����H
bool Weapon_Data::Open_File() {
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
		SETTING_WEAPON_DATA data;
		auto values = Convenient_Function::Split(line, ","); //','�ŋ�؂��ēǂݍ���
		data.ID = std::stoi(values[0]);
		data.name = values[1];

		data.ask = std::stoi(values[2]);
		data.price = std::stoi(values[3]);
		data.level = std::stoi(values[4]);
		data.attack = std::stoi(values[5]);
		data.peculiar_seal = std::stoi(values[6]);
		data.slot = std::stoi(values[7]);
		data.damage = std::stoi(values[8]);
		data.evolution_level = std::stoi(values[9]);

		data.width = std::stoi(values[10]);
		data.height = std::stoi(values[11]);
		
		//load
		auto graphic_handle = LoadGraph(weapon_graphic.weapon_graphic[count++]);
		data.graphic_handle = graphic_handle;

		set_weapon_data.push_back(data); //�P�s���Ƃɔz��ɒǉ����Ă���
	}
}