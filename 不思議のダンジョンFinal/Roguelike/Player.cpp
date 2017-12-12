#include "Player.h"

// コンストラクタ
Player::Player() {
	set = std::make_shared<Set_File>();
	player_graphic = std::make_shared<Player_Graphic>();

	player_graphic->Load(); // 画像データを読み込む
	Set_Parametor();      // パラメータのセット
}

// デストラクタ
Player::~Player() {
	
}

// 座標のセット
void Player::Set_Position(int set_x, int set_y) {
	x = set_x;
	y = set_y;
}

// 座標の取得
void Player::Get_Position(int * set_x, int * set_y, eDIRECTION *set_direction) {
	if (set_x) {
		*set_x = x;
	}

	if (set_y) {
		*set_y = y;
	}
}

void Player::Set_Parametor() {

}

// HPの増減
int Player::Variation_HP(int value) {
	int old = hit_point;
	hit_point += value;

	if (Get_Max_HP() < hit_point) {
		hit_point = Get_Max_HP();
	}
	else if (hit_point < 0) {
		hit_point = 0;
	}

	// 効果値を返す
	return hit_point - old;
}

// NPの増減
int Player::Variation_NP(int value) {
	int old = noble_phantasm;
	noble_phantasm += value;

	if (Get_Max_NP() < noble_phantasm) {
		noble_phantasm = Get_Max_NP();
	}
	else if (noble_phantasm < 0) {
		noble_phantasm = 0;
	}

	// 効果値を返す
	return noble_phantasm - old;
}

// おなかゲージの増減
void Player::Variation_Hunger_Point(int value) {
	int old = hunger_point;
	hunger_point += value;

	//段階に分けメッセージを表示
	if (hunger_point <= HUNGER_HAZARD) {
		// SEND: 空腹時のメッセ
	}
	// TODO: ２以上の減少には対応できない？
	else if (old < HUNGER_DANGER && hunger_point <= HUNGER_DANGER) {
		// SEND: 空腹メッセ
	}
}

// ターンの終了
void Player::Turn_End() {
	++turn_count;

	//TODO: 現在の最大HPに比例して回復量を上げる。現状は５ターンに１回復
	if (turn_count % 5 == 0) {
		Variation_HP(1);
	}

	// 空腹時の処理
	if (hunger_point <= 0) {
		Variation_HP(-1);

		// 死亡した場合
		if (Is_Dead()) {
			// SEND: 餓死のメッセージ
		}
	}
	else {
		Variation_Hunger_Point(-1);
	}
}

// HPの最大値を取得
int Player::Get_Max_HP() {
	int hp;

	//基本最大HPを代入
	hp = max_hit_point;

	// TODO: アイテムを装備していたら
	
	return hp;
}

// NPの最大値を取得
int Player::Get_Max_NP() {
	int np;

	//基本最大NPを代入
	np = max_noble_phantasm;

	// TODO: アイテムを装備していたら

	return np;
}

// 攻撃力の取得
int Player::Get_Attack() {
	int atk;

	//基本攻撃力を代入
	atk = attack;

	// TODO: 武器を装備していたら
	// TODO: アイテムをを装備していたら
	return atk;
}

int Player::Get_Power() {
	int pow;

	//基本の力の値を代入
	pow = power;

	// TODO: アイテムを装備していたら

	return pow;
}

// 防御力の取得
int Player::Get_Defence() {
	int def;

	// 基本防御力を代入
	def = defence;

	// TODO: 盾を装備していたら
	// TODO: アイテムを装備していたら
	return def;
}

// 回避率の取得
int Player::Get_Agility() {
	int agi;
	
	// 基本回避率を代入
	agi = agility;

	return agi;
}

// 死亡判定の取得
bool Player::Is_Dead() {
	if (hit_point <= 0) {
		hit_point = 0;

		return true;
	}

	return false;
}

// 経験値をを得る
void Player::Add_Experience_Point(int add_experience_point) {
	experience_point += add_experience_point;

	// 最大値に達したら
	if (experience_point > MAX_EXP) {
		experience_point = MAX_EXP;
	}

	// SEND 経験値を得た

	// レベルが上がったか
	if (EXP_DATA[level - 1] <= experience_point) {
		int new_level = Get_Level();

		//一度に２以上あがっても大丈夫なように
		for (; level < new_level; ++level) {
			int add_hp;
			int add_atk;
			int add_def;

			// SEND: レベルがになった

			// 体力の最大値をランダムに(3~5)増やす
			add_hp = random.Dungeon_Random(3) + 3;
			// 最大HPを増加
			max_hit_point += add_hp;

			// 攻撃力をランダムに(3~5)増やす
			add_atk = random.Dungeon_Random(3) + 3;
			// 攻撃力を増加
			attack += add_atk;

			// 防御力をランダムに増やす
			add_def = random.Dungeon_Random(3) + 3;
			defence = add_def;
		}
	}
}

// アイテムの装備
void Player::Set_Equipment(Item * item) {

}

// アイテムの取得。カバンがいっぱいなら true を返す
bool Player::Get_Item(Item * item) {
	return false;
}

// 指定したフィルタで指定したインデックスのアイテムを取得
Item * Player::Get_Item_From_Index(eITEM_TYPE filter, int index) {
	return nullptr;
}

// 空腹率を 0 ~ 100% で返す 
int Player::Get_Hunger_Percent() {
	return hunger_point * 100 / FILL_HUNGER_POINT;
}

// 経験値からレベルを求める
int Player::Get_Level() {
	int lv;

	for (lv = 0; lv < MAX_LEVEL; ++lv) {
		if (EXP_DATA[lv] > experience_point) {
			break;
		}
	}

	return lv + 1;
}
