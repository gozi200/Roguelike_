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

//�T�C�N�����s
bool Game::Cycle() {
	Run_Action();

	//��ʍX�V
	Render();

	return false;
}

//�����̎��s
void Game::Run_Action() {
	////����ɂ���ď�����U�蕪����
	//switch (action) {
	//case ACTION_MOVE: Action_Move(); break;
	//
	//case ACTION_STEP: Action_Step(); break;
	//}
}

int Game::Message_Items(eITEM_TYPE filter) //NEXT
{
	int count;
	char sz_buffer[128];
	Item* item;

	count = 0;

	sz_buffer[0] = '\0';

	for (int i = 0; i < MAX_STOCK_ITEM; i++) {
		item = &player.actor_status.items[i];

		if (item->type == ITEM_TYPE_NONE) {
			continue;
		}

		// ���Ӓ蒊�o���H
		if (filter & ITEM_TYPE_UNIDENTIFIED) {
			// �Ӓ�ς݃A�C�e���Ȃ疳��
			if (item->unidentified == false) {
				continue;
			}
		}

		else {
			// �\���A�C�e�����قȂ�Ζ���
			if (filter != ITEM_TYPE_NONE && (item->type & filter) == 0) {
				continue;
		}
	}
		//������̕\�� SEND sprintf_s(sz_buffer + strlen(sz_buffer), sizeof(sz_buffer) - strlen(sz_buffer), "%c:%s ", 'A' + count, item->Get_Name());
		count++;

		// �P�s�T�ł܂Ƃ܂�Ε\��
		if ((count % 5) == 0) {
			//message(MESTYPE_SELECT, sz_buffer);
			sz_buffer[0] = '\0';
		}
	}

	// �A�C�e�����Ȃ��H
	if (count == 0) {
		return 0;
	}

	// �o�b�t�@�̎c����\��
	if (strlen(sz_buffer)) {
		//message(MESTYPE_SELECT, sz_buffer);
	}

	// �I�𕶂�\��
	if (count == 1) {
		//message(MESTYPE_INFO, "0/A �L�[�ŃA�C�e����I���B0 �L�[�ŃL�����Z��");
	}

	else {
		//message(MESTYPE_INFO, "0/A-%c �L�[�ŃA�C�e����I���B0 �L�[�ŃL�����Z��", 'A' + count - 1);
	}
	return count;
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

/*-----------
�A�C�e�����E��
------------*/
void Game::Action_Get_Item() {
	int index;
	Item* item;
	int mx, my;

	if (action_count == 0) {
		char sz_buffer[256];
		//�v���C���[�̌��݂̍��W���擾
		player.Get_Position(&mx, &my);

		//�����Ă���A�C�e�����
		item = dungeon_base->Get_Tile(mx, my)->drop_item;

		sz_buffer[0] = '\0';

		//�o�b�t�@�̐퓬�̂��̂̂ݕ\������
		while (item && action_count < 15) { //MAGICNUMBER
			//�o�b�t�@�ɂP�s���̃A�C�e�����X�g�����
			//������\�� //SAID
			++action_count;

			//�T�A�C�e�����łP�s�\��
			if ((action_count % 5) == 0); {
				//������\�� //SAID
				sz_buffer[0] = '\0';
			}
			item = item->next;
		}

		//�E�����̂��Ȃ��������̏���
		if (action_count == 0) {
			//�ړ������ɖ߂�
			Set_Action(ACTION_MOVE);
			//������\�� //SAID
			return;
		}

		//�o�b�t�@�̎c����\��
		if (strlen(sz_buffer)) {
			//�����̕\�� //SAID
		}

		//�I�𕶂�\��
		if (action_count == 1) {
			//�����̕\�� //SEND
		}

		else {
			//�����̕\�� //SEND
		}
		return;
	}

	//"0"�L�[�̓L�����Z��
	if (PUSH_0_KEY) {
		//�ړ������ɖ߂�
		Set_Action(ACTION_MOVE);
		//�����̕\�� //SEND
		return;
	}

	index = -1;
	for (int i = 0; i < action_count; ++i) {
		if (PUSH_A_KEY); { // Amended �L�[���͂̏���   �{�ł� if(keys['A'+i] & 0x80 )
			index = i;
			break;
		}
	}
	
	if (index == 1) {
		return;
	}

	//�I�������A�C�e�������̃A�C�e������T��
	player.Get_Position(&mx, &my);
	item = dungeon_base->Get_Tile(mx, my)->drop_item;
	
	while (item) {
		if (--index == 0) {
			//�A�C�e�����E��
			if (player.actor_status.Get_Item(item) == false) {
				//�����̕\�� //SEND
				
				//������A�C�e������菜��
				dungeon_base->Remove_Item(mx, my, item);
			}

			else {
				//�����̕\�� //SEND
				Set_Action(ACTION_MOVE);
				return;
			}
			//�ړ������ɖ߂�
			Set_Action(ACTION_MOVE);
			return;
		}
		item = item->next;
	}
}

void Game::Action_Equip() {
	int index;
	Item* item;
	const eITEM_TYPE item_filter = (eITEM_TYPE)(ITEM_TYPE_WEAPON | ITEM_TYPE_SHIELD | ITEM_TYPE_ACCESSORIE);

	if (action_count == 0) {
		//�A�C�e���ꗗ��\�����A�Y���A�C�e���������Ă��邩���ׂ�
		action_count = Message_Items(item_filter);

		if (action_count == 0) {
			//�����̕\���@SEND
			Set_Action(ACTION_MOVE);
			return;
		}
	}

	//�O�L�[�̓L�����Z��
	if (PUSH_0_KEY) {
		//�ړ������ɖ߂�
		//�����̕\���@SEND
		Set_Action(ACTION_MOVE);
		return;
	}

	index = -1;
	for (int i = 0; i < action_count; ++i) {
		if (PUSH_A_KEY) { //Amended Action_Get_Item�Q��
			index = i;
			break;
		}
	}
	
	if (index == -1) {
		return;
	}

	//�I�������A�C�e�����擾
	item = player.actor_status.Get_Item_Flom_Index(item_filter, index);

	//�I�������A�C�e���𑕔�����
	//�����̕\���@SEND

	//On_Equip_Chanfe();

	//�I�������Ɉړ�
	Set_Action(ACTION_MOVE);
}

void Game::Action_Drop_Item() {
	int index;
	int mx, my;
	Item* item;
	const eITEM_TYPE item_filter = ITEM_TYPE_NONE;

	if (action_count == 0) {
		//�A�C�e���ꗗ��\�����A�Y���A�C�e���������Ă��邩���ׂ�
		action_count = Message_Items(item_filter);

		if (action_count == 0) {
			//�ړ������ɖ߂�
			//�����̕\��
			Set_Action(ACTION_MOVE);
		}
		//�\�����s�������U������
	}

	//�O�L�[�̓L�����Z��
	if (PUSH_0_KEY) {
		//�ړ������ɖ߂�
		//�����̕\��
		Set_Action(ACTION_MOVE);
		return;
	}

	index = -1;
	for (int i = 0; i < action_count; ++i) {
		if (PUSH_A_KEY) { //ActionGet_Item�Q��
			index = i; 
			break;
		}
	}

	if (index == -1) {
		return;
	}

	//�I�������A�C�e�����擾
	item = player.actor_status.Get_Item_Flom_Index(item_filter, index);
	
	//�v���C���[�̍��W�Ǝ擾
	player.Get_Position(&mx, &my);

	//�I�������A�C�e�����_���W�����Ɏ̂Ă�
	Item* drop_item = new Item;
	drop_item->Copy(item);
	dungeon_base->Drop_Item(mx, my, drop_item);

	//�����̕\�� SEND
	item->Erase();

	//�I�������Ɉړ�
	Set_Action(ACTION_MOVE);
}

/*------------
�A�C�e�����g��
-------------*/
void Game::Action_Use_Item() {
	int index;
	const eITEM_TYPE item_filter = ITEM_TYPE_USEITEM;
	bool used;

	if (action_count == 0) {
		//�A�C�e���ꗗ��\�����A�Y���A�C�e���������Ă��邩���ׂ�
		action_count = Message_Items(item_filter);

		if (action_count == 0) {
			//�ړ������ɖ߂�
			//�����̕\�� SEND
			Set_Action(ACTION_MOVE);
			return;
		}
	}

	//0�L�[�̓L�����Z��
	if (PUSH_0_KEY) {
		//�ړ������ɖ߂�
		//�����̕\�� SEND
		Set_Action(ACTION_MOVE);
		return;
	}

	index = -1;
	for (int i = 0; i < action_count; ++i) {
		if (PUSH_A_KEY) {
			index = i;
			break;
		}
	}
		if (index == -1) {
			return;
		}
	
	//�I�������A�C�e�����擾
	use_item = player.actor_status.Get_Item_Flom_Index(item_filter, index);
	
	//�����̕\�� SEND

	//�I�������A�C�e���̃J�e�S���ŏ����𕪂���
	switch (use_item->parameter[0]) {
	//HP��
	case HP_CURE:
			//�A�C�e���̌��ʂ𔭓�
			used = Use_Item_HP_Cure(use_item);

	//�H��
	case HUNGER_CURE:
			//�A�C�e���̌��ʂ𔭓�
			used = Use_Item_Food(use_item);
			break;
	}

	//�A�C�e�����g�p�������ǂ���
	if (used) {
		//�A�C�e��������
		use_item->Erase();

		//�s�����N�������̂ŁA�^�[���I��
		Enemy_Move();
	}

	//�I�������Ɉړ�
	Set_Action(ACTION_MOVE);
}

void Game::Set_Action(ACTION set_action) {
	//���ʕϐ��̕ύX
	action = set_action;

	//�ėp�ϐ��̃[�����Z�b�g
	action_count = 0;
}

bool Game::Action_Step() {
	return true;
}

bool Game::Use_Item_HP_Cure(Item * item) {
	int value = item->parameter[1];

	//HP����
	value = player.actor_status.Cure_Hit_Point(value);

	if (value < 0) {
		//�����̕\�� SEND
	}

	else {
		//�����̕\�� SEND
	}

	return true;
}

bool Game::Use_Item_Food(Item * item) {
	//�����x�̉�
	player.actor_status.Add_Hunger_Point(item->parameter[1]);

	//�����̕\�� SEND

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

			//�o���l������ TODO:
			//player.actor_status.Add_Experience_Point(enemy_.enemy_data.getExp(0));
		}
	}

	return false;
}

bool Game::Move_Check_Command() {
	//�A�C�e�����E��
	if (PUSH_G_KEY) {

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


	//On_Enemy_Moved();


}