#pragma once

#include<string>
#include<vector>
#include<cstdlib>
#include<fstream>

class Convenient_Function {
public:
	//CSVファイルの','をデリミタとして改行する為の関数
	std::vector<std::string> Split(const std::string & str, const std::string & delim);
};