//リスト例
//Dxライブラリ使用
#pragma once
#include "main.h"
#include "char.h"


//ユニークポインタを使ったリスト
list<unique_ptr<Bace>>bace;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE,
	_In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	//windowモード切り替え
	ChangeWindowMode(TRUE);
	//windowサイズ
	SetGraphMode(WIDTH, HEIGHT, 32);

	//Dxライブラリの初期化
	if (DxLib_Init() == -1)return -1;

	//windowの名前
	SetWindowText("リスト");

	//バックバッファを使用
	SetDrawScreen(DX_SCREEN_BACK);

	//リストにプレイヤー追加
	auto a = (unique_ptr<Bace>)new Player();
	bace.push_back(move(a));

	//メインループ
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//リストのメソッドを実行
		for (auto i = bace.begin(); i != bace.end(); i++)
			(*i)->Action(bace);//各オブジェクトの処理
		
		ScreenFlip();//画面更新
		//例外処理
		if ((ProcessMessage() == -1))break;
	}

	DxLib_End();

	return 0;
}//aaaaaaaaaa
//aaaaaaaaaa