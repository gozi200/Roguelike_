#pragma once

#include"DxLib.h"
#include"Define.h"
#include"Food_Graphic.h"
#include"Convenient_Function.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include<algorithm>

//床に持たせる情報を設定する
struct SETTING_FOOD_DATA {
	int ID;				//ナンバー
	std::string name;	//いる？

	int x;				//x軸座標
	int y;				//y軸座標
	int effect;			//効果値
	int add_capacity;	//最大値の増加
	int ask;			//売る時の金額
	int price;			//買う時の金額
	int damage;			//投げ当てたときののダメージ

	int width;			//画像の横幅
	int height;			//画像の縦幅
	int graphic_handle; //画像データを格納する
};

/*////////////////////////////////
床の画像を管理するクラス(階段も含む)
*/////////////////////////////////

class Food_Data {
	/*////////
	メンバ変数
	*/////////
public:
	Food_Graphic tile_graphic;

	std::string file_pass;

	std::vector<SETTING_FOOD_DATA> set_tile_data;

	/*////////
	メンバ関数
	*/////////
public:
	//コンストラクタ
	Food_Data();

	//デストラクタ
	~Food_Data();

	/*開くファイルのパスを指定
	　@param open_file_pass 開くファイルを指定
	*/
	void Set_File_Pass(const std::string & open_file_pass);

	//ファイルを開く
	bool Open_File();
};