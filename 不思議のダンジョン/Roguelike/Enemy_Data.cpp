#include "Enemy_Data.h"

Enemy_Data::Enemy_Data() {
	enemy_graphic.Load(); //�摜�f�[�^��ǂݍ���

	loop_count = 0; //������
}

Enemy_Data::~Enemy_Data() {

}

void Enemy_Data::Set_File_Pass(const std::string & open_file_pass) {
	file_pass = open_file_pass;
}

bool Enemy_Data::Open_File() {
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
	while (std::getline(ifs, line)) { //Amended ���[�v�𔲂����name�̒l�����������Ȃ�B
		auto values = Split::Split_(line, ",");
		SETTING_ENEMY_DATA enemy_data;

		enemy_data.ID				= std::stoi(values[0]);  //�i���o�[
		enemy_data.name				= const_cast <char*>(values[1].c_str());  //���O
															  
		enemy_data.level			= std::stoi(values[2]);  //���x��
		enemy_data.hit_point		= std::stoi(values[3]);  //�q�b�g�|�C���g(0�Ŏ��S)
		enemy_data.max_hit_point	= std::stoi(values[4]);	 //�q�b�g�|�C���g�̍ő�l
		enemy_data.power			= std::stoi(values[5]);  //�͂���Ƀ��x���ŕϓ�����U���́A�����̍U���͂����Z���Ă���
		enemy_data.attack			= std::stoi(values[6]);  //�U����(���x���ɔ�Ⴕ�ď㏸)
		enemy_data.defence			= std::stoi(values[7]);  //�h���(���x���ɔ�Ⴕ�ď㏸)
		enemy_data.activity			= std::stoi(values[8]);  //�s����(�����ł͂P�^�[���ɍs���ł��鐔)
		enemy_data.turn_count		= std::stoi(values[9]);  //�o�߃^�[�����J�E���g
		enemy_data.experience_point = std::stoi(values[10]); //�o���l(�����ł͓|���ꂽ�Ƃ��Ƀv���C���[���ɗ^���鐔�l)
		enemy_data.first_floor		= std::stoi(values[11]); //�o���J�n�K�w
		enemy_data.last_floor		= std::stoi(values[12]); //�o���I���K�w
		enemy_data.agility			= std::stoi(values[13]); //�q����(�����ł͉�𗦂̂���)
		enemy_data.drop_item_ID		= std::stoi(values[14]); //�h���b�v����A�C�e��
														  
		enemy_data.width			= std::stoi(values[15]); //�\������镝
		enemy_data.height			= std::stoi(values[16]); //�\������鍂��
		
		auto graphic_handle = LoadGraph("Picture/Actor/Enemy/Enemy_Test.png");
		enemy_data.graphic_handle = graphic_handle;
		
		set_enemy_data.push_back(enemy_data); //�P�s���Ƃɔz��ɒǉ����Ă���
	}
}

