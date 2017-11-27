#include "Wall_Data.h"

Wall_Data::Wall_Data() {
	wall_graphic.Load();

}

Wall_Data::~Wall_Data() {
}

void Wall_Data::Set_File_Pass(const std::string & open_file_path) {
	file_pass = open_file_path;
}

bool Wall_Data::Open_File() {
	auto ifs = std::ifstream();
	ifs.open(file_pass);


	if (!ifs.is_open()) {
		return false;
	}

	std::string line;
	std::getline(ifs, line); //csvファイルの使わない行を読み飛ばす
	std::getline(ifs, line); //同上

	ifs.clear();

	//それぞれの要素にcsvデータを読み込む
	int count = 0;
	while (!std::getline(ifs, line).eof()) {
		SETTING_WALL_DATA wall_data;
		auto values = Split::Split_(line, ","); //','で区切って読み込む
	
		wall_data.ID			 = std::stoi(values[0]); //ナンバー
		wall_data.name			 = values[1];			 //名前
		wall_data.width			 = std::stoi(values[2]); //画像(横幅)	
		wall_data.height		 = std::stoi(values[3]); //画像(縦幅)
		
		//load
		auto graphic_handle		 = LoadGraph(wall_graphic.wall_graphic[count++]);
		wall_data.graphic_handle = graphic_handle;

		set_wall_data.push_back(wall_data); //１行ごとに配列に追加していく
	}
}