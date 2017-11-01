#pragma once

#include"Actor.h"

/*////////////////////////
Actorクラスを継承

自機、味方を管理するクラス
*////////////////////////

class Ally : public  Actor {
/*////////
メンバ変数
*/////////

protected:
	int experiece_point; //経験値


/*////////
メンバ関数
*/////////
public:
	//体力ゲージの描画
	void Render_Hit_Point(); 

	//経験値ゲージの描画
	void Render_Experiece_Point();
};