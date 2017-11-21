#pragma once

#include<string>

struct Object_Status_Base {
	int ID;						//ナンバー
	std::string name;			//名前
	int x;						//横の座標
	int y;						//縦の座標
								
	int level;					//レベル
	int power;					//ちから (素の攻撃力。ここに武器の攻撃力、レベルで変動する攻撃力を計算)
	int attack;					//攻撃力
	int defence;				//防御力
	int hit_point;				//ヒットポイント(0で死亡)
	int activity;				//行動力(ここでは１ターンに行動できる数)
	int turn_count;				//経過ターンをカウント
	int experience_point;		//経験値(一定値ごとにレベルが上がる)
	Item items[MAX_STOCK_ITEM]; //持ち切れるアイテムの数
								
					  			
	int width;					//表示される幅
	int height;					//表示される高さ
	int graphic_handle;			//画像のハンドル
};