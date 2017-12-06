#pragma once

#include"Item.h"
#include"Shield.h"
#include"Define.h"
#include"Weapon.h"
#include"Vector2D.h"
#include"Enemy_Data.h"
#include"Accessorie.h"

/*----------------------------------
キャラクターのステータスを管理するクラス
-----------------------------------*/

class Actor_Status {
/*----------
メンバ変数
-----------*/
public:
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
	int max_hit_point;			//ヒットポイントの最大値
	int noble_phantasm;			//宝具を撃つためのポイント
	int hunger_point;			//空腹ポイント
	int activity;				//行動力(ここでは１ターンに行動できる数)
	int turn_count;				//経過ターンをカウント
	int experience_point;		//経験値(ここでは倒されたときに相手に与える値)
	int graphic_handle;			//画像のハンドル
	int paturn;					//行動パターン
	int evolution;				//進化形態
	int first_floor;			//出現開始階層
	int last_floor;				//出現終了階層
	int drop_item_ID;			//ドロップするアイテムのID

	int width;					//表示される幅
	int height;					//表示される高さ

	Item items[MAX_STOCK_ITEM]; //アイテムの持ち切れる数
	Item drop_item;				//死亡時に確率で落とすアイテム
	Item weapon;				//武器
	Item shield;				//盾
	Item accessorie;			//装飾品

/*---------
メンバ関数
---------*/
public:
	//コンストラクタ
	Actor_Status();

	//デストラクタ
	~Actor_Status();

	//位置の取得
	void Set_Position(int x,int y);
	void Get_Position(int* px, int*py, eDIRECTION* dir = NULL);

	//パラメータのセット
	void Set_Parameter(SETTING_ENEMY_DATA* record, Item* drop_item);

	//HIt_Pointの増減(計算した値を返す)
	int Get_Hit_Point(int hit_point);

	//Magic_Pointの増減(計算した値を返す)
	int Get_Magic_Point(int magic_point);
	
	//空腹ポイントを0~100%で返す
	int Get_Hunger_Point();

	//HPの増減(戻り値: 実際に増減した値)
	int Cure_Hit_Point(int value);
	
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

	/*アイテムを装備
	@param item 装備可能アイテム
 	*/
	void Set_Equipment(Item* equipment);

	//アイテムを取得(持ちきれないときはfalseを返す)
	bool Get_Item(Item* item);

	//アイテム情報を選択して取得
	Item* Get_Item_Flom_Index(eITEM_TYPE filter, int index);
	
	//死亡判定
	bool Is_Dead();
};
