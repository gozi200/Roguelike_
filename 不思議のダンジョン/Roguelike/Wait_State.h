#pragma once

#include"Actor_State.h"
#include"Actor.h"

class Wait_State : public Actor_State {

public:						   //Actorに行動パターンを書き込む
	Actor* actor;

	Wait_State(Actor* owner) : actor(owner) {
		//待機状態の初期化状態
	}

	~Wait_State() {
		//待機状態の終了処理
	}
						//FPSが決まっていたらいらない
	virtual void Update(/*float time*/) override {
		
		//待機状態の実装
		
		if (actor->isWait()){}
	}

private:
//	Actor* actor; //状態の所有者
};