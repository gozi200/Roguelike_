#include"Split.h"

//デリミタを設定する
std::vector<std::string> Split::Split_(const std::string & str, const std::string & delim) {
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