#include "Tile.h"

// コンストラクタ
Tile::Tile() {
	set = std::make_shared<Set_File>();
	tile_graphic = std::make_shared<Tile_Graphic>();	

	tile_graphic->Load(); // 画像データを読み込む
	Set_Parametor();      // パラメータのセット
}

// デストラクタ
Tile::~Tile() {
}

// csvで読み込んだ情報を構造体に格納していく
void Tile::Set_Parametor() {
	auto ifs = std::ifstream();
	ifs.open(set->Set_File_Pass(file_pass, "csv/Stage/Tile/Tile.csv")); // csvファイルの場所を与え呼び出す

	std::string line;
	std::getline(ifs, line); // csvファイルの使わない行を読み飛ばす
	std::getline(ifs, line); // 同上
	std::getline(ifs, line);
	ifs.clear();             // 読み飛ばしたデータを破棄する

	loop_count = 0;

	// それぞれの要素にCSVデータと画像データを読み込む
	while (!std::getline(ifs, line).eof()) { //ここを修正
		TILE_DATA tile_data;

		auto values = Split::Split_(line, ","); // ','で区切って読み込む

		tile_data.ID     = std::stoi(values[0]); // ナンバー
		tile_data.name   = values[1];            // 名前
		tile_data.width  = std::stoi(values[2]); // 画像のサイズ(幅)
		tile_data.height = std::stoi(values[3]); // 画像のサイズ(高さ)

		// 画像のパスを格納
		auto graphic_handle = LoadGraph(tile_graphic->graphics[loop_count++]);
		tile_data.graphic_handle = graphic_handle;

		tile_datas.push_back(tile_data); //１行ごとに配列に追加していく
	}
}

//　引数のIDと同じIDの画像を、引数の座標へ描画する
void Tile::Render(int call_ID, int x, int y) {
	switch(call_ID){
	//昇り階段を描画
	case UP_STAIRS: //Define定数使用
		DrawExtendGraph(x,
						y, 
						x + tile_datas.at(call_ID).width, 
						y + tile_datas.at(call_ID).height, 
						tile_datas.at(call_ID).graphic_handle, TRUE);
		break;

	//下り階段を描画
	case DOWN_STAIRS: //Define定数使用
		DrawExtendGraph(x,
						y,
						x + tile_datas.at(call_ID).width,
						y + tile_datas.at(call_ID).height,
						tile_datas.at(call_ID).graphic_handle, TRUE);
		break;

	//草原の床を描画
	case TILE_GRASS: //Define定数使用
		DrawExtendGraph(x,
						y,
						x + tile_datas.at(call_ID).width,
						y + tile_datas.at(call_ID).height,
						tile_datas.at(call_ID).graphic_handle, TRUE);
		break;

	//洞窟の床を描画 
	case TILE_CAVE: //Define定数使用
		DrawExtendGraph(x,
						y,
						x + tile_datas.at(call_ID).width,
						y + tile_datas.at(call_ID).height,
						tile_datas.at(call_ID).graphic_handle, TRUE);
		break;
	}
}