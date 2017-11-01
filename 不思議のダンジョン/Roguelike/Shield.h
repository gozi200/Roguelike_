#pragma once

#include"Item.h"

class Shield : public Item {
public:
	int attack; //‘f‚ÌUŒ‚—Í ‚±‚ê‚É‹­‰»’l‚ğ‚È‚ñ‚ç‚©‚ÌŒ`‚ÅŒvZ‚·‚é

	Shield();

	~Shield();

	void Update();

	void Arrange(Vector2D position);
};