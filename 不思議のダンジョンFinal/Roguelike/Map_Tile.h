#pragma once

#include"Set_File.h"

#include<string>
#include<memory>

/*----------------------------
タイルに持たせる情報の基底構造体
----------------------------*/

struct MAP_TILE_TADA {
	int ID;			    //ID
	std::string name;   //名前
	int width;		    //画像の幅
	int height;         //画像の高さ
	int graphic_handle; //画像ハンドル
};

/*------------------------------
マップに配置するタイルの基底クラス
-------------------------------*/

class Map_Tile {
/*--------
メンバ変数
--------*/
protected:
	int ID;           //ID
	std::string name; //名前
	int width;		  //画像の幅
	int height;		  //画像の高さ

	int loop_count;

	std::string file_pass;
	std::shared_ptr<Set_File> set;

/*--------
メンバ関数
---------*/
	virtual void Set_Parametor() = 0;

	virtual void Render(int x, int y, int call_ID) = 0;
};