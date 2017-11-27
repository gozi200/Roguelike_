#include"Construction_Data.h"

Construction_Data::Construction_Data() {
	//	Construction_graphic.Load();
}

Construction_Data::~Construction_Data() {
}

//開くファイルのパスを指定する
void Construction_Data::Set_File_Pass(const std::string & open_file_pass) {
	file_pass = open_file_pass;
}

//指定されたパスにあるファイルを開き読み込む
bool Construction_Data::Open_File() {
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
	while (!std::getline(ifs, line).eof()) {
		SETTING_CONSTRUCTION_DATA data;
		auto values = Split::Split_(line, ","); //','で区切って読み込む
		data.ID = std::stoi(values[0]); //ナンバー
		data.name = values[1];
		data.width = std::stoi(values[2]); //画像(横幅)	
		data.height = std::stoi(values[3]); //画像(縦幅)
											//load
		data.graphic_handle = std::stoi(values[4]); //画像ファイル

		set_construction_data.push_back(data); //１行ごとに配列に追加していく
	}
}