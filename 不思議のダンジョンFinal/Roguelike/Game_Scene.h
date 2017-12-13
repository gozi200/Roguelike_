#pragma once

#include"DxLib.h"
#include"Define.h"
#include"Dungeon_Sycle.h"
#include"Dungeon_GUI.h"

#include"Player.h" // Amended
#include"Create_Dungeon.h"

/*-------------------------
ゲームシーンを管理するクラス
-------------------------*/

class Game_Scene {
/*--------
メンバ変数
--------*/
private:
	Player* player;
	Dungeon_GUI* dungeon_GUI;
	Create_Dungeon* create_dungeon;

/*--------
メンバ関数
--------*/
public:
	// コンストラクタ
	Game_Scene();
	
	// デストラクタ
	~Game_Scene();

	// 初期化
	void Initialize();

	// 毎フレームごとに更新
	void Update();

	// 更新した内容を毎フレームごとに描画
	void Render();
};