#include"Dungeon_Base.h"

Dungeon_Base::Dungeon_Base() {
	width = DUNGEON_WIDTH; //define�萔�g�p
	height = DUNGEON_HEIGHT; //define�萔�g�p
	rectangle_count = 0;

	tile_judge = new Tile_Judge[width * height]();

	enemy_data.Set_File_Pass("CSV/Actor/Enemy/Enemy.csv"); //CSV�t�@�C���������ǂݍ���
	enemy_data.Open_File(); //�t�@�C�����J���ēǂݍ���
}

//�f�X�g���N�^
Dungeon_Base::~Dungeon_Base() {
	delete[] tile_judge;
}

bool Dungeon_Base::Alloc(int set_width, int set_height) {
	tile_judge = new Tile_Judge[width*height];
	if (tile_judge == NULL)
		return true;

	// �����o�����ׂă[��������
	memset(tile_judge, 0, sizeof(Tile_Judge)*width*height);

	// �_���W�����T�C�Y��ۑ�
	width = set_width;
	height = set_height;

	return false;
}

Tile_Judge* Dungeon_Base::Get_Tile(int set_x, int set_y) {
	if (tile_judge == NULL) {
		return NULL;
	}

	if (set_x < 0 || set_x >= width || set_y < 0 || set_y >= height) {
		return NULL;
	}

	return &tile_judge[set_x + set_y * width];
}

int Dungeon_Base::Get_Rectangle_Count() {
	return rectangle_count;
}

int Dungeon_Base::Get_Room_Count() {
	return rectangle_count;
}

int Dungeon_Base::Get_Romm_Count() {
	return Get_Rectangle_Count();
};

bool Dungeon_Base::Is_Move(int set_x, int set_y) {
	//�͈͊O�͈ړ��s��
	if (set_x < 0 || set_x >= width || set_y < 0 || set_y >= height) {
		return true;
	}

	//�ǂ���������ړ��s��
	if (Get_Tile(set_x, set_y)->is_wall) {
		return true;
	}

	//�ړ��s��
	return false;
}

//�����͈̔�+�����̘A�������̂ݕǃt���O��false�� 
void Dungeon_Base::Fill_Rectangle(int left, int top, int right, int bottom, bool is_wall) {
	int x, y;

	if (left > right)
	{
		int tmp = left;
		left = right;
		right = tmp;
	}
	if (top > bottom)
	{
		int tmp = top;
		top = bottom;
		bottom = tmp;
	}

	for (y = top; y<bottom; y++)
	{
		for (x = left; x<right; x++)
		{
			Get_Tile(x, y)->is_wall = is_wall;
		}
	}
};

void Dungeon_Base::Fill_Horizontal_Line(int left, int right, int y, bool is_wall) {
	int x;

	if (left > right) {
		int tmp = left;
		left = right;
		right = tmp;
	}

	for (x = left; x <= right; x++) {
		Get_Tile(x, y)->is_wall = is_wall;
	}
};

void Dungeon_Base::Fill_Vertical_Line(int top, int bottom, int x, bool is_wall) {
	int y;

	if (top > bottom) {
		int tmp = top;
		top = bottom;
		bottom = tmp;
	}

	for (y = top; y <= bottom; y++) {
		Get_Tile(x, y)->is_wall = is_wall;
	}
};

//�w�肵�����������烉���_���ɍ��W���擾
void Dungeon_Base::Random_Room_Point(int index, int *x, int *y) {
	RECT* room = &dungeon_rectangle[index].room;

	*x = room->left + random.Dungeon_Random(RECTANGLE_WIDTH(*room));
	*y = room->top  + random.Dungeon_Random(RECTANGLE_HEIGHT(*room));
}


bool Dungeon_Base::Check_Move(int set_ax, int set_ay, int set_bx, int set_by) {
	//MEMO: ���݂���ʒu = A,�@�V�����ړ�����ʒu = B

	//A,B�����ꂩ�ǂ���
	if (set_ax == set_bx && set_ay == set_by) {
		return false; //����͎��͂W�}�X
	}

	//A,B�͎���8�}�X�ɂ��Ȃ����@(�H)
	if (abs(set_ax - set_bx) > 1 || abs(set_ay - set_by) > 1) {
		return false; //����Ă���
	}

	//B�͈ړ��\�Ȓn�`��
	if (Is_Move(set_bx, set_by)) {
		return false;
	}

	//A���猩��B�͍���ɂ��邩
	if (set_ax - 1 == set_bx && set_ay - 1 == set_by) {
		//���Ə�̑o�����ړ��s���ǂ���
		if (Is_Move(set_ax - 1, set_ay) && Is_Move(set_ax, set_ay - 1)) {
			return false;
		}
		return true;
	}

	//A���猩��B�͉E��ɂ��邩
	if (set_ax + 1 == set_bx && set_ay - 1 == set_by) {
		//�E�Ə�̑o�����ړ��s���ǂ���
		if (Is_Move(set_ax + 1, set_ay) && Is_Move(set_ax, set_ay - 1)) {
			return false;
		}
		return true;
	}

	//A���猩��B�͍����ɂ��邩
	if (set_ax - 1 == set_bx && set_ay + 1 == set_by) {
		//�E�Ɖ��̑o�����ړ��s�\���ǂ���
		if (Is_Move(set_ax - 1, set_ay) && Is_Move(set_ax, set_ay + 1)) {
			return false;
		}
		return true;
	}

	//A���猩��B�͉E���ɂ��邩
	if (set_ax + 1 == set_bx && set_ay + 1 == set_by) {
		//�E�Ɖ��̑o�����ړ��s�\���ǂ���
		if (Is_Move(set_ax + 1, set_ay) && Is_Move(set_ax, set_ay + 1)) {
			return false;
		}
		return true;
	}
	return false;
};

void Dungeon_Base::Delete_Enemy() {
	while (enemy_count)
	{
		--enemy_count;
		delete m_enemy[enemy_count];
		m_enemy[enemy_count] = NULL;
	}
};

Actor* Dungeon_Base::Get_Point_Enemy(int x, int y) {
	// ���ׂẴ����X�^�[�𒲂ׂ�
	for (int i = 0; i < enemy_count; i++)
	{
		int mx, my;
		Actor *actor = m_enemy[i];
		actor->Get_Position(&mx, &my);
		if (actor->Is_Dead() && mx == x && my == y)
			return actor;
	}
	return NULL;
};


Actor* Dungeon_Base::Get_Mob_From_Index(int index) {
	// �p�����[�^�[�`�F�b�N
	if (index < 0 || index >= enemy_count)
		return NULL;

	return m_enemy[index];
	return 0;
};

void Dungeon_Base::Create_Enemy(int set_floor) {
	int x, y;

	//���ꂼ��̕����ɂP�̔z�u����
	for (int i = 1; i <= rectangle_count; ++i) {
		Enemy* p_enemy; //�����o�ϐ��Ɩ��O�̏d���������
		
		//�G�l�~�[�̃I�u�W�F�N�g���쐬
		p_enemy = Get_Enemy(set_floor);

		if (p_enemy) {
			//�������̍��p�������_���Ɏ擾
			Random_Room_Point(i, &x, &y);

			//�G�l�~�[��z�u
			p_enemy->Set_Position(x, y);

			//�G�l�~�[�z�u���̎擾
			m_enemy[enemy_count] = p_enemy;
			++enemy_count;
		}
	}
}

void Dungeon_Base::Drop_Item(int x, int y, Item* item) {
	Tile_Judge *tile;

	tile = Get_Tile(x, y);
	if (tile == NULL)
		return;

	// �^�C���̃A�C�e�����ɒǉ�����
	if (tile->drop_item == NULL) {
		item->next = NULL;
	}

	else
		item->next = tile->drop_item;

	tile->drop_item = item;
}

void Dungeon_Base::Remove_Item(int x, int y, Item* remove_item) {
	Tile_Judge *tile;
	Item *item, *preview;

	tile = Get_Tile(x, y);
	if (tile == NULL)
		return;

	// �^�C���̏�񂩂�����A�C�e����T��
	preview = item = tile->drop_item;
	while (item)
	{
		if (item == remove_item)
		{
			// �����N���X�g����O��
			if (preview == item) {
				tile->drop_item = item->next;
			}

			else {
				preview->next = item->next;
			}

			// �A�C�e�����̍폜
			item->Erase();

			delete item;

			return;
		}
		preview = item;
		item = item->next;
	}
}

//�w��ʒu�̕����C���f�b�N�X��Ԃ�(���A�ǂȂ� -1 ��Ԃ�)
int Dungeon_Base::Get_Room_Index(int x, int y) {
	const POINT position = { x, y }; //TODO: �@�\

	for (int i = 0; i < rectangle_count; i++)
	{
		// �����̋�`���Ɉ����̍��W�͓����Ă��邩�H
		// ��PiInRect ��WinAPI �ŁA�w���`���Ɏw�肵���_������Ȃ� 0 �ȊO��Ԃ�
		if (PtInRect(&dungeon_rectangle[i].room, position))
			return i;
	}
	return -1;
}

int Dungeon_Base::Get_Rectangle_Index(int x, int y)
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

int Dungeon_Base::Attack(Actor* attacker, Actor* target) {
	int damage;

	damage = attacker->Attack(target);

	// �����ގ������H
	if (target->actor_status.Is_Dead())
	{
		// �|�����̂ŃA�C�e���h���b�v����
		if (random.Dungeon_Random(100) < target->actor_status.drop_item_ID)
		{
			// �h���b�v�m��
			Item* item = new Item;
			item->Copy(&target->actor_status.drop_item);

			// �����X�^�[�̈ʒu�ɃA�C�e���𗎂Ƃ�
			int x, y;
			target->Get_Position(&x, &y);
			Drop_Item(x, y, item);

			//���b�Z�[�W�̕\�� //SEND
		}
	}
		return damage;
}

bool Dungeon_Base::Make_Enemy(int paturn, Enemy** enemy) {
	if (enemy == NULL) {
		return true;
	}

	*enemy = new Enemy_01;

	return false;
}

int Dungeon_Base::Get_Enemy_Count() {
	return enemy_count;
}

void Dungeon_Base::Random_Create_Enemy(int floor) {
	int x, y;
	int player_romm_index, room_index;

	//�v���C���[�̍��W���擾
	player->Get_Position(&x, &y);
	player_romm_index = Get_Room_Index(x, y);

	//�����X�^�[�̏o���ő吔�ɒB���Ă�����I��
	if (enemy_count >= MAX_ENEMY) {
		return;
	}

	//�z�u����������܂Ń��[�v����
	for (;;) {
		//�K���ȕ����ԍ���I��
		room_index = random.Dungeon_Random(Get_Romm_Count());

		//�v���C���[�̂��镔���̓_��
		if (room_index == player_romm_index) {
			continue;
		}

		//���̋�����t�n���ȍ��W���擾
		Random_Room_Point(room_index, &x, &y);
		
		//���̍��W�ɂق��̃G�l�~�[��������_��
		if (Get_Point_Enemy(x, y) != NULL) {
			continue;
		}

		/*-------------
		�G�l�~�[��z�u����
		---------------*/
		//�G�l�~�[�I�u�W�F�N�g�̍쐬
		Enemy* p_enemy = Get_Enemy(floor);

		if (p_enemy) {
			//�G�l�~�[�̔z�u
			p_enemy->Set_Position(x, y);

			//�G�l�~�[�z�u���̕ۑ�
			m_enemy[enemy_count] = p_enemy;
			++enemy_count;

			//�z�u���I������̂ŏI��
			return;
		}
	}
};

void Dungeon_Base::Set_Enemy_Parameter(Enemy* enemy, SETTING_ENEMY_DATA* enemy_data) {
	enemy->actor_status.Set_Parameter(enemy_data, &ITEM_DATA_BASE[enemy_data->drop_item_ID]);

	enemy->Reset();

	//���O�̐ݒ�
	enemy->Set_Name(enemy_data->name);
};

Enemy* Dungeon_Base::Get_Enemy(int floor) {
	Enemy* enemy;
	SETTING_ENEMY_DATA* sample;

	//�K�������X�^�[�ɓ�����܂Ō������J��Ԃ�
	while (true) {
		int index;

		//�����_���Ƀf�[�^�x�[�X��������Ă���
		index = random.Dungeon_Random(0/*ENMY_DATA_NUMBER*/); /*TODO: �G�l�~�[�X�e�[�^�X�v�f�������Ȃ����̐����H 
																	  �v�f�� < �G�l�~�[�̎�ނȂ̂ň�悸��0*/
		sample = &enemy_data.set_enemy_data.at(index); 

		//���݂̊K�w�ɓK������Ȃ�̗p����
		if (sample->first_floor <= floor && sample->last_floor >= floor) {
			break;
		}

		//�w�肵��AI�̃����X�^�[�N���X���쐬
		if (Make_Enemy(sample->paturn, &enemy)) {
			return NULL;
		}

		//�p�����[�^�̐ݒ�
		Set_Enemy_Parameter(enemy, sample);
		
		return enemy;
	}
}

