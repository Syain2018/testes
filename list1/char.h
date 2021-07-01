#pragma once
#include "main.h"

//プレイヤー
class Player :public Bace
{
private:
	int x = 0;//マウスポインタのX方向取得に使用
	int y = 0;//マウスポインタでY方向取得に使用
	int j = 0;

	int save[50];  //入力した数字を格納する配列
	int check = 0;   //格納された数字と比較する
	int count = 0;   //チェック用カウント
	int save_count;//保存用カウント

	int button_flag = 0;//どのボタンが押されているかを確認する
	int player_flag = 0;//どのプレイヤーが押したかを確認する

	bool victory_flag = false;//相手の入力が間違ったときに使用
	bool check_flag = false;  //true:button_flagの中に入る
	bool font_flag = false;  //現在配列に入っている数字を表示するのに使用
public:
	int img{ 0 };//画像
	int sound{ 0 };//音楽
	Pos pos{ 0.0f,0.0f };//位置
	Vec vec{ 0.0f,0.0f };//移動ベクトル

	//コンストラクタ
	Player();
	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};