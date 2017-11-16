#pragma once

#include"Game.h"
#include"DxLib.h"
#include"Define.h"
#include"Tile_Data.h"
#include"Wall_Data.h"
#include"Tile_Judge.h"
#include"Wall_Function.h"
#include"Tile_Function.h"
#include"Enemy_Manager.h"

#include<vector>

/*/////////////////////////////
テキストベース版のゲーム基本クラス
/*/////////////////////////////

class Game_Gui : public Game {
/*///////
メンバ変数
*////////
public:
	 //const Tile_Judge* tile_judge; 
	 //const Tile_Judge* tile_down;
	 Tile_Function* tile_function;
	 Wall_Function* wall_function;

	 int x, y; //画面
	 int mx, my; //マップ
	 int cx, cy; //キャラ
	 int dx, dy; //ダンジョン
	 int loop_count = 0; //ループ回数を数える

/*////////
メンバ関数
*////////
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