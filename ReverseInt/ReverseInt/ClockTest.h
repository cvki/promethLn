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
	ClockTest()=default;//�����൱�����ڶ��壬����Ҫ�����ⶨ����
	//ClockTest();ֻд��һ���д��󡣵��������������������ʵ�֣����ǶԵġ�
	void getClockTime();
	void setClockTime(int hour=0, int minute=0, int second=0);
};
//ClockTest::ClockTest() {}//����������Ĺ��캯��ʵ�֡���Ӧ�������������
void ClockTest::getClockTime()
{//�޸������ʽ
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
