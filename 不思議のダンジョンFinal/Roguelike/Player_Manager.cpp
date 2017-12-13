#include "Player_Manager.h"

// �R���X�g���N�^
Player_Manager::Player_Manager() {
	player = std::make_shared<Player>();
	dungeon_manager = std::make_shared<Dungeon_Manager>();
}

// �f�X�g���N�^
Player_Manager::~Player_Manager() {

}

//�@�v���C���[��z�u����
void Player_Manager::Player_Arrange() { // TODO: memory�ɓ���Ƃ��񂲂���������������
	player->Get_Position(&map_x, &map_y);

	character_x = (map_x - 10) * TILE_SIZE;
	character_y = (map_y - 7)  * TILE_SIZE;

	for (int y = 0; y < dungeon_manager->height; ++y) {
		dungeon_y = y * TILE_SIZE - character_y;

		// ��ʊO�͖���
		if (dungeon_y <= -TILE_SIZE / 2 || dungeon_y >= WINDOW_Y) {
			continue;
		}

		dungeon_y += 120; // �}�W�b�N�i���o�[

		for (int x = 0; x < dungeon_manager->width; ++x) {
			const Tile_Judge* tile_judge;

			dungeon_x = x * TILE_SIZE - character_x;

			// ��ʊO�͖���
			if (dungeon_x <= -TILE_SIZE || dungeon_x >= WINDOW_X) {
				continue;
			}

			// �^�C���̏����擾
			tile_judge = dungeon_manager->Get_Tile(x, y);

			// �v���C���[������Ƃ���ɕ`��
			if (map_x == x && map_y == y) {
				player->Render(dungeon_x, dungeon_y, OKITA);
			}
		}
	}
}
