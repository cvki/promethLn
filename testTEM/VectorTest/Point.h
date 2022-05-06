#pragma once

#include<iostream>

using namespace std;
class Point
{
	friend istream& operator>>(istream& in, Point& p);
	friend ostream& operator<<(ostream& out, const Point& p);
private:
	float x;
	float y;
	string s;
public:
	Point() = default;
	Point(string s,float x = 0, float y = 0) :x(x), y(y),s(s) {}
	float getX() const{ return x; }
	float getY() const{ return y; }
	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
	Point operator+(Point& p) {
		return Point(this->s + p.s,this->x + p.x, this->y + p.y);
	}
	Point operator-(Point& p) {
		return Point(this->s + p.s,this->x - p.x, this->y - p.y);
	}
};


