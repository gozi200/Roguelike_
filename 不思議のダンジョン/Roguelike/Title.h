#pragma once

#include"Scene_Manager.h"

/*///////////////////////
Scene�N���X���p��

�^�C�g����ʂ��Ǘ�
///////////////////////*/

class Title : public Scene {
public:
	Title(Scene_Manager* pManager) :Scene(pManager) {};

	~Title() {};

	void Update();
	void Render();
};