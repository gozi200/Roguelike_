#pragma once

#include<string>
#include<vector>
#include<cstdlib>
#include<fstream>

class Split {
public:
	//CSV�t�@�C����','���f���~�^�Ƃ��ĉ��s����ׂ̊֐�
	static std::vector<std::string> Split_(const std::string & str, const std::string & delim);
};