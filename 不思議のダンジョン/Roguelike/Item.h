#pragma once

#include"Object.h"

//------------------------
//Objectπp³

//ACeπΗ·ιNX
//------------------------

//TODO: Equipment(υi)NXΖtoolNXΕͺ―ιH

enum ITEMTYPE {
	ITEMTYPE_NONE = 0,		     //Θ΅
	ITEMTYPE_USEITEM = (1<<1),   //ΑΥi
	ITEMTYPE_WEAPON = (1<<2),    //ν
	ITEMTYPE_SHIELD = (1<<3),    //c
	ITEMTYPE_ACCESSORIE = (1<<4),//όi
};

enum USEITEM_CATEGORY {
	HP_CURE, //HPρ 
	MP_CURE, //MPρ
};

class Item : public Object {
public:
	ITEMTYPE type;
};