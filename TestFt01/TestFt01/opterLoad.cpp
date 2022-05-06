#include "opterLoad.h"
#include<iostream>
using namespace std;
opterLoad::opterLoad(int hour, int minute , int second ):hour(hour),minute(minute),second(second) {
	cout << "opterLoad默认构造函数" << endl;
};
opterLoad::opterLoad(const opterLoad& opd):hour(opd.hour),minute(opd.minute),second(opd.second) {
	cout << "opterLoad拷贝构造函数" << endl;
};
opterLoad::opterLoad(opterLoad&& opd):hour(opd.hour), minute(opd.minute), second(opd.second) {
	cout << "opterLoad移动构造函数" << endl;
};
opterLoad::~opterLoad() {
	cout << "opterLoad析构函数" << endl;
};
int opterLoad::getH() { return hour; };
int opterLoad::getM() { return minute; };
int opterLoad::getS() { return second; };
void opterLoad::setH(int h) { this->hour = h; };
void opterLoad::setM(int m) { this->minute = m; };
void opterLoad::setS(int s) { this->second = s; };
opterLoad& opterLoad::operator++() { //前置运算符
	if (second >= 0 && second < 59)
		++second;
	else if (second == 59) {
		++minute;
		second = 0;
	}
	if (minute == 60) {
		hour = (hour + 1) % 24;
		minute = 0;
	}
	return *this;
};

//opterLoad& opterLoad::operator++() { //前置运算符,THU解法
//	second++;
//	if (second >= 60)
//	{
//		second -= 60; 
//		minute++;
//	}
//	if (minute == 60)
//	{
//		minute -= 60;
//		hour = (hour + 1) % 24;
//	}
//	return *this;
//};
opterLoad opterLoad::operator++(int) {
	//在前置运算符重载时，是先进行了对象的运算再使用该对象，因此，在实现逻辑中，首先可直接使用该对象自加或自减，然后把该对象返回。而返回的是this，也就是传递进来的对象，它在前置运算符重载函数结束后是正常返回结束的。
	//但是在后置运算符重载中，是要先进行该对象本身的其他操作，然后再对该对象进行自加或自减。因此需要保存当前对象以免对该对象操作后，返回不了原值。所以用了一个临时类对象保存当前对象的信息，而返回的也是该对象(因为原对象this可能经过其他操作后已被修改)，对于返回的临时对象来说，就不能用引用了，它不是this指向，在该后置运算符重载函数结束后，这个临时对象就被析构(在这里调用的是移动构造函数)，若用引用则它所在的内存由于被回收变为不确定的值。是错误的。因此不能返回指针类或引用，必须返回一个具体内容对象。而这个具体对象是个右值，不能取引用或指针地址。
	opterLoad old(*this);
	++(*this);//调用前置++运算符
	return old;
};

void opterLoad::showTime() {
	cout << hour << ":" << minute << ":" << second << endl;
}

