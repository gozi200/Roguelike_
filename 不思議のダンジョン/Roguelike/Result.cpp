#include"Result.h"
#include"Title.h"

void Result::Update() {
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		manager->scene = new Title(manager);
		delete this;
	}
}

void Result::Render() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "リザルト画面");
	DrawFormatString(WINDOW_X / 2, WINDOW_Y / 2, GetColor(255, 255, 255), "↓を押すとタイトルへ");
}