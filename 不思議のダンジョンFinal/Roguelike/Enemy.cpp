#include "Enemy.h"

// �R���X�g���N�^
Enemy::Enemy() {

}

// �f�X�g���N�^
Enemy::~Enemy() {

}

// �^�[���̏I��
void Enemy::Turn_End() {
	Get_Turn_Count(1);

	if (Is_Dead()) {
		//TODO: �A�C�e���𗎂Ƃ�
	}
}