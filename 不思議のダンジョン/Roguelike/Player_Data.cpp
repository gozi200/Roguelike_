#include"Player_Data.h"

Player_Data::Player_Data() {
	player_graphic.Load(); //�摜�f�[�^��ǂݍ���

	loop_count = 0; //������
}

Player_Data::~Player_Data() {

}

void Player_Data::Set_File_Pass(const std::string & open_file_pass) {
	file_pass = open_file_pass;
}

bool Player_Data::Open_File() {
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

//���ꂼ��̗v�f��csv�f�[�^�Ɖ摜�f�[�^��ǂݍ���
	while (std::getline(ifs, line)) {
		auto values = Split::Split_(line, ",");
		SETTING_PLAYER_DATA player_data;

		player_data.ID				 = std::stoi(values[0]);  //�i���o�[
		player_data.name			 = values[1];			  //���O
							  
		player_data.level			 = std::stoi(values[2]);  //���x��
		player_data.hit_point		 = std::stoi(values[3]);  //�q�b�g�|�C���g(0�Ŏ��S)
		player_data.power			 = std::stoi(values[4]);  //������(�f�̍U���́B�����ɕ���̍U���́A���x���ŕϓ�����U���͂��v�Z)
		player_data.attack			 = std::stoi(values[5]);  //�U����(���x���ɔ�Ⴕ�ď㏸)
		player_data.defence			 = std::stoi(values[6]);  //�h���(���x���ɔ�Ⴕ�ď㏸)
		player_data.hunger_point	 = std::stoi(values[7]);  //�����x
		player_data.noble_phantasm	 = std::stoi(values[8]);  //���������߂̃|�C���g
		player_data.experience_point = std::stoi(values[9]);  //�o���l(���l���ƂɃ��x�����オ��)
		player_data.activity		 = std::stoi(values[10]); //�s����(�����ł͂P�^�[���ɍs���ł��鐔)
		player_data.turn_count		 = std::stoi(values[11]); //�o�߃^�[�����J�E���g
 		
		player_data.width			 = std::stoi(values[12]); //�\������镝
		player_data.height			 = std::stoi(values[13]); //�\������鍂��
	
		auto graphic_handle	  = LoadGraph(player_graphic.player_graphic[loop_count++]);
		player_data.graphic_handle	  = graphic_handle;

		set_player_data.push_back(player_data); //�P�s���Ƃɔz��ɒǉ����Ă���
	}
}
