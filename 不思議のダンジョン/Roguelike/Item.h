#pragma once

#include"Object.h"

//------------------------
//Object���p��

//�A�C�e�����Ǘ�����N���X
//------------------------

//TODO: Equipment(�����i)�N���X��tool�N���X�ŕ�����H

enum ITEMTYPE {
	ITEMTYPE_NONE = 0,		     //�Ȃ�
	ITEMTYPE_USEITEM = (1<<1),   //���Օi
	ITEMTYPE_WEAPON = (1<<2),    //����
	ITEMTYPE_SHIELD = (1<<3),    //�c
	ITEMTYPE_ACCESSORIE = (1<<4),//�����i
};

enum USEITEM_CATEGORY {
	HP_CURE, //HP�� 
	MP_CURE, //MP��
};

class Item : public Object {
public:
	ITEMTYPE type;
	char* Unidentifid_Name; //���Ӓ莞�̖��O //TODO: �ЂƂ܂��͂�����

	//�R�s�[
	void Copy(Item *po); //po���ĉ�

	//�폜
	void Erase();
};