#pragma once

#include"Split.h"
#include"Define.h"
#include"Set_File.h"

#include<vector>
#include<memory>
#include<string>
#include<fstream>

/*-------------------
Enemy,Allyの親クラス
-------------------*/
struct ACTOR_DATA {
	int ID;				  // ナンバー
	std::string  name;    // 名前

	int calss;            // クラス
	int saint_graph;      // 再臨状態
	int level;			  // レベル
	int attack;			  // 攻撃力
	int defence;		  // 防御力
	int hit_point;		  // ヒットポイント(0で死亡)
	int max_hit_point;	  // ヒットポイントの最大値
	int activity;		  // 行動力(ここでは１ターンに行動できる数)
	int experience_point; // 経験値(敵から与える、敵から貰える値)
	int turn_count;       // 経過ターンをカウント
	int sukill;           // スキル

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
public:
	int x;                // 横の座標
	int y;                // 縦の座標
	int level;            // レベル
	int loop_counter;     // カウンター

	std::string file_pass; 
	std::shared_ptr<Set_File> set;

private:
	int ID;               // ナンバー
	std::string* name;    // 名前

	int power;            // ちから (攻撃力に加算するボーナス)
	int max_power;        // 力の最大値
	int attack;           // 攻撃力 (素の攻撃力。ここに武器の攻撃力、
	int defence;          // 防御力
	int hit_point;        // ヒットポイント(0以下で死亡)
	int max_hit_point;    // ヒットポイントの最大値
	int activity;         // 行動力(ここでは１ターンに行動できる数)
	int skill;            // スキル
	int turn_count;       // 経過ターンをカウント

	int graphic_handle;   // 画像のハンドル
	int width;            // 表示される幅
	int height;           // 表示される高さ

	
protected:
	int experience_point; // 経験値(敵から与える、敵から貰える値)

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
protected:
	// デストラクタ
	~Actor();

	// hit_pointの増減
	virtual int Variation_HP(int value);

	// 最大のHPの取得
	virtual int Get_Max_HP(int set_max_HP);

	// 攻撃力の取得
	virtual int Get_Attack(int set_ATK);

	// 防御力の取得
	virtual int Get_Defence(int set_DEF);

	//// カウンターを回す
	//virtual int Get_Loop_Counter(int set_counter);

	// ターンカウントを回す
	virtual int Get_Turn_Count(int set_turn_count);

	// 死亡判定
	virtual bool Is_Dead();

	// ターンの終了
	virtual void Turn_End();

	//ステータスをセット
	virtual void Set_Parametor() = 0;

	// 描画
	virtual void Render(int x, int y, int call_ID) = 0;
};