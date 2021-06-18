#pragma once
#include "char.h"

//コンストラクタ
Player::Player()
{
	x = 0;
	y = 0;
	flag = 0;
	count = 0;
	for (int i = 0; i < 50; i++)
	{
		save[i] = 0;
		check[i] = 0;
	}
}

//処理
int Player::Action(list<unique_ptr<Bace>>& bace)
{
	//メイン
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		GetMousePoint(&x, &y);
		SetFontSize(45);

		int Button = LoadGraph("image\\button1.png");
		DrawGraph(20, 350, Button, TRUE);

		int Button2 = LoadGraph("image\\button2.png");
		DrawGraph(100, 480, Button2, TRUE);

		int Button3 = LoadGraph("image\\button3.png");
		DrawGraph(180, 350, Button3, TRUE);

		int Button4 = LoadGraph("image\\button4.png");
		DrawGraph(260, 480, Button4, TRUE);

		int Button5 = LoadGraph("image\\button5.png");
		DrawGraph(340, 350, Button5, TRUE);

		int Button6 = LoadGraph("image\\button6.png");
		DrawGraph(420, 480, Button6, TRUE);

		int Button7 = LoadGraph("image\\button7.png");
		DrawGraph(500, 350, Button7, TRUE);

		int Button8 = LoadGraph("image\\button8.png");
		DrawGraph(580, 480, Button8, TRUE);

		int Button9 = LoadGraph("image\\button9.png");
		DrawGraph(650, 350, Button9, TRUE);

		if (flag == 0&&!(CheckHitKey(KEY_INPUT_RETURN)))
		{
			if ((((x - 82) * (x - 82)) + ((y - 390) * (y - 390))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				flag = 1;
				save[count] = 1;
				count += 1;
			}

			else if ((((x - 162) * (x - 162)) + ((y - 520) * (y - 520))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				flag = 2;
				save[count] = 2;
				count += 1;
			}

			else if ((((x - 242) * (x - 242)) + ((y - 390) * (y - 390))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				flag = 3;
				save[count] = 3;
				count += 1;
			}

			else if ((((x - 320) * (x - 320)) + ((y - 520) * (y - 520))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				flag = 4;
				save[count] = 4;
				count += 1;
			}

			else if ((((x - 402) * (x - 402)) + ((y - 390) * (y - 390))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				flag = 5;
				save[count] = 5;
				count += 1;
			}

			else if ((((x - 480) * (x - 480)) + ((y - 520) * (y - 520))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				flag = 6;
				save[count] = 6;
				count += 1;
			}

			else if ((((x - 562) * (x - 562)) + ((y - 390) * (y - 390))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				flag = 7;
				save[count] = 7;
				count += 1;
			}

			else if ((((x - 642) * (x - 642)) + ((y - 520) * (y - 520))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				flag = 8;
				save[count] = 8;
				count += 1;
			}

			else if ((((x - 710) * (x - 710)) + ((y - 390) * (y - 390))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				flag = 9;
				save[count] = 9;
				count += 1;
			}

			else if ((GetMouseInput() & MOUSE_INPUT_RIGHT))
			{
				flag = 999;
			}
		}

		if (flag == 1)
		{
			DrawString(240, 200, "1が押されました", GetColor(255, 255, 255));
			DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				flag = 0;

			}
		}

		else if (flag == 2)
		{
			DrawString(240, 200, "2が押されました", GetColor(255, 255, 255));
			DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				flag = 0;
			}
		}

		else if (flag == 3)
		{
			DrawString(240, 200, "3が押されました", GetColor(255, 255, 255));
			DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				flag = 0;
			}
		}

		else if (flag == 4)
		{
			DrawString(240, 200, "4が押されました", GetColor(255, 255, 255));
			DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				flag = 0;
			}
		}

		else if (flag == 5)
		{
			DrawString(240, 200, "5が押されました", GetColor(255, 255, 255));
			DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				flag = 0;
			}
		}

		else if (flag == 6)
		{
			DrawString(240, 200, "6が押されました", GetColor(255, 255, 255));
			DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				flag = 0;
			}
		}

		else if (flag == 7)
		{
			DrawString(240, 200, "7が押されました", GetColor(255, 255, 255));
			DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				flag = 0;
			}
		}

		else if (flag == 8)
		{
			DrawString(240, 200, "8が押されました", GetColor(255, 255, 255));
			DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				flag = 0;
			}
		}

		else if (flag == 9)
		{
			DrawString(240, 200, "9が押されました", GetColor(255, 255, 255));
			DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				flag = 0;
			}
		}

		else if (flag == 999)
		{
			j = 0;
			for (int i = 0; i < count; i++)
			{
				if (j%20==0&&j!=0)
				{
					j = 0;
				}
				DrawFormatString(80+(j*30), 10+((i/20)*60),GetColor(255, 255, 255),"%d", save[i]);
				j++;

			}	
			DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				flag = 0;
			}
		}


		ScreenFlip();//画面更新

		ClearDrawScreen();//画面クリア

		//例外処理
		if ((ProcessMessage() == -1))break;
	}
	
	DxLib_End();//Dxライブラリの終了処理

	return 0;
}

//描画
void Player::Draw()
{
	DrawGraphF(pos.x, pos.y, img, TRUE);
}