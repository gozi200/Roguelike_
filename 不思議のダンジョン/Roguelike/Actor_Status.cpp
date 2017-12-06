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

	// 効果値を返す
	return hit_point - old;
	return 0;
}

int Actor_Status::Get_Max_Hit_Point() {
	int hit_point;

	// 基本最大HPを代入
	hit_point = max_hit_point;

	// 最大HPアップの指輪をしていれば加算
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

	//基本攻撃力を代入
	set_attack = attack;

	//武器を装備していれば加算
	if (weapon.type != ITEM_TYPE_NONE) {
		set_attack += weapon.parameter[0];
	}

	//攻撃力の上がる装飾品を装備していたら加算
	if (accessorie.type == ITEM_TYPE_ACCESSORIE && accessorie.parameter[0] == 0) {
		set_attack += accessorie.parameter[1];
	}

	return set_attack;
}

int Actor_Status::Get_Defence() {
	int set_defence;

	//基本防御力を代入
	set_defence = defence;

	//盾を装備していれば加算
	if (shield.type != ITEM_TYPE_NONE) {
		set_defence += shield.parameter[0];
	}

	//防御力の上がる装飾品を装備していたら加算
	if (accessorie.type == ITEM_TYPE_ACCESSORIE && accessorie.parameter[0] == 1) {
		set_defence += accessorie.parameter[1];
	}

	return set_defence;
}

int Actor_Status::Get_Activity() {
	int set_activity;

	//行動力を代入
	set_activity = activity;

	return set_activity;
}

void Actor_Status::Turn() { //NEXT
	++turn_count;

	//すでに空腹か？
	if (hunger_point >= 0)
	{
		//1ダメージ受ける
		Cure_Hit_Point(-1);

		// 死亡した？
		if (Is_Dead()) {
			//文字の表示　SEND
		}

		else {
			// 空腹じゃないので 1ポイント空腹になる
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
		武器
	----------*/
	case ITEM_TYPE_WEAPON: {
		Item tmp; //装備アイテムを一時的に保存するために定義

		tmp = weapon; //今装備しているアイテムを一時保存

		//カバンから装備欄に複製
		weapon.Copy(equipment);

		//カバンのアイテムを削除
		equipment->Erase();

		//以前に装備していたアイテムをカバンに複製
		equipment->Copy(&tmp);

		//以前装備していたオブジェクトを削除
		tmp.Erase();

		return;
	}

	  /*---------
		  防具
	  ----------*/
	case ITEM_TYPE_SHIELD: {
		Item tmp; //装備アイテムを一時的に保存するために定義

		tmp = shield; //今装備しているアイテムを一時保存

		//カバンから装備欄に複製
		shield.Copy(equipment);

		//カバンのアイテムを削除
		equipment->Erase();

		//以前に装備していたアイテムをカバンに複製
		equipment->Copy(&tmp);

		//以前装備していたオブジェクトを削除
		tmp.Erase();

		return;
	}

	  /*---------
		 装飾品
	  ----------*/
	case ITEM_TYPE_ACCESSORIE: {
		Item tmp; //装備アイテムを一時的に保存するために定義

		tmp = accessorie; //今装備しているアイテムを一時保存

		//カバンから装備欄に複製
		accessorie.Copy(equipment);

		//カバンのアイテムを削除
		equipment->Erase();

		//以前に装備していたアイテムをカバンに複製
		equipment->Copy(&tmp);

		//以前装備していたオブジェクトを削除
		tmp.Erase();

		return;
	}
	}
}

bool Actor_Status::Get_Item(Item* item) {
	if (item == NULL) {
		return true;
	}

	//カバンに空いているスロットがあるか調べる
	for (int i = 0; i < MAX_STOCK_ITEM; ++i) {
		Item* slot = &items[i];

		//空きスロットであったら
		if (slot->type == ITEM_TYPE_NONE) {
			//アイテムに取得アイテムをコピーして終了
			slot->Copy(item);
			return false;
		}
	}
	//空きがない
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

		//フィルターと異なればスキップ
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