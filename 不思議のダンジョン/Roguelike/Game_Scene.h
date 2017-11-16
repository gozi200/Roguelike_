#pragma once

#include"Game.h"
#include"Game_Gui.h"
#include"Tile_Data.h"
#include"Scene_Manager.h"

#include<string>

class Game_Scene: public Scene {
public:
	Game_Gui* game = nullptr;

	Tile_Data Tile_data;

	Game_Scene(Scene_Manager* Manager);

	~Game_Scene() {
		delete game; //ゲーム削除
	};

	int result; //実行結果

	void Update();

	void Render();
};