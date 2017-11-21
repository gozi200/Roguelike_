#pragma once

#include"DxLib.h"
#include"Item.h"
#include"Define.h"
#include"Enemy_Graphic.h"
#include"Object_Status_Base.h"
#include"Convenient_Function.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>

/*-----------------------------------------------------
エネミーのステータスをCSVファイルで管理するクラス(画像も)
-----------------------------------------------------*/

struct SETTING_ENEMY_DATA : Object_Status_Base {
	int paturn;			  //行動パターン
	int evolution;		  //進化形態
	int drop_item;		  //死亡時に確率で落とすアイテム
	int experience_point; //経験値(ここでは倒されたときにプレイヤー側に与える数値)
};

class Enemy_Data {
/*--------
メンバ変数
---------*/
public:
	Enemy_Graphic enemy_graphic;

	std::string file_pass;

	std::vector<SETTING_ENEMY_DATA> set_enemy_data;

	int loop_count;

	/*--------
	メンバ関数
	---------*/
public:
	//コンストラクタ
	Enemy_Data();

	//デストラクタ
	~Enemy_Data();

	/*開くファイルのパスを指定
	　@param open_file_pass 開くファイルを指定
	 */
	void Set_File_Pass(const std::string & open_file_pass);

	//ファイルを開く
	bool Open_File();
};