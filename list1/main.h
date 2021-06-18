#pragma once
#include "DxLib.h"
#include<list>
#include <memory>

using namespace std;

#define WIDTH 800 //windowサイズ　横
#define HEIGHT 600 //window サイズ　縦

struct Pos { float x; float y; };//位置

struct Vec { float x; float y; };//移動ベクトル

//ベースクラス
class Bace 
{
private:
public:
	int ID{ -1 };//オブジェクトのID
	virtual int Action(list<unique_ptr<Bace>>& bace) = 0;
	virtual void Draw() = 0;//描画

};