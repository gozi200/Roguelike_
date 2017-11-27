#pragma once

/*------------------------
アイテムを管理するクラス
------------------------*/
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
	HUNGRY_CURE, //満腹回復
};

class Item {
public:
	ITEMTYPE type; //アイテム種類
	char* name;    //名前
	char* Unidentifid_Name; //未鑑定時の名前
	int param[2]; //TODO: ひとまずはこの値で
	char sz_name[15]; //名前バッファ
	
	Item* next; //リンクリスト？

	//アイテム名を取得
	char* Get_Name();

	//コピー
	void Copy(Item *po); //poって何

	//削除
	void Erase();
};