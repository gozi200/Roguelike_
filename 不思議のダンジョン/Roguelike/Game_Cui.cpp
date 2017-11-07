#include"Game_Cui.h"

//TODO: マジックナンバー

//コンストラクタ
Game_Cui::Game_Cui() {
	tile_judge = new Tile_Judge;
	tile_down = new Tile_Judge;
	tile_function = new Tile_Function;
}

//デストラクタ
Game_Cui::~Game_Cui() {
	delete tile_function;
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

//初めに描画を行う //p202
void Game_Cui::Render() {

	//プレイヤーの座標を取得
	player.Get_Position(&mx, &my);

	//プレイヤーの位置を画面の中央へ
	cx = HALF_WINDOW_X;
	cy = HALF_WINDOW_Y;

	//床の描画
	for (y = 0; y < dungeon_base->height - 1; ++y) { //ダンジョンの大きさ分の行を作る
		dy = y * 32 - cy;

		//画面外は無視
		if (dy <= 16 || dy >= WINDOW_Y) {
			continue;
		}

		dy += 120;

		for (x = 0; x < dungeon_base->width - 1; ++x) {
			dx = x * 32 - cx;

			//画面外は無視
			if (dx <= -16 || dx >= WINDOW_X) {
				continue;
			}

			//タイルの情報を取得
			tile_judge = dungeon_base->Get_Tile(x, y);

			//壁かどうか
			if (tile_judge->is_wall) { //TODO: たまに例外を吐く 乱数の関係か
				//壁の画像を表示する
				tile_down = dungeon_base->Get_Tile(x, y + 1);
				if (tile_down && tile_down->is_wall == false) {
					//下が床の時の壁の画像
				}
				else {
					//下が壁の時の壁の画像
				}
			continue; //壁であるなら配置するものがないのでループに戻る
			}

		//昇り階段か
			if (tile_judge->is_up_stairs) {
				tile_function->Draw_Tile(UP_STAIRS); //Define定数使用

			}
			//下り階段か
			else if (tile_judge->is_down_stairs) {
				tile_function->Draw_Tile(DOWN_STAIRS); //Define定数使用
			}

			////アイテムが落ちているか
			//else if (tile_judge->is_drop_item) {
			//	//アイテム画像挿入
			//}

			//それ以外はステージに合った壁を表示
			else {
				tile_function->Draw_Tile(TILE_GRASS); //Define定数使用

				//設定している画面外は壁を挿入
			}
		}
	}
}

	////その座標のエネミー情報を取得
	//enemy = (Enemy_Manager*)dungeon_base->Get_Point_Enemy(x, y);
	//
	//else if (enemy) {
	//	//敵を挿入
	//}
	////プレイヤーがいるか
	//if (mx == x && my == y) {
	//	//プレイヤーを挿入
	//}
