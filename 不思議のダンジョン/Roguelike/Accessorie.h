#pragma once

#include"Item.h"

/*

*/

class Accessorie : public Item {
public:
	int attack; //�f�̍U���� ����ɋ����l���Ȃ�炩�̌`�Ōv�Z����

	Accessorie();

	~Accessorie();

	void Update();

	void Arrange(Vector2D position);
};