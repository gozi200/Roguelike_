#pragma once

#include"Ally.h"
#include"Vector2D.h"
#include"Player_Data.h"
#include"Player_Key_Contloroller.h"

/*//////////////////
Actorクラスを継承

自機を管理するクラス
//////////////////*/

class Player : public Ally {


	/*////////
	メンバ変数
	*/////////
public:
	char* player_name;
	PLAYER_STATUS_DATA* player_data;
	Player_Key_Controller* player_key_controller;

	//Player_Data* player_data;

	//Ally_Status status; //基本ステータス

/*////////
メンバ関数
*/////////

public:
	/*プレイヤーのコンストラクタ
	*/
	Player();

	//プレイヤーのデストラクタ
	~Player();

	/* スポーンしたプレイヤーを配置
	   @param x x座標
	   @param y y座標
	*/
	void Arrange(int x, int y); //QUESTION: Vector2D使う？

	//毎フレーム呼び出す処理を書く
	void Update();

	//現在の状態ににあった画像に切り替える。
	void Current_Graphic();

	//位置の設定、取得
	void Set_Position(int x, int y);
	void Get_Position(int *px, int*py, DIRECTION *direction = NULL);


	///////////////////////////////別のところで処理する？(hp,お腹,レベル,経験値などの可視化できるものはまとめる？)
	void Render_Hit_Point();

	void Render_Experiece_Point();

	void Render_Stmach(); //おなかゲージの描画
	////////////////////////////////
};