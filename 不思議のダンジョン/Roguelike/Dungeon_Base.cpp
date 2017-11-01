#include"Dungeon_Base.h"

Dungeon_Base::Dungeon_Base() {
	width = DUNGEON_WIDTH; //define�萔�g�p
	height = DUNGEON_HEIGHT; //define�萔�g�p
	rectangle_count = 0;
	tile_judge = new Tile_Judge(); //�^�C�������Ȃ̂����Ȃ̂��𔻒f
}

//�f�X�g���N�^
Dungeon_Base::~Dungeon_Base() {
	delete tile_judge;
}

bool Dungeon_Base::Alloc(int set_x, int set_y) {
	return true;
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
	return 0;
}

int Dungeon_Base::Get_Room_Count() {
	return Get_Rectangle_Count();
};

bool Dungeon_Base::is_Move(int set_x, int set_y) {
	return true;
}

void Dungeon_Base::Fill_Rectangle(int left, int top, int right, int bottom, bool is_wall) {

};

void Dungeon_Base::Fill_H_Line(int left, int right, int y, bool is_wall) { //TODO: H���ĂȂɁH

};

void Dungeon_Base::Fill_V_Line(int top, int bottom, int x, bool is_wall) {

};

void Dungeon_Base::Random_Room_Point(int index, int *px, int *py) {

};

bool Dungeon_Base::Chekc_Move(int ax, int ay, int bx, int by) {
	return true;
};

void Dungeon_Base::Delete_Enemy() {

};

int Dungeon_Base::Get_Enemy_Count() {
	return 0;
};

Enemy* Dungeon_Base::Get_Point_Enemy(int x, int y) {
	return 0;
};


Enemy* Dungeon_Base::Get_Mob_From_Index(int index) {
	return 0;
};

void Dungeon_Base::Enemy_Array(int set_floor) {
	int i, x, y;

	//���ꂼ��̕����ɂP�̔z�u����
	//�O�Ԗڂ̓v���C���[�̂��镔���Ȃ̂ŁA�z�u���Ȃ�
	for (i = 1; i < rectangle_count; ++i) {
		Enemy* p_enemy; //�����o�ϐ��Ƃ̏d���������
		Vector2D position;

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

bool Dungeon_Base::Make_Enemy(int ai, Enemy** enemy) {
	return true;
};

void Dungeon_Base::Set_Enemy_Parameter(Enemy* enemy, Enemy_Database* enemy_data) {

};

Enemy* Dungeon_Base::Get_Enemy(int set_floor) {
	return 0;
}

