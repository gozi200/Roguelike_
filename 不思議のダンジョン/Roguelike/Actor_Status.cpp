#include"Actor_Status.h"

Actor_Status::Actor_Status() {
	Weapon wepon;

	Shield shield;

	Accessorie accessorie;
}

Actor_Status::~Actor_Status() {

}

void Actor_Status::Set_Position(int set_x, int set_y) {

}

void Actor_Status::Get_Position(int * px, int * py, DIRECTION * dir)
{
}

void Actor_Status::Set_Parameter(SETTING_ENEMY_DATA* set_record, Item* set_drop_item) {
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

int Actor_Status::Get_Max_Hit_Point() {
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
	int set_atk;
	
	//��{�U���͂���
	set_atk = attack;
	return set_atk;
}

int Actor_Status::Get_Defence() {
	int set_def;

	//��{�h��͂���
	set_def = defence;

	return set_def;
}

int Actor_Status::Get_Activity() {
	int set_activity;

	//�s���͂���
	set_activity = activity;

	return set_activity;
}

void Actor_Status::Turn() { //NEXT
	++turn_count;
}

void Actor_Status::Set_Equipment(Item* set_eqipment) {

}

bool Actor_Status::Get_Item(Item* set_tool) {
	return true;
}

Item* Actor_Status::Get_Item_Flom_Index(Item_Type* set_filter, int set_index) {
	return 0;
}

bool Actor_Status::Is_Dead() { 
	return true;
}