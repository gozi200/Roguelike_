#pragma once

#include"Vector2D.h"

/*//////////////////////////////////
Actorの継承元クラスであり、基底クラス
//////////////////////////////////*/

class Actor_Manager; //基底クラスに宣言しておく
class Item_Manager; //同上

class Object {
	Actor_Manager* actor_manager;
	Item_Manager* item_manager;
	Vector2D position; //座標　QESTION: positionを使うならx,yは？
	
/*/////////
メンバ変数
*//////////
protected:

	int x;

	int y;

	bool is_exist; //存在フラグ

	float collision; //飛び道具などのヒット確認のための当たり判定

	bool is_hostility_flag; //敵意 trueはfalseのみ攻撃可能。逆も然り


/*////////
メンバ関数
*/////////
public:
	Object();

	bool Get_Exist() const;

	int Get_X() const;

	int Get_Y() const;

	double Get_Collision() const;

	double Get_Hostility_Flag() const;
};
