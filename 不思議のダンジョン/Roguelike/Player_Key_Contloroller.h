#pragma once

/*/////////////////////////////////
プレイヤーのキー操作を管理するクラス
////////////////////////////////*/

class Player_Key_Controller {
public:
	int x; //移動軸 横
	int y; //移動軸 縦

	bool Player_Move_Up(); //操作キャラクターを上へ動かす
	bool Player_Move_Right(); //操作キャラクターを右へ動かす
	bool Player_Move_Down(); //操作キャラクターを下へ動かす
	bool Player_Move_Left(); //操作キャラクターを左へ動かす

	bool Attack(); //操作キャラクターを攻撃させる

	bool Projectile_Weapon(); //飛び道具の意 矢などの使用
};