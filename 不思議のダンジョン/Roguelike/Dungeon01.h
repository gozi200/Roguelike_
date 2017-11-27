#pragma once

#include"Actor.h"
#include"Random.h"
#include"Define.h"
#include"Dungeon_Base.h"

class Dungeon01 : public Dungeon_Base {
/*////////
�����o�ϐ�
*/////////
public:
	Random random;

/*////////
�����o�֐�
*/////////
public:
	//�R���X�g���N�^
	Dungeon01();

	//�f�X�g���N�^
	~Dungeon01();

	void Make(Actor* player, int floor);

	/*�������
	 @param left ����
	 @param top ���
	 @param right �E��
	 @param bottom ����
	*/
	DUNEON_RECTANGLE* Create_Rectangle(int left, int top, int right, int bottom);

	void Split_Rectangle(bool is_vertical);

	void Create_Room();

	void Connect_Room();

	void Create_Road(int room_A, int room_B);

private:
};