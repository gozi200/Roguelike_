#pragma once

#include"Split.h"
#include"Define.h"
#include"Set_File.h"
#include"Wall_Graphic.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include<algorithm>

// 床に持たせる情報を設定する
struct WALL_DATA {
	int ID;             // ナンバー
	std::string name;   // 名前
	int width;          // 画像の横幅
	int height;         // 画像の縦幅
	int graphic_handle; // 画像データを格納する
};

/*-------------
床のを扱うクラス
--------------*/
class Wall {
private:
	Set_File* open;             // csvファイルを開くためのクラス
	Wall_Graphic* wall_graphic; // リソースからグラフィックデータを呼ぶクラス

	int ID;             // ナンバー
	std::string name;   // 名前
	int width;          // 画像の横幅
	int height;         // 画像の縦幅
	int graphic_handle; // 画像データを格納する

	int loop_count;     // ループ回数に応じて加算

	std::string file_pass;              //ファイルのパス
	std::vector <WALL_DATA> wall_datas; //タイルの種類ごとに格納

public:
	// コンストラクタ
	Wall();

	//デストラクタ
	~Wall();

	//csvで読み込んだ情報を格納していく
	void Set_Parametor();

public:
	/*引数のIDと同じIDの画像を、引数の座標へ描画する
	@param x       横座標
	@param y       縦座標
	@param call_ID 呼び出しID
	*/
	void Render(int x, int y, int call_ID);
};