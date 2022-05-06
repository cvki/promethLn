#pragma once
#include<iostream>

using namespace std;

class ClockTestFun
{
private:
	int hour;
	int minute;
	int second;
public:
	ClockTestFun() = default;//或者ClockTestFun() {};也是对的
	ClockTestFun(int h,int m,int s):hour(h),minute(m),second(s){}
	void getClockTestTime();
	void setClockTestTime(int h, int m, int s);
};
void ClockTestFun::getClockTestTime()
{
	cout << hour << ":" << minute << ":" << second << endl;
}
void ClockTestFun::setClockTestTime(int h, int m, int s)
{
	this->hour = h;
	this->minute = m;
	this->second = s;
}

