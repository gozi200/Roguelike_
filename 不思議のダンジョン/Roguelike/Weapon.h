#pragma once

#include"Item.h"

class Weapon : public Item {
public:
	int attack; //�f�̍U���� ����ɋ����l���Ȃ�炩�̌`�Ōv�Z����

	Weapon();

	~Weapon();

	void Update();

	void Arrange(Vector2D position);
};