#include "Game_Scene.h"

Game_Scene::Game_Scene() {
}

Game_Scene::~Game_Scene() {

}

void Game_Scene::Update() {

}

void Game_Scene::Render() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�Q�[�����");
	DrawFormatString(WINDOW_X - 300, 300, GetColor(255, 255, 255), "DELETE�������ƏI��");
}
