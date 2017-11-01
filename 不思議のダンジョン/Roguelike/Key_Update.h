#pragma once

#include"Define.h"

class Key_Update {
public:
/*////////
メンバ変数
/*////////
	char* key;

	char temporary_key[KEY_NUMBER]; //ここにキーの入力状態を格納する

/*////////
メンバ関数
*/////////
	int Get_Key(char* key);
};