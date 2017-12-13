#pragma once

#include"Item.h"
#include"Ally.h"
#include"Split.h"
#include"Define.h"
#include"Player_Graphic.h"

#include<vector>
#include<string>
#include<fstream>
#include<memory>

/*------------------------------
プレイヤーに持たせる情報を設定する
------------------------------*/
struct PLAYER_DATA : public ALLY_DATA {
	int hunger_point;       // 空腹ポイント
};

/*--------------------------------------
プレイヤーを管理するクラス
---------------------------------------*/

class Player : public Actor {
/*--------
メンバ変数
--------*/
public:
	std::shared_ptr<Player_Graphic> player_graphic;
	std::vector<PLAYER_DATA> player_datas; // キャラ毎に格納
	
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

	// パラメータをセット
	void Set_Parametor() override;

	// ターンの終了
	void Turn_End() override;

	// 描画
	void Render(int x, int y, int call_ID) override;

	// おなかゲージの増減
	void Variation_Hunger_Point(int value);

	// アイテムの取得。カバンがいっぱいなら true を返す
	bool Get_Item(Item* item);

	// 指定したフィルタで指定したインデックスのアイテムを取得
	Item* Get_Item_From_Index(eITEM_TYPE filter, int index);

	// 空腹率を 0~100% で返す
	int Get_Hunger_Percent();
};