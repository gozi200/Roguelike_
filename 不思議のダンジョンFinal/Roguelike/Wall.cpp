#include "Wall.h"

// コンストラクタ
Wall::Wall() {
	set = std::make_shared<Set_File>();
	wall_graphic = std::make_shared<Wall_Graphic>();

	wall_graphic->Load(); // 画像データを読み込む
	Set_Parametor();      // パラメータのセット
}

// デストラクタ
Wall::~Wall() {
}

// csvで読み込んだ情報を構造体に格納していく
void Wall::Set_Parametor() {
	auto ifs = std::ifstream();
	ifs.open(set->Set_File_Pass(file_pass, "csv/Stage/Wall/Wall.csv")); // csvファイルの場所を与え呼び出す

	std::string line;
	std::getline(ifs, line); // csvファイルの使わない行を読み飛ばす
	std::getline(ifs, line); // 同上
	ifs.clear();             // 読み飛ばしたデータを破棄する

	loop_count = 0;

	// それぞれの要素にCSVデータと画像データを読み込む
	while (!std::getline(ifs, line).eof()) { //ここを修正
		WALL_DATA wall_data;

		auto values = Split::Split_(line, ","); // ','で区切って読み込む

		wall_data.ID = std::stoi(values[0]); // ナンバー
		wall_data.name = values[1];            // 名前
		wall_data.width = std::stoi(values[2]); // 画像のサイズ(幅)
		wall_data.height = std::stoi(values[3]); // 画像のサイズ(高さ)

		// 画像のパスを格納
		auto graphic_handle = LoadGraph(wall_graphic->graphics[loop_count++]);
		wall_data.graphic_handle = graphic_handle;

		wall_datas.push_back(wall_data); //１行ごとに配列に追加していく
	}
}

//　引数のIDと同じIDの画像を、引数の座標へ描画する
void Wall::Render(int call_ID, int x, int y) {
	switch (call_ID) {
	//草原用の壁を描画
	case WALL_GRASS: //Define定数使用
		DrawExtendGraph(x,
						y,
						x + wall_datas.at(call_ID).width,
						y + wall_datas.at(call_ID).height,
						wall_datas.at(call_ID).graphic_handle, TRUE);
		break;

	//草原用のかど壁を描画
	case CORNER_WALL_GRASS: //Define定数使用
		DrawExtendGraph(x,
						y,
						x + wall_datas.at(call_ID).width,
						y + wall_datas.at(call_ID).height,
						wall_datas.at(call_ID).graphic_handle, TRUE);
		break;

	//洞窟用の壁を描画
	case WALL_CAVE: //Define定数使用
		DrawExtendGraph(x,
						y,
						x + wall_datas.at(call_ID).width,
						y + wall_datas.at(call_ID).height,
						wall_datas.at(call_ID).graphic_handle, TRUE);
		break;

	//洞窟用のかど壁を描画 
	case CORNER_WALL_CAVE: //Define定数使用
		DrawExtendGraph(x,
						y,
						x + wall_datas.at(call_ID).width,
						y + wall_datas.at(call_ID).height,
						wall_datas.at(call_ID).graphic_handle, TRUE);
		break;
	}
}
