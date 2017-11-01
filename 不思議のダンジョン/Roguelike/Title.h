#pragma once

#include"Scene_Manager.h"

/*///////////////////////
Sceneクラスを継承

タイトル画面を管理
///////////////////////*/

class Title : public Scene {
public:
	Title(Scene_Manager* pManager) :Scene(pManager) {};

	~Title() {};

	void Update();
	void Render();
};