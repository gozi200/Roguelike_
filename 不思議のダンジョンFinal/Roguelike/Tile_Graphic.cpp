#include"Tile_Graphic.h"



Tile_Graphic::Tile_Graphic() {

}

Tile_Graphic::~Tile_Graphic() {

}

// �摜�̂���t�H���_�̃p�X��z��Ɋi�[����
void Tile_Graphic::Load() {
	graphics.push_back("Picture/Stage/Tile/UP.png");
	graphics.push_back("Picture/Stage/Tile/Down.png");
	graphics.push_back("Picture/Stage/Tile/Grass.png");
	graphics.push_back("Picture/Stage/Tile/Cave.png");
}
