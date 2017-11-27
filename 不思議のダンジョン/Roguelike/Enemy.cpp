#include"Enemy.h"
#include"Dungeon_Base.h"

#include<math.h>

Enemy::Enemy() {
}

Enemy::~Enemy() {
}

bool Enemy::Move_Action(Dungeon_Base* dungeon_base, int mx, int my) {
	int x, y;

	//���݂̍��W���擾
	Get_Position(&x, &y);

	//�ړ��悪�ǂł���Ή������Ȃ�
	if (dungeon_base->Check_Move(x, y, mx, my) == false) {
		return false;
	}

	//�v���C���[�̍��W���擾
	dungeon_base->player->Get_Position(&x, &y);

	//�ړ���Ƀv���C���[�����邩�ǂ���
	if (x == mx && y == my) {
		int damage;

		//�v���C���[�ɍU������
		damage = dungeon_base->Attack(this, dungeon_base->player);

		//���b�Z�[�W�ǉ�
		//hoge��fuga�ɍU��!piyo��hogehoge�_���[�W

		//��l�������񂾂�
		if (dungeon_base->player->actor_status.Is_Dead()) {
			//hoge��fuga	�ɂ��ꂽ
		}
	}

	else {
		//���̏ꏊ�Ƀ����X�^�[�����Ȃ���
		if (dungeon_base->Get_Point_Enemy(mx, my)) {
			//�����X�^�[�����Ȃ��̂ňړ�����
			Set_Position(mx, my);
			return true;
		}

		else {/*�����X�^�[������̂ŉ������Ȃ�*/ }
	}
	return false;
}

void Enemy::Render(int set_graphic_handle, int set_x, int set_y) {//NEXT
	//ID�ɍ��킹�ĉ摜��`�悷��
	//DrawExtendGraph(set_x,
	//					set_y,
	//					set_x + //�摜�̕�width,
	//					set_y + //�摜�̍���height,
	//					//�摜�n���h��graphic_handle, TRUE);
}

int Enemy::Turn(Dungeon_Base* dungeon_base, int count) {
	next_count -= count;

	if (next_count <= 0) {
		next_count += actor_status.activity;
		Move(dungeon_base);
	}
	
	//���̍s���^�[������Ԃ�(0�ȉ��Ȃ�p�����čs���\)
	return next_count;
}