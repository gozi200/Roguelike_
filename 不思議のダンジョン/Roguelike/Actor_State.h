#pragma once

/*/////////////////////////////
Actor�̏�Ԃ��Ǘ�������N���X
//////////////////////*////////

class Actor_State {
public:
	virtual ~Actor_State() {};

	virtual void Update() = 0;
};