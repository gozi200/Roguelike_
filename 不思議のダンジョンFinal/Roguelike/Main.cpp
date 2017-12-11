#include"DxLib.h"
#include"Define.h"

#include"Game_Scene.h" // TODO: ひとまずは直接ゲームシーンへ

// キーの入力状態を更新する
static int Update_Key(char* key) {
	char tmpKey[KEY_NUMBER]; // 現在のキーの入力状態を収納

	 // 全てのキーの入力状態を得る
	GetHitKeyStateAll(tmpKey);

	for (int i = 0; i < KEY_NUMBER; ++i) {
		if (tmpKey[i] != 0) { // i番目のキーが押されていたら加算
			++key[i];
		}
		else { // 押されていなければ0を代入
			key[i] = 0;
		}
	}
	return 0;
}

// ここがfalseならループを抜けゲーム終了
bool Process(char key[KEY_NUMBER]) { // Defnie定数使用
	if (ScreenFlip()) return false;           // 裏画面と入れ替える
	if (ProcessMessage()) return false;       // windowからの生存確認を自動で行う
	if (ClearDrawScreen()) return false;      // 現在いる画面の裏画面を消去
	if (GetHitKeyStateAll(key)) return false; // キーボードの入力を取得

	return true;
}

// Win32なのでmainはWINAPIから
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(true);               // ウィンドウモードに変換
	SetGraphMode(WINDOW_X, WINDOW_Y, 32); // 画面の大きさと使用する色情報　//Define定数使用
	if (DxLib_Init() == -1) return -1;    // DXライブラリ初期化 エラーが起きたらただちに終了
	SetWindowText("不思議のダンジョン");    // ウィンドウタイトル
	SetDrawScreen(DX_SCREEN_BACK);        // 処理中に裏画面を描画

	char key[KEY_NUMBER]; // キー取得 Define定数使用

	// シーンをインスタンス化---------
	Game_Scene* game_scene;
	game_scene = new Game_Scene();
	// -------------------------------

	while (ProcessMessage() != -1) {
		ScreenFlip();
		ClearDrawScreen();

		// 更新をかけ、新しい状況を描画する
		game_scene->Update();
		game_scene->Render();
		// -----------------------------

		int start_time = GetNowCount();
		int endTime = GetNowCount();
		WaitTimer(1000 / 60 - (endTime - start_time)); // 60FPS

		if (CheckHitKey(KEY_INPUT_DELETE) == 1) break;
	}
	fclose(stdout);

	delete game_scene; //解放

	DxLib_End(); // DXライブラリ使用の終了処理

	return 0; // ソフトの終了
}

////プレイヤーのインスタンス化(例)
//Actor_Factory* actor_factory = new Actor_Factory();
//Vector2D vec;
//vec.x = 0;
//vec.y = 0;
//actor_factory->Create_Actor("player");
//delete actor_factory;


/*
メモ: Dungeon_Base = Dungeon_Manager
	  Game         = Create_Dungeon

*/


/*-----------------------
製作開始日時 2017/12/08
-----------------------*/