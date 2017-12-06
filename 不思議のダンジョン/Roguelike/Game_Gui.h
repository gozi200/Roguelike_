#pragma once

#include"Tile.h"
#include"Wall.h"
#include"Game.h"
#include"DxLib.h"
#include"Player.h"
#include"Define.h"
#include"Tile_Data.h"
#include"Wall_Data.h"
#include"Tile_Judge.h"
#include"Enemy.h"

#include<vector>

/*-------------
ゲーム基本クラス
---------------*/
class Game_Gui : public Game {
/*-------
メンバ変数
--------*/
public:
	 Tile* tile;
	 Wall* wall;
	 Player* player_;

	 int x, y; //画面
	 int mx, my; //マップ?
	 int cx, cy; //キャラ
	 int dx, dy; //ダンジョン
	 int loop_count = 0; //ループ回数を数える

/*--------
メンバ関数
---------*/
	 //コンストラクタ/
	 Game_Gui();
	 //デストラクタ
	 ~Game_Gui();

	//ゲームの実行
	int Run();

	//コンソールの初期化
	void Console_Init();

	//画面の描画
	virtual void Render() override;
};