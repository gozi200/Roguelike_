#pragma once

#include"Object.h"
#include"Define.h"
#include"Actor_State.h"

/*////////////////////////
Objectを継承

Actor全体を管理するクラス
////////////////////////*/

class Actor : public Object {
/*////////
メンバ変数
*////////
protected:
	int level;

	int hit_point;

	int state; //現在の状態

	int attack; //素の攻撃力 これに武器の攻撃力を反映

	int defense; //素の防御力 これに防具の防御力を反映

	int Energy; //１ターンに行動できる数

	int Speed; //1ターンに移動できる数

	int change_state;

	char* name;

public:

/*////////
メンバ関数
*/////////
public:
	//コンストラクタ
	Actor();
	
	//デストラクタ
	~Actor() {};

	void Render_Charactor(); //いる？

	void Change_State();

#pragma region State_Paturn

	bool isWait();
	bool isAttack();

#pragma endregion
};