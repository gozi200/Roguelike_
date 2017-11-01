#pragma once

#include"Actor.h"
#include"Player.h"
#include"Partner.h"
#include"Enemy.h"
#include"Define.h"

/*/////////////////////////
Actorの個を管理するクラス
////////////////////////*/

class Actor_Manager {
private:
	bool is_gameover_flag;

public:
	//コンストラクタ
	Actor_Manager(char*); //プレイヤーを動かすためキー確認

	//デストラクタ
	~Actor_Manager();

	void Update(); //毎フレーム呼び出される処理

	void Render();

	bool Get_Gameover_Flag();

	void Actor_Array();

};
