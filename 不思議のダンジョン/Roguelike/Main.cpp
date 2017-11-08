#include"DxLib.h"
#include"Title.h"
#include"Define.h"
#include"Scene_Manager.h"


//�L�[�̓��͏�Ԃ��X�V����
int Update_Key(char* key) {
	char tmpKey[KEY_NUMBER]; //���݂̃L�[�̓��͏�Ԃ����[

	//�S�ẴL�[�̓��͏�Ԃ𓾂�
	GetHitKeyStateAll(tmpKey);

	for (int i = 0; i < KEY_NUMBER; ++i) {
		if (tmpKey[i] != 0) { //i�Ԗڂ̃L�[��������Ă�������Z
			++key[i];
		}
		else { //������Ă��Ȃ����0����
			key[i] = 0;
		}
	}
	return 0;
}

//������false�Ȃ烋�[�v�𔲂��Q�[���I��
bool Process(char key[KEY_NUMBER]) { //Defnie�萔�g�p
	if (ScreenFlip()) return false; //����ʂƓ���ւ���
	if (ProcessMessage()) return false; //window����̐����m�F�������ōs��
	if (ClearDrawScreen()) return false; //���݂����ʂ̗���ʂ�����
	if (GetHitKeyStateAll(key)) return false; //�L�[�{�[�h�̓��͂��擾

	return true;
}

//Win32�Ȃ̂�main��WINAPI����
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(true); //�E�B���h�E���[�h�ɕϊ�
	SetGraphMode(WINDOW_X, WINDOW_Y, 32); //��ʂ̑傫���Ǝg�p����F���@//Define�萔�g�p
	if (DxLib_Init() == -1) return -1; //DX���C�u���������� �G���[���N�����炽�����ɏI��
	SetWindowText("�s�v�c�̃_���W����"); //�E�B���h�E�^�C�g��
	SetDrawScreen(DX_SCREEN_BACK); //�������ɗ���ʂ�`��

	char key[KEY_NUMBER]; //�L�[�擾 Define�萔�g�p

/*////////////////////
�N���X�̃C���X�^���X��
*/////////////////////
	Scene_Manager* scene_manager; //�Ǘ��V�X�e���𓮓I�m��
	scene_manager = new Scene_Manager(key);
	scene_manager->scene = new Title(scene_manager); //�^�C�g���𓮓I�m��

	while (ProcessMessage() != -1) {
		ScreenFlip();
		ClearDrawScreen();

		//�Q�[�����[�v(�n)
		scene_manager->Render(); //���t���[���Ăяo��
		scene_manager->Update(); //���t���[���Ăяo��

		int start_time = GetNowCount();
		int endTime = GetNowCount();
		WaitTimer(1000 / 60 - (endTime - start_time)); //60FPS

		if (CheckHitKey(KEY_INPUT_DELETE) == 1) break;
	}
	fclose(stdout);
	delete scene_manager; //�N���X�̉��

	DxLib_End(); //DX���C�u�����g�p�̏I������

	return 0; //�\�t�g�̏I��
}