#pragma once
#include "main.h"

//�v���C���[
class Player :public Bace
{
private:
	int x = 0;//�}�E�X�|�C���^��X�����擾�Ɏg�p
	int y = 0;//�}�E�X�|�C���^��Y�����擾�Ɏg�p
	int j = 0;

	int save[50];  //���͂����������i�[����z��
	int check = 0;   //�i�[���ꂽ�����Ɣ�r����
	int count = 0;   //�`�F�b�N�p�J�E���g
	int save_count;//�ۑ��p�J�E���g

	int button_flag = 0;//�ǂ̃{�^����������Ă��邩���m�F����
	int player_flag = 0;//�ǂ̃v���C���[�������������m�F����

	bool victory_flag = false;//����̓��͂��Ԉ�����Ƃ��Ɏg�p
	bool check_flag = false;  //true:button_flag�̒��ɓ���
	bool font_flag = false;  //���ݔz��ɓ����Ă��鐔����\������̂Ɏg�p
public:
	int img{ 0 };//�摜
	int sound{ 0 };//���y
	Pos pos{ 0.0f,0.0f };//�ʒu
	Vec vec{ 0.0f,0.0f };//�ړ��x�N�g��

	//�R���X�g���N�^
	Player();
	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};