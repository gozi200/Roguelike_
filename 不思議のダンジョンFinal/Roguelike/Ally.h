#pragma once

#include"Item.h"
#include"Actor.h"
#include"Random.h"

/*------------------------------
プレイヤーに持たせる情報を設定する
------------------------------*/
struct ALLY_DATA : public ACTOR_DATA {
	int power;              // 力(攻撃力に上乗せされる)
	int max_power;          // 力の最大値
	int noble_phantasm;     // 宝具を撃つためのポイント
	int max_noble_phantasm; // npの最大値
	int command_card;       // コマンドカード
	int arts_card;          // アーツカードの枚数
	int quick_card;         // クイックカードの枚数
	int budter_card;        // バスターカードの枚数
	int star;               // クリティカルスターの保持数
	int star_occur;         // スター発生率

	//Item items[MAX_STOCK_ITEM]; //アイテムの持ち切れる数
	//Item weapon;				//武器
	//Item shield;				//盾
	//Item accessorie;			//装飾品
};

/*-----------------------
PlayerとPartnerの親クラス
------------------------*/
class Ally : public Actor {
/*--------
メンバ変数
--------*/
protected:
	Random random;

	int power;              // 力(攻撃力に上乗せされる)
	int max_power;          // 力の最大値
	int noble_phantasm;     // 宝具を撃つためのポイント
	int command_card;       // コマンドカード
	int atrs_card;          // アーツカードの枚数
	int quick_card;         // クイックカードの枚数
	int buster_card;        // バスターカードの枚数
	int max_noble_phantasm; // npの最大値
	int star_occur;         // スター発生率

	//Item items[MAX_STOCK_ITEM]; //アイテムの持ち切れる数
	//Item weapon;				//武器
	//Item shield;				//盾
	//Item accessorie;			//装飾品

/*--------
メンバ関数
---------*/
public:
	// コンストラクタ
	Ally();

	// デストラクタ
	~Ally();

protected:
	// 力の最大値の取得
	virtual int Get_Max_Power();

	// NPの取得
	virtual int Get_Max_NP();

	// NPの増減
	virtual int Variation_NP(int vlue);

	// 力の増減
	virtual int Variation_Power(int vlue);

	// 経験値を得る
	virtual void Add_Experience_Point(int experience_point);

	// 現在の経験値量を取得
	virtual int Get_Experience_Point(int set_EXP);

	// 経験値からレベルを求める
	int Get_EXP_Level();

	// レベルを得る
	int Get_Level(int set_level);
};