#include"DxLib.h"
#include"Object.h"
#include"Define.h"

Object::Object() : is_exist(false) {}

bool Object::Get_Exist() const {
	return is_exist;
}

int Object::Get_X() const {
	return x;
}

int Object::Get_Y() const {
	return y;
}

double Object::Get_Collision() const {
	return collision;
}

double Object::Get_Hostility_Flag() const {
	return is_hostility_flag;
}

//void Object::Render() { //Ç¢ÇÈÅH
//	if (is_exist) {
//		DrawExtendGraph(x, y, static_cast<int>(1.0), static_cast<int>(1.0), graphic_handle, TRUE);
//	}
//}