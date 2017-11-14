#include"Dungeon_Base.h"

Dungeon_Base::Dungeon_Base() {
	width = DUNGEON_WIDTH; //define�萔�g�p
	height = DUNGEON_HEIGHT; //define�萔�g�p
	rectangle_count = 0;
	tile_judge = new Tile_Judge[width * height]();
}

//�f�X�g���N�^
Dungeon_Base::~Dungeon_Base() {
	delete[] tile_judge;
}

bool Dungeon_Base::Alloc(int set_x, int set_y) {
	return true;
}

Tile_Judge* Dungeon_Base::Get_Tile(int set_x, int set_y) {
	if (tile_judge == NULL) {
		return NULL;
	}

	if (set_x < 0 || set_x >= width || set_y < 0 || set_y >= height) { //�����ɓ����Ă��܂��Ă���
		OutputDebugString("Get_Tile()��NULL�ł�");
		return NULL;
	}

	return &tile_judge[set_x + set_y * width];
}


int Dungeon_Base::Get_Rectangle_Count() {
	return 0;
}

int Dungeon_Base::Get_Room_Count() {
	return Get_Rectangle_Count();
};

bool Dungeon_Base::is_Move(int set_x, int set_y) {
	return true;
}

//�����͈̔͂̂ݕǃt���O��false�� 
void Dungeon_Base::Fill_Rectangle(int set_left, int set_top, int set_right, int set_bottom, bool set_is_wall) {
	for (int y = set_top; y < set_bottom; ++y) {
		for (int x = set_left; x < set_right; ++x) {
			Get_Tile(x, y)->is_wall = set_is_wall;
		}
	}
};


void Dungeon_Base::Fill_H_Line(int set_left, int set_right, int set_y, bool set_is_wall) {
	if (set_left < set_right) {
		for (int x = set_left; x <= set_right; ++x) {
			Get_Tile(x, set_y)->is_wall = set_is_wall;
		}
	}

	else {
		for (int x = set_right; x <= set_left; ++x) {
			Get_Tile(x, set_y)->is_wall = set_is_wall;
		}
	}
};

void Dungeon_Base::Fill_V_Line(int set_top, int set_bottom, int set_x, bool set_is_wall) {
	if (set_top < set_bottom) {
		for (int y = set_top; y <= set_bottom; ++y) {
			Get_Tile(set_x, y)->is_wall = set_is_wall;
		}
	}

	else
		for (int y = set_bottom; y <= set_top; ++y) {
			Get_Tile(set_x, y)->is_wall = set_is_wall;
		}
};

void Dungeon_Base::Random_Room_Point(int index, int *set_x, int *set_y) {
	RECT* room = &dungeon_rectangle[index].room;

	*set_x = room->left + random.Dungeon_Random(RECTANGLE_WIDTH(*room));
	*set_y = room->top + random.Dungeon_Random(RECTANGLE_HEIGHT(*room));
};

bool Dungeon_Base::Chekc_Move(int set_ax, int set_ay, int set_bx, int set_by) {
	return true;
};

void Dungeon_Base::Delete_Enemy() {

};

int Dungeon_Base::Get_Enemy_Count() {
	return 0;
};

Enemy* Dungeon_Base::Get_Point_Enemy(int set_x, int set_y) {
	return 0;
};


Enemy* Dungeon_Base::Get_Mob_From_Index(int index) {
	return 0;
};

void Dungeon_Base::Enemy_Array(int set_floor) {
	int x, y;

	//���ꂼ��̕����ɂP�̔z�u����
	//�O�Ԗڂ̓v���C���[�̂��镔���Ȃ̂ŁA�z�u���Ȃ�
	for (int i = 1; i < rectangle_count; ++i) {
		Enemy* p_enemy; //�����o�ϐ��Ɩ��O�̏d���������
		//Vector2D position;

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

void Dungeon_Base::Drop_Item(int set_x, int set_y, Item* set_item) {

}

void Dungeon_Base::Remove_Item(int set_x, int set_y, Item* set_item) {

}

int Dungeon_Base::Get_Room_Index(int set_x, int set_y) {
	return 0;
}

int Dungeon_Base::Attack(Player* set_player, Player* set_target) {
	return 0;
}

bool Dungeon_Base::Make_Enemy(int ai, Enemy* enemy) {
	return true;
};

void Dungeon_Base::Set_Enemy_Parameter(Enemy* enemy, Enemy_Database* enemy_data) {

};

Enemy* Dungeon_Base::Get_Enemy(int set_floor) {
	return 0;
}

