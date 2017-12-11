#include "Wall_Graphic.h"

// コンストラクタ
Wall_Graphic::Wall_Graphic() {

}

// デストラクタ
Wall_Graphic::~Wall_Graphic() {

}

// 画像のあるフォルダのパスを配列に格納する
void Wall_Graphic::Load() {
	graphics.push_back("Picture/Stage/Wall/Grass.png");
	graphics.push_back("Picture/Stage/Wall/Corner_Grass.png");
	graphics.push_back("Picture/Stage/Wall/Cave.png");
	graphics.push_back("Picture/Stage/Wall/Corner_Cave.png");
}
