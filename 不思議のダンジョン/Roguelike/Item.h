#pragma once

#include"Object.h"

/*/////////////////////////
Object���p��

�A�C�e�����Ǘ�����N���X
/////////////////////////*/

//TODO: Equipment(�����i)�N���X��tool�N���X�ŕ�����H

class Item : public Object {
protected:
	int NUMBER; //�A�C�e����ID

public:
	//���t���[���Ăяo������������
	virtual void Update() = 0;

	/*�X�|�[�������A�C�e����z�u
	*@param x x���W
	*@param y y���W
	*/
	virtual void Arrange(Vector2D position) = 0;

	void Render(); //����H
};