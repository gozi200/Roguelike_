#pragma once

#include"Actor.h"

/*////////////////////////
Actor�N���X���p��

���@�A�������Ǘ�����N���X
*////////////////////////

class Ally : public  Actor {
/*////////
�����o�ϐ�
*/////////

protected:
	int experiece_point; //�o���l


/*////////
�����o�֐�
*/////////
public:
	//�̗̓Q�[�W�̕`��
	void Render_Hit_Point(); 

	//�o���l�Q�[�W�̕`��
	void Render_Experiece_Point();
};