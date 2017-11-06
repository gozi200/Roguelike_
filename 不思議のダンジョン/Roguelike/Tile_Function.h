#pragma once

#include"Define.h"
#include"Tile_Data.h"

/*//////////////////////////
床に関係する関数を設定するクラス
*//////////////////////////

class Tile_Function {
public:
	Tile_Data Tile_data;

	int loop_count = 0; //ループ回数を数える

	//コンストラクタ
	Tile_Function();

	//デストラクタ
	~Tile_Function();

	/*床の画像を描画する
	　@param call_ID IDに合った画像を呼ぶ
	*/
	void Draw_Tile(int call_ID);

};