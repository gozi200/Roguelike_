#pragma once
#include"Define.h"

/*------------------------
�A�C�e�����Ǘ�����N���X
------------------------*/

class Item {
public:
	eITEM_TYPE type; //�A�C�e�����
	char* name;				//���O
	char* unidentifid_name; //���Ӓ莞�̖��O
	int parameter[2];		//TODO: �ЂƂ܂��͂��̒l��
	char sz_name[15];		//���O�o�b�t�@
	bool unidentified;		// ���Ӓ�Ȃ� true
	
	Item* next;				 //�����N���X�g(?)

	//�A�C�e�������擾
	char* Get_Name();

	//�R�s�[
	void Copy(Item *po); //po���ĉ�

	//�폜
	void Erase();
};