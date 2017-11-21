#pragma once

#include"Item.h"
#include"Weapon.h"
#include"Shield.h"
#include"Define.h"
#include"Vector2D.h"
#include"Item_Type.h"
#include"Accessorie.h"

/*----------------------------------
味方勢力のステータスを管理するクラス
-----------------------------------*/

class Ally_Status {
/*----------
メンバ変数
-----------*/
public:
	int x; //現在位置の座標(横)
	int y; //現在位置の座標(縦)

/*---------
メンバ関数
---------*/
public:
	//コンストラクタ
	Ally_Status();

	//デストラクタ
	~Ally_Status();

	//位置の取得
	void Set_Position(int x,int y);
	void Get_Position(int* px, int*py, DIRECTION* dir = NULL);

	////パラメータのセット
	//void Set_Parameter(Enemy_Database* record, Item* drop_item);

	//HIt_Pointの増減(計算した値を返す)
	int Get_Hit_Point(int hit_point);

	//Magic_Pointの増減(計算した値を返す)
	int Get_Magic_Point(int magic_point);
	
	//空腹ポイントを0~100%で返す
	int Get_Hunger_Point();
	
	/*食事を行う
	@param hunger_point 空腹ゲージ
	*/
	int Add_Hunger_Point(int hunger_point);
	
	/*経験値を取得
	@param experience_point 経験値
	*/
	int Add_Experience_Point(int experience_point);

	//攻撃力の取得
	int Get_Attack();

	//防御力の取得
	int Get_Defence();

	//行動力の取得
	int Get_Activity();
	
	//ターンの終了
	void Turn();

	//最大Hit_Pointの取得
	int Get_Max_Hit_Point(); //一応

	//最大Magic_Pointの取得
	int Get_Max_Magic_Point(); //一応

	//TODO: 装備アイテムと使用アイテムで分ける？------------------------------
	
	/*アイテムを装備
	@param item 装備可能アイテム
 	*/
	void Set_Equipment(Item* equipment);

	//アイテムを取得(持ちきれないときはfalseを返す)
	bool Get_Item(Item* item);

	//指定したフィルタを使って指定したインデックスとのアイテムを取得
	Item* Get_Item_Flom_Index(Item_Type* filter, int index);
	
	//------------------------------------------------------------------

	//死亡判定
	bool Is_Dead();
};
