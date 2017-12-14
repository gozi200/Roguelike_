#include "Dungeon_Manager.h"

// �R���X�g���N�^
Dungeon_Manager::Dungeon_Manager() {
	width  = DUNGEON_WIDTH;  //Define�萔�g�p
	height = DUNGEON_HEIGHT; //Define�萔�g�p

	turn_count      = 0;
	rectangle_count = 0;

	random = new Random();
	tile_judge = new Tile_Judge[width * height]();
}

// �f�X�g���N�^
Dungeon_Manager::~Dungeon_Manager() {
	delete[] tile_judge;
	delete random;
}

// �_���W�����̃������̊m��
bool Dungeon_Manager::Alloc(int set_width, int set_height) {
	tile_judge = new Tile_Judge[set_width * set_height];

	if (tile_judge == NULL) {
		return true;
	}

	// �����o�����ׂă[��������
	memset(tile_judge, 0, sizeof(Tile_Judge) * set_width * set_height);

	// �_���W�����T�C�Y��ۑ�
	width  = set_width;
	height = set_height;

	return false;
}

// ���̏����擾
Tile_Judge* Dungeon_Manager::Get_Tile(int x, int y) {
	if (tile_judge == NULL) {
		return NULL;
	}

	if (x < 0 || x >= width || y < 0 || y >= height) {
		return NULL;
	}

	return &tile_judge[x + y * width];
}

// ���̐����擾
int Dungeon_Manager::Get_Rectangle_Count() {
	return rectangle_count;
}

// �����̐����擾
int Dungeon_Manager::Get_Room_Count() {
	return rectangle_count; //�P���ɕ����͈�Ȃ̂�rect�ő�p
}

int Dungeon_Manager::Get_Width (int set_width) {
	width += set_width;

	return width;
}

int Dungeon_Manager::Get_Height(int set_height) {
	height += set_height;

	return height;
}

// �w�肵���������̓K���ȍ��W���擾
void Dungeon_Manager::Random_Room_Point(int index, int* x, int* y) {
	RECT* room = &dungeon_rectangle[index].room;

	*x = room->left + random->Dungeon_Random(RECTANGLE_WIDTH(*room));
	*y = room->top  + random->Dungeon_Random(RECTANGLE_HEIGHT(*room));
}

//�w��ʒu�̕����C���f�b�N�X��Ԃ�(���A�ǂȂ�-1��Ԃ�)
int Dungeon_Manager::Get_Room_Index(int x, int y) {
	const POINT position = { x, y }; //TODO: �ǂ߂�悤��

	for (int i = 0; i < rectangle_count; i++)
	{
		// �����̋�`���Ɉ����̍��W�͓����Ă��邩�H
		// ��PiInRect ��WinAPI �ŁA�w���`���Ɏw�肵���_������Ȃ� 0 �ȊO��Ԃ�
		if (PtInRect(&dungeon_rectangle[i].room, position))
			return i;
	}
	return -1;
}

//�w��ʒu�̋�`�C���f�b�N�X��Ԃ�(���A�ǂȂ�-1��Ԃ�)
int Dungeon_Manager::Get_Rectangle_Index(int x, int y)
{
	const POINT position = { x, y };

	for (int i = 0; i < rectangle_count; i++)
	{
		// ��`���Ɉ����̍��W�͓����Ă��邩�H
		// ��PiInRect ��WinAPI �ŁA�w���`���Ɏw�肵���_������Ȃ� 0 �ȊO��Ԃ�
		if (PtInRect(&dungeon_rectangle[i].rect, position))
			return i;
	}

	return -1;
}
