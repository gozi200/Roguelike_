#include"Player_Data.h"

Player_Data::Player_Data(const std::string & openFilePath) : file_pass(openFilePath) {

	auto ifs = std::ifstream();
	ifs.open(file_pass);

	if (!ifs.is_open()) {
		return;
	}

	std::string line;

	while (std::getline(ifs, line)) {
		auto values = Convenient_Function::Split(line, ",");

		player_data.ID = std::stoi(values[0]);
		player_data.name = values[1];
		player_data.x = std::stoi(values[2]);
		player_data.y = std::stoi(values[3]);
		player_data.width = std::stoi(values[4]);
		player_data.height = std::stoi(values[5]);
		player_data.level = std::stoi(values[6]);
		player_data.hit_point = std::stoi(values[7]);
		player_data.noble_phantasm = std::stoi(values[8]);
		player_data.hunger_point = std::stoi(values[9]);
		player_data.experience_point = std::stoi(values[10]);
		player_data.attack = std::stoi(values[11]);
		player_data.defence = std::stoi(values[12]);
		player_data.power = std::stoi(values[13]);
		player_data.activity = std::stoi(values[14]);
		player_data.turn_point = std::stoi(values[15]);
		//load
		player_data.graphic_handle = std::stoi(values[16]);
	
	}

}