#pragma once

/*------------------------
�A�C�e�����Ǘ�����N���X
------------------------*/
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
	HUNGRY_CURE, //������
};

class Item {
public:
	ITEMTYPE type; //�A�C�e�����
	char* name;    //���O
	char* Unidentifid_Name; //���Ӓ莞�̖��O
	int param[2]; //TODO: �ЂƂ܂��͂��̒l��
	char sz_name[15]; //���O�o�b�t�@
	
	Item* next; //�����N���X�g�H

	//�A�C�e�������擾
	char* Get_Name();

	//�R�s�[
	void Copy(Item *po); //po���ĉ�

	//�폜
	void Erase();
};