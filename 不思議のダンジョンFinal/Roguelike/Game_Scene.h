#pragma once

#include"DxLib.h"
#include"Define.h"

/*-------------------------
ゲームシーンを管理するクラス
-------------------------*/

class Game_Scene {
/*--------
メンバ変数
--------*/

/*--------
メンバ関数
--------*/
public:
	Game_Scene();

	~Game_Scene();

	void Update();

	void Render();
};