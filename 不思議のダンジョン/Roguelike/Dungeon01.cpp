#include"Dungeon01.h"

Dungeon01::Dungeon01() : Dungeon_Base() {
	random = Random();
}

Dungeon01::~Dungeon01() {

}

void Dungeon01::Make(Actor* set_player, int set_floor) {
	rectangle_count = 0; //���̐������Z�b�g

	player = set_player;

	//������(��U���ׂĕǂɂ���)
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			Get_Tile(x, y)->is_wall = true;
		}
	}

	//�������
	//���߂ɑS�̂��P�̋��Ƃ���
	Create_Rectangle(0, 0, width - 1, height - 1);

	//���Œ�߂������ו������Ă���
	Split_Rectangle(random.Dungeon_Random(2) ? true : false);

	//���������
	Create_Room();

	//�������m���Ȃ���
	Connect_Room();

	//�e�����ɃG�l�~�[��z�u
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

	//������������擾
	parent = &dungeon_rectangle[rectangle_count - 1];
	rectangle = &parent->rect;

	//��������
	if (!set_is_vertical) {
		//���ɕ���--------------------------------------------------------------------------

		//�敪�𕪊��ł��邩�m�F
		if (RECTANGLE_WIDTH(*rectangle) < (MIN_ROOM_SIZE + 3) * 2 + 1) {
			return; //�����ł��Ȃ��Ƃ��͏I��
		}

		int a, b, ab, p;
		//���[��A�_�����߂�
		a = MIN_ROOM_SIZE + 3;

		//�E�[��B�_�����߂�
		b = RECTANGLE_WIDTH(*rectangle) - MIN_ROOM_SIZE - 4;

		//a,b�Ԃ̋��������߂�
		ab = b - a;

		//a,b�Ԃ̂ǂ����Ɍ��肷��
		p = a + random.Dungeon_Random(ab + 1);

		//�V�����E�̋����쐬����
		child = Create_Rectangle(
			rectangle->left + p,
			rectangle->top,
			rectangle->right,
			rectangle->bottom);

		//���̋��̉E��p�n�_�Ɉړ������āA�����̋��ɂ���
		parent->rect.right = child->rect.left;

		//--------------------------------------------------------------------------------------
	}

	else {
		//�c�ɕ�������

		//�敪�𕪊��ł��邩�`�F�b�N
		if (RECTANGLE_HEIGHT(*rectangle) < (MIN_ROOM_SIZE + 3) * 2 + 1) {
			//�����ł��Ȃ��Ƃ��͏I��
			return;
		}
		int a, b, ab, p;

		a = MIN_ROOM_SIZE + 3;
		b = RECTANGLE_HEIGHT(*rectangle) - MIN_ROOM_SIZE - 4;
		ab = b - a;

		p = a + random.Dungeon_Random(ab + 1);

		//�V���������쐬����
		child = Create_Rectangle(
			rectangle->left,
			rectangle->top + p,
			rectangle->right,
			rectangle->bottom);

		//���̋��̉���p�n�_�Ɉړ������āA��̋��Ƃ���
		parent->rect.bottom = child->rect.top;
	}

	//���̕����������_���Ō��肷�邽�߂ɓ���ւ���
	if (random.Dungeon_Random(2)) {
		DUNEON_RECTANGLE dungeon_rectangle;
		dungeon_rectangle = *child;
		*child = *parent;
		*parent = dungeon_rectangle;
	}

	//child�̕���������ɕ�������
	Split_Rectangle(!set_is_vertical);
}

void Dungeon01::Create_Room() {
	int width, height,						//���̕��ƍ���
		charactor_width, charactor_height,  //�L�����N�^�[�̕��ƍ���
		sw, sh,								//?
		room_width, room_height,			//�����̕��ƍ���(�Ǎ�)
		room_x, room_y;						//�����̑傫��(�ǔ���)

	for (int i = 0; i < rectangle_count; ++i) {
		RECT* rectangle = &dungeon_rectangle[i].rect; //�����
		RECT* room = &dungeon_rectangle[i].room; //���ō�镔�����

		//��`�̑傫�����v�Z
		width = RECTANGLE_WIDTH(*rectangle) - 3;
		height = RECTANGLE_HEIGHT(*rectangle) - 3;

		//���ɓ���ŏ������̗]�T�����߂�
		charactor_width = width - MIN_ROOM_SIZE;
		charactor_height = height - MIN_ROOM_SIZE;

		//�����̑傫�������肷��
		sw = random.Dungeon_Random(charactor_width);
		sh = random.Dungeon_Random(charactor_height);
		room_width = width - sw;
		room_height = height - sh;

		//�����̈ʒu�����肷��
		room_x = random.Dungeon_Random(sw) + 2;
		room_y = random.Dungeon_Random(sh) + 2;

		//���߂����ʂ��畔���̏���ݒ�
		room->left = rectangle->left + room_x;
		room->top = rectangle->top + room_y;
		room->right = room->left + room_width;
		room->bottom = room->top + room_height;

		//���������
		Fill_Rectangle( //�_���W�����̑傫��(width,height�̊O�Ɏ���Ă��܂��Ă���B)
			room->left,
			room->top,
			room->right,
			room->bottom, false);

		//�P�ڂ̕����Ȃ�K���Ȉʒu�ɊK�i��ݒu
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
	RECT* rect_A, *rect_B; //�}�N���g�p
	RECT* room_A, *room_B; //�}�N���g�p

	rect_A = &dungeon_rectangle[set_room_A].rect;
	rect_B = &dungeon_rectangle[set_room_B].rect;
	room_A = &dungeon_rectangle[set_room_A].room;
	room_B = &dungeon_rectangle[set_room_B].room;

	/*----------------------------------------------------------------
	��擯�m���A�㉺�����E�̂ǂ���łȂ����Ă��邩�ŏ����𕪂��A�����Ȃ�
	-----------------------------------------------------------------*/

	//�㉺�Ōq�����Ă��邩�̊m�F
	if (rect_A->bottom == rect_B->top || rect_A->top == rect_B->bottom) {
		int x1, x2, y;

		x1 = random.Dungeon_Random(RECTANGLE_WIDTH(*room_A)) + room_A->left;
		x2 = random.Dungeon_Random(RECTANGLE_WIDTH(*room_B)) + room_B->left;

		if (rect_A->top > rect_B->top) {
			/* B
			   A
			   �̕��т̎�
			*/
			y = rect_A->top;
			//AB�Ԃ̉������q���������
			Fill_Rectangle(x1, y + 1, x1 + 1 , room_A->top, false);
			Fill_Rectangle(x2, room_B->bottom, x2 + 1, y, false);
		}

		else {
			/* A
			   B
			   �̕��т̎�
			*/
			y = rect_B->top;
			//AB�Ԃ̉������q���������
			Fill_Rectangle(x1, room_A->bottom, x1 + 1, y, false);
			Fill_Rectangle(x2, y, x2 + 1, room_B->top, false);
		}

		//�����m���q���鉡�������
		Fill_Horizontal_Line(x1, x2, y, false);
	}

	//���E�łȂ����Ă��邩
	else if (rect_A->right == rect_B->left || rect_A->left == rect_B->right) {
		int y1, y2, x;

		y1 = random.Dungeon_Random(room_A->bottom - room_A->top) + room_A->top;
		y2 = random.Dungeon_Random(room_B->bottom - room_B->top) + room_B->top;

		if (rect_A->left > rect_B->left) {
			/*BA
			  �̕��т̂Ƃ�
			*/
			x = rect_A->left;
			//AB�Ԃ̏c�����q���������
			Fill_Rectangle(room_B->right, y2, x, y2 + 1, false);
			Fill_Rectangle(x + 1, y1, room_A->left, y1 + 1, false);
		}

		else {
			/*AB
			  �̕��т̎�
			*/
			x = rect_B->left;
			//AB�Ԃ̏c�����q���������
			Fill_Rectangle(room_A->right, y1, x, y1 + 1, false);
			Fill_Rectangle(x, y2, room_B->left, y2 + 1, false);
		}

		//�����m���q����c�������
		Fill_Vertical_Line(y1, y2, x, false);
	}
}
