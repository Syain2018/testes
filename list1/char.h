#pragma once
#include "main.h"

//�v���C���[
class Player:public Bace
{
private:
	//�}�E�X�|�C���^�Ŏg�p
	int x = 0;
	int y = 0;

	int flag = 0;

	//�z��֌W�Ŏg�p
	int save[50];
	int check[50];
	int count;
	int j;

public:
	int img{ 0 };//�摜
	Pos pos{ 0.0f,0.0f };//�ʒu
	Vec vec{ 0.0f,0.0f };//�ړ��x�N�g��

	//�R���X�g���N�^
	Player();
	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};