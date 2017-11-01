#pragma once

#include"Scene_Manager.h"
#include"Actor_Manager.h"
#include"Define.h"

/*/////////////////////////
Sceneクラスを継承　　　　　　

チュートリアルステージ
////////////////////////*/

class Tutorial_Stage : public Scene {
public:
	char key[KEY_NUMBER]; //Define定数使用

	Actor_Manager* actor_manager;

	Tutorial_Stage(Scene_Manager* Manager) : Scene(Manager) {
		actor_manager = new Actor_Manager(key);
	};

	~Tutorial_Stage() {
		delete actor_manager;
	};

	void Update();

	void Render();
};