#pragma once

/*------------------------------
読み込むcsvファイルを設定するクラス
------------------------------*/

#include"DxLib.h"

#include<string>

class Set_File {
/*---------
メンバ変数
----------*/
public:

/*---------
メンバ関数
----------*/
public:
	// コンストラクタ
	Set_File();

	// デストラクタ
	~Set_File();

	/*開くファイルのパスを指定
	　@param open_file_pass 開くファイルを指定
	*/
	std::string Set_File_Pass(std::string file_pass, const std::string& open_file_pass);
};