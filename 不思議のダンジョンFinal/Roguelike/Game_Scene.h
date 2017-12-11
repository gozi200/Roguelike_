#pragma once

#include"DxLib.h"
#include"Define.h"
#include"Dungeon_Sycle.h"
#include"Dungeon_GUI.h"

#include"Create_Dungeon.h"

/*-------------------------
ゲームシーンを管理するクラス
-------------------------*/

class Game_Scene {
/*--------
メンバ変数
--------*/
private:
	Dungeon_GUI* dungeon_GUI;
	Dungeon_Sycle* dungeon_sycle;

	Create_Dungeon* create_dungeon;

/*--------
メンバ関数
--------*/
public:
	// コンストラクタ
	Game_Scene();
	
	// デストラクタ
	~Game_Scene();

	// 毎フレームごとに更新
	void Update();

	// 更新した内容を毎フレームごとに描画
	void Render();
};