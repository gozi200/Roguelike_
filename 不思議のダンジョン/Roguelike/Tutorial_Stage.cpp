#include"Tutorial_Stage.h"
#include"Actor_Factory.h"
#include"DxLib.h"
#include"Result.h"

#include"Vector2D.h"
void Tutorial_Stage::Update() {
	if (CheckHitKey(KEY_INPUT_T)) {
		manager->scene = new Result(manager);
		delete this;

		//プレイヤーのインスタンス化(例)
		Actor_Factory* actor_factory = new Actor_Factory();
		Vector2D vec;
		vec.x = 0;
		vec.y = 0;
		actor_factory->Create_Actor("player");
		delete actor_factory;
		//////

	}
}

void Tutorial_Stage::Render() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "ゲーム画面");
	DrawFormatString(WINDOW_X / 2, WINDOW_Y / 2, GetColor(255, 255, 255), "Tキーを押してください");
}