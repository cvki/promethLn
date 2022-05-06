#pragma once


class Board
{
private:
	int** board; //����ָ��
	int n; //���̴�С
	int dx;	//��������
	int dy;	//���������
public:
	Board(int n=16); //����n*n�����̴�С��n=2^k
	Board(const Board& bd);
	~Board();
	int getN() const;
	int getDx()const; //get����������
	int getDy()const;
	bool setXY(const int& x, const int& y);	//�����������,��0��ʾ���
};

