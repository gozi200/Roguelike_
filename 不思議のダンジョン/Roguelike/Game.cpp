#include"Game.h"

//�R���X�g���N�^
Game::Game() {
	dungeon_base = new Dungeon01;
	dungeon01 = dynamic_cast<Dungeon01*>(dungeon_base);
}

//�f�X�g���N�^
Game::~Game() {
	bool isSameDungeon = dungeon_base == dungeon01;

	if (dungeon_base != nullptr) {
		delete dungeon_base;
		dungeon_base = nullptr;
	}
	if (!isSameDungeon && dungeon01 != nullptr) {
		delete dungeon01;
		dungeon01 = nullptr;
	}
}

void Game::Init() {

}

bool Game::Cycle() {
	Run_Action();

	//��ʍX�V
	Render();

	return false;
}

//�ʂ�߂����_���W����(�K)��j������
void Game::Create_Floor() {
	if (dungeon_base) {
		delete dungeon_base;
	}

	dungeon01->Alloc(DUNGEON_WIDTH, DUNGEON_HEIGHT); //Define�萔�g�p

	dungeon01->Make(&player, floor);

	dungeon_base = dungeon01;
}

void Game::Set_Action(ACTION set_action) {

}

void Game::Run_Action() {
	////����ɂ���ď�����U�蕪����
	//switch (action) {
	//case ACTION_MOVE: Action_Move(); break;
	//
	//case ACTION_STEP: Action_Step(); break;
	//}
}

bool Game::Action_Step() {
	return true;
}

bool Game::Move_Check_Enemy(int set_x, int set_y) {
	Actor* enemy;

	//���W�ړ�������Ƃ��ɂ��̐�ɃG�l�~�[�����邩���擾
	enemy = dungeon_base->Get_Point_Enemy(set_x, set_y);

	//�ړ���Ƀ����X�^�[������ꍇ
	if (enemy) {
		int damage;

		//�U�����s��
		damage = dungeon_base->Attack(&player, enemy);

		//���b�Z�[�W��ǉ�
		//Draw_String hoge�̍U���I
		//fuga��piyo�_���[�W�I

		//���̍U���œ|������
		if (enemy->actor_status.Is_Dead()) {
			//���b�Z�[�W�̒ǉ�
			//hoge��fuga��|����

			//�o���l������
			//player.actor_status.Add_Experience_Point(enemy_.enemy_data.getExp(0));
		}
	}

	return false;
}

bool Game::Move_Check_Command() {
	//�A�C�e�����E��
	if (GET_ITEM) {

	}
	return true;
}

void Game::Enemy_Move() {
	bool moved;
	int player_count;

	//�v���C���[�̎����Ă���^�[���J�E���g��i�߂�
	player.actor_status.Turn();

	//�����X�^�[�̃^�[�����v���C���[�̍s���͕��s��
	player_count = player.actor_status.activity;

	do {
		moved = false;

		for (int i = 0; i < dungeon_base->enemy_count; ++i) {
			Enemy* enemy = dungeon_base->m_enemy[i];
			//�����ȃG�l�~�[�̓X�L�b�v
			if (enemy->Is_Dead() == false) {
				continue;
			}

			//�s�����s��
			if (enemy->Turn(dungeon_base, player_count) <= 0) {
				moved = true;
			}
		}
			//do���[�v�P�T�ڂ�Enemy::Turn�̎��ŁA�v���C���[�̍s������^���Ă���̂ŃN���A���Ă���
			player_count = 0;
	
	} while (moved);


	//On_Enemy_Moved(); //NEXT
}