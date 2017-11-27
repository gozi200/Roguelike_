#pragma once

#include<string>
#include<vector>
#include<cstdlib>
#include<fstream>

class Split {
public:
	//CSVファイルの','をデリミタとして改行する為の関数
	static std::vector<std::string> Split_(const std::string & str, const std::string & delim);
};