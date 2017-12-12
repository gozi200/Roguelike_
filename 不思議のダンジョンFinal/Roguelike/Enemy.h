#pragma once

#include"Item.h"
#include"Actor.h"

/*----------------------------
エネミーに持たせる情報を決定する
----------------------------*/
struct ENEMY_DATA : public ACTOR_DATA {
	int evolition;   // 進化段階
	int AI_paturn;   // 行動パターン
	int first_floor; // 出現開始階層
	int last_floor;  // 出現終了階層
	int item_drop;   // 死亡時にアイテムを落とす確率

	Item drop_item;  // 死亡時に確率で落とすアイテム
};

/*-------------------------------
エネミーの基底クラス(種類で分ける？)
--------------------------------*/

class Enemy : public Actor {
/*--------
メンバ変数
--------*/
public:

/*--------
メンバ関数
---------*/
public:
	// コンストラクタ
	Enemy();

	// デストラクタ
	~Enemy();

	// 座標のセット
	void Set_Position(int x, int y) override;

	// 座標の取得
	void Get_Position(int* x, int* y, eDIRECTION* direction = NULL) override;

	// hit_pointの増減
	int Variation_HP(int value) override;

	// ターンの終了
	void Turn_End() override;

	// 最大のHPの取得
	int Get_Max_HP() override;

	// 攻撃力の取得
	int Get_Attack() override;

	// 防御力の取得
	int Get_Defence() override;

	// 回避率を取得
	int Get_Agility() override;

	// 死亡判定
	bool Is_Dead() override;

};