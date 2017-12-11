#pragma once

#include"random.h"
#include"Define.h"
#include"Tile_Judge.h"

/*-----------------------------
ダンジョン生成のの元となるクラス
------------------------------*/

class Dungeon_Manager {
/*---------
メンバ変数
---------*/
public:
	Random* random;         // 乱数生成に使用 
	Tile_Judge* tile_judge; //その座標の地面は何なのかを判断
	DUNEON_RECTANGLE dungeon_rectangle[MAX_RECTANGLE]; //矩形
	 
	int width;           // ダンジョンの幅
	int height;          // ダンジョンの高さ

	int turn_count;      // 経過ターンを数える
	
	int rectangle_count; // １フロアの区画の数

/*---------
メンバ関数
----------*/
public:
	// コンストラクタ
	Dungeon_Manager();

	// デストラクタ
	virtual ~Dungeon_Manager();

	// ダンジョンのメモリの確保
	bool Alloc(int set_width, int set_height);

	// タイルの情報を取得
	Tile_Judge* Get_Tile(int x, int y);

	// 指定した部屋内の適当な座標を取得
	void Random_Room_Point(int index, int* px, int* py);

private:
	// 区画の数を取得
	int Get_Rectangle_Count();

	// 部屋の数を取得
	int Get_Room_Count();

	//指定位置の部屋インデックスを返す(道、壁なら-1を返す)
	int Get_Room_Index(int x, int y);

	//指定位置の矩形インデックスを返す(道、壁なら-1を返す)
	int Get_Rectangle_Index(int x, int y);
};