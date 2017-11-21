#pragma once

#include"Define.h"
#include"Wall_Data.h"

/*-------------------------
壁の実体?
-------------------------*/

class Wall {
public:
	/*----------
	メンバ変数
	----------*/
	Wall_Data wall_data;

	int loop_count = 0; //ループ回数を数える

	/*----------
	メンバ関数
	-----------*/

	//コンストラクタ
	Wall();

	//デストラクタ
	~Wall();

	/*床の画像を描画する
	@param call_ID IDに合った画像を呼ぶ
	@param x 描画する場所のx軸
	@param y 描画する場所のy軸
	*/
	void Render(int call_ID, int x, int y);

};