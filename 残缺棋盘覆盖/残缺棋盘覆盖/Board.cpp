#include "Board.h"
#include<iostream>

const int MAXSIZE = 1024;

Board::Board(int dn){
	dn = 16;
	if(dn>16&&dn<1025)
		n=dn;
	board = new int* [n];
	for (int i = 0; i < n; i++)
		board[i] = new int[n];
}

Board::Board(const Board& bd){
	n = bd.getN();
	this->board = new int* [n];
	for (int i = 0; i < n; i++)
		board[i] = new int[n];
	for (int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			this->board[i][j] = bd.board[i][j];
		}
}

Board::~Board(){
	for (int i = 0; i < n; i++)
		delete[] board[i];
	delete[] board;
}

int Board::getN()const {
	return n;
}

int Board::getDx() const{
	return dx;
}

int Board::getDy() const{
	return dy;
}

bool Board::setXY(const int& x,const int& y){
	if (x > 0 && x < n && y>0 && y < n) {
		board[x][y] = 0;
		return true;
	}
	std::cerr << "INDEX ERROR!" << std::endl;
	return false;
}
