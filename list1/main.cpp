//���X�g��
//Dx���C�u�����g�p
#pragma once
#include "main.h"
#include "char.h"


//���j�[�N�|�C���^���g�������X�g
list<unique_ptr<Bace>>bace;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE,
	_In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	//window���[�h�؂�ւ�
	ChangeWindowMode(TRUE);
	//window�T�C�Y
	SetGraphMode(WIDTH, HEIGHT, 32);

	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1)return -1;

	//window�̖��O
	SetWindowText("���X�g");

	//�o�b�N�o�b�t�@���g�p
	SetDrawScreen(DX_SCREEN_BACK);

	//���X�g�Ƀv���C���[�ǉ�
	auto a = (unique_ptr<Bace>)new Player();
	bace.push_back(move(a));

	//���C�����[�v
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//���X�g�̃��\�b�h�����s
		for (auto i = bace.begin(); i != bace.end(); i++)
			(*i)->Action(bace);//�e�I�u�W�F�N�g�̏���
		
		ScreenFlip();//��ʍX�V
		//��O����
		if ((ProcessMessage() == -1))break;
	}

	DxLib_End();

	return 0;
}//aaaaaaaaaa
//aaaaaaaaaa