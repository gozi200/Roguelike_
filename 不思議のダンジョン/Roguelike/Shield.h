#pragma once

#include"Item.h"

class Shield : public Item {
public:
	int attack; //素の攻撃力 これに強化値をなんらかの形で計算する

	Shield();

	~Shield();

	void Update();

	void Arrange(Vector2D position);
};