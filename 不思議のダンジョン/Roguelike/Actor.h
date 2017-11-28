#pragma once

#include"Define.h"
#include"Random.h"
#include"Actor_Status.h"

class Actor {
/*-------
メンバ変数
--------*/
public:
	Random random;

	Actor_Status actor_status;

	char* name; //キャラクターの名前

	bool is_dead_frag; //生存フラグ

	int next_count; //ターンのカウントに使用


/*--------
メンバ関数
---------*/
public:
	//コンストラクタ
	Actor();
	
	//デストラクタ
	virtual ~Actor();

	//名前の設定
	void Set_Name(char* name);
	char* Get_Name();

	//位置の設定、取得
	void Set_Position(int x, int y);
	void Get_Position(int* x, int* y, DIRECTION* dir = NULL);

	//生存確認
	bool Is_Dead();

	//保持ターン数をリセット
	int reset();

	//攻撃
	int Attack(Actor* target);
};