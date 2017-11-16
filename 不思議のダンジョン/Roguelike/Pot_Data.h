#pragma once

#include"DxLib.h"
#include"Define.h"
#include"Pot_Graphic.h"
#include"Convenient_Function.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include<algorithm>

//床に持たせる情報を設定する
struct SETTING_POT_DATA {
	int ID;				//ナンバー
	std::string name;	//いる？

	int x;				//x軸座標
	int y;				//y軸座標
	int ask;			//売る時の金額
	int price;			//買う時の金額
	int damage;			//投げあてたときのダメージ

	int width;			//画像の横幅
	int height;			//画像の縦幅
	int graphic_handle; //画像データを格納する
};

/*////////////////////////////////
床の画像を管理するクラス(階段も含む)
*/////////////////////////////////

class Pot_Data {
	/*////////
	メンバ変数
	*/////////
public:
	Pot_Graphic tile_graphic;

	std::string file_pass;

	std::vector<SETTING_POT_DATA> set_tile_data;

	/*////////
	メンバ関数
	*/////////
public:
	//コンストラクタ
	Pot_Data();

	//デストラクタ
	~Pot_Data();

	/*開くファイルのパスを指定
	　@param open_file_pass 開くファイルを指定
	 */
	void Set_File_Pass(const std::string & open_file_pass);

	//ファイルを開く
	bool Open_File();
};