#pragma once

#include"Scene_Manager.h"

/*///////////////////////
Scene�N���X���p��

���U���g��ʂ��Ǘ�
///////////////////////*/

class Result : public Scene {
public:
	Result(Scene_Manager* pManager) :Scene(pManager) {};

	~Result() {};

	void Update();
	void Render();
};