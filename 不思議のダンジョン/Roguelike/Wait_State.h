#pragma once

#include"Actor_State.h"
#include"Actor.h"

class Wait_State : public Actor_State {

public:						   //Actor�ɍs���p�^�[������������
	Actor* actor;

	Wait_State(Actor* owner) : actor(owner) {
		//�ҋ@��Ԃ̏��������
	}

	~Wait_State() {
		//�ҋ@��Ԃ̏I������
	}
						//FPS�����܂��Ă����炢��Ȃ�
	virtual void Update(/*float time*/) override {
		
		//�ҋ@��Ԃ̎���
		
		if (actor->isWait()){}
	}

private:
//	Actor* actor; //��Ԃ̏��L��
};