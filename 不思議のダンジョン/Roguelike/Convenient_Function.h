#pragma once

#include<string>
#include<vector>
#include<cstdlib>
#include<fstream>

class Convenient_Function {
public:
	//CSV�t�@�C����','���f���~�^�Ƃ��ĉ��s����ׂ̊֐�
	static std::vector<std::string> Split(const std::string & str, const std::string & delim);
};