#pragma once

#include"Item.h"

/*

*/

class Accessorie : public Item {
public:
	int attack; //‘f‚ÌUŒ‚—Í ‚±‚ê‚É‹­‰»’l‚ğ‚È‚ñ‚ç‚©‚ÌŒ`‚ÅŒvZ‚·‚é

	Accessorie();

	~Accessorie();

	void Update();

	void Arrange(Vector2D position);
};