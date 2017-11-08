#include"Game_Cui.h"

//コンストラクタ
Game_Cui::Game_Cui() { 
	tile_judge = new Tile_Judge;
	tile_down = new Tile_Judge;
	tile_function = new Tile_Function;
	wall_function = new Wall_Function;

	dungeon01->Make(&player, floor);
}

//デストラクタ
Game_Cui::~Game_Cui() {
	delete tile_function;
	delete wall_function;

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
	//プレイヤーの座標を取得
	player.Get_Position(&mx, &my);

	//プレイヤーの位置を画面の中央へ
	cx = static_cast<int>(HALF_WINDOW_X) - ACTOR_SIZE_X / 2; //頂点の関係で位置を少しずらす
	cy = static_cast<int>(HALF_WINDOW_Y) - ACTOR_SIZE_Y / 2; //同上
	//床の描画

		//ダンジョンの大さを測る(y軸)
	for (y = 0; y < dungeon_base->height - 1; ++y) {
		dy = y * 90 - cy; //タイルの縦幅分、縦のタイル同士で距離を取る

		//画面外は無視
		if (dy < -ACTOR_SIZE_Y || dy > WINDOW_Y) {
			continue;
		}

		//ダンジョンの大さを測る(x軸)
		for (x = 0; x < dungeon_base->width - 1; ++x) {
			dx = x * 90 - cx; //タイルの横幅分、横のタイル同士で距離を取る

			//画面外は無視
			if (dx < -ACTOR_SIZE_X || dx > WINDOW_X) {
				continue;
			}
			//タイルの情報を取得
			tile_judge = dungeon_base->Get_Tile(x, y);

			//壁かどうか
			if (tile_judge->is_wall) { //TODO: たまに例外を吐く 乱数の関係か
				//壁の画像を表示する
				tile_down = dungeon_base->Get_Tile(x, y + 1);
				//下に壁がないとき(かど)の壁を描画
				if (tile_down && tile_down->is_wall == false) {
					wall_function->Draw_Wall(CORNER_WALL_GRASS, dx, dy); //Define定数使用
				}
				//それ以外の普通の壁を描画
				else {
					wall_function->Draw_Wall(WALL_GRASS, dx, dy); //Define定数使用
				}
				continue; //壁であるなら配置するものがないのでループに戻る
			}

			//昇り階段か
			if (tile_judge->is_up_stairs) {
				tile_function->Draw_Tile(UP_STAIRS, dx, dy); //Define定数使用
			}
			//下り階段か
			else if (tile_judge->is_down_stairs) {
				tile_function->Draw_Tile(DOWN_STAIRS, dx, dy); //Define定数使用
			}

			////アイテムが落ちているか
			//else if (tile_judge->is_drop_item) {
			//	//アイテム画像挿入
			//}

			//それ以外は床
			else {
				tile_function->Draw_Tile(TILE_GRASS, dx, dy); //Define定数使用

				//TODO:設定している画面外は壁を挿入
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
