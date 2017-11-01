#include "Wall_Data.h"

Wall_Data::Wall_Data() {
	wall_graphic.Load();
}

Wall_Data::~Wall_Data() {}

void Wall_Data::Set_File_Pass(const std::string & open_file_path) {
	file_pass = open_file_path;
}

bool Wall_Data::Open_File() {
	auto ifs = std::ifstream();
	ifs.open(file_pass);

	Convenient_Function* convenient_function = new Convenient_Function;

	if (!ifs.is_open()) {
		return false;
	}

	std::string line;
	std::getline(ifs, line); //csvファイルの使わない行を読み飛ばす
	std::getline(ifs, line); //同上

	ifs.clear();

	while (!std::getline(ifs, line).eof()) {
		SETTING_WALL_DATA data;
		auto values = convenient_function->Split(line, ","); //','で区切って読み込む
		data.ID = std::stoi(values[0]); //ナンバー
		data.name = values[1];
		data.width = std::stoi(values[2]); //画像(横幅)	
		data.height = std::stoi(values[3]); //画像(縦幅)
											//load
		data.graphic_handle = std::stoi(values[4]); //画像ファイル

		Load_Graph();

		set_wall_data.push_back(data); //１行ごとに配列に追加していく
	}
}

void Wall_Data::Load_Graph() {
	for (auto& data : set_wall_data) { //TODO: 番号に合った画像を入れる
		data.graphic_handle = LoadGraph(wall_graphic.wall_graphic[0]);
	}
}
