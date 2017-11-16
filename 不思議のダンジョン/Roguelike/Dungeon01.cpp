#include"Dungeon01.h"

Dungeon01::Dungeon01() : Dungeon_Base() {
	random = Random();
}

Dungeon01::~Dungeon01() {

}

void Dungeon01::Make(Player* set_player, int set_floor) {
	rectangle_count = 0; //区画の数をリセット

	player = set_player;

	//初期化(一旦すべて壁にする)
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			Get_Tile(x, y)->is_wall = true;
		}
	}

	//区画を作る
	//初めに全体を１つの区画とする
	Create_Rectangle(0, 0, width - 1, height - 1);

	//↑で定めた区画を細分化していく
	Split_Rectangle(random.Dungeon_Random(2) ? true : false);

	//部屋を作る
	Create_Room();

	//部屋同士をつなげる
	Connect_Room();

	//各部屋にエネミーを配置
	//Enemy_Array(floor);
}

DUNEON_RECTANGLE* Dungeon01::Create_Rectangle(int set_left, int set_top, int set_right, int set_bottom) {
	DUNEON_RECTANGLE* new_rectangle;

	new_rectangle = &dungeon_rectangle[rectangle_count];

	ZeroMemory(new_rectangle, sizeof(DUNEON_RECTANGLE));

	SetRect(&new_rectangle->rect, set_left, set_top, set_right, set_bottom);

	++rectangle_count;

	return new_rectangle;
}

void Dungeon01::Split_Rectangle(bool set_is_vertical) {
	DUNEON_RECTANGLE* parent;
	DUNEON_RECTANGLE* child;
	RECT* rectangle;

	//分ける区画情報を取得
	parent = &dungeon_rectangle[rectangle_count - 1];
	rectangle = &parent->rect;

	//分割する
	if (!set_is_vertical) {
		//横に分割--------------------------------------------------------------------------

		//区分を分割できるか確認
		if (RECTANGLE_WIDTH(*rectangle) < (MIN_ROOM_SIZE + 3) * 2 + 1) {
			return; //分割できないときは終了
		}

		int a, b, ab, p;
		//左端のA点を求める
		a = MIN_ROOM_SIZE + 3;

		//右端のB点を求める
		b = RECTANGLE_WIDTH(*rectangle) - MIN_ROOM_SIZE - 4;

		//a,b間の距離を求める
		ab = b - a;

		//a,b間のどこかに決定する
		p = a + random.Dungeon_Random(ab + 1);

		//新しく右の区画を作成する
		child = Create_Rectangle(
			rectangle->left + p,
			rectangle->top,
			rectangle->right,
			rectangle->bottom);

		//元の区画の右をp地点に移動させて、左側の区画にする
		parent->rect.right = child->rect.left;

		//--------------------------------------------------------------------------------------
	}

	else {
		//縦に分割する

		//区分を分割できるかチェック
		if (RECTANGLE_HEIGHT(*rectangle) < (MIN_ROOM_SIZE + 3) * 2 + 1) {
			//分割できないときは終了
			return;
		}
		int a, b, ab, p;

		a = MIN_ROOM_SIZE + 3;
		b = RECTANGLE_HEIGHT(*rectangle) - MIN_ROOM_SIZE - 4;
		ab = b - a;

		p = a + random.Dungeon_Random(ab + 1);

		//新しく区画を作成する
		child = Create_Rectangle(
			rectangle->left,
			rectangle->top + p,
			rectangle->right,
			rectangle->bottom);

		//元の区画の下をp地点に移動させて、上の区画とする
		parent->rect.bottom = child->rect.top;
	}

	//次の分割をランダムで決定するために入れ替える
	if (random.Dungeon_Random(2)) {
		DUNEON_RECTANGLE dungeon_rectangle;
		dungeon_rectangle = *child;
		*child = *parent;
		*parent = dungeon_rectangle;
	}

	//childの部屋をさらに分割する
	Split_Rectangle(!set_is_vertical);
}

void Dungeon01::Create_Room() {
	int w, h, cw, ch, sw, sh, rw, rh, rx, ry; //TODO: 名前をつける w = width, h = height, x = 横座標, y = 縦座標か 

	for (int i = 0; i < rectangle_count; ++i) {
		RECT* rectangle = &dungeon_rectangle[i].rect; //区画情報
		RECT* room = &dungeon_rectangle[i].room; //↓で作る部屋情報

		//矩形の大きさを計算
		w = RECTANGLE_WIDTH(*rectangle) - 3;
		h = RECTANGLE_HEIGHT(*rectangle) - 3;

		//区画に入る最小部屋の余裕を求める
		cw = w - MIN_ROOM_SIZE;
		ch = h - MIN_ROOM_SIZE;

		//部屋の大きさを決定する
		sw = random.Dungeon_Random(cw);
		sh = random.Dungeon_Random(ch);
		rw = w - sw;
		rh = h - sh;

		//部屋の位置を決定する
		rx = random.Dungeon_Random(sw) + 2;
		ry = random.Dungeon_Random(sh) + 2;

		//求めた結果から部屋の情報を設定
		room->left = rectangle->left + rx;
		room->top = rectangle->top + ry;
		room->right = room->left + rw;
		room->bottom = room->top + rh;

		//部屋を作る
		Fill_Rectangle( //ダンジョンの大きさ(width,heightの外に取ってしまっている。)
			room->left,
			room->top,
			room->right,
			room->bottom, false);

		//１つ目の部屋なら適当な位置に階段を設置
		if (i == 0) {
			int x, y;
			Random_Room_Point(i, &x, &y);
			Get_Tile(x, y)->is_up_stairs = true;
			up_stairs_x = x;
			up_stairs_y = y;
		}

		if (i == rectangle_count - 1) {
			int x, y;
			Random_Room_Point(i, &x, &y);
			Get_Tile(x, y)->is_down_stairs = true;
			down_stairs_x = x;
			down_stairs_y = y;
		}
	}
}

void Dungeon01::Connect_Room() {
	for (int i = 0; i < rectangle_count - 1; ++i) {
		Create_Road(i, i + 1);
	}
}

void Dungeon01::Create_Road(int set_room_A, int set_room_B) {
	RECT* rect_A, *rect_B; //マクロ使用
	RECT* room_A, *room_B; //マクロ使用

	rect_A = &dungeon_rectangle[set_room_A].rect;
	rect_B = &dungeon_rectangle[set_room_B].rect;
	room_A = &dungeon_rectangle[set_room_A].room;
	room_B = &dungeon_rectangle[set_room_B].room;

	/*////////////////////////////////////////////////////////////////
	区画同士が、上下か左右のどちらでつながっているかで処理を分け、道をつなぐ
	///////////////////////////////////////////////////////////////*/

	//上下で繋がっているかの確認
	if (rect_A->bottom == rect_B->top || rect_A->top == rect_B->bottom) {
		int x1, x2, y;

		x1 = random.Dungeon_Random(RECTANGLE_WIDTH(*room_A)) + room_A->left;
		x2 = random.Dungeon_Random(RECTANGLE_WIDTH(*room_B)) + room_B->left;

		if (rect_A->top > rect_B->top) {
			/* B
			   A
			   の並びの時
			*/
			y = rect_A->top;
			//AB間の横道を繋ぐ道を作る
			Fill_Rectangle(x1, y + 1, x1 + 1 , room_A->top, false);
			Fill_Rectangle(x2, room_B->bottom, x2 + 1, y, false);
		}

		else {
			/* A
			   B
			   の並びの時
			*/
			y = rect_B->top;
			//AB間の横道を繋ぐ道を作る
			Fill_Rectangle(x1, room_A->bottom, x1 + 1, y, false);
			Fill_Rectangle(x2, y, x2 + 1, room_B->top, false);
		}

		//道同士を繋げる横道を作る
		Fill_H_Line(x1, x2, y, false);
	}

	//左右でつながっているか
	else if (rect_A->right == rect_B->left || rect_A->left == rect_B->right) {
		int y1, y2, x;

		y1 = random.Dungeon_Random(room_A->bottom - room_A->top) + room_A->top;
		y2 = random.Dungeon_Random(room_B->bottom - room_B->top) + room_B->top;

		if (rect_A->left > rect_B->left) {
			/*BA
			  の並びのとき
			*/
			x = rect_A->left;
			//AB間の縦道を繋ぐ道を作る
			Fill_Rectangle(room_B->right, y2, x, y2 + 1, false);
			Fill_Rectangle(x + 1, y1, room_A->left, y1 + 1, false);
		}

		else {
			/*AB
			  の並びの時
			*/
			x = rect_B->left;
			//AB間の縦道を繋ぐ道を作る
			Fill_Rectangle(room_A->right, y1, x, y1 + 1, false);
			Fill_Rectangle(x, y2, room_B->left, y2 + 1, false);
		}

		//道同士を繋げる縦道を作る
		Fill_V_Line(y1, y2, x, false);
	}
}
