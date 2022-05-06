#pragma once
#include<iostream>
using namespace std;

class Point {
	//friend  ostream& operator<<(ostream& out, const Point& p);
private:
	double x;
	double y;
public:
	Point(double x = 0, double y = 0);
	Point(const Point& p);
	const Point operator+(const Point&)const;
	~Point();
};


