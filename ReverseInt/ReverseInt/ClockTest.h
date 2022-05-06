#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
class ClockTest {
private:
	int hour;
	int minute;
	int second;
public:
	ClockTest()=default;//这样相当于类内定义，不需要在类外定义了
	//ClockTest();只写这一个有错误。但如果类内声明，在类外实现，就是对的。
	void getClockTime();
	void setClockTime(int hour=0, int minute=0, int second=0);
};
//ClockTest::ClockTest() {}//这里是类外的构造函数实现。对应上面的类内声明
void ClockTest::getClockTime()
{//修改输出格式
	if (hour >= 10 && hour <= 24)
		cout << hour << ":";
	else if (hour < 10 && hour >= 0)
		cout << "0" << hour<<":";
	if (minute >= 10 && minute <= 59)
		cout << minute << ":";
	else if (minute < 10 && minute >= 0)
		cout << "0" << minute << ":";
	if (second >= 10 && second <= 59)
		cout << second << endl;
	else if (second < 10 && second >= 0)
		cout << "0" << second << endl;

	cout << hour << ":" << minute << ":" << second << endl;
}
void ClockTest::setClockTime(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}
