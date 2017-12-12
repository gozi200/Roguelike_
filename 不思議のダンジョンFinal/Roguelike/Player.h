#pragma once

#include"Item.h"
#include"Actor.h"
#include"Split.h"
#include"Random.h"
#include"Define.h"
#include"Player_Graphic.h"

#include<vector>
#include<string>
#include<fstream>
#include<memory>

/*------------------------------
プレイヤーに持たせる情報を設定する
------------------------------*/
struct PLAYER_DATA : public ACTOR_DATA {
	int skill;              // スキル
	int power;              // 力(攻撃力に上乗せされる)
	int max_power;          // 力の最大値
	int treasure_tool;      // 宝具
	int hunger_point;       // 空腹ポイント
	int noble_phantasm;     // 宝具を撃つためのポイント
	int max_noble_phantasm; // npの最大値

	//Item items[MAX_STOCK_ITEM]; //アイテムの持ち切れる数
	//Item weapon;				//武器
	//Item shield;				//盾
	//Item accessorie;			//装飾品
};

/*--------------------------------------
プレイヤーを管理するクラス
---------------------------------------*/

class Player : public Actor {
/*--------
メンバ変数
--------*/
public:
	Random random;
	std::shared_ptr<Player_Graphic> player_graphic;
	std::vector<PLAYER_DATA> player_data; // キャラ毎に格納
	
	int hunger_point;       // 空腹ポイント
	int noble_phantasm;     // 宝具を撃つためのポイント

private:
	int max_noble_phantasm; // npの最大値

/*--------
メンバ関数
---------*/
public:
	// コンストラクタ
	Player();

	// デストラクタ
	~Player();

	// 座標のセット
	void Set_Position(int x, int y) override;

	// 座標の取得
	void Get_Position(int* x, int* y, eDIRECTION* direction = NULL) override;

	// パラメータをセット
	void Set_Parametor() override;

	// HPの増減
	int Variation_HP(int value) override;

	// ターンの終了
	void Turn_End() override;

	// 最大のHPの取得
	int Get_Max_HP() override;

	// 攻撃力の取得
	int Get_Attack() override;

	// 力の取得
	int Get_Power();

	// 防御力の取得
	int Get_Defence() override;

	// 回避率を取得
	int Get_Agility() override;

	// 死亡判定
	bool Is_Dead() override;

	// NPの取得
	int Get_Max_NP();

	// NPの増減
	int Variation_NP(int vlue);

	// 経験値を得る
	void Add_Experience_Point(int experience_point);

	// おなかゲージの増減
	void Variation_Hunger_Point(int value);

	// アイテムの装備
	void Set_Equipment(Item* item);

	// アイテムの取得。カバンがいっぱいなら true を返す
	bool Get_Item(Item* item);

	// 指定したフィルタで指定したインデックスのアイテムを取得
	Item* Get_Item_From_Index(eITEM_TYPE filter, int index);

	// 空腹率を 0~100% で返す
	int Get_Hunger_Percent();

	// 経験値からレベルを求める
	int Get_Level();
};