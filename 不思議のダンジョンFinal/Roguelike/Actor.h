#pragma once

#include"DxLib.h"
#include"Set_File.h"
#include"Define.h"

#include<memory>
#include<string>

/*-------------------
Enemy,Allyの親クラス
-------------------*/
struct ACTOR_DATA {
	int ID;				  // ナンバー
	std::string  name;    // 名前
						  
	int level;			  // レベル
	int attack;			  // 攻撃力
	int defence;		  // 防御力
	int hit_point;		  // ヒットポイント(0で死亡)
	int max_hit_point;	  // ヒットポイントの最大値
	int activity;		  // 行動力(ここでは１ターンに行動できる数)
	int experience_point; // 経験値(敵から与える、敵から貰える値)
	int turn_count;		  // 経過ターンをカウント
						 
	int graphic_handle;	  // 画像のハンドル
	int width;			  // 表示される幅
	int height;			  // 表示される高さ
};

/*----------------------
Player,Enemyの基底クラス
-----------------------*/
class Actor {
/*--------
メンバ変数
--------*/
protected:
	int ID;               // ナンバー
	std::string* name;    // 名前

	int x;                // 横の座標
	int y;                // 縦の座標

	int level;            // レベル
	int power;            // ちから (攻撃力に加算するボーナス)
	int max_power;        // 力の最大値
	int attack;           // 攻撃力 (素の攻撃力。ここに武器の攻撃力、
	int defence;          // 防御力
	int hit_point;        // ヒットポイント(0以下で死亡)
	int max_hit_point;    // ヒットポイントの最大値
	int activity;         // 行動力(ここでは１ターンに行動できる数)
	int turn_count;       // 経過ターンをカウント
	int experience_point; // 経験値(敵から与える、敵から貰える値)

	int graphic_handle;   // 画像のハンドル
	int width;            // 表示される幅
	int height;           // 表示される高さ

	int loop_count;

	std::shared_ptr<Set_File> set;
	std::string file_pass; //ファイルのパス

/*--------
メンバ関数
--------*/
public:
	// コンストラクタ
	Actor();

	// 座標のセット
	virtual void Set_Position(int x, int y);

	// 座標の取得
	virtual void Get_Position(int* x, int* y, eDIRECTION* direction = NULL);

	// hit_pointの増減
	virtual int Variation_HP(int value);

	// 最大のHPの取得
	virtual int Get_Max_HP();

	// 攻撃力の取得
	virtual int Get_Attack();

	// 防御力の取得
	virtual int Get_Defence();

	// 死亡判定
	virtual bool Is_Dead();

protected:
	// デストラクタ
	~Actor();

	//ステータスをセット
	virtual void Set_Parametor() = 0;

	// ターンの終了
	virtual void Turn_End() = 0;

	// 描画
	virtual void Render(int x, int y, int call_ID) = 0;
};