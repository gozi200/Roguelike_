#pragma once

#include"Define.h"
#include"Wall_Data.h"

/*//////////////////////////
壁に関する関数を設定するクラス
*//////////////////////////

class Wall_Function {
public:
	Wall_Data wall_data;

	int loop_count = 0; //ループ回数を数える

						//コンストラクタ
	Wall_Function();

	//デストラクタ
	~Wall_Function();

	/*床の画像を描画する
	 @param call_ID IDに合った画像を呼ぶ
	 @param x 描画する場所のx軸
	 @param y 描画する場所のy軸
	 */
	void Draw_Wall(int call_ID, int x, int y);

};