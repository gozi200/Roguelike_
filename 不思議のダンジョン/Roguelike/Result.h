#pragma once

#include"Scene_Manager.h"

/*///////////////////////
Sceneクラスを継承

リザルト画面を管理
///////////////////////*/

class Result : public Scene {
public:
	Result(Scene_Manager* pManager) :Scene(pManager) {};

	~Result() {};

	void Update();
	void Render();
};