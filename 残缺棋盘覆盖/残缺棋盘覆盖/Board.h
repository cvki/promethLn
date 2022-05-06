#pragma once


class Board
{
private:
	int** board; //棋盘指针
	int n; //棋盘大小
	int dx;	//噪点横坐标
	int dy;	//噪点纵坐标
public:
	Board(int n=16); //生成n*n的棋盘大小，n=2^k
	Board(const Board& bd);
	~Board();
	int getN() const;
	int getDx()const; //get噪点横纵坐标
	int getDy()const;
	bool setXY(const int& x, const int& y);	//设置噪点坐标,置0表示噪点
};

