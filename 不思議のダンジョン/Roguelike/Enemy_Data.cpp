#include "Enemy_Data.h"

Enemy_Data::Enemy_Data() {
	enemy_graphic.Load(); //画像データを読み込む

	loop_count = 0; //初期化
}

Enemy_Data::~Enemy_Data() {

}

void Enemy_Data::Set_File_Pass(const std::string & open_file_pass) {
	file_pass = open_file_pass;
}

bool Enemy_Data::Open_File() {
	auto ifs = std::ifstream();
	ifs.open(file_pass);

	//ファイルが開けなかったらfalse
	if (!ifs.is_open()) {
		return false;
	}

	std::string line;
	std::getline(ifs, line); //csvファイルの使わない行を読み飛ばす
	std::getline(ifs, line); //同上
	ifs.clear(); //読み飛ばしたデータを破棄する

	//それぞれの要素にcsvデータと画像データを読み込む
	while (std::getline(ifs, line)) { //Amended ループを抜けるとnameの値がおかしくなる。
		auto values = Split::Split_(line, ",");
		SETTING_ENEMY_DATA enemy_data;

		enemy_data.ID				= std::stoi(values[0]);  //ナンバー
		enemy_data.name				= const_cast <char*>(values[1].c_str());  //名前
															  
		enemy_data.level			= std::stoi(values[2]);  //レベル
		enemy_data.hit_point		= std::stoi(values[3]);  //ヒットポイント(0で死亡)
		enemy_data.max_hit_point	= std::stoi(values[4]);	 //ヒットポイントの最大値
		enemy_data.power			= std::stoi(values[5]);  //力これにレベルで変動する攻撃力、装備の攻撃力を加算していく
		enemy_data.attack			= std::stoi(values[6]);  //攻撃力(レベルに比例して上昇)
		enemy_data.defence			= std::stoi(values[7]);  //防御力(レベルに比例して上昇)
		enemy_data.activity			= std::stoi(values[8]);  //行動力(ここでは１ターンに行動できる数)
		enemy_data.turn_count		= std::stoi(values[9]);  //経過ターンをカウント
		enemy_data.experience_point = std::stoi(values[10]); //経験値(ここでは倒されたときにプレイヤー側に与える数値)
		enemy_data.first_floor		= std::stoi(values[11]); //出現開始階層
		enemy_data.last_floor		= std::stoi(values[12]); //出現終了階層
		enemy_data.agility			= std::stoi(values[13]); //敏捷性(ここでは回避率のこと)
		enemy_data.drop_item_ID		= std::stoi(values[14]); //ドロップするアイテム
														  
		enemy_data.width			= std::stoi(values[15]); //表示される幅
		enemy_data.height			= std::stoi(values[16]); //表示される高さ
		
		auto graphic_handle = LoadGraph("Picture/Actor/Enemy/Enemy_Test.png");
		enemy_data.graphic_handle = graphic_handle;
		
		set_enemy_data.push_back(enemy_data); //１行ごとに配列に追加していく
	}
}

