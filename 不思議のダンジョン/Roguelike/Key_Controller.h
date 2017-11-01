#pragma once

/*//////////////////////////
キー操作を管理するクラス
/////////////////////////*/

class Key_Controller {
public:
	int x; //移動軸 横
	int y; //移動軸 縦

	bool Cursor_Move_Up(); //カーソルを上へ動かす
	bool Cursor_Move_Right(); //カーソルを右へ動かす
	bool Cursor_Move_Down(); //カーソルを下へ動かす
	bool Cursor_Move_Left(); //カーソルを左へ動かす

	bool Open_Menu(); //メニューを開く

	bool Decide(); //カーソルのあるところを選択する
};