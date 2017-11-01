#include"DxLib.h"
#include"Key_Update.h"

//キーの入力状態を更新する
int Key_Update::Get_Key(char* set_key) {
	//key = set_key;

//全てのキーの入力状態を得る
	GetHitKeyStateAll(temporary_key);

	for (int i = 0; i < KEY_NUMBER; ++i) {
		if (temporary_key[i] != 0) { //i番目のキーが押されていたら加算
			++set_key[i];
		}
		else { //押されていなければ0に
			set_key[i] = 0;
		}
	}
	return 0;
}