#include"Set_File.h"

// コンストラクタ
Set_File::Set_File() {

}

// デストラクタ
Set_File::~Set_File() {

}

// 開くファイルのパスを指定する
std::string Set_File::Set_File_Pass(std::string file_pass, const std::string & open_file_pass) {
	file_pass = open_file_pass;
	
	return file_pass;
}