#include"Ally.h"
#include"DxLib.h"

void Ally::Render_Hit_Point() { //�̗̓Q�[�W�̕`��
	if (is_exist) {
		DrawBox(x - 30, y - 10, x + 30,                 y - 17, GetColor(0, 0, 0), FALSE);
		DrawBox(x - 30, y - 10, x - 30 + hit_point / 2, y - 17, GetColor(255, 0, 0), TRUE);
	}
}

void Ally::Render_Experiece_Point() { //�o���l�Q�[�W�̕`��
	if (is_exist) {
		DrawBox(x - 30, y - 10, x + 30,                 y - 17, GetColor(0, 0, 0), FALSE);
		DrawBox(x - 30, y - 10, x - 30 + hit_point / 2, y - 17, GetColor(0, 0, 255), TRUE);
	}
}