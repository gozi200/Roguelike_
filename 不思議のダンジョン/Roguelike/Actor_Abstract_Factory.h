#pragma once

#include"Vector2D.h"

#include<string>

/*///////////////////////
アクター工場の基底クラス
*////////////////////////

class Actor_Abstract_Factory {
public:
	//仮想デストラクタ
	virtual ~Actor_Abstract_Factory() {}

	//アクターの生成(仮想関数)
	virtual Actor* Create_Actor(const std::string& name) = 0;
};