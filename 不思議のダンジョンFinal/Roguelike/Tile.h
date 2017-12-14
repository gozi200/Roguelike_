#pragma once

#include"Split.h"
#include"Define.h"
#include"Set_File.h"
#include"Map_Tile.h"
#include"Tile_Graphic.h"

#include<vector>
#include<string>
#include<fstream>
#include<memory>

/*----------------------
床に持たせる情報を設定する
-----------------------*/
struct TILE_DATA  : public MAP_TILE_TADA {
};

/*-------------
床の扱うクラス
--------------*/
class Tile : public Map_Tile{
private:
	std::shared_ptr<Tile_Graphic> tile_graphic;

	std::vector<TILE_DATA> tile_datas; //タイルの種類ごとに格納

public:
	// コンストラクタ
	Tile();

	//デストラクタ
	~Tile();

	/*引数のIDと同じIDの画像を、引数の座標へ描画する
	  @param x       横座標
	  @param y       縦座標
	  @param call_ID 呼び出しID
	*/
	void Render(int x, int y, int call_ID);
	
private:
	//csvで読み込んだ情報を格納していく
	void Set_Parametor();
};