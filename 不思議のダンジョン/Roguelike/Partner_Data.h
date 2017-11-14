#pragma once

#include"DxLib.h"
#include"Convenient_Function.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>

/*////////////////////////////////////////////////
相方のステータスをCSVファイルで管理するクラス(画像も)
*/////////////////////////////////////////////////

struct PARTNER_STATUS_DATA {
	int ID; //ナンバー
	std::string name; //いる？
	int x; //x軸座標
	int y; //y軸座標
	int width; //画像の横幅
	int height; //画像の横幅
	int level;
	int hit_point;
	int noble_phantasm; //宝具を撃つためのポイント
	int experience_point; //経験値
	int attack; //素の攻撃力(ここに武器の攻撃力、力を計算)
	int defence; //素の防御力(ここに防具の防御力、力を計算)
	int power; //力
	int activity; //１ターンに行動できる回数
	int graphic_handle; //画像データを格納
	char* graphic_handle_pass; //画像データのある場所
};

class Partner_Data {
		std::string file_pass;

		PARTNER_STATUS_DATA partner_data;

	public:
		//コンストラクタ
		Partner_Data(const std::string & open_filepass);

		//デストラクタ
		Partner_Data();

		void Load_Graph();
};