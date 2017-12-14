#include "Ally.h"

// コンストラクタ
Ally::Ally() {

}

// デストラクタ
Ally::~Ally() {

}

int Ally::Get_Max_Power() {
	int max_pow;

	//力の基本値を代入
	max_pow = max_power;

	// TODO: アイテムを装備していたら

	return max_pow;
}

int Ally::Get_Max_NP() {
	int np;

	//基本最大HPを代入
	np = max_noble_phantasm;

	// TODO: アイテムを装備していたら

	return np;
}

int Ally::Variation_NP(int value) {
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

int Ally::Variation_Power(int value) {
	int old = power;
	power += value;

	if (Get_Max_Power() < power) {
		power = Get_Max_Power();
	}
	else if (power < 0) {
		power = 0;
	}

	// 効果値を返す
	return power - old;
}

int Ally::Get_EXP_Level() {
	int Lv;

	for (Lv = 0; Lv < MAX_LEVEL; Lv++)
	{
		if (EXP_DATA[Lv] > Get_Experience_Point(0))
			break;
	}

	return Lv + 1;
}

int Ally::Get_Level(int set_level)
{
	//現在のレベルを代入
	level = set_level;

	return level;
}

void Ally::Add_Experience_Point(int add_EXP) {
	Get_Experience_Point(add_EXP);
	// カンスト処理
	if (Get_Experience_Point(0) > MAX_EXP) {
		Get_Experience_Point(MAX_EXP);
	}

	// SEND

	// レベルアップ？
	if(EXP_DATA[level -1] <= Get_Experience_Point(0)) {
		int new_Lv = Get_EXP_Level();

		// 一度で何個か分あがっても大丈夫なように、上がった分処理を行う
		for (; level < new_Lv; ++level) {
			int add_hp;
			int add_atk;
			int add_def;
			int add_agi;

			// SEND

			// MaxHPをランダム(3~5）で増やす
			add_hp = random.Dungeon_Random(3) + 3;
			// 増加分、最大HPを増加
			Get_Max_HP(add_hp);

			// 攻撃力をランダム(3~5)で増やす
			add_atk = random.Dungeon_Random(3) + 3;
			Get_Attack(add_atk);

			// 防御力をランダム(3~5)で増やす
			add_def = random.Dungeon_Random(3) + 3;
			Get_Defence(add_def);
		}
	}
}

int Ally::Get_Experience_Point(int set_EXP) {
	// 獲得経験値を代入
	experience_point += set_EXP;

	return experience_point;
}