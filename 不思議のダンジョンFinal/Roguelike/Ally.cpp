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

int Ally::Get_Level()
{
	return 0;
}

void Ally::Add_Experience_Point(int add_EXP) {
	experience_point += add_EXP;
	// カンスト処理
	if (experience_point > MAX_EXP)
		experience_point = MAX_EXP;

	// SEND

	// レベルアップ？
	if (EXP_DATA[level - 1] <= experience_point)
	{
		int new_Lv = Get_Level();

		// 一度で何個か分あがっても大丈夫なように、上がった分処理を行う
		for (; level < new_Lv; ++level)
		{
			int add_hp;
			int add_atk;
			int add_def;
			int add_agi;

			// SEND

			// MaxHPをランダム(3~5）で増やす
			add_hp = random.Dungeon_Random(3) + 3;
			// 増加分、最大HPを増加
			max_hit_point += add_hp;

			// 攻撃力をランダム(3~5)で増やす
			add_atk = random.Dungeon_Random(3) + 3;
			attack += add_atk;

			// 防御力をランダム(3~5)で増やす
			add_def = random.Dungeon_Random(3) + 3;
			defence += add_def;
		}
	}
}
