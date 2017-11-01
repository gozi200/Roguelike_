#include"Title.h"
#include"DxLib.h"
#include"Game_Scene.h"

#include"Ally.h"

void Title::Update() {

	if (CheckHitKey(KEY_INPUT_UP)) {
		manager->scene = new Game_Scene(manager);
		delete this;
	}
}

void Title::Render() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "タイトル画面");
	DrawFormatString(WINDOW_X / 2, WINDOW_Y / 2, GetColor(255, 255, 255), "↑キーを押してください");
}