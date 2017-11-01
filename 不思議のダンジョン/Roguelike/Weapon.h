#pragma once

#include"Item.h"

class Weapon : public Item {
public:
	int attack; //‘f‚ÌUŒ‚—Í ‚±‚ê‚É‹­‰»’l‚ğ‚È‚ñ‚ç‚©‚ÌŒ`‚ÅŒvZ‚·‚é

	Weapon();

	~Weapon();

	void Update();

	void Arrange(Vector2D position);
};