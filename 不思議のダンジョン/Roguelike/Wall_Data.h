#pragma once

#include"DxLib.h"
#include"Define.h"
#include"Wall_Graphic.h"
#include"Split.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include<algorithm>

/*/////////////////////
壁の画像を管理するクラス
*//////////////////////

struct SETTING_WALL_DATA {
	int ID;				//ナンバー
	std::string name;	//名前
	int x;				//x軸座標
	int y;				//y軸座標
	int width;			//画像の横幅
	int height;			//画像の縦幅
	int graphic_handle; //画像データを格納する
};

class Wall_Data {
/*////////
メンバ変数
*/////////
public:
	Wall_Graphic wall_graphic;

	std::string file_pass;

	std::vector<SETTING_WALL_DATA> set_wall_data;

/*////////
メンバ関数
*/////////
public:
	//コンストラクタ
	Wall_Data();

	//デストラクタ
	~Wall_Data();

	void Set_File_Pass(const std::string & open_file_path);

	bool Open_File();

	void Load_Graph();
};