#pragma once

#include"Item.h"

class Weapon : public Item {
public:
	int attack; //素の攻撃力 これに強化値をなんらかの形で計算する

	Weapon();

	~Weapon();

	void Update();

	void Arrange(Vector2D position);
};