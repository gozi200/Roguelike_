#include"Convenient_Function.h"

std::vector<std::string> Convenient_Function::Split(const std::string & str, const std::string & delim) {
	std::vector<std::string> ret;

	std::string::size_type pos = 0;

	while (pos != std::string::npos) {
		std::string::size_type p = str.find(delim, pos);
		if (p == std::string::npos) {
			ret.push_back(str.substr(pos));
			break;
		}
		else {
			ret.push_back(str.substr(pos, p - pos));
		}
		
		pos = p + delim.size();
	}

	return ret;
}








//	std::vector<std::string> ret;
//
//	auto beginPos = begin(str);
//	auto endPos = begin(str) + str.find(delim);
//
//	while (endPos != end(str)) {
//		auto beginIndex = std::distance(begin(str), beginPos);
//		auto strSize = std::distance(beginPos, endPos);
//
//		ret.push_back(str.substr(beginIndex, strSize));
//
//		beginPos = endPos + delim.size();
//		auto p = str.find(delim, beginIndex + strSize + delim.size() + 1);
//		if (p == std::string::npos) {
//			endPos = end(str) - 1;
//		}
//		endPos = begin(str) + p;
//	}
//
//	return ret;
//}