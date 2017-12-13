#include "Create_Dungeon.h"

// �R���X�g���N�^
Create_Dungeon::Create_Dungeon() {
	dungeon_manager = new Dungeon_Manager();
}

// �f�X�g���N�^
Create_Dungeon::~Create_Dungeon() {
}

// �������
DUNEON_RECTANGLE* Create_Dungeon::Create_Rectangle(int left, int top, int right, int bottom) {
	DUNEON_RECTANGLE* new_rectangle;

	new_rectangle = &dungeon_rectangle[rectangle_count];
	ZeroMemory(new_rectangle, sizeof(DUNEON_RECTANGLE));
	SetRect(&new_rectangle->rect, left, top, right, bottom);
	++rectangle_count;

	return new_rectangle;
}

// ��������𕪊�����
void Create_Dungeon::Split_Rectangle(bool is_vertical) {
	DUNEON_RECTANGLE* parent;
	DUNEON_RECTANGLE* child;
	RECT* rectangle;

	// ������������擾
	parent = &dungeon_rectangle[rectangle_count - 1];
	rectangle = &parent->rect;

	// ��������
	if (!is_vertical) {
		// ���ɕ���----------------------------------------------------------------

		// �敪�𕪊��ł��邩�m�F
		if (RECTANGLE_WIDTH(*rectangle) < (MIN_ROOM_SIZE + 3) * 2 + 1) {
			return; // �����ł��Ȃ��Ƃ��͏I��
		}

		// ���[��A�_�����߂�
		a = MIN_ROOM_SIZE + 3;

		// �E�[��B�_�����߂�
		b = RECTANGLE_WIDTH(*rectangle) - MIN_ROOM_SIZE - 4;

		// a,b�Ԃ̋��������߂�
		ab = b - a;

		// a,b�Ԃ̂ǂ����Ɍ��肷��
		p = a + random->Dungeon_Random(ab + 1);

		// �V�����E�̋����쐬����
		child = Create_Rectangle(
			rectangle->left + p,
			rectangle->top,
			rectangle->right,
			rectangle->bottom);

		// ���̋��̉E��p�n�_�Ɉړ������āA�����̋��ɂ���
		parent->rect.right = child->rect.left;

		// -----------------------------------------------------------------------
	}

	else {
		// �c�ɕ���----------------------------------------------------------------

		// �敪�𕪊��ł��邩�`�F�b�N
		if (RECTANGLE_HEIGHT(*rectangle) < (MIN_ROOM_SIZE + 3) * 2 + 1) {
			// �����ł��Ȃ��Ƃ��͏I��
			return;
		}

		a = MIN_ROOM_SIZE + 3;
		b = RECTANGLE_HEIGHT(*rectangle) - MIN_ROOM_SIZE - 4;
		ab = b - a;

		p = a + random->Dungeon_Random(ab + 1);

		// �V���������쐬����
		child = Create_Rectangle(
			rectangle->left,
			rectangle->top + p,
			rectangle->right,
			rectangle->bottom);

		// ���̋��̉���p�n�_�Ɉړ������āA��̋��Ƃ���
		parent->rect.bottom = child->rect.top;
	}

	// ���̕����������_���Ō��肷�邽�߂ɓ���ւ���
	if (random->Dungeon_Random(2)) {
		DUNEON_RECTANGLE dungeon_rectangle;
		dungeon_rectangle = *child;
		*child            = *parent;
		*parent           = dungeon_rectangle;
	}

	// child�̕���������ɕ�������
	Split_Rectangle(!is_vertical);

	// ----------------------------------------------------------------------------
}

// ���������
void Create_Dungeon::Create_Room() {
	int	sw, sh,                            // TODO:?
		width, height,                     // ���̕��ƍ���
		room_x, room_y,                    // �����̑傫��(�ǂ̕��͔���)
		room_width, room_height,           // �����̕��ƍ���(�ǂ̕�������)
		character_width, character_height; // �L�����N�^�[�̕��ƍ���

	//���̕��������������
	for (int i = 0; i < rectangle_count; ++i) {
		RECT* rectangle = &dungeon_rectangle[i].rect; // �����
		RECT* room      = &dungeon_rectangle[i].room; // �����̏��

		// ��`�̑傫�����v�Z
		width = RECTANGLE_WIDTH(*rectangle) - 3;
		height = RECTANGLE_HEIGHT(*rectangle) - 3;

		// ���ɓ���ŏ������̗]�T�����߂�
		character_width  = width  - MIN_ROOM_SIZE;
		character_height = height - MIN_ROOM_SIZE;

		// �����̑傫�������肷��
		sw = random->Dungeon_Random(character_width);
		sh = random->Dungeon_Random(character_height);
		room_width  = width  - sw;
		room_height = height - sh;

		// �����̈ʒu�����肷��
		room_x = random->Dungeon_Random(sw) + 2;
		room_y = random->Dungeon_Random(sh) + 2;

		// ���߂����ʂ��畔���̏���ݒ�
		room->left   = rectangle->left + room_x;
		room->top    = rectangle->top  + room_y;
		room->right  = room->left      + room_width;
		room->bottom = room->top       + room_height;

		// ���������
		Fill_Rectangle(
			room->left,
			room->top,
			room->right,
			room->bottom, false);

		// �ŏ��ɍ��ꂽ�����̒��Ƀ����_���ɊK�i��ݒu
		if (i == 0) {
			int x, y;
			Random_Room_Point(i, &x, &y);
			Get_Tile(x, y)->is_upstairs = true;
		}
	}
}

// �������m���q����
void Create_Dungeon::Connect_Room() {
	for (int i = 0; i < rectangle_count - 1; ++i) {
		Create_Road(i, i + 1);
	}
}

// �������
void Create_Dungeon::Create_Road(int set_room_A, int set_room_B) {
	RECT* rect_A, *rect_B;
	RECT* room_A, *room_B;

	rect_A = &dungeon_rectangle[set_room_A].rect;
	rect_B = &dungeon_rectangle[set_room_B].rect;
	room_A = &dungeon_rectangle[set_room_A].room;
	room_B = &dungeon_rectangle[set_room_B].room;

	/*----------------------------------------------------------------
	��擯�m���A�㉺�����E�̂ǂ���łȂ����Ă��邩�ŏ����𕪂��A�����Ȃ�
	-----------------------------------------------------------------*/

	// �㉺�Ōq�����Ă��邩�̊m�F
	if (rect_A->bottom == rect_B->top || rect_A->top == rect_B->bottom) {
		int x1, x2, y;

		x1 = random->Dungeon_Random(RECTANGLE_WIDTH(*room_A)) + room_A->left;
		x2 = random->Dungeon_Random(RECTANGLE_WIDTH(*room_B)) + room_B->left;

		if (rect_A->top > rect_B->top) {
			/*
			  B
			  A
			  �̕��т̎�
			*/
			y = rect_A->top;
			
			// AB�Ԃ̉������q���������
			Fill_Rectangle(x1, y + 1, x1 + 1, room_A->top, false);
			Fill_Rectangle(x2, room_B->bottom, x2 + 1, y, false);
		}
		else {
			/*
			  A
			  B
			  �̕��т̎�
			*/
			y = rect_B->top;

			// AB�Ԃ̉������q���������
			Fill_Rectangle(x1, room_A->bottom, x1 + 1, y, false);
			Fill_Rectangle(x2, y, x2 + 1, room_B->top, false);
		}

		// �����m���q���鉡�������
		Fill_Horizontal_Line(x1, x2, y, false);
	}

	// ���E�łȂ����Ă��邩
	else if (rect_A->right == rect_B->left || rect_A->left == rect_B->right) {
		int y1, y2, x;

		y1 = random->Dungeon_Random(room_A->bottom - room_A->top) + room_A->top;
		y2 = random->Dungeon_Random(room_B->bottom - room_B->top) + room_B->top;

		if (rect_A->left > rect_B->left) {
			/*
			  BA
			  �̕��т̂Ƃ�
			*/
			x = rect_A->left;
			// AB�Ԃ̏c�����q���������
			Fill_Rectangle(room_B->right, y2, x, y2 + 1, false);
			Fill_Rectangle(x + 1, y1, room_A->left, y1 + 1, false);
		}
		else {
			/*
			  AB
			  �̕��т̎�
			*/
			x = rect_B->left;
			// AB�Ԃ̏c�����q���������
			Fill_Rectangle(room_A->right, y1, x, y1 + 1, false);
			Fill_Rectangle(x, y2, room_B->left, y2 + 1, false);
		}

		// �����m���q����c�������
		Fill_Vertical_Line(y1, y2, x, false);
	}
}

// �����͈̔�+�����̘A�����̂ݕǃt���O��false��
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

// �����ƕ����̏c�����q��
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

// �����ƕ����̉������q��
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

// �P�t���A���̃_���W�����̐ݒ������
void Create_Dungeon::Set_Dungeon() {
	rectangle_count = 0;

	// ������(�}�b�v�S�Ă�ǂɂ���)
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			Get_Tile(x, y)->is_wall = true;
		}
	}

	// �������
	Create_Rectangle(0, 0, width - 1, height - 1);

	// Create_Rectangle�Œ�߂������ו������Ă���
	Split_Rectangle(random->Dungeon_Random(2) ? true : false);

	// ���������
	Create_Room();

	// �������m���q����
	Connect_Room();
}

// 1�t���A���̃_���W�����𐶐�����
void Create_Dungeon::Create_Floor() {
	// TODO: �K�w���i�ނƂ��́A�O�̊K��j��	

	// �_���W�����̃��������m��
	Alloc(DUNGEON_WIDTH, DUNGEON_HEIGHT); // Define�萔�g�p

	// �P�t���A���̃_���W�����̍\����ݒ��(���̐��A�����̐��Ȃ�)
	Set_Dungeon();

	dungeon_manager = this; //�ݒ肵�����̂�������
}