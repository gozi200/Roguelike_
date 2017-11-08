#include"Game_Cui.h"

//�R���X�g���N�^
Game_Cui::Game_Cui() { 
	tile_judge = new Tile_Judge;
	tile_down = new Tile_Judge;
	tile_function = new Tile_Function;
	wall_function = new Wall_Function;

	dungeon01->Make(&player, floor);
}

//�f�X�g���N�^
Game_Cui::~Game_Cui() {
	delete tile_function;
	delete wall_function;

}

int Game_Cui::Run() {
	//�Q�[���̏�����
	Game::Init();

	//���߂ɕ`����s��
	Render();

	//�Q�[���V�[���ɂ���Ԃ̓T�C�N�����񂵑�����
	while (Game::Cycle());

	return 0;
}

//�R���\�[���̏�����
void Game_Cui::Console_Init() {

}

//���߂ɕ`����s��
void Game_Cui::Render() {
	//�v���C���[�̍��W���擾
	player.Get_Position(&mx, &my);

	//�v���C���[�̈ʒu����ʂ̒�����
	cx = static_cast<int>(HALF_WINDOW_X) - ACTOR_SIZE_X / 2; //���_�̊֌W�ňʒu���������炷
	cy = static_cast<int>(HALF_WINDOW_Y) - ACTOR_SIZE_Y / 2; //����
	//���̕`��

		//�_���W�����̑傳�𑪂�(y��)
	for (y = 0; y < dungeon_base->height - 1; ++y) {
		dy = y * 90 - cy; //�^�C���̏c�����A�c�̃^�C�����m�ŋ��������

		//��ʊO�͖���
		if (dy < -ACTOR_SIZE_Y || dy > WINDOW_Y) {
			continue;
		}

		//�_���W�����̑傳�𑪂�(x��)
		for (x = 0; x < dungeon_base->width - 1; ++x) {
			dx = x * 90 - cx; //�^�C���̉������A���̃^�C�����m�ŋ��������

			//��ʊO�͖���
			if (dx < -ACTOR_SIZE_X || dx > WINDOW_X) {
				continue;
			}
			//�^�C���̏����擾
			tile_judge = dungeon_base->Get_Tile(x, y);

			//�ǂ��ǂ���
			if (tile_judge->is_wall) { //TODO: ���܂ɗ�O��f�� �����̊֌W��
				//�ǂ̉摜��\������
				tile_down = dungeon_base->Get_Tile(x, y + 1);
				//���ɕǂ��Ȃ��Ƃ�(����)�̕ǂ�`��
				if (tile_down && tile_down->is_wall == false) {
					wall_function->Draw_Wall(CORNER_WALL_GRASS, dx, dy); //Define�萔�g�p
				}
				//����ȊO�̕��ʂ̕ǂ�`��
				else {
					wall_function->Draw_Wall(WALL_GRASS, dx, dy); //Define�萔�g�p
				}
				continue; //�ǂł���Ȃ�z�u������̂��Ȃ��̂Ń��[�v�ɖ߂�
			}

			//����K�i��
			if (tile_judge->is_up_stairs) {
				tile_function->Draw_Tile(UP_STAIRS, dx, dy); //Define�萔�g�p
			}
			//����K�i��
			else if (tile_judge->is_down_stairs) {
				tile_function->Draw_Tile(DOWN_STAIRS, dx, dy); //Define�萔�g�p
			}

			////�A�C�e���������Ă��邩
			//else if (tile_judge->is_drop_item) {
			//	//�A�C�e���摜�}��
			//}

			//����ȊO�͏�
			else {
				tile_function->Draw_Tile(TILE_GRASS, dx, dy); //Define�萔�g�p

				//TODO:�ݒ肵�Ă����ʊO�͕ǂ�}��
			}
		}
	}
}

////���̍��W�̃G�l�~�[�����擾
//enemy = (Enemy_Manager*)dungeon_base->Get_Point_Enemy(x, y);
//
//else if (enemy) {
//	//�G��}��
//}
////�v���C���[�����邩
//if (mx == x && my == y) {
//	//�v���C���[��}��
//}
