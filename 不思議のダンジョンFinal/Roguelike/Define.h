#pragma once

#include"DxLib.h"

/*----------------------
定数を既定しておくクラス
-----------------------*/

#pragma region 画面サイズ

const int WINDOW_X = 1170; //画面サイズ(横) 

const int WINDOW_Y = 720;  //画面サイズ(縦)

const float HALF_WINDOW_X = WINDOW_X / 2; // 真ん中

const float HALF_WINDOW_Y = WINDOW_Y / 2; // 真ん中

#pragma endregion

#pragma region 計算に使う定数

const double PI = 3.14159265358979323846; //円周率

#pragma endregion

#pragma region IDの管理

#pragma region ダンジョンの各要素の呼び出し用ID

#pragma region 床のID

const int UP_STAIRS   = 0;

const int DOWN_STAIRS = 1;

const int TILE_GRASS  = 2;

const int TILE_CAVE   = 3;

#pragma endregion


#pragma region 壁のID

const int WALL_GRASS        = 0;
const int CORNER_WALL_GRASS = 1;
const int WALL_CAVE         = 2;
const int CORNER_WALL_CAVE  = 3;

#pragma endregion

#pragma endregion


#pragma region アクターの各要素の呼び出しID

#pragma region プレイヤーのID

const int ARTRIA = 1;

#pragma endregion


#pragma region エネミーのID

const int TEST_1 = 1;

#pragma endregion

#pragma endregion


#pragma region アイテムの各要素の呼び出しID



#pragma endregion

#pragma endregion

#pragma region アクターに関する定数

const int ACTOR_SIZE_X     = 90; //キャラクターのサイズ(横)
						   
const int ACTOR_SIZE_Y     = 90; //キャラクターのサイズ(縦)
						   
const int ALLY_NUMBER      = 2; //味方が同時に出現できる数
						   
const int MAX_ACTOR        = 35; //Actorが同時に出現できる数
						   
const int ACTOR_MOVEMENT   = 5; //1マス分の移動量 ひとまず
						   
const int COLLISION        = 20; //キャラの大きさ　ひとまず

const int MAX_ENEMY        = 500; //エネミーの量 ひとまず

const int MAX_STOCK_ITEM   = 30; //持ち切れるアイテムの最大値

const int ENMY_DATA_NUMBER = 22; //エネミーの持っているステータスの数 乱数生成の際に使用

#pragma endregion

#pragma region プレイヤーに関する定数

const int MAX_LEVEL = 25; //ひとまず

const int MAX_EXP   = 800000; //ひとまず

#pragma region レベルアップに必要な経験値量

const int EXP_DATA[MAX_LEVEL] = {
	5,		 //2レベルになるために必要な経験値量
	10,		 //3以下同文
	20,		 //4
	40,		 //5
	80,		 //6
	160,	 //7
	320,	 //8
	640,	 //9
	1300,	 //10
	2600,	 //11
	5200,	 //12
	10000,	 //13
	20000,	 //14
	39000,	 //15
	70000,	 //16
	130000,	 //17
	250000,	 //18
	480000,	 //19
	900000,	 //20
	160000,	 //21
	250000,	 //22
	4600000, //23
	6700000, //24
	MAX_EXP, //25
};

#pragma endregion

#pragma endregion



#pragma region 移動に関する定数

const int CHARACTOR_DIRECTION = 8; //キャラクターの向く方向 上下左右＋斜めの８方向

#pragma endregion


#pragma region アイテムに関する定数

const int ITEM_MAX = 500; //アイテムが同時に出現できる数　ひとまず

#pragma endregion


#pragma region ダンジョンに関する定数

const int DUNGEON_WIDTH  = 25; //ダンジョンの横マスの数 //最終は50

const int DUNGEON_HEIGHT = 25; //ダンジョンの縦マスの数

const int MAX_RECTANGLE  = 10; //区画の最大値

const int MIN_ROOM_SIZE  = 4; //最小の部屋のサイズ

const int TILE_SIZE      = 30; //１マスの大きさ

#pragma endregion


#pragma region キー入力を定数に格納する

const int PUSH_UP_KEY    = CheckHitKey(KEY_INPUT_UP);	 //上方向入力
const int PUSH_RIGHT_KEY = CheckHitKey(KEY_INPUT_RIGHT); //右方向入力
const int PUSH_DOWN_KEY  = CheckHitKey(KEY_INPUT_DOWN);  //下方向入力
const int PUSH_LEFT_KEY  = CheckHitKey(KEY_INPUT_LEFT);  //左方向入力

const int PUSH_G_KEY = CheckHitKey(KEY_INPUT_G); //アイテムを拾う 
const int PUSH_E_KEY = CheckHitKey(KEY_INPUT_E); //アイテムを装備する
const int PUSH_D_KEY = CheckHitKey(KEY_INPUT_D); //アイテムを捨てる
const int PUSH_U_KEY = CheckHitKey(KEY_INPUT_U); //アイテムを使う
const int PUSH_S_KEY = CheckHitKey(KEY_INPUT_S); //階段で移動する

const int PUSH_0_KEY = CheckHitKey(KEY_INPUT_0); //キャンセルボタン
const int PUSH_A_KEY = CheckHitKey(KEY_INPUT_A); //処理をみてコメントをつける

#pragma endregion


#pragma region 区画関連の定義

//区画情報構造体 関数化------------------------------------------------
typedef struct tagDUNGEON_RECTANGLE {

	RECT rect; //区画範囲

	RECT room; //部屋範囲

} DUNEON_RECTANGLE;

//-----------------------------------------------------------------

//RECT構造体の計算
#define RECTANGLE_WIDTH(r) ((r).right-(r).left) //RECTの高さを計算

#define RECTANGLE_HEIGHT(r) ((r).bottom-(r).top) //RECTの幅を計算

#pragma endregion


#pragma region ゲームの設定に関する定数

const int MAX_SCORE = 1000000;

const int TILE_NUMBER = 2; //床の種類(草原、洞窟など)

#pragma endregion


#pragma region その他

const int KEY_NUMBER = 256; //全てのキー

#pragma endregion

#pragma region 列挙型

enum eITEM_TYPE {
	ITEM_TYPE_NONE = 0,		     //なし
	ITEM_TYPE_USEITEM = (1 << 1),   //消耗品
	ITEM_TYPE_WEAPON = (1 << 2),    //武器
	ITEM_TYPE_SHIELD = (1 << 3),    //縦
	ITEM_TYPE_ACCESSORIE = (1 << 4),//装飾品
	ITEM_TYPE_UNIDENTIFIED = (1 << 5)// 未鑑定アイテムのみ（CGame::messageItems の引数にのみ使用）

};

//移動処理とキャラクターの向きを関連付ける
typedef enum eDIRECTION {
	DIRECTION_NONE,      //向き無し
	DIRECTION_DOWN,      //下向き(正面)
	DIRECTION_UP,        //上向き(背面)
	DIRECTION_LEFT,      //左向き
	DIRECTION_RIGHT,     //右向き
	DIRECTION_UPLEFT,    //左上
	DIRECTION_UPRIGHT,   //右上
	DIRECTION_DOWNLEFT,	 //左下
	DIRECTION_DOWNRIGHT, //左上
};

//使用アイテムのカテゴリー
enum eUSE_ITEM_CATEGORY {
	HP_CURE, //HP回復 
	MP_CURE, //MP回復
	HUNGER_CURE, //満腹回復
};

//キャラクターの行えるアクション
typedef enum eACTION {
	ACTION_MOVE,	  //移動処理
	ACTION_GET_ITEM,  //アイテムを拾う
	ACTION_EQIOP,	  //アイテムを装備
	ACTION_DROP_ITEM, //アイテムを捨てる
	ACTION_USE_ITEM,  //アイテムを捨てる
	ACTION_PROVE,	  //鑑定するアイテムを選択
	ACTION_GAMEOVER,  //ゲームオーバー
	ACTION_STEP,	  //階段移動確認

	ACTION_MAX,		  //ACTIONの最大値
};

#pragma endregion

#pragma region メッセージについての定数

//メッセージの種類
enum eMESTYPE
{
	MESTYPE_INFO					// 情報
	, MESTYPE_ATTACK					// ダメージ系
	, MESTYPE_SELECT					// 選択肢
	, MESTYPE_NEGATIVE				// ネガティブな状態
};

// メッセージバッファ
typedef struct tagMESDATA
{
	eMESTYPE	type;
	char		*pLine;
}MESDATA;

#pragma endregion
