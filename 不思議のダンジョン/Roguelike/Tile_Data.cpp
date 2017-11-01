#include"Tile_Data.h"

Tile_Data::Tile_Data() {
	tile_graphic.Load();
}

Tile_Data::~Tile_Data() {}

void Tile_Data::Set_File_Pass(const std::string & open_file_pass) {
	file_pass = open_file_pass;
}

bool Tile_Data::Open_File() {
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
		SETTING_TILE_DATA data;
		auto values = convenient_function->Split(line, ","); //','で区切って読み込む
		data.ID = std::stoi(values[0]); //ナンバー
		data.name = values[1];
		data.width = std::stoi(values[2]); //画像(横幅)	
		data.height = std::stoi(values[3]); //画像(縦幅)
		//load
		data.graphic_handle = std::stoi(values[4]); //画像ファイル
		
		Load_Graph();

		set_tile_data.push_back(data); //１行ごとに配列に追加していく
	}
}

//画像ファイルに画像データのあるパスを読み込ませる
void Tile_Data::Load_Graph() {
	for (auto& data : set_tile_data) { //TODO: 番号に合った画像を入れる
		data.graphic_handle = LoadGraph(tile_graphic.tile_graphic[0]);
	}
}