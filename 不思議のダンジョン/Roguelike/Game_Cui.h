#pragma once

#include"Game.h"
#include"DxLib.h"
#include"Tile_Judge.h"
#include"Tile_Data.h"
#include"Wall_Data.h"
#include"Enemy_Manager.h"

#include<vector>

/*/////////////////////////////
テキストベース版のゲーム基本クラス
/*/////////////////////////////

class Game_Cui : public Game {
public:
	 const Tile_Judge* tile_judge; 

	 Tile_Data tile_data;
	 Wall_Data wall_data;
/*////////
メンバ関数
*/////////
	 Game_Cui();

	~Game_Cui();

	//ゲームの実行
	int Run();

	//コンソールの初期化
	void Console_Init();

	//画面の描画
	virtual void Render() override;
};