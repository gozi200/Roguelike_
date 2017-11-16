#pragma once

#include"DxLib.h"
#include"Item.h"
#include"Define.h"
#include"Convenient_Function.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>

/*////////////////////////////////////////////////////
プレイヤーのステータスをCSVファイルで管理するクラス(画像も)
*/////////////////////////////////////////////////////

struct PLAYER_STATUS_DATA {
	int ID;				  //ナンバー
	std::string name;	  
	int x;				  //x軸座標
	int y;				  //y軸座標

	int level;			  //レベル
	int hit_point;		  //体力
	int power;			  //ちから 素の攻撃力(ここに武器の攻撃力、力を計算)
	int attack;			  //レベルアップで上昇するボーナス
	int defence;		  //素の防御力(ここに防具の防御力、力を計算)
	int hunger_point;	  //おなかゲージ
	int noble_phantasm;	  //宝具を撃つためのポイント
	int experience_point; //経験値
	int activity;		  //１ターンに行動できる回数
	int turn_count;		  //経過ターンをカウント
	
	int money;			  //所持金

	Item items[MAX_STOCK_ITEM]; //持ち切れるアイテムの数

	int width;			  //画像の横幅
	int height;			  //画像の横幅
	int graphic_handle;   //画像データを格納
};

class Player_Data {
	std::string file_pass;

	PLAYER_STATUS_DATA player_data;

public:
	//コンストラクタ
	Player_Data(const std::string & open_filepass);

	//デストラクタ
	Player_Data() {};

};