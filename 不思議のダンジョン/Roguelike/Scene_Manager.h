#pragma once
#include"DxLib.h" 
#include"Define.h"

class Scene_Manager;

/*///////////////////////
Scene‚ğŠÇ—‚·‚éƒNƒ‰ƒX
//////////////////////*/

class Scene {
protected:
	Scene_Manager* manager;

public:
	Scene(Scene_Manager*pManager) {
		manager = pManager;
	}

	virtual ~Scene() {}

	virtual void Update() {}

	virtual void Render() {}
};

class Scene_Manager {
	char* key;
public:
	Scene* scene;

	Scene_Manager(char* pKey) {
		key = pKey;
	}

	~Scene_Manager() {
		delete scene;
	}

	char* GetKey() {
		return key;
	}

	void Update() {
		scene->Update();
	}

	void Render() {
		scene->Render();
	}
};