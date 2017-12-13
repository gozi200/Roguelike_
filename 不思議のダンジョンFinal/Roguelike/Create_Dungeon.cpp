#include "Create_Dungeon.h"

// コンストラクタ
Create_Dungeon::Create_Dungeon() {
	dungeon_manager = new Dungeon_Manager();
}

// デストラクタ
Create_Dungeon::~Create_Dungeon() {
}

// 区画を作る
DUNEON_RECTANGLE* Create_Dungeon::Create_Rectangle(int left, int top, int right, int bottom) {
	DUNEON_RECTANGLE* new_rectangle;

	new_rectangle = &dungeon_rectangle[rectangle_count];
	ZeroMemory(new_rectangle, sizeof(DUNEON_RECTANGLE));
	SetRect(&new_rectangle->rect, left, top, right, bottom);
	++rectangle_count;

	return new_rectangle;
}

// 作った区画を分割する
void Create_Dungeon::Split_Rectangle(bool is_vertical) {
	DUNEON_RECTANGLE* parent;
	DUNEON_RECTANGLE* child;
	RECT* rectangle;

	// 分ける区画情報を取得
	parent = &dungeon_rectangle[rectangle_count - 1];
	rectangle = &parent->rect;

	// 分割する
	if (!is_vertical) {
		// 横に分割----------------------------------------------------------------

		// 区分を分割できるか確認
		if (RECTANGLE_WIDTH(*rectangle) < (MIN_ROOM_SIZE + 3) * 2 + 1) {
			return; // 分割できないときは終了
		}

		// 左端のA点を求める
		a = MIN_ROOM_SIZE + 3;

		// 右端のB点を求める
		b = RECTANGLE_WIDTH(*rectangle) - MIN_ROOM_SIZE - 4;

		// a,b間の距離を求める
		ab = b - a;

		// a,b間のどこかに決定する
		p = a + random->Dungeon_Random(ab + 1);

		// 新しく右の区画を作成する
		child = Create_Rectangle(
			rectangle->left + p,
			rectangle->top,
			rectangle->right,
			rectangle->bottom);

		// 元の区画の右をp地点に移動させて、左側の区画にする
		parent->rect.right = child->rect.left;

		// -----------------------------------------------------------------------
	}

	else {
		// 縦に分割----------------------------------------------------------------

		// 区分を分割できるかチェック
		if (RECTANGLE_HEIGHT(*rectangle) < (MIN_ROOM_SIZE + 3) * 2 + 1) {
			// 分割できないときは終了
			return;
		}

		a = MIN_ROOM_SIZE + 3;
		b = RECTANGLE_HEIGHT(*rectangle) - MIN_ROOM_SIZE - 4;
		ab = b - a;

		p = a + random->Dungeon_Random(ab + 1);

		// 新しく区画を作成する
		child = Create_Rectangle(
			rectangle->left,
			rectangle->top + p,
			rectangle->right,
			rectangle->bottom);

		// 元の区画の下をp地点に移動させて、上の区画とする
		parent->rect.bottom = child->rect.top;
	}

	// 次の分割をランダムで決定するために入れ替える
	if (random->Dungeon_Random(2)) {
		DUNEON_RECTANGLE dungeon_rectangle;
		dungeon_rectangle = *child;
		*child            = *parent;
		*parent           = dungeon_rectangle;
	}

	// childの部屋をさらに分割する
	Split_Rectangle(!is_vertical);

	// ----------------------------------------------------------------------------
}

// 部屋を作る
void Create_Dungeon::Create_Room() {
	int	sw, sh,                            // TODO:?
		width, height,                     // 区画の幅と高さ
		room_x, room_y,                    // 部屋の大きさ(壁の分は抜き)
		room_width, room_height,           // 部屋の幅と高さ(壁の分も込み)
		character_width, character_height; // キャラクターの幅と高さ

	//区画の分だけ部屋を作る
	for (int i = 0; i < rectangle_count; ++i) {
		RECT* rectangle = &dungeon_rectangle[i].rect; // 区画情報
		RECT* room      = &dungeon_rectangle[i].room; // 部屋の情報

		// 矩形の大きさを計算
		width = RECTANGLE_WIDTH(*rectangle) - 3;
		height = RECTANGLE_HEIGHT(*rectangle) - 3;

		// 区画に入る最小部屋の余裕を求める
		character_width  = width  - MIN_ROOM_SIZE;
		character_height = height - MIN_ROOM_SIZE;

		// 部屋の大きさを決定する
		sw = random->Dungeon_Random(character_width);
		sh = random->Dungeon_Random(character_height);
		room_width  = width  - sw;
		room_height = height - sh;

		// 部屋の位置を決定する
		room_x = random->Dungeon_Random(sw) + 2;
		room_y = random->Dungeon_Random(sh) + 2;

		// 求めた結果から部屋の情報を設定
		room->left   = rectangle->left + room_x;
		room->top    = rectangle->top  + room_y;
		room->right  = room->left      + room_width;
		room->bottom = room->top       + room_height;

		// 部屋を作る
		Fill_Rectangle(
			room->left,
			room->top,
			room->right,
			room->bottom, false);

		// 最初に作られた部屋の中にランダムに階段を設置
		if (i == 0) {
			int x, y;
			Random_Room_Point(i, &x, &y);
			Get_Tile(x, y)->is_upstairs = true;
		}
	}
}

// 部屋同士を繋げる
void Create_Dungeon::Connect_Room() {
	for (int i = 0; i < rectangle_count - 1; ++i) {
		Create_Road(i, i + 1);
	}
}

// 道を作る
void Create_Dungeon::Create_Road(int set_room_A, int set_room_B) {
	RECT* rect_A, *rect_B;
	RECT* room_A, *room_B;

	rect_A = &dungeon_rectangle[set_room_A].rect;
	rect_B = &dungeon_rectangle[set_room_B].rect;
	room_A = &dungeon_rectangle[set_room_A].room;
	room_B = &dungeon_rectangle[set_room_B].room;

	/*----------------------------------------------------------------
	区画同士が、上下か左右のどちらでつながっているかで処理を分け、道をつなぐ
	-----------------------------------------------------------------*/

	// 上下で繋がっているかの確認
	if (rect_A->bottom == rect_B->top || rect_A->top == rect_B->bottom) {
		int x1, x2, y;

		x1 = random->Dungeon_Random(RECTANGLE_WIDTH(*room_A)) + room_A->left;
		x2 = random->Dungeon_Random(RECTANGLE_WIDTH(*room_B)) + room_B->left;

		if (rect_A->top > rect_B->top) {
			/*
			  B
			  A
			  の並びの時
			*/
			y = rect_A->top;
			
			// AB間の横道を繋ぐ道を作る
			Fill_Rectangle(x1, y + 1, x1 + 1, room_A->top, false);
			Fill_Rectangle(x2, room_B->bottom, x2 + 1, y, false);
		}
		else {
			/*
			  A
			  B
			  の並びの時
			*/
			y = rect_B->top;

			// AB間の横道を繋ぐ道を作る
			Fill_Rectangle(x1, room_A->bottom, x1 + 1, y, false);
			Fill_Rectangle(x2, y, x2 + 1, room_B->top, false);
		}

		// 道同士を繋げる横道を作る
		Fill_Horizontal_Line(x1, x2, y, false);
	}

	// 左右でつながっているか
	else if (rect_A->right == rect_B->left || rect_A->left == rect_B->right) {
		int y1, y2, x;

		y1 = random->Dungeon_Random(room_A->bottom - room_A->top) + room_A->top;
		y2 = random->Dungeon_Random(room_B->bottom - room_B->top) + room_B->top;

		if (rect_A->left > rect_B->left) {
			/*
			  BA
			  の並びのとき
			*/
			x = rect_A->left;
			// AB間の縦道を繋ぐ道を作る
			Fill_Rectangle(room_B->right, y2, x, y2 + 1, false);
			Fill_Rectangle(x + 1, y1, room_A->left, y1 + 1, false);
		}
		else {
			/*
			  AB
			  の並びの時
			*/
			x = rect_B->left;
			// AB間の縦道を繋ぐ道を作る
			Fill_Rectangle(room_A->right, y1, x, y1 + 1, false);
			Fill_Rectangle(x, y2, room_B->left, y2 + 1, false);
		}

		// 道同士を繋げる縦道を作る
		Fill_Vertical_Line(y1, y2, x, false);
	}
}

// 部屋の範囲+部屋の連結部のみ壁フラグをfalseに
void Create_Dungeon::Fill_Rectangle(int left, int top, int right, int bottom, bool is_wall) {
	if (left > right) {
		int tmp = left;
		left    = right;
		right   = tmp;
	}

	if (top > bottom) {
		int tmp = top;
		top     = bottom;
		bottom  = tmp;
	}

	for (y = top; y < bottom; ++y) {
		for (x = left; x < right; ++x) {
			Get_Tile(x, y)->is_wall = is_wall;
		}
	}
}

// 部屋と部屋の縦道を繋ぐ
void Create_Dungeon::Fill_Horizontal_Line(int left, int right, int y, bool is_wall) {
	if (left > right) {
		int tmp = left;
		left    = right;
		right   = tmp;
	}

	for (x = left; x <= right; x++) {
		Get_Tile(x, y)->is_wall = is_wall;
	}
}

// 部屋と部屋の横道を繋ぐ
void Create_Dungeon::Fill_Vertical_Line(int top, int bottom, int x, bool is_wall) {
	if (top > bottom) {
		int tmp = top;
		top     = bottom;
		bottom  = tmp;
	}

	for (y = top; y <= bottom; y++) {
		Get_Tile(x, y)->is_wall = is_wall;
	}
}

// １フロア分のダンジョンの設定をする
void Create_Dungeon::Set_Dungeon() {
	rectangle_count = 0;

	// 初期化(マップ全てを壁にする)
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			Get_Tile(x, y)->is_wall = true;
		}
	}

	// 区画を作る
	Create_Rectangle(0, 0, width - 1, height - 1);

	// Create_Rectangleで定めた区画を細分化していく
	Split_Rectangle(random->Dungeon_Random(2) ? true : false);

	// 部屋を作る
	Create_Room();

	// 部屋同士を繋げる
	Connect_Room();
}

// 1フロア分のダンジョンを生成する
void Create_Dungeon::Create_Floor() {
	// TODO: 階層が進むときは、前の階を破壊	

	// ダンジョンのメモリを確保
	Alloc(DUNGEON_WIDTH, DUNGEON_HEIGHT); // Define定数使用

	// １フロア分のダンジョンの構成を設定る(区画の数、部屋の数など)
	Set_Dungeon();

	dungeon_manager = this; //設定したものを代入する
}