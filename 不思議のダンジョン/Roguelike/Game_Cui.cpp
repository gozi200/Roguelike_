#include"Game_Cui.h"

#include<iostream>

//コンストラクタ
Game_Cui::Game_Cui() {
	tile_judge = new Tile_Judge;
	
	//床の情報を読み込む
	tile_data.Set_File_Pass("CSV/Stage/Tile/Tile.csv");
	tile_data.Open_File(); //読み込み
	//壁の情報を読み込む
	wall_data.Set_File_Pass("CSV/Stage/Wall/Wall.csv");
	wall_data.Open_File();
}

//デストラクタ
Game_Cui::~Game_Cui() {

}

int Game_Cui::Run() {
	//ゲームの初期化
	Game::Init();

	//初めに描画を行う
	Render();

	//ゲームシーンにいる間はサイクルを回し続ける
	while (Game::Cycle());

	return 0;
}


//コンソールの初期化
void Game_Cui::Console_Init() {
}

//初めに描画を行う
void Game_Cui::Render() {
	int x, y;
	int mx, my;

	//プレイヤーの座標を取得
	player.Get_Position(&mx, &my);

	for (y = 0; y < dungeon_base->height - 1; ++y) { //ダンジョンの大きさ分の行を作る
		//改行処理
	}

	for (x = 0; x < dungeon_base->width - 1; ++x) {

		Enemy_Manager* enemy;

		//タイルの情報を取得
		tile_judge = dungeon_base->Get_Tile(x, y);

		//壁かどうか
		if (tile_judge->is_wall) { //TODO: たまに例外を吐く 乱数の関係か
			for (std::vector<SETTING_WALL_DATA>::const_iterator setting_wall = wall_data.set_wall_data.cbegin();
				setting_wall != wall_data.set_wall_data.cend();
				++setting_wall) {
				DrawExtendGraph(HALF_WINDOW_X, HALF_WINDOW_X + setting_wall->width,
					HALF_WINDOW_Y, HALF_WINDOW_Y + setting_wall->height,
					setting_wall->graphic_handle, TRUE);

				continue; //壁であるなら配置するものがないのでループに戻る
			}
		}

		//その座標のエネミー情報を取得
		enemy = (Enemy_Manager*)dungeon_base->Get_Point_Enemy(x, y);

		//プレイヤーがいるか
		if (mx == x && my == y) {
			//プレイヤーを挿入
		}

		else if (enemy) {
			//敵を挿入
		}

		//昇り階段か
		else if (tile_judge->is_up_stairs) {
			//昇り階段を挿入
		}
		//下り階段か
		else if (tile_judge->is_down_stairs) {
			//下り階段を挿入
		}

		//それ以外は床を表示
		else {
			for (std::vector<SETTING_TILE_DATA>::const_iterator setting_tile = tile_data.set_tile_data.cbegin();
				setting_tile != tile_data.set_tile_data.cend();
				++setting_tile) {
				DrawExtendGraph(HALF_WINDOW_X, HALF_WINDOW_X + setting_tile->width,
								HALF_WINDOW_Y, HALF_WINDOW_Y + setting_tile->height,
								setting_tile->graphic_handle, TRUE);
			}
		}
	}
}
