#include"DxLib.h"
#include"Define.h"
#include"Actor.h"

#include"Wait_State.h"



Actor::Actor()/* : state(nullptr)*/ {
//	Change_State(new Wait_State(this));
//}
//
//
//
//void Actor::Update() {
//	state->
}

void Actor::Render_Charactor() { //いる？
//	if (is_exist) {
//		DrawExtendGraph(x, y, x + 300, y + 300, graphic_handle, TRUE);
//	}
}

#pragma region State_Paturn

bool Actor::isWait() {
	//if(stateがWaitのとき){}
	return false;
}

bool Actor::isAttack() {
	return false;
}

#pragma endregion
