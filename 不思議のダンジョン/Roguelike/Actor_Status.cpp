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
	//プレイヤーと共通している物のみ？
	ID				 = set_record->ID;				 //ナンバー
	name			 = set_record->name;			 //名前
	x				 = set_record->x;				 //横の座標
	y				 = set_record->y;				 //縦の座標
													 
	level			 = set_record->level;			 //レベル
	power			 = set_record->power;			 //ちから (素の攻撃力。ここに武器の攻撃力、レベルで変動する攻撃力を計算)
	paturn			 = set_record->paturn;			 //行動パターン
	attack			 = set_record->attack;			 //攻撃力
	defence			 = set_record->defence;			 //防御力
	agility			 = set_record->agility;			 //敏捷性(ここでは回避率)
	activity		 = set_record->activity;		 //行動力(ここでは１ターンに行動できる数)
	evolution		 = set_record->evolution;		 //進化形態
	hit_point		 = set_record->hit_point;		 //体力(０になると死亡)
	drop_item		 = set_record->drop_item;		 //死亡時に確率で落とすアイテム
	turn_count		 = set_record->turn_count;		 //経過ターンをカウント
	first_floor		 = set_record->first_floor;		 //出現開始階層
	last_floor		 = set_record->last_floor;		 //出現終了階層
	drop_item_ID	 = set_record->drop_item_ID;	 //死亡時に確率で落とすアイテムのID
	graphic_handle	 = set_record->graphic_handle;	 //画像ハンドル
	experience_point = set_record->experience_point; //経験値(ここでは倒されたときに相手に与える値)
													
	width			 = set_record->width;			 //画像が表示される幅
	height			 = set_record->height;			 //画像が表示される高さ
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
	
	//基本攻撃力を代入
	set_atk = attack;
	return set_atk;
}

int Actor_Status::Get_Defence() {
	int set_def;

	//基本防御力を代入
	set_def = defence;

	return set_def;
}

int Actor_Status::Get_Activity() {
	int set_activity;

	//行動力を代入
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