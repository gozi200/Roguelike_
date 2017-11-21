#pragma once

/*---------------------------------
床の情報を管理するクラス(階段も含む)
----------------------------------*/

#include"DxLib.h"
#include"Define.h"
#include"Tile_Graphic.h"
#include"Convenient_Function.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include<algorithm>

//床に持たせる情報を設定する
struct SETTING_TILE_DATA {
	int ID;				//ナンバー
	std::string name;	//いる？
	//int x;				//x軸座標 いらない？
	//int y;				//y軸座標
	int width;			//画像の横幅
	int height;			//画像の縦幅
	int graphic_handle; //画像データを格納する
};

class Tile_Data {
/*---------
メンバ変数
----------*/
public:
	Tile_Graphic tile_graphic;

	std::string file_pass;

	std::vector<SETTING_TILE_DATA> set_tile_data;

	int loop_count;

/*---------
メンバ関数
----------*/
public:
	//コンストラクタ
	Tile_Data();

	//デストラクタ
	~Tile_Data();

	/*開くファイルのパスを指定
	　@param open_file_pass 開くファイルを指定
	*/
	void Set_File_Pass(const std::string & open_file_pass);

	//ファイルを開く
	bool Open_File();
};