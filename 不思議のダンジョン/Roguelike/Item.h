#pragma once

#include"Object.h"

//------------------------
//Objectを継承

//アイテムを管理するクラス
//------------------------

//TODO: Equipment(装備品)クラスとtoolクラスで分ける？

enum ITEMTYPE {
	ITEMTYPE_NONE = 0,		     //なし
	ITEMTYPE_USEITEM = (1<<1),   //消耗品
	ITEMTYPE_WEAPON = (1<<2),    //武器
	ITEMTYPE_SHIELD = (1<<3),    //縦
	ITEMTYPE_ACCESSORIE = (1<<4),//装飾品
};

enum USEITEM_CATEGORY {
	HP_CURE, //HP回復 
	MP_CURE, //MP回復
};

class Item : public Object {
public:
	ITEMTYPE type;
};