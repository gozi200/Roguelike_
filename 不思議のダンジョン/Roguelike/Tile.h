#pragma once

#include"Define.h"
#include"Tile_Data.h"

/*--------------
床の実体を所持？
---------------*/

class Tile {
public:
	Tile_Data tile_data;

	int loop_count; //ループ回数を数える

	//コンストラクタ
	Tile();

	//デストラクタ
	~Tile();

	/*床の画像を描画する
	　@param call_ID IDに合った画像を呼ぶ
	 @param x 描画する場所のx軸
	 @param y 描画する場所のy軸
	 */
	void Render(int call_ID, int x, int y);

};