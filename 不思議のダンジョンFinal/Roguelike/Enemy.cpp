#include "Enemy.h"

// �R���X�g���N�^
Enemy::Enemy() {

}

// �f�X�g���N�^
Enemy::~Enemy() {

}

// �^�[���̏I��
void Enemy::Turn_End() {
	++turn_count;

	if (Is_Dead()) {
		//TODO: �A�C�e���𗎂Ƃ�
	}
}