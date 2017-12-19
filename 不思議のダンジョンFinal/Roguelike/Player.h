#pragma once

#include"Ally.h"
#include"Player_Graphic.h"
#include"Make_Dungeon_Map.h"

/*------------------------------
プレイヤーに持たせる情報を設定する
------------------------------*/

struct PLAYER_DATA : public ALLY_DATA {
	int keep_star;    // クリティカルスターの保持数
	int hunger_point; // 空腹ポイント
};

/*----------------------
プレイヤーを管理するクラス
-----------------------*/
class Make_Dungeon;

class Player : public Ally {
/*--------
メンバ変数
--------*/
private:
	std::shared_ptr<Player_Graphic> player_graphic;
	std::shared_ptr<Make_Dungeon_Map> dungeon_manager;
	
	int* player_x;    // プレイヤーの座標(横)
	int player_y;     // プレイヤーの座標(縦)
	int keep_star;    // クリティカルスターの保持数
	int hunger_point; // 空腹ポイント

	std::vector<PLAYER_DATA> player_datas; // キャラ毎に格納

public:
	int spawn_point_x; // 生成の座標(横)
	int spawn_point_y; // 生成の座標(縦)

/*--------
メンバ関数
---------*/
public:
	// コンストラクタ
	Player();

	Player(std::shared_ptr<Make_Dungeon_Map> manager);

	// デストラクタ
	~Player();

	// パラメータをセット
	void Set_Parametor() override;
	

private:
	// 座標を取得
	void Set_Player_Position();

	// ターンの終了
	void Turn_End() override;

	// おなかゲージの増減
	void Variation_Hunger_Point(int value);

	//// アイテムの取得。カバンがいっぱいなら true を返す
	//bool Get_Item(Item* item);

	//// 指定したフィルタで指定したインデックスのアイテムを取得
	//Item* Get_Item_From_Index(eITEM_TYPE filter, int index);

	// 空腹率を 0~100% で返す
	int Get_Hunger_Percent();

public:
	// 描画
	void Render(int x, int y, int call_ID) override;
};