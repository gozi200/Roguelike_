#include "Dungeon_GUI.h"

// コンストラクタ
Dungeon_GUI::Dungeon_GUI() {
	tile = std::make_shared<Tile>();
	wall = std::make_shared<Wall>();
	player_manager = std::make_shared<Player_Manager>();
	dungeon_manager = new Dungeon_Manager();

	Create_Floor(); //TODO: ダンジョンに移動したとき、階層移動の時に呼ばれるようにする。
	player_manager->Player_Arrange();
}

// デストラクタ
Dungeon_GUI::~Dungeon_GUI() {
	//delete tile;
	//delete wall;
	//delete dungeon_manager;
}

// 描画
void Dungeon_GUI::Render() {
	// TODO:　プレイヤーの座標を取得

	// プレイヤーの位置を画面の中央へ
	character_x = DUNGEON_WIDTH / 2 - 350;
	character_y = DUNGEON_HEIGHT / 2;

	/*---------
	地面の描画
	---------*/
	// ダンジョンの大きさをはかる(縦軸)
	for (y = 0; y < dungeon_manager->height; ++y) {
		dungeon_y = y * TILE_SIZE - character_y;

		// 画面外は無視
		if (dungeon_y <= -TILE_SIZE / 2 || dungeon_y >= WINDOW_Y) {
			continue;
		}

		// ダンジョンの大さを測る(x軸)
		for (x = 0; x < dungeon_manager->width; ++x) {
			const Tile_Judge* tile_judge;

			dungeon_x = x * TILE_SIZE - character_x;

			// 画面は無視
			if (dungeon_x <= -TILE_SIZE / 2 || dungeon_x >= WINDOW_X) {
				continue;
			}

			// 床の情報を取得
			tile_judge = dungeon_manager->Get_Tile(x, y);

			// 壁かどうか
		if (tile_judge->is_wall) {
				const Tile_Judge* tile_down = dungeon_manager->Get_Tile(x, y + 1);

				// 下に壁がないときは。かど用の壁を描画
				if (tile_down && tile_down->is_wall == false) {
					wall->Render(CORNER_WALL_GRASS, dungeon_x, dungeon_y); // Define定数使用
				}
				// それ以外は普通の壁を使用
				else {
					wall->Render(WALL_GRASS, dungeon_x, dungeon_y); // Define定数使用
				}
				continue; //壁であるなら配置するものがないのでループに戻る
			}

			// 昇り階段か
			if (tile_judge->is_upstairs) {
				tile->Render(UP_STAIRS, dungeon_x, dungeon_y); // Define定数使用
			}
			//// 下り階段か
			//else if (tile_judge->is_downstairs) {
			//	tile->Render(DOWN_STAIRS, dungeon_x, dungeon_y); 現状では下り階段はいらない
			//}
			//それ以外は床
			else {
				tile->Render(TILE_GRASS, dungeon_x, dungeon_y);
			}
			// TODO: 画面外は暗黒ではなく壁を挿入
		}
	}
}