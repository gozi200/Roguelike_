#include"Game_Cui.h"

//コンストラクタ
Game_Cui::Game_Cui() {
	tile_judge = new Tile_Judge;
	tile_function = new Tile_Function;

#pragma region CSVファイルの読み込み

	//床の情報を読み込む
	//Tile_data.Set_File_Pass("CSV/Stage/Tile/Tile.csv");
	//Tile_data.Open_File(); //読み込み
	//壁の情報を読み込む
	//wall_data.Set_File_Pass("CSV/Stage/Wall/Wall.csv");
	//wall_data.Open_File();

#pragma endregion

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
			//壁の画像を表示する
			continue; //壁であるなら配置するものがないのでループに戻る
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
			//床の画像を表示する
			tile_function->Draw_Tile(TILE_GRASS); //Define定数使用

		}
	}
}