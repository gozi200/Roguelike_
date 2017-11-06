#pragma once

#include"Game.h"
#include"DxLib.h"
#include"Define.h"
#include"Tile_Data.h"
#include"Wall_Data.h"
#include"Tile_Judge.h"
#include"Tile_Function.h"
#include"Enemy_Manager.h"

#include<vector>

/*/////////////////////////////
テキストベース版のゲーム基本クラス
/*/////////////////////////////

class Game_Cui : public Game {
/*///////
メンバ変数
*////////
public:
	 const Tile_Judge* tile_judge; 
	 Tile_Function* tile_function;

	 Tile_Data Tile_data;
	 Wall_Data wall_data;

	 int loop_count = 0; //ループ回数を数える

/*////////
メンバ関数
*////////
	 //コンストラクタ/
	 Game_Cui();
	 //デストラクタ
	~Game_Cui();

	//ゲームの実行
	int Run();

	//コンソールの初期化
	void Console_Init();

	//画面の描画
	virtual void Render() override;
};