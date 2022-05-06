#pragma once

#include<iostream>
#include"classCombineTest.h"

using namespace std;



class testOth {
private:
	int x;
	int y;
public:
	testOth();
	testOth(int x, int y);
	testOth(const testOth& t1);
	void getOth()const;
	void setOth(int x, int y);
	~testOth();
};

testOth::testOth() = default; 
testOth::testOth(int x, int y):x(x), y(y) {}
testOth::testOth(const testOth& t1):x(t1.x),y(t1.y){}
void testOth::getOth() const
{
	cout << "testOthX=" << x << "testOthY=" << y <<endl;
}
void testOth::setOth(int x,int y)
{
	this->x = x;
	this->y = y;
}


//const关键字的测试
class testConst {
private:
	int ss1;
	//const ss2;const成员必须要在定义时初始化，否则会报错
	const int ss2=0;
public:
	void testShow() {
		cout << "ss1:	" << ss1 << "\t" << "ss2: " << 15+ss2 <<endl;//这里为什么可以在非const函数中调用const变量？？而且还能修改？？
	}
	void testShow() const {
		//ss2 += 1;//报错，这里ss2为const类型，不能被修改。
		cout << "ss1:	" << ss1 << "\t" << "ss2: " << 18+ss2 <<endl;
	}
};


//返回值为引用和指针的测试
class dynamitePoint {
private:
	Point* p;
	int size;
public:
	dynamitePoint(int size) :size(size) { p = new Point[size](); }
	dynamitePoint() :size(10) { p = new Point[size]{}; }
	Point* movedymp(int x,int y) {//修改某个点的位置
		p->setPoint(x, y);
		return p;//这里函数返回值类型不能为Point&型，因为这里的对象为Point*,而调用的也是Point对象，因此返回如果是引用Point&的话，this应该是个具体Point对象才行，否则类型不匹配。
	}
	void dymPointVisit(const Point& p) {//输出某个点的坐标
		p.getPoint();//注意，若getPoint()不是const类型，则const Point p无法调用该函数。const对象无法调用非const函数。因为const对象若调用非const函数，可能会在该函数内部修改const值，因此不允许该现象发生。
		//非const对象可以调用const函数，因为非cosnt变量的值是可以改变的，因此对非const函数和const函数的调用都可以
	}
	void getdymp()
	{
		p->getPoint();
		//return p;
	}

	Point& elementDym(int index)
	{//取出第index元素的值
		if (index < size)
			return *(p + index );
		else
			cout << "INDEX ERROR!" << endl;
	}
	//可修改为：
	Point* elementDym2(int index)
	{//取出第index元素的值
		if (index < size)
			return p + index;
		else
			cout << "INDEX ERROR!" << endl;
	}


	~dynamitePoint()
	{
		delete[] p;
		cout << "~dynamitePoint();" << endl;
	}
};

