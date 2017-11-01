#pragma once

#include"Player.h"
#include"Enemy.h"
#include"Dungeon01.h"
#include"Dungeon_Base.h"

class Game {
/*////
定数
*/////
	enum ACTION {
		ACTION_MOVE, //移動処理
		ACTION_STEP, //階段移動確認
		ACTION_MAX, //GAmeクラスで宣言させているACTIONの最大値
	};

/*////////
メンバ変数
*/////////
public:
	Player player; //プレイヤーのデータ
	Dungeon_Base* dungeon_base = new Dungeon_Base;
	Dungeon01* dungeon01 = new Dungeon01; //TODO: newはどこに？

	int floor; //現在の階層

	char key[KEY_NUMBER]; //全てのキー

private:
	ACTION action; //現在のメイン処理

	int action_count; //メイン処理汎用変数

/*////////
メンバ関数
*/////////
public:
	//コンストラクタ
	Game() {

	}

	//デストラクタ
	virtual ~Game();

	//ゲームの初期化
	void Init();

	//ゲームのメインループ実行(サイクル実行)
	bool Cycle();

	//フロアの作成
	void Create_Floor();

	//画面の描画
	virtual void Render() = 0;

private:
	//処理の切り替え
	void Set_Action(ACTION action);

	//処理の実行
	void Run_Action();

	//移動処理
	bool Action_Step();

};