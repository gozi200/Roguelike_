#include "Enemy.h"

// コンストラクタ
Enemy::Enemy() {
	set = std::make_shared<Set_File>();
	enemy_graphic = std::make_shared<Enemy_Graphic>();

}

// デストラクタ
Enemy::~Enemy() {

}

void Enemy::Set_Parametor() {
	auto ifs = std::ifstream();
	ifs.open(set->Set_File_Pass(file_pass, "csv/Actor/Player/Player.csv")); // csvファイルの場所を与え呼び出す

	std::string line;
	std::getline(ifs, line); // csvファイルの使わない行を読み飛ばす
	std::getline(ifs, line); // 同上
	std::getline(ifs, line);
	ifs.clear();             // 読み飛ばしたデータを破棄する

							 // それぞれの要素にCSVデータと画像データを読み込む
	while (!std::getline(ifs, line).eof()) {
		ENEMY_DATA enemy_data;

		auto values = Split::Split_(line, ","); // ','で区切って読み込む
	
		enemy_data.ID               = std::stoi(values[0]);  // 
		enemy_data.name             = values[1];			 // 
		enemy_data.calss            = std::stoi(values[2]);	 // 
		enemy_data.evolition        = std::stoi(values[3]);	 // 
		enemy_data.level            = std::stoi(values[4]);	 // 
		enemy_data.hit_point        = std::stoi(values[5]);	 // 
		enemy_data.max_hit_point    = std::stoi(values[6]);	 // 
		enemy_data.attack           = std::stoi(values[7]);	 // 
		enemy_data.defence          = std::stoi(values[8]);	 // 
		enemy_data.activity         = std::stoi(values[9]);	 // 
		enemy_data.critical         = std::stoi(values[10]); // 
		enemy_data.experience_point = std::stoi(values[11]); // 
		enemy_data.AI_paturn        = std::stoi(values[12]); // 
		enemy_data.first_floor      = std::stoi(values[13]); // 
		enemy_data.last_floor       = std::stoi(values[14]); // 
		enemy_data.width            = std::stoi(values[15]); // 
		enemy_data.height           = std::stoi(values[16]); // 

	
	
	
	}
}

// ターンの終了
void Enemy::Turn_End() {
	Get_Turn_Count(1);

	if (Is_Dead()) {
		//TODO: アイテムを落とす
	}
}