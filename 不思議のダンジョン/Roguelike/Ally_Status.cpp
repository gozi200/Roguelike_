#include"Ally_Status.h"

Ally_Status::Ally_Status() {
	Weapon wepon;

	Shield shield;

	Accessorie accessorie;
}

Ally_Status::~Ally_Status() {

}

void Ally_Status::Set_Position(int set_x, int set_y) {

}

void Ally_Status::Get_Position(int * px, int * py, DIRECTION * dir)
{
}

//void Ally_Status::Set_Parameter(Enemy_Database* set_record, Item* set_drop_item) {
//
//}

int Ally_Status::Get_Hit_Point(int set_hit_point) {
	return 0;
}

int Ally_Status::Get_Magic_Point(int set_magic_point) {
	return 0;
}

int Ally_Status::Get_Hunger_Point() {
	return 0;
}

int Ally_Status::Get_Max_Hit_Point() {
	return 0;
}

int Ally_Status::Get_Max_Magic_Point() {
	return 0;
}

int Ally_Status::Add_Experience_Point(int set_experience_point) {
	return 0;
}

int Ally_Status::Add_Hunger_Point(int set_hunger_point) {
	return 0;
}

int Ally_Status::Get_Attack() {
	return 0;
}

int Ally_Status::Get_Defence() {
	return 0;
}

int Ally_Status::Get_Activity() {
	return 0;
}

void Ally_Status::Turn() {

}

void Ally_Status::Set_Equipment(Item* set_eqipment) {

}

bool Ally_Status::Get_Item(Item* set_tool) {
	return true;
}

Item* Ally_Status::Get_Item_Flom_Index(Item_Type* set_filter, int set_index) {
	return 0;
}

bool Ally_Status::Is_Dead() {
	return true;
}