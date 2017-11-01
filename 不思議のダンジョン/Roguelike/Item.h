#pragma once

#include"Object.h"

/*/////////////////////////
Objectを継承

アイテムを管理するクラス
/////////////////////////*/

//TODO: Equipment(装備品)クラスとtoolクラスで分ける？

class Item : public Object {
protected:
	int NUMBER; //アイテムのID

public:
	//毎フレーム呼び出す処理を書く
	virtual void Update() = 0;

	/*スポーンしたアイテムを配置
	*@param x x座標
	*@param y y座標
	*/
	virtual void Arrange(Vector2D position) = 0;

	void Render(); //いる？
};