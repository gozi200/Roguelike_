#include"DxLib.h"
#include"Key_Update.h"

//�L�[�̓��͏�Ԃ��X�V����
int Key_Update::Get_Key(char* set_key) {
	//key = set_key;

//�S�ẴL�[�̓��͏�Ԃ𓾂�
	GetHitKeyStateAll(temporary_key);

	for (int i = 0; i < KEY_NUMBER; ++i) {
		if (temporary_key[i] != 0) { //i�Ԗڂ̃L�[��������Ă�������Z
			++set_key[i];
		}
		else { //������Ă��Ȃ����0��
			set_key[i] = 0;
		}
	}
	return 0;
}