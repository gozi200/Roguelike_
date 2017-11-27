#include"Game_Gui.h"

//�R���X�g���N�^
Game_Gui::Game_Gui() {
	tile = new Tile;
	wall = new Wall;
	enemy_manager = new Enemy_Manager;
	player_ = new Player;
	dungeon01->Make(&player, floor);
}

//�f�X�g���N�^
Game_Gui::~Game_Gui() {
	delete tile;
	delete wall;
	delete enemy_manager;
	delete player_;
}

int Game_Gui::Run() {
	//�Q�[���̏�����
	Game::Init();

	//���߂ɕ`����s��
	Render();

	//�Q�[���V�[���ɂ���Ԃ̓T�C�N�����񂵑�����
	while (Game::Cycle());

	return 0;
}

//�R���\�[���̏�����
void Game_Gui::Console_Init() {

}

//���߂ɕ`����s��
void Game_Gui::Render() {
	//�v���C���[�̍��W���擾
	player.Get_Position(&mx, &my);

	//�v���C���[�̈ʒu����ʂ̒�����
	cx = DUNGEON_WIDTH / 2 - 350; //�Ƃ肠����
	cy = DUNGEON_HEIGHT / 2; 

	//--------------
	//�n�ʂ̕`��
	//--------------

	//�_���W�����̑傳�𑪂�(y��)
	for (y = 0; y < dungeon_base->height; ++y) {
		dy = y * TILE_SIZE - cy; //�^�C���̏c�����A�c�̃^�C�����m�ŋ��������

		//��ʊO�͖���
		if (dy <= -TILE_SIZE / 2 || dy >= WINDOW_Y) {
			continue;
		}

		//�_���W�����̑傳�𑪂�(x��)
		for (x = 0; x < dungeon_base->width; ++x) {
			dx = x * TILE_SIZE - cx; //�^�C���̉������A���̃^�C�����m�ŋ��������
			const Tile_Judge *tile_judge;

			//��ʊO�͖���
			if (dx <= -TILE_SIZE / 2 || dx >= WINDOW_X) {
				continue;
			}

			//�^�C���̏����擾
			tile_judge = dungeon_base->Get_Tile(x, y);

			//�ǂ��ǂ���
			if (tile_judge->is_wall) {
				const Tile_Judge *tile_down = dungeon_base->Get_Tile(x, y + 1);

				//���ɕǂ��Ȃ��Ƃ��́A���Ǘp�̕ǂ�`��
				if (tile_down && tile_down->is_wall == false) {
					wall->Render(CORNER_WALL_GRASS, dx, dy); //Define�萔�g�p
				}

				//����ȊO�̕��ʂ̕ǂ�`��
				else {
					wall->Render(WALL_GRASS, dx, dy); //Define�萔�g�p
				}
				continue; //�ǂł���Ȃ�z�u������̂��Ȃ��̂Ń��[�v�ɖ߂�
			}
			else {
				int a = 0;
			}

			//����K�i��
			if (tile_judge->is_up_stairs) {
				tile->Render(UP_STAIRS, dx, dy); //Define�萔�g�p
			}

			//����K�i��
			else if (tile_judge->is_down_stairs) {
				tile->Render(DOWN_STAIRS, dx, dy); //Define�萔�g�p
			}

			////�A�C�e���������Ă��邩
			//else if (tile_judge->is_drop_item) {
			//	//�A�C�e���摜�}��
			//}

			//����ȊO�͏�
			else {
				tile->Render(TILE_GRASS, dx, dy); //Define�萔�g�p

				//TODO:�ݒ肵�Ă����ʊO�͕ǂ�}��
			}
		}
	}

	/*---------------
	�A�N�^�[�̕`��
	---------------*/
	for (y = 0; y < dungeon_base->height; ++y) {
		dy = y * TILE_SIZE - cy;

		//��ʊO�͖���
		if (dy <= -TILE_SIZE / 2 || dy >= WINDOW_Y) {
			continue;
		}

		dy += 120;

		for (x = 0; x < dungeon_base->width; ++x) {
			const Tile_Judge* tile_judge;
			Enemy* Enemy;

			dx = x * TILE_SIZE - cx;

			//��ʊO�͖���
			if (dx <= -TILE_SIZE / 2 || dx >= WINDOW_X) {
				continue;
			}

			//�^�C�������擾	
			tile_judge = dungeon01->Get_Tile(x, y);

			//�v���C���[�����邩
			if (mx == x && my == y) {
				player_->Render(ARTRIA, dx, dy);
			}

			//���̍��W�̃G�l�~�[�����擾
			enemy_manager = (Enemy_Manager*)dungeon_base->Get_Point_Enemy(x, y);

			if (enemy_manager) {
				//enemy��`��
			}
		}
	}
}



