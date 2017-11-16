#pragma once

//----------------------------
//武器の情報を管理するクラス
//----------------------------

#include"DxLib.h"
#include"Define.h"
#include"Weapon_Graphic.h"
#include"Convenient_Function.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>
#include<algorithm>

//床に持たせる情報を設定する
struct SETTING_WEAPON_DATA {
	int ID;					 //ナンバー
	std::string name;		 //いる？
							 
	int x;					 //x軸座標
	int y;					 //y軸座標
	int ask;				 //売る時の金額
	int price;				 //買う時の金額
	int level;				 //武器のレベル
	int attack;				 //攻撃力
	int peculiar_seal;		 //元々ついている固有の印
	int slot;				 //印を入れるためのスロット
	int damage;				 //投げあてたときのダメージ
	int evolution_level;	 //進化に必要なレベル
	int reinforcement_value; //強化値

	int width;				 //画像の横幅
	int height;				 //画像の縦幅
	int SD_graphic_handle;			 //床落ち、投擲時の武器の画像
	int graphic_handle;		 //画像データを格納する
};

class Weapon_Data {
	/*////////
	メンバ変数
	*/////////
public:
	Weapon_Graphic weapon_graphic;

	std::string file_pass;

	std::vector<SETTING_WEAPON_DATA> set_weapon_data;

	/*////////
	メンバ関数
	*/////////
public:
	//コンストラクタ
	Weapon_Data();

	//デストラクタ
	~Weapon_Data();

	/*開くファイルのパスを指定
	　@param open_file_pass 開くファイルを指定
	 */
	void Set_File_Pass(const std::string & open_file_pass);

	//ファイルを開く
	bool Open_File();
};