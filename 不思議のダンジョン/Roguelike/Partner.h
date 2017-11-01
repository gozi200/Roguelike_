#pragma once

#include"Ally.h"
#include"Vector2D.h"

/*////////////////////////
Actorクラスを継承

パートナーを管理するクラス
///////////////////////*/

class Partner : public Ally {
private:
	enum State{};

public:
	//コンストラクタ
	Partner();

	//デストラクタ
	~Partner() {};
};