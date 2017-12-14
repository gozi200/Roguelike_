#include "Dungeon_GUI.h"

// �R���X�g���N�^
Dungeon_GUI::Dungeon_GUI() {
	tile = std::make_shared<Tile>();
	wall = std::make_shared<Wall>();
//	dungeon_manager = new Dungeon_Manager();
	//player_manager = std::make_shared<Player_Manager>();

//	player = std::make_shared<Player>();
}

// �f�X�g���N�^
Dungeon_GUI::~Dungeon_GUI() {

}

// �`��
void Dungeon_GUI::Render() {
	// TODO:�@�v���C���[�̍��W���擾

	// �v���C���[�̈ʒu����ʂ̒�����
	//player_manager->character_x = DUNGEON_WIDTH / 2 - 350;
	//player_manager->character_y = DUNGEON_HEIGHT / 2;

	/*---------
	�n�ʂ̕`��
	---------*/
	// �_���W�����̑傫�����͂���(�c��)
	for (y = 0; y < Get_Height(0); ++y) {
		dungeon_y = y * TILE_SIZE - character_y;

		// ��ʊO�͖���
		if (dungeon_y <= -TILE_SIZE / 2 || dungeon_y >= WINDOW_Y) {
			continue;
		}

		// �_���W�����̑傳�𑪂�(x��)
		for (x = 0; x < Get_Width(0); ++x) {
			const Tile_Judge* tile_judge;

			dungeon_x = x * TILE_SIZE - character_x;

			// ��ʂ͖���
			if (dungeon_x <= -TILE_SIZE / 2 || dungeon_x >= WINDOW_X) {
				continue;
			}

			// ���̏����擾
			tile_judge = Get_Tile(x, y);

			// �ǂ��ǂ���
		if (tile_judge->is_wall) {
				const Tile_Judge* tile_down = Get_Tile(x, y + 1);

				// ���ɕǂ��Ȃ��Ƃ��́B���Ǘp�̕ǂ�`��
				if (tile_down && tile_down->is_wall == false) {
					wall->Render(CORNER_WALL_GRASS, dungeon_x, dungeon_y); // Define�萔�g�p
				}
				// ����ȊO�͕��ʂ̕ǂ��g�p
				else {
					wall->Render(WALL_GRASS, dungeon_x, dungeon_y); // Define�萔�g�p
				}
				continue; //�ǂł���Ȃ�z�u������̂��Ȃ��̂Ń��[�v�ɖ߂�
			}

			// ����K�i��
			if (tile_judge->is_upstairs) {
				tile->Render(UP_STAIRS, dungeon_x, dungeon_y); // Define�萔�g�p
			}
			
			//����ȊO�͏�
			else {
				tile->Render(TILE_GRASS, dungeon_x, dungeon_y);
			}
			// TODO: ��ʊO�͈Í��ł͂Ȃ��ǂ�}��
		}
	}
}