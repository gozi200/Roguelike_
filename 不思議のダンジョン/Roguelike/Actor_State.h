#pragma once

/*/////////////////////////////
Actorの状態を管理する基底クラス
//////////////////////*////////

class Actor_State {
public:
	virtual ~Actor_State() {};

	virtual void Update() = 0;
};