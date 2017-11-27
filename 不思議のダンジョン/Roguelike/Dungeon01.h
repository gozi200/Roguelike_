#pragma once

#include"Actor.h"
#include"Random.h"
#include"Define.h"
#include"Dungeon_Base.h"

class Dungeon01 : public Dungeon_Base {
/*////////
メンバ変数
*/////////
public:
	Random random;

/*////////
メンバ関数
*/////////
public:
	//コンストラクタ
	Dungeon01();

	//デストラクタ
	~Dungeon01();

	void Make(Actor* player, int floor);

	/*区画を作る
	 @param left 左辺
	 @param top 上辺
	 @param right 右辺
	 @param bottom 下辺
	*/
	DUNEON_RECTANGLE* Create_Rectangle(int left, int top, int right, int bottom);

	void Split_Rectangle(bool is_vertical);

	void Create_Room();

	void Connect_Room();

	void Create_Road(int room_A, int room_B);

private:
};