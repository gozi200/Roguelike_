#include"Game_Gui.h"

//コンストラクタ
Game_Gui::Game_Gui() {
	tile_function = new Tile_Function;
	wall_function = new Wall_Function; 
	dungeon01->Make(&player, floor);
}

//デストラクタ
Game_Gui::~Game_Gui() {
	delete tile_function;
	delete wall_function;
}

int Game_Gui::Run() {
	//ゲームの初期化
	Game::Init();

	//初めに描画を行う
	Render();

	//ゲームシーンにいる間はサイクルを回し続ける
	while (Game::Cycle());

	return 0;
}

//コンソールの初期化
void Game_Gui::Console_Init() {

}

//初めに描画を行う
void Game_Gui::Render() {
	//プレイヤーの座標を取得
	player.Get_Position(&mx, &my);

	//プレイヤーの位置を画面の中央へ
	cx = static_cast<int>(DUNGEON_WIDTH / 2) - ACTOR_SIZE_X / 2; //頂点の関係で位置を少しずらす
	cy = static_cast<int>(DUNGEON_HEIGHT / 2) - ACTOR_SIZE_Y / 2 + 35; //同上


	//--------------
	//地面の描画
	//--------------

	//ダンジョンの大さを測る(y軸)
	for (y = 0; y < dungeon_base->height; ++y) {
		dy = y * TILE_SIZE - cy; //タイルの縦幅分、縦のタイル同士で距離を取る

		//画面外は無視
		if (dy <= -TILE_SIZE / 2 || dy >= WINDOW_Y) {
			continue;
		}

		//ダンジョンの大さを測る(x軸)
		for (x = 0; x < dungeon_base->width; ++x) {
			dx = x * TILE_SIZE - cx; //タイルの横幅分、横のタイル同士で距離を取る
			const Tile_Judge *tile_judge;

			//画面外は無視
			if (dx <= -TILE_SIZE / 2 || dx >= WINDOW_X) {
				continue;
			}

			//タイルの情報を取得
			tile_judge = dungeon_base->Get_Tile(x, y);

			//壁かどうか
			if (tile_judge->is_wall) { //TODO: たまに例外を吐く 乱数の関係か
				const Tile_Judge *tile_down = dungeon_base->Get_Tile(x, y + 1);

				//下に壁がないときは、かど用の壁を描画
				if (tile_down && tile_down->is_wall == false) {
					wall_function->Draw_Wall(CORNER_WALL_GRASS, dx, dy); //Define定数使用
				}

				//それ以外の普通の壁を描画
				else {
					wall_function->Draw_Wall(WALL_GRASS, dx, dy); //Define定数使用
				}
				continue; //壁であるなら配置するものがないのでループに戻る
			}
			else {
				int a = 0;
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

	//-----------------
	//アクターの描画
	//-----------------

	for (y = 0; y < dungeon_base->height; ++y) {
		dy = y * TILE_SIZE - cy;

		//画面外は無視
		if (dy <= -TILE_SIZE / 2 || dy >= WINDOW_Y) {
			continue;
		}

		dy += 120;

		for (x = 0; x < dungeon_base->width; ++x) {
			const Tile_Judge *tile_judge;
			Enemy *enemy;

			dx = x * TILE_SIZE - cx;

			//画面外は無視
			if (dx <= -TILE_SIZE / 2 || dx >= WINDOW_X) {
				continue;
			}

			//タイル情報を取得	
			tile_judge = dungeon01->Get_Tile(x, y);

			//プレイヤーがいるか
			if (mx == x && my == y) {
				//プレイヤーを挿入
			}

			//その座標のエネミー情報を取得
			enemy = (Enemy_Manager*)dungeon_base->Get_Point_Enemy(x, y);

			if (enemy) {
				//敵を挿入
			}
		}
	}
}



