#pragma once

#include"Item.h"
#include"Actor.h"
#include"Enemy.h"
#include"Define.h"
#include"Random.h"
#include"Vector2D.h"
#include"Enemy_01.h"
#include"Tile_Judge.h"
#include"Enemy_Data.h"
#include"Actor_Status.h"

static Item ITEM_DATA_BASE[] {
	{ITEM_TYPE_USEITEM,    "外科手術セット"   ,"回復"     ,{HP_CURE, 50}},
	{ITEM_TYPE_USEITEM,    "聖者の贈り物"     ,"回復"     ,{HP_CURE, 100}},
	{ITEM_TYPE_USEITEM,    "白銀の果実"       ,"食べ物"   ,{HUNGER_CURE, 50}},
	{ITEM_TYPE_WEAPON,     "エクスカリバー"   ,"武器"     ,{50}},
	{ITEM_TYPE_SHIELD,     "ギャラハッドの盾" ,"盾"       ,{50}},
	{ITEM_TYPE_ACCESSORIE, "聖杯"            ,"概念礼装" ,{0,10}},
};

static SETTING_ENEMY_DATA;

/*----------------------------
ダンジョン作成の元となるクラス
----------------------------*/

class Dungeon_Base {
/*---------
メンバ変数
---------*/
public:
	Actor* player; //プレイヤー

	Random random;

	Enemy_Data enemy_data;

	Tile_Judge* tile_judge; //タイルが床なのか何なのかを判断

	Enemy* m_enemy[MAX_ENEMY]; //エネミーへのポインタ ポインタとの重複を避ける
	
	DUNEON_RECTANGLE dungeon_rectangle[MAX_RECTANGLE]; //rectangleは矩形の意味 ここでは区画情報のこと

	int width; //ダンジョンの幅 
	
	int height; //ダンジョンの高さ

	int rectangle_count; //区画数
	
	int enemy_count; //登録されているエネミーの数

	int turn_count; //経過ターンを数える

	int up_stairs_x; //昇り階段のある座標(横)

	int up_stairs_y; //昇り階段のある座標(縦)

	int down_stairs_x; //下り階段のある座標(横)

	int down_stairs_y; //下り階段のある座標(縦)

/*--------
メンバ関数
---------*/
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

	//部屋の数を取得
	int Get_Romm_Count();

	//指定場所が移動可能か判断(trueなら移動可能)
	bool Is_Move(int x, int y);

	//指定矩形を壁か道にする(right,bottomのマスは塗らない)
	void Fill_Rectangle(int left, int top, int right, int bottom, bool is_wall);

	//指定の横マスを壁か道にする
	void Fill_Horizontal_Line(int left, int right, int y, bool is_wall); //Hってなに？

	//指定の縦マスを壁か道にする
	void Fill_Vertical_Line(int top, int bottom, int x, bool is_wall); //同上

	//指定した部屋内の適当な座標を取得
	void Random_Room_Point(int index, int *px, int *py);

	//指定した座標Aから、座標Bは移動できる周囲の８マスであればtrueを返す
	bool Check_Move(int ax, int ay, int bx, int by);

	//エネミーを部屋に配置
	void Create_Enemy(int floor);

	//エネミーを全て削除する
	void Delete_Enemy();

	//エネミーの数を取得(死んでいるものも含む)
	int Get_Enemy_Count();

	//指定座標にエネミーがいるか
	Actor* Get_Point_Enemy(int x, int y);

	//指定インデックスのエネミー情報を得る
	Actor* Get_Mob_From_Index(int index);

	//指定座標にアイテムを落とす
	void Drop_Item(int x, int y, Item* item);

	//指定座標に落ちているアイテムを削除
	void Remove_Item(int x, int y, Item * item);

	//攻撃処理
	int Attack(Actor* player, Actor* target);

	//IDからエネミークラスを作成
	bool Make_Enemy(int ai, Enemy** enemy);

	//ランダムにエネミーを配置
	void Random_Create_Enemy(int floor);

	//エネミーのデータベースからパラメータをセット
	void Set_Enemy_Parameter(Enemy* enemy, SETTING_ENEMY_DATA* enemy_data);

	//指定位置の部屋インデックスを返す(道、壁なら-1を返す)
	int Get_Room_Index(int x, int y);

	//指定位置の矩形インデックスを返す(道、壁なら-1を返す)
	int Get_Rectangle_Index(int x, int y);

private:
	//階層にあったエネミーを生成取得
	Enemy* Get_Enemy(int floor);
};