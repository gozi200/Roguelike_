#include"Game_Cui.h"

#include<iostream>

//�R���X�g���N�^
Game_Cui::Game_Cui() {
	tile_judge = new Tile_Judge;
	
	//���̏���ǂݍ���
	tile_data.Set_File_Pass("CSV/Stage/Tile/Tile.csv");
	tile_data.Open_File(); //�ǂݍ���
	//�ǂ̏���ǂݍ���
	wall_data.Set_File_Pass("CSV/Stage/Wall/Wall.csv");
	wall_data.Open_File();
}

//�f�X�g���N�^
Game_Cui::~Game_Cui() {

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
	int x, y;
	int mx, my;

	//�v���C���[�̍��W���擾
	player.Get_Position(&mx, &my);

	for (y = 0; y < dungeon_base->height - 1; ++y) { //�_���W�����̑傫�����̍s�����
		//���s����
	}

	for (x = 0; x < dungeon_base->width - 1; ++x) {

		Enemy_Manager* enemy;

		//�^�C���̏����擾
		tile_judge = dungeon_base->Get_Tile(x, y);

		//�ǂ��ǂ���
		if (tile_judge->is_wall) { //TODO: ���܂ɗ�O��f�� �����̊֌W��
			for (std::vector<SETTING_WALL_DATA>::const_iterator setting_wall = wall_data.set_wall_data.cbegin();
				setting_wall != wall_data.set_wall_data.cend();
				++setting_wall) {
				DrawExtendGraph(HALF_WINDOW_X, HALF_WINDOW_X + setting_wall->width,
					HALF_WINDOW_Y, HALF_WINDOW_Y + setting_wall->height,
					setting_wall->graphic_handle, TRUE);

				continue; //�ǂł���Ȃ�z�u������̂��Ȃ��̂Ń��[�v�ɖ߂�
			}
		}

		//���̍��W�̃G�l�~�[�����擾
		enemy = (Enemy_Manager*)dungeon_base->Get_Point_Enemy(x, y);

		//�v���C���[�����邩
		if (mx == x && my == y) {
			//�v���C���[��}��
		}

		else if (enemy) {
			//�G��}��
		}

		//����K�i��
		else if (tile_judge->is_up_stairs) {
			//����K�i��}��
		}
		//����K�i��
		else if (tile_judge->is_down_stairs) {
			//����K�i��}��
		}

		//����ȊO�͏���\��
		else {
			for (std::vector<SETTING_TILE_DATA>::const_iterator setting_tile = tile_data.set_tile_data.cbegin();
				setting_tile != tile_data.set_tile_data.cend();
				++setting_tile) {
				DrawExtendGraph(HALF_WINDOW_X, HALF_WINDOW_X + setting_tile->width,
								HALF_WINDOW_Y, HALF_WINDOW_Y + setting_tile->height,
								setting_tile->graphic_handle, TRUE);
			}
		}
	}
}
