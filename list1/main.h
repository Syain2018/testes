#pragma once
#include "DxLib.h"
#include<list>
#include <memory>

using namespace std;

#define WIDTH 800 //window�T�C�Y�@��
#define HEIGHT 600 //window �T�C�Y�@�c

struct Pos { float x; float y; };//�ʒu

struct Vec { float x; float y; };//�ړ��x�N�g��

//�x�[�X�N���X
class Bace 
{
private:
public:
	int ID{ -1 };//�I�u�W�F�N�g��ID
	virtual int Action(list<unique_ptr<Bace>>& bace) = 0;
	virtual void Draw() = 0;//�`��

};