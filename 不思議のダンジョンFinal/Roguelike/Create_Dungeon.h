#pragma once

#include"Define.h"
#include"Tile_Judge.h"
#include"Dungeon_Manager.h"

#include<memory>

/*---------------------------------------------------
ダンジョンマップを生成するクラス : Dungeon_Managerを継承
----------------------------------------------------*/

class Create_Dungeon : public Dungeon_Manager {
/*--------
メンバ変数
--------*/
public:
	Dungeon_Manager* dungeon_manager;


	int x, // 座標(横)
		y; // 座標(縦)

	int a, b, ab, p;

	int upstairs_x;	  // 昇り階段の座標(横)
	int upstairs_y;	  // 昇り階段の座標(縦)
	int downstairs_x; // 下り階段の座標(横)
	int downstairs_y; // 下り階段の座標(縦)

/*-------
メンバ関数
--------*/
public:
	//コンストラクタ 
	Create_Dungeon();
	
	// デストラクタ
	~Create_Dungeon();

	/*区画を作る
	  @param left   左辺
	  @param top    上辺
	  @param right  右辺
	  @param bottom 下辺
	*/
	DUNEON_RECTANGLE* Create_Rectangle(int left, int top, int right, int bottom);

	/* 区画を細分化する
	   @param 
	*/
	void Split_Rectangle(bool is_vertical);
	
	// 部屋を作る
	void Create_Room();

	// 部屋を繋げる
	void Connect_Room();

	/* 道を作る
	   @param room_A 繋がれる道の片割れ
	   @param room_B 繋がれる道の片割れ
	*/
	void Create_Road(int room_A, int room_B);

	// 部屋の範囲+部屋の連結部のみ壁フラグをfalseに
	void Fill_Rectangle(int left, int top, int right, int bottom, bool is_wall);

	// 部屋と部屋の縦道を繋ぐ
	void Fill_Horizontal_Line(int left, int right, int y, bool is_wall);

	// 部屋と部屋の横道を繋ぐ
	void Fill_Vertical_Line(int top, int bottom, int x, bool is_wall);

	//１フロア分のダンジョンを生成する。ダンジョンへ移行、階層移動ごとに呼び出す
	void Create_Floor();

	// １フロア分のダンジョンの構成を設定する(区画の数、部屋の数など)
	void Set_Dungeon();
};