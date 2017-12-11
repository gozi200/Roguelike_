#include"DxLib.h"
#include"Define.h"

#include"Game_Scene.h" // TODO: �ЂƂ܂��͒��ڃQ�[���V�[����

// �L�[�̓��͏�Ԃ��X�V����
static int Update_Key(char* key) {
	char tmpKey[KEY_NUMBER]; // ���݂̃L�[�̓��͏�Ԃ����[

	 // �S�ẴL�[�̓��͏�Ԃ𓾂�
	GetHitKeyStateAll(tmpKey);

	for (int i = 0; i < KEY_NUMBER; ++i) {
		if (tmpKey[i] != 0) { // i�Ԗڂ̃L�[��������Ă�������Z
			++key[i];
		}
		else { // ������Ă��Ȃ����0����
			key[i] = 0;
		}
	}
	return 0;
}

// ������false�Ȃ烋�[�v�𔲂��Q�[���I��
bool Process(char key[KEY_NUMBER]) { // Defnie�萔�g�p
	if (ScreenFlip()) return false;           // ����ʂƓ���ւ���
	if (ProcessMessage()) return false;       // window����̐����m�F�������ōs��
	if (ClearDrawScreen()) return false;      // ���݂����ʂ̗���ʂ�����
	if (GetHitKeyStateAll(key)) return false; // �L�[�{�[�h�̓��͂��擾

	return true;
}

// Win32�Ȃ̂�main��WINAPI����
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(true);               // �E�B���h�E���[�h�ɕϊ�
	SetGraphMode(WINDOW_X, WINDOW_Y, 32); // ��ʂ̑傫���Ǝg�p����F���@//Define�萔�g�p
	if (DxLib_Init() == -1) return -1;    // DX���C�u���������� �G���[���N�����炽�����ɏI��
	SetWindowText("�s�v�c�̃_���W����");    // �E�B���h�E�^�C�g��
	SetDrawScreen(DX_SCREEN_BACK);        // �������ɗ���ʂ�`��

	char key[KEY_NUMBER]; // �L�[�擾 Define�萔�g�p

	// �V�[�����C���X�^���X��---------
	Game_Scene* game_scene;
	game_scene = new Game_Scene();
	// -------------------------------

	while (ProcessMessage() != -1) {
		ScreenFlip();
		ClearDrawScreen();

		// �X�V�������A�V�����󋵂�`�悷��
		game_scene->Update();
		game_scene->Render();
		// -----------------------------

		int start_time = GetNowCount();
		int endTime = GetNowCount();
		WaitTimer(1000 / 60 - (endTime - start_time)); // 60FPS

		if (CheckHitKey(KEY_INPUT_DELETE) == 1) break;
	}
	fclose(stdout);

	delete game_scene; //���

	DxLib_End(); // DX���C�u�����g�p�̏I������

	return 0; // �\�t�g�̏I��
}

////�v���C���[�̃C���X�^���X��(��)
//Actor_Factory* actor_factory = new Actor_Factory();
//Vector2D vec;
//vec.x = 0;
//vec.y = 0;
//actor_factory->Create_Actor("player");
//delete actor_factory;


/*
����: Dungeon_Base = Dungeon_Manager
	  Game         = Create_Dungeon

*/


/*-----------------------
����J�n���� 2017/12/08
-----------------------*/