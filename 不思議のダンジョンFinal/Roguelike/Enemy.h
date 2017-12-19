#pragma once

#include"Item.h"
#include"Actor.h"
#include"Enemy_Graphic.h"


/*----------------------------
エネミーに持たせる情報を決定する
----------------------------*/
struct ENEMY_DATA : public ACTOR_DATA {
	int evolition;   // 進化段階
	int AI_paturn;   // 行動パターン
	int critical;    // クリティカル
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

private:
	std::shared_ptr<Enemy_Graphic> enemy_graphic;

	std::vector<ENEMY_DATA> player_datas; // キャラ毎に格納

/*--------
メンバ関数
---------*/
public:
	// コンストラクタ
	Enemy();

	// デストラクタ
	~Enemy();

	// パラメータをセット
	void Set_Parametor() override;

private:
	// ターンの終了
	void Turn_End() override;
};