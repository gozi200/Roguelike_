#include "Dungeon_Manager.h"

// コンストラクタ
Dungeon_Manager::Dungeon_Manager() {
	width  = DUNGEON_WIDTH;  //Define定数使用
	height = DUNGEON_HEIGHT; //Define定数使用

	turn_count      = 0;
	rectangle_count = 0;

	random = new Random();
	tile_judge = new Tile_Judge[width * height]();
}

// デストラクタ
Dungeon_Manager::~Dungeon_Manager() {
	delete[] tile_judge;
	delete random;
}

// ダンジョンのメモリの確保
bool Dungeon_Manager::Alloc(int set_width, int set_height) {
	tile_judge = new Tile_Judge[set_width * set_height];

	if (tile_judge == NULL) {
		return true;
	}

	// メンバをすべてゼロ初期化
	memset(tile_judge, 0, sizeof(Tile_Judge) * set_width * set_height);

	// ダンジョンサイズを保存
	width  = set_width;
	height = set_height;

	return false;
}

// 床の情報を取得
Tile_Judge* Dungeon_Manager::Get_Tile(int x, int y) {
	if (tile_judge == NULL) {
		return NULL;
	}

	if (x < 0 || x >= width || y < 0 || y >= height) {
		return NULL;
	}

	return &tile_judge[x + y * width];
}

// 区画の数を取得
int Dungeon_Manager::Get_Rectangle_Count() {
	return rectangle_count;
}

// 部屋の数を取得
int Dungeon_Manager::Get_Room_Count() {
	return rectangle_count; //１区画に部屋は一つなのでrectで代用
}

int Dungeon_Manager::Get_Width (int set_width) {
	width += set_width;

	return width;
}

int Dungeon_Manager::Get_Height(int set_height) {
	height += set_height;

	return height;
}

// 指定した部屋内の適当な座標を取得
void Dungeon_Manager::Random_Room_Point(int index, int* x, int* y) {
	RECT* room = &dungeon_rectangle[index].room;

	*x = room->left + random->Dungeon_Random(RECTANGLE_WIDTH(*room));
	*y = room->top  + random->Dungeon_Random(RECTANGLE_HEIGHT(*room));
}

//指定位置の部屋インデックスを返す(道、壁なら-1を返す)
int Dungeon_Manager::Get_Room_Index(int x, int y) {
	const POINT position = { x, y }; //TODO: 読めるように

	for (int i = 0; i < rectangle_count; i++)
	{
		// 部屋の矩形内に引数の座標は入っているか？
		// ※PiInRect はWinAPI で、指定矩形内に指定した点が入るなら 0 以外を返す
		if (PtInRect(&dungeon_rectangle[i].room, position))
			return i;
	}
	return -1;
}

//指定位置の矩形インデックスを返す(道、壁なら-1を返す)
int Dungeon_Manager::Get_Rectangle_Index(int x, int y)
{
	const POINT position = { x, y };

	for (int i = 0; i < rectangle_count; i++)
	{
		// 矩形内に引数の座標は入っているか？
		// ※PiInRect はWinAPI で、指定矩形内に指定した点が入るなら 0 以外を返す
		if (PtInRect(&dungeon_rectangle[i].rect, position))
			return i;
	}

	return -1;
}
