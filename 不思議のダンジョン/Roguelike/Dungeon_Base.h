#pragma once

#include"Item.h"
#include"Enemy.h"
#include"Player.h"
#include"Define.h"
#include"Vector2D.h"
#include"Tile_Judge.h"
#include"Enemy_Database.h"

/*///////////////////////////
ダンジョン作成の元となるクラス
///////////////////////////*/

class Dungeon_Base {
/*////////
メンバ変数
*/////////
public:
	DUNEON_RECTANGLE dungeon_rectangle[MAX_RECTANGLE]; //rectangleは矩形の意味 ここでは区画情報のこと

	int rectangle_count; //区画数

	int width; //ダンジョンの幅 部屋？
	
	int height; //ダンジョンの高さ　部屋？

	Tile_Judge* tile_judge;// = new Tile_Judge; //タイルが床なのか何なのかを判断

	Player *player; //プレイヤー

	Enemy *m_enemy[MAX_ENEMY]; //エネミーへのポインタ ポインタとの重複を避ける

	int enemy_count; //登録されているエネミーの数

	int up_stairs_x;

	int up_stairs_y;

	int down_stairs_x;

	int down_stairs_y;

/*////////
メンバ関数
*/////////
public:
	//コンストラクタ
	Dungeon_Base();

	//デストラクタ
	virtual ~Dungeon_Base();

	//ダンジョンのメモリの確保
	bool Alloc(int width, int height); //MEMO: allocは要素の数が決まってない値に使用するもの

	//タイル情報を取得
	Tile_Judge* Get_Tile(int x, int y); 

	//区画の数を取得
	int Get_Rectangle_Count();

	//部屋の数を取得
	int Get_Room_Count();

	//指定場所が移動可能か判断(trueなら移動可能)
	bool is_Move(int x, int y);

	//指定矩形を壁化道にする(right,bottomのマスは塗らない)
	void Fill_Rectangle(int left, int top, int right, int bottom, bool is_wall);

	//指定の横マスを壁化道にする
	void Fill_H_Line(int left, int right, int y, bool is_wall); //TODO: Hってなに？

	//指定の縦マスを壁化道にする
	void Fill_V_Line(int top, int bottom, int x, bool is_wall); //同上

	//指定した部屋内の適当な座標を取得
	void Random_Room_Point(int index, int *px, int *py);

	//指定した座標Aから、座標Bは移動できる周囲の８マスであればtrueを返す
	bool Chekc_Move(int ax, int ay, int bx, int by);

	//エネミーを部屋に配置
	void Enemy_Array(int floor);

	//エネミーを全て削除する
	void Delete_Enemy();

	//エネミーの数を取得(死んでいるものも含む)
	int Get_Enemy_Count();

	//指定座標にエネミーがいるか
	Enemy* Get_Point_Enemy(int x, int y);

	//指定インデックスのエネミー情報を得る
	Enemy* Get_Mob_From_Index(int index);

	//指定座標にアイテムを落とす
	void Drop_Item(int x, int y, Item* item);

	//指定座標に落ちているアイテムを削除
	void Remove_Item(int x, int y, Item * item);

	//指定位置の部屋インデックスを返す(道または壁なら-1を返す)
	int Get_Room_Index(int x, int y);

	//攻撃処理
	int Attack(Player* player, Player* target);

	//IDからエネミークラスを作成
	bool Make_Enemy(int ai, Enemy** enemy);

	//エネミーのベーステーブルからパラメータをセット
	void Set_Enemy_Parameter(Enemy* enemy, Enemy_Database* enemy_data);

private:
	//階層にあったエネミーを生成取得
	Enemy* Get_Enemy(int floor);
};