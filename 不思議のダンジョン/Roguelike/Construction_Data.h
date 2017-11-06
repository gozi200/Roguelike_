#pragma once

#include"DxLib.h"
#include"Define.h"
#include"Construction_Graphic.h"
#include"Convenient_Function.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include<algorithm>

//床に持たせる情報を設定する
struct SETTING_CONSTRUCTION_DATA {
	int ID; //ナンバー　TODO: いる？
	std::string name;
	int x; //x軸座標
	int y; //y軸座標
	int width; //画像の横幅
	int height; //画像の縦幅
	int graphic_handle; //画像データを格納する
};

/*////////////////////////////
建物の画像を配列に格納するクラス
*/////////////////////////////

class Construction_Data {
public:
	//Construction_Graphic Construction_graphic;

	std::string file_pass;

	std::vector<SETTING_CONSTRUCTION_DATA> set_construction_data;

	/*////////
	メンバ関数
	*/////////
public:
	//コンストラクタ
	Construction_Data();

	//デストラクタ
	~Construction_Data();

	/*開くファイルのパスを指定
	　@param open_file_pass 開くファイルを指定
	 */
	void Set_File_Pass(const std::string & open_file_pass);

	//ファイルを開く
	bool Open_File();

	//画像を読み込む
	void Load_Graph();
};