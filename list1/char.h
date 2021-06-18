#pragma once
#include "main.h"

//プレイヤー
class Player:public Bace
{
private:
	//マウスポインタで使用
	int x = 0;
	int y = 0;

	int flag = 0;

	//配列関係で使用
	int save[50];
	int check[50];
	int count;
	int j;

public:
	int img{ 0 };//画像
	Pos pos{ 0.0f,0.0f };//位置
	Vec vec{ 0.0f,0.0f };//移動ベクトル

	//コンストラクタ
	Player();
	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};