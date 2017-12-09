#pragma once

class Create_Dungeon {
/*--------
メンバ変数
--------*/

/*-------
メンバ関数
--------*/
public:
	//コンストラクタ 
	Create_Dungeon();
	
	// デストラクタ
	~Create_Dungeon();

	//１フロア分のダンジョンを生成する
	void Create_Floor();
};