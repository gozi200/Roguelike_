#include"Pot_Data.h"

Pot_Data::Pot_Data() {
	tile_graphic.Load();

}

Pot_Data::~Pot_Data() {
}

//開くファイルのパスを指定する
void Pot_Data::Set_File_Pass(const std::string & open_file_pass) {
	file_pass = open_file_pass;
}

//指定されたパスにあるファイルを開き読み込む
bool Pot_Data::Open_File() {
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

				 //それぞれの要素にcsvデータを読み込む
	int count = 0;
	while (!std::getline(ifs, line).eof()) {
		SETTING_POT_DATA data;
		auto values = Split::Split_(line, ","); //','で区切って読み込む
		data.ID = std::stoi(values[0]);
		data.name = values[1];

		data.ask = std::stoi(values[2]);
		data.price = std::stoi(values[3]);
		data.damage = std::stoi(values[4]);

		data.width = std::stoi(values[5]);
		data.height = std::stoi(values[6]);
		//load
		auto graphic_handle = LoadGraph(tile_graphic.pot_graphic[count++]);
		data.graphic_handle = graphic_handle;

		set_tile_data.push_back(data); //１行ごとに配列に追加していく
	}
}