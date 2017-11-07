#include"DxLib.h"
#include"Result.h"
#include"Game_Scene.h"

Game_Scene::Game_Scene(Scene_Manager * Manager) : Scene(Manager) {
	game = new Game_Cui();	
}

void Game_Scene::Update() {
	result = game->Run(); //���s

	if (CheckHitKey(KEY_INPUT_R)) {
		manager->scene = new Result(manager);
		delete this;
	}
}

void Game_Scene::Render() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�Q�[�����");
	DrawFormatString(WINDOW_X - 300,WINDOW_Y - 300, GetColor(255, 255, 255), "R�������ƃ��U���g��");
}