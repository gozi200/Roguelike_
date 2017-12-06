#pragma once
#include"Define.h"

/*------------------------
アイテムを管理するクラス
------------------------*/

class Item {
public:
	eITEM_TYPE type; //アイテム種類
	char* name;				//名前
	char* unidentifid_name; //未鑑定時の名前
	int parameter[2];		//TODO: ひとまずはこの値で
	char sz_name[15];		//名前バッファ
	bool unidentified;		// 未鑑定なら true
	
	Item* next;				 //リンクリスト(?)

	//アイテム名を取得
	char* Get_Name();

	//コピー
	void Copy(Item *po); //poって何

	//削除
	void Erase();
};