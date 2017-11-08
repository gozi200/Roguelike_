#pragma once

#include"DxLib.h"

/*//////////////////////////
様々な定数を既定しておくクラス
//////////////////////////*/

#pragma region 画面サイズ

const int WINDOW_X = 1170; //画面サイズ(横) 

const int WINDOW_Y = 720; //画面サイズ(縦)

#pragma endregion

#pragma region 計算に使う定数

const double PI = 3.14159265358979323846; //円周率

#pragma endregion

#pragma region アクターに関する定数
const int ACTOR_SIZE_X = 90; //キャラクターのサイズ(横)

const int ACTOR_SIZE_Y = 90; //キャラうたーのサイズ(縦)

const int ENERGY = 1; //１ターンに行動できる数

const int ALLY_NUMBER = 2; //味方が同時に出現できる数

const int MAX_ACTOR = 35; //Actorが同時に出現できる数

const int ACTOR_MOVEMENT = 5; //1マス分の移動量 ひとまず

const int COLLISION = 20; //いうならばキャラの大きさ　ひとまず

const int MAX_ENEMY = 500; //エネミーの量 ひとまず

#pragma endregion


#pragma region アイテムに関する定数

const int ITEM_MAX = 500; //アイテムが同時に出現できる数　ひとまず

#pragma endregion


#pragma region ダンジョンに関する定数
//とりあえずはここに

const int DUNGEON_WIDTH = 50; //ダンジョンの横マスの数

const int DUNGEON_HEIGHT = 50; //ダンジョンの縦マスの数

const int RECTANGLE = 100; //ひとまずの値 矩形、長方形

const int MAX_RECTANGLE = 10; //区画の最大値

const int MIN_ROOM_SIZE = 4; //最小の部屋のサイズ

#pragma endregion

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

#pragma region 各要素の呼び出し用ID

#pragma region 床のID

const int UP_STAIRS = 1;

const int DOWN_STAIRS = 2;

const int TILE_GRASS = 3;

const int TILE_CAVE = 4;

#pragma endregion


#pragma region 壁のID

const int WALL_GRASS = 1;
const int CORNER_WALL_GRASS = 2;

const int WALL_CAVE = 3;
const int CORNER_WALL_CAVE = 4;

#pragma endregion


#pragma endregion

#pragma region ゲームの設定に関する定数

const int MAX_SCORE = 1000000;

const int TILE_NUMBER = 2; //床の種類(草原、洞窟など) TODO: とりあえず

#pragma endregion

#pragma region その他

const int KEY_NUMBER = 256; //全てのキー

const float HALF_WINDOW_X = WINDOW_X / 2;

const float HALF_WINDOW_Y = WINDOW_Y / 2;

typedef enum DIRECTION {
	DIRECTION_NONE, //向き無し
	DIRECTION_DOWN, //下向き(正面)
	DIRECTION_UP, //上向き(背面)
	DIRECTION_LEFT, //左向き
	DIRECTION_RIGHT, //右向き
	DIRECTION_UPLEFT, //左上
	DIRECTION_UPRIGHT, //右上
	DIRECTION_DOWNLEFT, //左下
	DIRECTION_DOWNRIGHT, //左上
};

#pragma endregion
