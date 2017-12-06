#pragma once

#include"Define.h"
#include"Actor.h"
#include"Enemy.h"
#include"Dungeon01.h"
#include"Dungeon_Base.h"
#include"Actor_Status.h"

#include<string>

class Game {
	enum ACTION {
		ACTION_MOVE,      //移動処理
		ACTION_GET_ITEM,  //アイテムを拾う
		ACTION_EQUIPMENT, //装備アイテムを装備する
		ACTION_DORP_ITEM, //アイテムを落とす
		ACTION_USE_ITEM,  //アイテムを使う
		ACTION_STEP,      //階段移動確認
		ACTION_MAX,       //Gameクラスで宣言させているACTIONの最大値
	};

/*--------
メンバ変数
---------*/
public:
	Dungeon_Base* dungeon_base;
	Dungeon01* dungeon01;
	Actor player;
	Enemy* enemy_;
	Actor_Status actor_status;

	int floor; //現在の階層

private:
	ACTION action; //現在のメイン処理

	int action_count; //メイン処理汎用変数

	Item* use_item; //使用アイテム(持ち物のアイテムへのポインタ)

/*---------
メンバ関数
----------*/
public:
	//コンストラクタ
	Game();

	//デストラクタ
	virtual ~Game();

	//ゲームの初期化
	void Init();

	//ゲームのメインループ実行(サイクル実行)
	bool Cycle();

	//フロアの作成
	void Create_Floor();

	//アイテムの取得
	void Action_Get_Item();

	//アイテムを捨てる
	void Action_Drop_Item();

	//アイテムを使う
	void Action_Use_Item();

	//アイテムの装備
	void Action_Equip();


	//画面の描画
	virtual void Render() = 0;

private:
	//所持アイテムを選択表示
	int Message_Items(eITEM_TYPE filter = ITEM_TYPE_NONE); //戻り値はアイテムの数

	//処理の切り替え
	void Set_Action(ACTION action);

	//処理の実行
	void Run_Action();

	//移動処理
	bool Action_Step();

	bool Use_Item_HP_Cure(Item* item);

	bool Use_Item_Food(Item* item);

	bool Move_Check_Enemy(int x, int y);

	bool Move_Check_Command();

	void Enemy_Move();
};