#include"Game_Cui.h"

//TODO: �}�W�b�N�i���o�[

//�R���X�g���N�^
Game_Cui::Game_Cui() {
	tile_judge = new Tile_Judge;
	tile_down = new Tile_Judge;
	tile_function = new Tile_Function;
}

//�f�X�g���N�^
Game_Cui::~Game_Cui() {
	delete tile_function;
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

//���߂ɕ`����s�� //p202
void Game_Cui::Render() {

	//�v���C���[�̍��W���擾
	player.Get_Position(&mx, &my);

	//�v���C���[�̈ʒu����ʂ̒�����
	cx = HALF_WINDOW_X;
	cy = HALF_WINDOW_Y;

	//���̕`��
	for (y = 0; y < dungeon_base->height - 1; ++y) { //�_���W�����̑傫�����̍s�����
		dy = y * 32 - cy;

		//��ʊO�͖���
		if (dy <= 16 || dy >= WINDOW_Y) {
			continue;
		}

		dy += 120;

		for (x = 0; x < dungeon_base->width - 1; ++x) {
			dx = x * 32 - cx;

			//��ʊO�͖���
			if (dx <= -16 || dx >= WINDOW_X) {
				continue;
			}

			//�^�C���̏����擾
			tile_judge = dungeon_base->Get_Tile(x, y);

			//�ǂ��ǂ���
			if (tile_judge->is_wall) { //TODO: ���܂ɗ�O��f�� �����̊֌W��
				//�ǂ̉摜��\������
				tile_down = dungeon_base->Get_Tile(x, y + 1);
				if (tile_down && tile_down->is_wall == false) {
					//�������̎��̕ǂ̉摜
				}
				else {
					//�����ǂ̎��̕ǂ̉摜
				}
			continue; //�ǂł���Ȃ�z�u������̂��Ȃ��̂Ń��[�v�ɖ߂�
			}

		//����K�i��
			if (tile_judge->is_up_stairs) {
				tile_function->Draw_Tile(UP_STAIRS); //Define�萔�g�p

			}
			//����K�i��
			else if (tile_judge->is_down_stairs) {
				tile_function->Draw_Tile(DOWN_STAIRS); //Define�萔�g�p
			}

			////�A�C�e���������Ă��邩
			//else if (tile_judge->is_drop_item) {
			//	//�A�C�e���摜�}��
			//}

			//����ȊO�̓X�e�[�W�ɍ������ǂ�\��
			else {
				tile_function->Draw_Tile(TILE_GRASS); //Define�萔�g�p

				//�ݒ肵�Ă����ʊO�͕ǂ�}��
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
