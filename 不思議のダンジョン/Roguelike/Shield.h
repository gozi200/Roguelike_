#pragma once

#include"Item.h"

class Shield : public Item {
public:
	int attack; //�f�̍U���� ����ɋ����l���Ȃ�炩�̌`�Ōv�Z����

	Shield();

	~Shield();

	void Update();

	void Arrange(Vector2D position);
};