#include"Actor_Status.h"

Actor_Status::Actor_Status() {

}

Actor_Status::~Actor_Status() {

}

void Actor_Status::Set_Position(int set_x, int set_y) {
	x = set_x;
	y = set_y;
}

void Actor_Status::Get_Position(int * px, int * py, eDIRECTION * dir) {
	if (px)
		*px = x;
	if (py)
		*py = y;
}

void Actor_Status::Set_Parameter(SETTING_ENEMY_DATA* set_record, Item* p_drop_item) {
	//�v���C���[�Ƌ��ʂ��Ă��镨�̂݁H
	ID				 = set_record->ID;				 //�i���o�[
	name			 = set_record->name;			 //���O
	x				 = set_record->x;				 //���̍��W
	y				 = set_record->y;				 //�c�̍��W

	level			 = set_record->level;			 //���x��
	power			 = set_record->power;			 //������ (�f�̍U���́B�����ɕ���̍U���́A���x���ŕϓ�����U���͂��v�Z)
	paturn			 = set_record->paturn;			 //�s���p�^�[��
	attack			 = set_record->attack;			 //�U����
	defence			 = set_record->defence;			 //�h���
	agility			 = set_record->agility;			 //�q����(�����ł͉��)
	activity		 = set_record->activity;		 //�s����(�����ł͂P�^�[���ɍs���ł��鐔)
	evolution		 = set_record->evolution;		 //�i���`��
	hit_point		 = set_record->hit_point;		 //�̗�(�O�ɂȂ�Ǝ��S)
	drop_item		 = set_record->drop_item;		 //���S���Ɋm���ŗ��Ƃ��A�C�e��
	turn_count		 = set_record->turn_count;		 //�o�߃^�[�����J�E���g
	first_floor		 = set_record->first_floor;		 //�o���J�n�K�w
	last_floor		 = set_record->last_floor;		 //�o���I���K�w
	drop_item_ID	 = set_record->drop_item_ID;	 //���S���Ɋm���ŗ��Ƃ��A�C�e����ID
	graphic_handle	 = set_record->graphic_handle;	 //�摜�n���h��
	experience_point = set_record->experience_point; //�o���l(�����ł͓|���ꂽ�Ƃ��ɑ���ɗ^����l)

	width			 = set_record->width;			 //�摜���\������镝
	height			 = set_record->height;			 //�摜���\������鍂��

	if (p_drop_item)
		drop_item.Copy(p_drop_item);
}

int Actor_Status::Get_Hit_Point(int set_hit_point) {
	return 0;
}

int Actor_Status::Get_Magic_Point(int set_magic_point) {
	return 0;
}

int Actor_Status::Get_Hunger_Point() {
	return 0;
}

int Actor_Status::Cure_Hit_Point(int value) {
	int old = hit_point;

	hit_point += value;
	if (Get_Max_Hit_Point() < hit_point)
		hit_point = Get_Max_Hit_Point();
	else if (hit_point < 0)
		hit_point = 0;

	// ���ʒl��Ԃ�
	return hit_point - old;
	return 0;
}

int Actor_Status::Get_Max_Hit_Point() {
	int hit_point;

	// ��{�ő�HP����
	hit_point = max_hit_point;

	// �ő�HP�A�b�v�̎w�ւ����Ă���Ή��Z
	if (accessorie.type == ITEM_TYPE_ACCESSORIE && accessorie.parameter[0] == 2)
		hit_point += accessorie.parameter[1];

	return hit_point;
	return 0;
}

int Actor_Status::Get_Max_Magic_Point() {
	return 0;
}

int Actor_Status::Add_Experience_Point(int set_experience_point) {
	return 0;
}

int Actor_Status::Add_Hunger_Point(int set_hunger_point) {
	return 0;
}

int Actor_Status::Get_Attack() {
	int set_attack;

	//��{�U���͂���
	set_attack = attack;

	//����𑕔����Ă���Ή��Z
	if (weapon.type != ITEM_TYPE_NONE) {
		set_attack += weapon.parameter[0];
	}

	//�U���͂̏オ�鑕���i�𑕔����Ă�������Z
	if (accessorie.type == ITEM_TYPE_ACCESSORIE && accessorie.parameter[0] == 0) {
		set_attack += accessorie.parameter[1];
	}

	return set_attack;
}

int Actor_Status::Get_Defence() {
	int set_defence;

	//��{�h��͂���
	set_defence = defence;

	//���𑕔����Ă���Ή��Z
	if (shield.type != ITEM_TYPE_NONE) {
		set_defence += shield.parameter[0];
	}

	//�h��͂̏オ�鑕���i�𑕔����Ă�������Z
	if (accessorie.type == ITEM_TYPE_ACCESSORIE && accessorie.parameter[0] == 1) {
		set_defence += accessorie.parameter[1];
	}

	return set_defence;
}

int Actor_Status::Get_Activity() {
	int set_activity;

	//�s���͂���
	set_activity = activity;

	return set_activity;
}

void Actor_Status::Turn() { //NEXT
	++turn_count;

	//���łɋ󕠂��H
	if (hunger_point >= 0)
	{
		//1�_���[�W�󂯂�
		Cure_Hit_Point(-1);

		// ���S�����H
		if (Is_Dead()) {
			//�����̕\���@SEND
		}

		else {
			// �󕠂���Ȃ��̂� 1�|�C���g�󕠂ɂȂ�
			Add_Hunger_Point(-1);
		}
	}
}


void Actor_Status::Set_Equipment(Item* equipment) {
	if (equipment == NULL) {
		return;
	}

	switch (equipment->type) {
	/*---------
		����
	----------*/
	case ITEM_TYPE_WEAPON: {
		Item tmp; //�����A�C�e�����ꎞ�I�ɕۑ����邽�߂ɒ�`

		tmp = weapon; //���������Ă���A�C�e�����ꎞ�ۑ�

		//�J�o�����瑕�����ɕ���
		weapon.Copy(equipment);

		//�J�o���̃A�C�e�����폜
		equipment->Erase();

		//�ȑO�ɑ������Ă����A�C�e�����J�o���ɕ���
		equipment->Copy(&tmp);

		//�ȑO�������Ă����I�u�W�F�N�g���폜
		tmp.Erase();

		return;
	}

	  /*---------
		  �h��
	  ----------*/
	case ITEM_TYPE_SHIELD: {
		Item tmp; //�����A�C�e�����ꎞ�I�ɕۑ����邽�߂ɒ�`

		tmp = shield; //���������Ă���A�C�e�����ꎞ�ۑ�

		//�J�o�����瑕�����ɕ���
		shield.Copy(equipment);

		//�J�o���̃A�C�e�����폜
		equipment->Erase();

		//�ȑO�ɑ������Ă����A�C�e�����J�o���ɕ���
		equipment->Copy(&tmp);

		//�ȑO�������Ă����I�u�W�F�N�g���폜
		tmp.Erase();

		return;
	}

	  /*---------
		 �����i
	  ----------*/
	case ITEM_TYPE_ACCESSORIE: {
		Item tmp; //�����A�C�e�����ꎞ�I�ɕۑ����邽�߂ɒ�`

		tmp = accessorie; //���������Ă���A�C�e�����ꎞ�ۑ�

		//�J�o�����瑕�����ɕ���
		accessorie.Copy(equipment);

		//�J�o���̃A�C�e�����폜
		equipment->Erase();

		//�ȑO�ɑ������Ă����A�C�e�����J�o���ɕ���
		equipment->Copy(&tmp);

		//�ȑO�������Ă����I�u�W�F�N�g���폜
		tmp.Erase();

		return;
	}
	}
}

bool Actor_Status::Get_Item(Item* item) {
	if (item == NULL) {
		return true;
	}

	//�J�o���ɋ󂢂Ă���X���b�g�����邩���ׂ�
	for (int i = 0; i < MAX_STOCK_ITEM; ++i) {
		Item* slot = &items[i];

		//�󂫃X���b�g�ł�������
		if (slot->type == ITEM_TYPE_NONE) {
			//�A�C�e���Ɏ擾�A�C�e�����R�s�[���ďI��
			slot->Copy(item);
			return false;
		}
	}
	//�󂫂��Ȃ�
	return true;
}

Item* Actor_Status::Get_Item_Flom_Index(eITEM_TYPE filter, int index) {
	if (index < 0) {
		return 0;
	}

	for (int i = 0; i < MAX_STOCK_ITEM; ++i) {
		Item* item = &items[i];

		if (item->type == ITEM_TYPE_NONE) {
			continue;
		}

		//�t�B���^�[�ƈقȂ�΃X�L�b�v
		if (filter != ITEM_TYPE_NONE && (item->type & filter) == 0) {
			continue;
		}

		if (index == 0) {
			return item;
		}
		--index;
	}
	return NULL;
}

bool Actor_Status::Is_Dead() {
	return true;
}