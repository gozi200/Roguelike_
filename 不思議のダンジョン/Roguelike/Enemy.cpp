#include"Enemy.h"
#include"Dungeon_Base.h"

#include<math.h>

Enemy::Enemy() {
}

Enemy::~Enemy() {
}

//ターン数を進める
int Enemy::Turn(Dungeon_Base* dungeon_base, int count) {
	next_count -= count;

	if (next_count <= 0) {
		next_count += actor_status.activity;
		Move(dungeon_base);
	}

	//次の行動ターン数を返す(0以下なら継続して行動可能)
	return next_count;
}


bool Enemy::Move_Action(Dungeon_Base* dungeon_base, int mx, int my) {
	int x, y;

	//現在の座標を取得
	Get_Position(&x, &y);

	//移動先が壁であれば何もしない
	if (dungeon_base->Check_Move(x, y, mx, my) == false) {
		return false;
	}

	//プレイヤーの座標を取得
	dungeon_base->player->Get_Position(&x, &y);

	//移動先にプレイヤーがいるかどうか
	if (x == mx && y == my) {
		int damage;

		//プレイヤーに攻撃する
		damage = dungeon_base->Attack(this, dungeon_base->player);

		//文字の表示　SEND

		//主人公が死んだか
		if (dungeon_base->player->actor_status.Is_Dead()) {
			//文字の表示　SEND
		}
	}

	else {
		//その場所にモンスターがいないか
		if (dungeon_base->Get_Point_Enemy(mx, my)) {
			//モンスターもいないので移動する
			Set_Position(mx, my);
			return true;
		}

		else {/*モンスターがいるので何もしない*/ }
	}
	return false;
}

int Enemy::Reset()
{
	actor_status.turn_count = 0;
	return actor_status.turn_count;
}


void Enemy::Render(int set_graphic_handle, int set_x, int set_y) {//NEXT
	DrawExtendGraph(
		set_x,
		set_y,
		set_x + actor_status.width,
		set_y + actor_status.height,
		set_graphic_handle, TRUE);
	//エネミーの描画
}