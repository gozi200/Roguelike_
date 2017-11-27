#include"Partner_Data.h"

Partner_Data::Partner_Data(const std::string & openFilePath) : file_pass(openFilePath) {
	
	auto ifs = std::ifstream();
	ifs.open(file_pass);

	if (!ifs.is_open()) {
		return;
	}

	std::string line;

	while (std::getline(ifs, line)) {
		auto values = Split::Split_(line, ",");

		partner_data.ID = std::stoi(values[0]);
		partner_data.name = values[1];
		partner_data.x = std::stoi(values[2]);
		partner_data.y = std::stoi(values[3]);
		partner_data.width = std::stoi(values[4]);
		partner_data.height = std::stoi(values[5]);
		partner_data.level = std::stoi(values[6]);
		partner_data.hit_point = std::stoi(values[7]);
		partner_data.noble_phantasm = std::stoi(values[8]);
		partner_data.experience_point = std::stoi(values[10]);
		partner_data.attack = std::stoi(values[11]);
		partner_data.defence = std::stoi(values[12]);
		partner_data.power = std::stoi(values[13]);
		partner_data.activity = std::stoi(values[14]);
		//load
		partner_data.graphic_handle = std::stoi(values[16]);
		partner_data.graphic_handle_pass = const_cast <char*>(values[17].c_str());

		Load_Graph();
	}

}

Partner_Data::Partner_Data() {
	
}

void Partner_Data::Load_Graph() {
	partner_data.graphic_handle = LoadGraph(partner_data.graphic_handle_pass);

}