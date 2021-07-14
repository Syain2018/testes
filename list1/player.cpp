#pragma once
#include "char.h"

//�R���X�g���N�^
Player::Player()
{
	x = 0;
	y = 0;
	count = 0;
	check = 0;
	save_count = 0;

	button_flag = 0;
	player_flag = 0;
	check_flag = false;
	victory_flag = false;
	font_flag = false;
	title_flag = false;
	sound_flag = false;

	SetFontSize(45);//�t�H���g�̑傫��

	for (int i = 0; i < 50; i++)
	{
		save[i] = 0;
	}

	//�摜&���y�f�[�^�̓ǂݍ���
	Button[0] = LoadGraph("image\\button1.png");

	Button[1] = LoadGraph("image\\button2.png");

	Button[2] = LoadGraph("image\\button3.png");

	Button[3] = LoadGraph("image\\button4.png");

	Button[4] = LoadGraph("image\\button5.png");

	Button[5] = LoadGraph("image\\button6.png");

	Button[6] = LoadGraph("image\\button7.png");

	Button[7] = LoadGraph("image\\button8.png");

	Button[8] = LoadGraph("image\\button9.png");

	Sound = LoadSoundMem("sound\\answer.mp3");

	Sound2 = LoadSoundMem("sound\\button.mp3");

	Sound3 = LoadSoundMem("sound\\not_answer.mp3");

	Sound4 = LoadSoundMem("sound\\BGM.wav");

}

//����
int Player::Action(list<unique_ptr<Bace>>& bace)
{
	GetMousePoint(&x, &y);//���݂̃}�E�X�̈ʒu�擾

	//��ʐ؂�ւ��̏���
	if ((CheckHitKey(KEY_INPUT_RETURN)))
	{
		title_flag = true;
	}

	//BGM�̏���
	if (title_flag == true && save_count == 0 && sound_flag == false)
	{
		sound = PlaySoundMem(Sound4, DX_PLAYTYPE_BACK);
		sound_flag = true;
	}

	//�e�{�^���������ꂽ���̏���
	if (button_flag == 0 && !(CheckHitKey(KEY_INPUT_RETURN)) && title_flag == true)
	{
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			button_flag = Hit(x, y);
		}
	}

	//�z��Ɋi�[����Ă��鐔���Ɖ����ꂽ�����������������ʂ��鏈��
	if (button_flag != 0 && save_count > count && check_flag == false)
	{
		//��������
		if (save[count] == button_flag)
		{
			count += 1;
			check_flag = true;
			sound = PlaySoundMem(Sound, DX_PLAYTYPE_BACK);

			true_flag = true;
		}
		//�Ԉ���Ă��鎞
		else
		{
			sound = PlaySoundMem(Sound3, DX_PLAYTYPE_BACK);
			check_flag = true;
			victory_flag = true;
			true_flag = false;
		}
	}

	//�z��ɐ������i�[����Ă��Ȃ��������ɍs������
	else if (button_flag != 0 && save_count <= count && check_flag == false)
	{
		save[count] = button_flag;
		count += 1;
		save_count = count;
		count = 0;
		check_flag = true;
		font_flag = true;
		true_flag = false;

		//�v���C���[�̔Ԃ���シ��
		if (player_flag == 0)
		{
			player_flag = 1;
			sound = PlaySoundMem(Sound2, DX_PLAYTYPE_BACK);
		}

		else if (player_flag == 1)
		{
			player_flag = 0;
			sound = PlaySoundMem(Sound2, DX_PLAYTYPE_BACK);
		}
	}

	//�{�^���������ꂽ���̏���
	if (check_flag == true && victory_flag == false)
	{
		if (font_flag == true)
		{
			j = 0;
			for (int i = 0; i < save_count; i++)
			{
				if (j % 20 == 0 && j != 0)
				{
					j = 0;
				}
				j++;
			}
		}
	}

	if (button_flag != 0 && victory_flag == false)
	{
		//flag�ނ����������鏈��
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			button_flag = 0;
			check_flag = false;
			font_flag = false;
			true_flag = false;
		}
	}

	return 0;
}

//�`��
void Player::Draw()
{
	if (title_flag == false)
	{
		SetFontSize(80);
		DrawString(200, 170, "�L���Q�[��", GetColor(255, 0, 0));
		SetFontSize(45);
		DrawString(100, 400, "   �Q�[�����n�߂�ɂ�\n\nENTER�L�[�������Ă�������", GetColor(255, 255, 255));
	}

	else if (title_flag == true)
	{
		//�摜�̕\������
		for (int i = 1; i < 10; i++)
		{
			if (i % 2 == 1)
				DrawGraph(20 + (i * 80 - 80), 350, Button[i - 1], TRUE);
			else
				DrawGraph(20 + (i * 80 - 80), 350 + 130, Button[i - 1], TRUE);
		}
	}

	//�ǂ��炩�̏������m�肵�����̏���
	if (victory_flag == true && player_flag == 0)
	{
		DrawString(250, 100, "2P�̏����ł�", GetColor(255, 0, 0));
	}

	else if (victory_flag == true && player_flag == 1)
	{
		DrawString(250, 100, "1P�̏����ł�", GetColor(255, 0, 0));
	}

	//�{�^����������Ď�Ԃ��ς�鎞�̏���
	if (check_flag == true && victory_flag == false)
	{
		if (font_flag == true)
		{
			if (button_flag != 0)
			{
				DrawFormatString(175, 160, GetColor(255, 0, 0), "%d�{�^����������܂���", button_flag);
				DrawString(240, 220, "��Ԃ��ς��܂�", GetColor(255, 255, 255));
				DrawString(120, 280, "ENTER�L�[�������Ă�������", GetColor(255, 255, 255));
			}
		}
	}

	//���͂����������������������̏���
	if (true_flag == true)
	{
		DrawString(120, 200, "���������������͂���܂���", GetColor(255, 0, 0));
	}

	//���ݓ��͂���Ă��鐔�������邽�߂̏���
	if (font_flag == true)
	{
		for (int i = 0; save[i] != 0; i++)
		{
			DrawFormatString(70 + i * 30, 30, GetColor(255, 255, 255), "%d", save[i]);
		}
	}

	//�ҋ@��ʂɕ�����\�����鏈��
	if (button_flag == 0 && save_count > count && title_flag == true)
	{
		DrawString(90, 150, "��قǓ��͂��ꂽ������\n        �S���I�����Ă�������", GetColor(255, 255, 255));
	}

	else if (button_flag == 0 && save_count == 0 && title_flag == true)
	{
		DrawString(150, 150, "��������͂��Ă�������", GetColor(255, 255, 255));
	}

	else if (button_flag == 0 && save_count <= count && title_flag == true)
	{
		DrawString(90, 150, "�V���ɐ�������͂��Ă�������", GetColor(255, 255, 255));
	}

}