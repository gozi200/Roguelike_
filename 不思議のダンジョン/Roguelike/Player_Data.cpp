#include"Player_Data.h"

Player_Data::Player_Data() {
	player_graphic.Load(); //画像データを読み込む

	loop_count = 0; //初期化
}

Player_Data::~Player_Data() {

}

void Player_Data::Set_File_Pass(const std::string & open_file_pass) {
	file_pass = open_file_pass;
}

bool Player_Data::Open_File() {
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
	while (std::getline(ifs, line)) {
		auto values = Convenient_Function::Split(line, ",");
		SETTING_PLAYER_DATA data;

		data.ID				  = std::stoi(values[0]);  //ナンバー
		data.name			  = values[1];			   //名前
							  
		data.level			  = std::stoi(values[2]);  //レベル
		data.hit_point		  = std::stoi(values[3]);  //ヒットポイント(0で死亡)
		data.power			  = std::stoi(values[4]);  //ちから(素の攻撃力。ここに武器の攻撃力、レベルで変動する攻撃力を計算)
		data.attack			  = std::stoi(values[5]);  //攻撃力(レベルに比例して上昇)
		data.defence		  = std::stoi(values[6]);  //防御力(レベルに比例して上昇)
		data.hunger_point	  = std::stoi(values[7]);  //満腹度
		data.noble_phantasm	  = std::stoi(values[8]);  //宝具を撃つためのポイント
		data.experience_point = std::stoi(values[9]);  //経験値(一定値ごとにレベルが上がる)
		data.activity		  = std::stoi(values[10]); //行動力(ここでは１ターンに行動できる数)
		data.turn_count		  = std::stoi(values[11]); //経過ターンをカウント
 
		data.width			  = std::stoi(values[12]); //表示される幅
		data.height			  = std::stoi(values[13]); //表示される高さ
	
		auto graphic_handle	  = LoadGraph(player_graphic.player_graphic[loop_count++]);
		data.graphic_handle	  = graphic_handle;

		set_player_data.push_back(data); //１行ごとに配列に追加していく
	}
}
