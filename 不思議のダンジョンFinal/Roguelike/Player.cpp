#include "Player.h"

// コンストラクタ
Player::Player() {
	set = std::make_shared<Set_File>();
	player_graphic = std::make_shared<Player_Graphic>();

	player_graphic->Load(); // 画像データを読み込む
	Set_Parametor();        // パラメータのセット
}

// デストラクタ
Player::~Player() {
	
}

void Player::Set_Parametor() {
	auto ifs = std::ifstream();
	ifs.open(set->Set_File_Pass(file_pass, "csv/Actor/Player/Player.csv")); // csvファイルの場所を与え呼び出す

	std::string line;
	std::getline(ifs, line); // csvファイルの使わない行を読み飛ばす
	std::getline(ifs, line); // 同上
	ifs.clear();             // 読み飛ばしたデータを破棄する

	loop_count = 0;

	// それぞれの要素にCSVデータと画像データを読み込む
	while (!std::getline(ifs, line).eof()) {
		PLAYER_DATA player_data;

		auto values = Split::Split_(line, ","); // ','で区切って読み込む

		player_data.ID                 = std::stoi(values[0]);  // ID
		player_data.name               = values[1];			    // 名前
		player_data.level              = std::stoi(values[2]);  // レベル
		player_data.attack             = std::stoi(values[3]);  // 攻撃力
		player_data.defence            = std::stoi(values[4]);  // 防御力
		player_data.hit_point          = std::stoi(values[5]);  // 体力
		player_data.max_hit_point      = std::stoi(values[6]);  // 体力の最大値
		player_data.activity           = std::stoi(values[7]);  // 行動力(1ターンに動ける回数)
		player_data.experience_point   = std::stoi(values[8]);  // 経験値
		player_data.turn_count         = std::stoi(values[9]);  // 経過ターン
		player_data.power              = std::stoi(values[10]); // 力(攻撃力へのボーナス)
		player_data.max_power          = std::stoi(values[11]); // 力の最大値
		player_data.hunger_point       = std::stoi(values[12]); // 満腹度
		player_data.noble_phantasm     = std::stoi(values[13]); // 宝具を撃つためのポイント
		player_data.max_noble_phantasm = std::stoi(values[14]); // 宝具を撃つためのポイントの最大値
		player_data.width              = std::stoi(values[15]); // 画像の幅
		player_data.height             = std::stoi(values[16]); // 画像の高さ

		// 画像のパスを格納
		auto graphic_handle = LoadGraph(player_graphic->graphics[loop_count++]);
		player_data.graphic_handle = graphic_handle;

		player_datas.push_back(player_data); //１行ごとに配列に追加していく
	}
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

//　引数のIDと同じIDの画像を、引数の座標へ描画する
void Player::Render(int call_ID, int x, int y) {
	switch (call_ID) {
		//沖田さん描画
	case OKITA:
		DrawExtendGraph(x,
						y,
						x + player_datas.at(call_ID).width,
						y + player_datas.at(call_ID).height,
						player_datas.at(call_ID).graphic_handle, TRUE);
		break;
	}
}
