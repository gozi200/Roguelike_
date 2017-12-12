#pragma once

#include"Split.h"
#include"Define.h"
#include"Map_Tile.h"
#include"Wall_Graphic.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include<memory>

/*-----------------------
壁に持たせる情報を設定する
-----------------------*/
struct WALL_DATA : public MAP_TILE_TADA {

};

/*-------------
床のを扱うクラス
--------------*/
class Wall : public Map_Tile {
private:
	std::vector <WALL_DATA> wall_datas; //タイルの種類ごとに格納
	std::shared_ptr<Wall_Graphic> wall_graphic; // リソースからグラフィックデータを呼ぶクラス

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