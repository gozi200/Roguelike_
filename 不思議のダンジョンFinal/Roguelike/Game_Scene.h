#pragma once

#include"DxLib.h"
#include"Define.h"
#include"Make_Dungeon.h"

#include<memory>

/*-------------------------
ゲームシーンを管理するクラス
-------------------------*/

class Game_Scene {
/*--------
メンバ変数
--------*/
private:
	std::shared_ptr<Make_Dungeon> make_dungeon;

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