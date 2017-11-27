#pragma once

#include"DxLib.h"
#include"Item.h"
#include"Define.h"
#include"Player_Graphic.h"
#include"Object_Status_Base.h"
#include"Split.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>

/*-----------------------------------------------------
プレイヤーのステータスをCSVファイルで管理するクラス(画像も)
-----------------------------------------------------*/

struct SETTING_PLAYER_DATA : Object_Status_Base{
	int hunger_point;	  //満腹度
	int noble_phantasm;	  //宝具を撃つためのポイント
	int money;			  //所持金
};

class Player_Data {
/*--------
メンバ変数
---------*/
public:
	Player_Graphic player_graphic;

	std::string file_pass;

	std::vector<SETTING_PLAYER_DATA> set_player_data;

	int loop_count;

/*--------
メンバ関数
---------*/
public:
	//コンストラクタ
	Player_Data();

	//デストラクタ
	~Player_Data();

	/*開くファイルのパスを指定
	　@param open_file_pass 開くファイルを指定
	 */
	void Set_File_Pass(const std::string & open_file_pass);

	//ファイルを開く
	bool Open_File();
};