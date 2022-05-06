#pragma once
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

class Point {
private:
	double xp;
	double yp;
public:
	Point():Point(0, 0) 
	{
		//cout << "calling Point default construct() and Point consign constrcutor()" << endl; 
	};
	//这里加不加逗号都可以.此时调用Point(double x,double y)作为委托构造函数进行初始化，注意委托构造只能放在参数列表初始化
	Point(double x, double y);
	Point(const Point& p1) :xp(p1.xp), yp(p1.yp) 
	{ 
		//cout << "calling Point copy constructor()" << endl; 
	};//这里加不加逗号都可以
	void setPoint(double x, double y);
	double getX() { return xp; };//这里单独getX和getY是为了得到单独的坐标，也时组合类Line中的求长度的要求。
	double getY() { return yp; };
	void getPoint() const;
	~Point() 
	{
		//cout << "calling Point destructor()" << endl; 
	};
};
Point::Point(double x, double y) :xp(x),yp(y) 
{//注意，this指针不能用于初始化列表，因为初始化列表是先于对象的创建，因此不能使用this，这里可以用同名的变量：xp(xp),yp(yp)
	//cout << "calling Point(double x, double y)" << endl;
}
void Point::setPoint(double x, double y) 
{	this->xp = x;
	this->yp = y; 
	//cout << "calling setPoint(double x, double y)" << endl;
}
void Point::getPoint()const
{ 
	cout << "(" << this->xp << "," << this->yp << ")" << endl; 
	//cout << "calling Point::getPoint()" << endl;
}


class Line
{//组合类的使用和构造（重难点）
private:
	Point p1;
	Point p2;
	double lentgL;
public:
	Line();
	Line(Point p1, Point p2);
	Line(const Line& l);
	//Line(const Line& l):p1(l.p1),p2(l.p2)=default;其中=default可以用于构造函数中，和不写一样
	void getPointL();
	void setPointL(Point, Point);
	double getLengthL();
	~Line()
	{ 
		//cout << "calling Line destructor(): " << endl; 
	}
};
Line::Line():p1(Point()), p2(Point()),lentgL(0) 
{ 
	//cout << "calling default constructor Line():(0,0)" << endl; 
}
//组合类中的初始化，要使用Point部件类的构造函数进行相应初始化操作
Line::Line(Point pA, Point pB):p1(pA),p2(pB) 
{ 
	//cout << "calling default constructor Line(Point pA, Point pB):" << endl; 
}
Line::Line(const Line& l) :p1(l.p1), p2(l.p2), lentgL(l.lentgL) 
{ 
	//cout << "calling copy constructor Line(): " << endl; 
};
//注意这里拷贝构造的初始化列表的写法，在所有构造函数的初始化列表中，可以使用p(p)这种同名变量。不必非要换参数名
void Line::getPointL()
{
	cout << "p1:";
	p1.getPoint(); 
	cout << "p2:";
	p2.getPoint();
}
void Line::setPointL(Point pA, Point pB) { p1 = pA; p2 = pB; }//注意这里不是构造函数，不能使用初始化列表
double Line::getLengthL()
{
	return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
}
