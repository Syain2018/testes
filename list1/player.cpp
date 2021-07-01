#pragma once
#include "char.h"

//コンストラクタ
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

	for (int i = 0; i < 50; i++)
	{
		save[i] = 0;
	}
}

//処理
int Player::Action(list<unique_ptr<Bace>>& bace)
{
	//メイン
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		GetMousePoint(&x, &y);//現在のマウスの位置取得
		SetFontSize(45);      //フォントの大きさ

		//画像&音楽データの読み込み
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

		int Sound = LoadSoundMem("sound\\answer.mp3");

		int Sound2 = LoadSoundMem("sound\\button.mp3");

		int Sound3 = LoadSoundMem("sound\\not_answer.mp3");

		//各ボタンが押された時の処理
		if (button_flag == 0 && !(CheckHitKey(KEY_INPUT_RETURN)))
		{
			if ((((x - 82) * (x - 82)) + ((y - 390) * (y - 390))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				button_flag = 1;
			}

			else if ((((x - 162) * (x - 162)) + ((y - 520) * (y - 520))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				button_flag = 2;
			}

			else if ((((x - 242) * (x - 242)) + ((y - 390) * (y - 390))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				button_flag = 3;
			}

			else if ((((x - 320) * (x - 320)) + ((y - 520) * (y - 520))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				button_flag = 4;
			}

			else if ((((x - 402) * (x - 402)) + ((y - 390) * (y - 390))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				button_flag = 5;
			}

			else if ((((x - 480) * (x - 480)) + ((y - 520) * (y - 520))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				button_flag = 6;
			}

			else if ((((x - 562) * (x - 562)) + ((y - 390) * (y - 390))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				button_flag = 7;
			}

			else if ((((x - 642) * (x - 642)) + ((y - 520) * (y - 520))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				button_flag = 8;
			}

			else if ((((x - 710) * (x - 710)) + ((y - 390) * (y - 390))) < 41 * 41 && (GetMouseInput() & MOUSE_INPUT_LEFT))
			{
				button_flag = 9;
			}
		}

		//配列に格納されている数字と押された数字が正しいか判別する処理
		if (button_flag != 0 && save_count > count && check_flag == false)
		{
			//正しい時
			if (save[count] == button_flag)
			{
				count += 1;
				check_flag = true;
				sound = PlaySoundMem(Sound, DX_PLAYTYPE_BACK);
			}
			//間違っている時
			else
			{
				sound = PlaySoundMem(Sound3, DX_PLAYTYPE_BACK);
				check_flag = true;
				victory_flag = true;
			}
		}

		//配列に数字が格納されていなかった時に行う処理
		else if (button_flag != 0 && save_count <= count && check_flag == false)
		{
			save[count] = button_flag;
			count += 1;
			save_count = count;
			count = 0;
			check_flag = true;
			font_flag = true;

			//プレイヤーの番を交代する
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

		//ボタンが押された時の処理
		if (check_flag == true && victory_flag == false)
		{
			if (button_flag == 1)
			{
				DrawString(240, 200, "1が押されました", GetColor(255, 255, 255));
				DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			}

			else if (button_flag == 2)
			{
				DrawString(240, 200, "2が押されました", GetColor(255, 255, 255));
				DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			}

			else if (button_flag == 3)
			{
				DrawString(240, 200, "3が押されました", GetColor(255, 255, 255));
				DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			}

			else if (button_flag == 4)
			{
				DrawString(240, 200, "4が押されました", GetColor(255, 255, 255));
				DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			}

			else if (button_flag == 5)
			{
				DrawString(240, 200, "5が押されました", GetColor(255, 255, 255));
				DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			}

			else if (button_flag == 6)
			{
				DrawString(240, 200, "6が押されました", GetColor(255, 255, 255));
				DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			}

			else if (button_flag == 7)
			{
				DrawString(240, 200, "7が押されました", GetColor(255, 255, 255));
				DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			}

			else if (button_flag == 8)
			{
				DrawString(240, 200, "8が押されました", GetColor(255, 255, 255));
				DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			}

			else if (button_flag == 9)
			{
				DrawString(240, 200, "9が押されました", GetColor(255, 255, 255));
				DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			}

			if (font_flag == true)
			{
				j = 0;
				for (int i = 0; i < save_count; i++)
				{
					if (j % 20 == 0 && j != 0)
					{
						j = 0;
					}
					DrawFormatString(80 + (j * 30), 10 + ((i / 20) * 60), GetColor(255, 255, 255), "%d", save[i]);
					j++;
				}
				DrawString(120, 280, "ENTERキーを押してください", GetColor(255, 255, 255));
			}

			if (button_flag != 0)
			{
				if (CheckHitKey(KEY_INPUT_RETURN))
				{
					button_flag = 0;
					check_flag = false;
					font_flag = false;
				}
			}
		}

		//どちらかの勝利が確定した時の処理
		if (victory_flag == true && player_flag == 0)
		{
			SetFontSize(55);
			DrawString(250, 100, "2Pの勝ちです", GetColor(255, 0, 0));
			DrawString(60, 240, "ENTERでゲームを終了します", GetColor(255, 255, 255));
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				break;
			}
		}

		else if (victory_flag == true && player_flag == 1)
		{
			SetFontSize(55);
			DrawString(250, 100, "1Pの勝ちです", GetColor(255, 0, 0));
			DrawString(60, 240, "ENTERでゲームを終了します", GetColor(255, 255, 255));
			if (CheckHitKey(KEY_INPUT_RETURN))
			{
				break;
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
