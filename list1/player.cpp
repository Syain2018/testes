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
	title_flag = false;
	sound_flag = false;

	SetFontSize(45);//フォントの大きさ

	for (int i = 0; i < 50; i++)
	{
		save[i] = 0;
	}

	//画像&音楽データの読み込み
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

//処理
int Player::Action(list<unique_ptr<Bace>>& bace)
{
	GetMousePoint(&x, &y);//現在のマウスの位置取得

	//画面切り替えの処理
	if ((CheckHitKey(KEY_INPUT_RETURN)))
	{
		title_flag = true;
	}

	//BGMの処理
	if (title_flag == true && save_count == 0 && sound_flag == false)
	{
		sound = PlaySoundMem(Sound4, DX_PLAYTYPE_BACK);
		sound_flag = true;
	}

	//各ボタンが押された時の処理
	if (button_flag == 0 && !(CheckHitKey(KEY_INPUT_RETURN)) && title_flag == true)
	{
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			button_flag = Hit(x, y);
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

			true_flag = true;
		}
		//間違っている時
		else
		{
			sound = PlaySoundMem(Sound3, DX_PLAYTYPE_BACK);
			check_flag = true;
			victory_flag = true;
			true_flag = false;
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
		true_flag = false;

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
		//flag類を初期化する処理
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			button_flag = 0;
			check_flag = false;
			font_flag = false;
			true_flag = false;
		}
	}

	if (victory_flag == true && CheckHitKey(KEY_INPUT_T))
	{
		title_flag = false;
		victory_flag = false;
		check_flag = false;
		font_flag = false;
		true_flag = false;
		sound_flag = false;
		StopSoundFile();
		button_flag = 0;
		player_flag = 0;
		save_count = 0;
		count = 0;
		for (int i = 0; i < 50; i++)
		{
			save[i] = 0;
		}
	}

	else if (victory_flag == true && CheckHitKey(KEY_INPUT_E))
	{
		DxLib_End();
	}

	return 0;
}

//描画
void Player::Draw()
{
	//タイトル画面の表示
	if (title_flag == false)
	{
		SetFontSize(100);
		DrawString(160, 150, "記憶ゲーム", GetColor(0, 255,0));
		SetFontSize(45);
		DrawString(55, 400, "ENTERキー:ゲームをスタートする", GetColor(255, 255, 255));
		DrawString(155, 500, "Eキー:ゲームを終了する", GetColor(255, 255, 255));
	}

	//ゲーム画面の表示
	else if (title_flag == true)
	{
		//画像の表示処理
		for (int i = 1; i < 10; i++)
		{
			if (i % 2 == 1)
				DrawGraph(20 + (i * 80 - 80), 350, Button[i - 1], TRUE);
			else
				DrawGraph(20 + (i * 80 - 80), 350 + 130, Button[i - 1], TRUE);
		}
	}

	//どちらかの勝利が確定した時の処理
	if (victory_flag == true)
	{
		if (player_flag == 0)
		{
			DrawString(150, 40, "1Pが入力を間違えたので", GetColor(255, 255, 255));
			DrawString(270, 130, "2Pの勝ちです", GetColor(0, 255, 255));
		}
		else if (player_flag == 1)
		{
			DrawString(150, 40, "2Pが入力を間違えたので", GetColor(255, 255, 255));
			DrawString(270, 130, "1Pの勝ちです", GetColor(255, 0, 0));
		}
		DrawString(150, 230, "Tキー:タイトル画面に戻る", GetColor(255, 255, 255));
		DrawString(150, 290, "Eキー:ゲームを終了する", GetColor(255, 255, 255));
	}

	//ボタンが押されて手番が変わる時の処理
	if (check_flag == true && victory_flag == false)
	{
		if (font_flag == true)
		{
			if (button_flag != 0)
			{
				DrawFormatString(170, 120, GetColor(255, 0, 0), "%dボタンが押されました", button_flag);
				DrawString(200, 210, "ENTERキーを押したら", GetColor(255, 255, 255));
				DrawString(230, 280, "手番が変わります", GetColor(255, 255, 255));
			}
		}
	}

	//入力した数字が正しかった時の処理
	if (true_flag == true)
	{
		DrawString(110, 150, "正しい数字が入力されました", GetColor(255, 255, 255));
	}

	//現在入力されている数字を見るための処理
	if (font_flag == true)
	{
		for (int i = 0; save[i] != 0; i++)
		{
			DrawFormatString(25 + i * 30, 20, GetColor(255, 255, 255), "%d", save[i]);
		}
	}

	//待機画面に文字を表示する処理
	if (button_flag == 0 && save_count > count && title_flag == true)
	{
		DrawString(70,150,"先ほど入力された数字を\n    順番通りに選択してください", GetColor(255, 255, 255));
	}

	else if (button_flag == 0 && save_count == 0 && title_flag == true)
	{
		DrawString(150,150,"数字を入力してください", GetColor(255, 255, 255));
	}

	else if (button_flag == 0 && save_count <= count && title_flag == true)
	{
		DrawString(90,150,"新たに数字を入力してください", GetColor(255, 255, 255));
	}

	//待機画面に文字を表示する処理2
	if (title_flag == true && player_flag == 0 && font_flag == false && victory_flag == false)
	{
		DrawString(260, 270, "※1Pの番です", GetColor(255, 0, 0));
	}

	else if (title_flag == true && player_flag == 1 && font_flag == false && victory_flag == false)
	{
		DrawString(260, 270, "※2Pの番です", GetColor(0, 255, 255));
	}

}