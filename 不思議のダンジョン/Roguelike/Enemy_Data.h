#pragma once

#include"DxLib.h"
#include"Item.h"
#include"Define.h"
#include"Enemy_Graphic.h"
#include"Split.h"

#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>

/*-----------------------------------------------------
エネミーのステータスをCSVファイルで管理するクラス(画像も)
-----------------------------------------------------*/

struct SETTING_ENEMY_DATA {
	int ID;						//ナンバー
	char* name;					//名前
	int x;						//横の座標
	int y;						//縦の座標

	int level;					//レベル
	int power;					//ちから (素の攻撃力。ここに武器の攻撃力、レベルで変動する攻撃力を計算)
	int attack;					//攻撃力
	int defence;				//防御力
	int agility;				//敏捷性(ここでは回避率)
	int hit_point;				//ヒットポイント(0で死亡)
	int activity;				//行動力(ここでは１ターンに行動できる数)
	int turn_count;				//経過ターンをカウント
	int experience_point;		//経験値(一定値ごとにレベルが上がる)

	int graphic_handle;			//画像のハンドル
	int paturn;					//行動パターン
	int evolution;				//進化形態
	int drop_item;				//死亡時に確率で落とすアイテム
	int first_floor;			//出現開始階層
	int last_floor;				//出現終了階層
	int drop_item_ID;			//ドロップするアイテムのID
	int width;					//表示される幅
	int height;					//表示される高さ
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