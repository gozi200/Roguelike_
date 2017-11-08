#include"DxLib.h"
#include"Title.h"
#include"Define.h"
#include"Scene_Manager.h"


//キーの入力状態を更新する
int Update_Key(char* key) {
	char tmpKey[KEY_NUMBER]; //現在のキーの入力状態を収納

	//全てのキーの入力状態を得る
	GetHitKeyStateAll(tmpKey);

	for (int i = 0; i < KEY_NUMBER; ++i) {
		if (tmpKey[i] != 0) { //i番目のキーが押されていたら加算
			++key[i];
		}
		else { //押されていなければ0を代入
			key[i] = 0;
		}
	}
	return 0;
}

//ここがfalseならループを抜けゲーム終了
bool Process(char key[KEY_NUMBER]) { //Defnie定数使用
	if (ScreenFlip()) return false; //裏画面と入れ替える
	if (ProcessMessage()) return false; //windowからの生存確認を自動で行う
	if (ClearDrawScreen()) return false; //現在いる画面の裏画面を消去
	if (GetHitKeyStateAll(key)) return false; //キーボードの入力を取得

	return true;
}

//Win32なのでmainはWINAPIから
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(true); //ウィンドウモードに変換
	SetGraphMode(WINDOW_X, WINDOW_Y, 32); //画面の大きさと使用する色情報　//Define定数使用
	if (DxLib_Init() == -1) return -1; //DXライブラリ初期化 エラーが起きたらただちに終了
	SetWindowText("不思議のダンジョン"); //ウィンドウタイトル
	SetDrawScreen(DX_SCREEN_BACK); //処理中に裏画面を描画

	char key[KEY_NUMBER]; //キー取得 Define定数使用

/*////////////////////
クラスのインスタンス化
*/////////////////////
	Scene_Manager* scene_manager; //管理システムを動的確保
	scene_manager = new Scene_Manager(key);
	scene_manager->scene = new Title(scene_manager); //タイトルを動的確保

	while (ProcessMessage() != -1) {
		ScreenFlip();
		ClearDrawScreen();

		//ゲームループ(始)
		scene_manager->Render(); //毎フレーム呼び出し
		scene_manager->Update(); //毎フレーム呼び出し

		int start_time = GetNowCount();
		int endTime = GetNowCount();
		WaitTimer(1000 / 60 - (endTime - start_time)); //60FPS

		if (CheckHitKey(KEY_INPUT_DELETE) == 1) break;
	}
	fclose(stdout);
	delete scene_manager; //クラスの解放

	DxLib_End(); //DXライブラリ使用の終了処理

	return 0; //ソフトの終了
}