#include "Player.h"

// コンストラクタ
Player::Player() {
	set = std::make_shared<Set_File>();
	player_graphic  = std::make_shared<Player_Graphic>();
	dungeon_manager = std::make_shared<Dungeon_Manager>();

	spawn_point_x = 0;
	spawn_point_y = 0;
	loop_counter  = 0;

	player_graphic->Load(); // 画像データを読み込む

	Set_Parametor();
}

// デストラクタ
Player::~Player() {
	
}

void Player::Player_Set_Position() {
	dungeon_manager->Random_Room_Point(
		random.Dungeon_Random(dungeon_manager->rectangle_count),
		&spawn_point_x,
		&spawn_point_y);

	Set_Position(spawn_point_x, spawn_point_y);
}

void Player::Set_Parametor() {
	Player_Set_Position();

	auto ifs = std::ifstream();
	ifs.open(set->Set_File_Pass(file_pass, "csv/Actor/Player/Player.csv")); // csvファイルの場所を与え呼び出す

	std::string line;
	std::getline(ifs, line); // csvファイルの使わない行を読み飛ばす
	std::getline(ifs, line); // 同上
	ifs.clear();             // 読み飛ばしたデータを破棄する

	// それぞれの要素にCSVデータと画像データを読み込む
	while (!std::getline(ifs, line).eof()) {
		PLAYER_DATA player_data;

		auto values = Split::Split_(line, ","); // ','で区切って読み込む

		player_data.ID                 = std::stoi(values[0]);  // ID
		player_data.name               = values[1];			    // 名前
		player_data.calss              = std::stoi(values[2]);  // クラス
		player_data.level              = std::stoi(values[3]);  // レベル
		player_data.attack             = std::stoi(values[4]);  // 攻撃力
		player_data.defence            = std::stoi(values[5]);  // 防御力
		player_data.hit_point          = std::stoi(values[6]);  // 体力
		player_data.max_hit_point      = std::stoi(values[7]);  // 体力の最大値
		player_data.activity           = std::stoi(values[8]);  // 行動力(1ターンに動ける回数)
		player_data.experience_point   = std::stoi(values[9]);  // 経験値
		player_data.turn_count         = std::stoi(values[10]); // 経過ターン
		player_data.power              = std::stoi(values[11]); // 力(攻撃力へのボーナス)
		player_data.max_power          = std::stoi(values[12]); // 力の最大値
		player_data.hunger_point       = std::stoi(values[13]); // 満腹度
		player_data.command_card       = std::stoi(values[14]); // コマンドカード枚数
		player_data.arts_card          = std::stoi(values[15]); // アーツカードの枚数
		player_data.quick_card         = std::stoi(values[16]); // クイックカードの枚数
		player_data.budter_card        = std::stoi(values[17]); // バスターカードの枚数
		player_data.star               = std::stoi(values[18]); // クリティカルスター保持数
		player_data.star_occur         = std::stoi(values[19]); // スター発生率
		player_data.noble_phantasm     = std::stoi(values[20]); // 宝具を撃つためのポイント
		player_data.max_noble_phantasm = std::stoi(values[21]); // 宝具を撃つためのポイントの最大値
		player_data.width              = std::stoi(values[22]); // 画像の幅
		player_data.height             = std::stoi(values[23]); // 画像の高さ

		// 画像のパスを格納
		auto graphic_handle = LoadGraph(player_graphic->graphics[loop_counter++]);
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

int Player::Get_Hunger_Percent() {
	return (hunger_point * 100) / FILL_HUNGER_POINT;
}

// ターンの終了
void Player::Turn_End() {
	Get_Turn_Count(1);

	//TODO: 現在の最大HPに比例して回復量を上げる。現状は５ターンに１回復
	if (Get_Turn_Count(0) % 5 == 0) {
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
