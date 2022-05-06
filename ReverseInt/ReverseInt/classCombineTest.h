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
	//����Ӳ��Ӷ��Ŷ�����.��ʱ����Point(double x,double y)��Ϊί�й��캯�����г�ʼ����ע��ί�й���ֻ�ܷ��ڲ����б��ʼ��
	Point(double x, double y);
	Point(const Point& p1) :xp(p1.xp), yp(p1.yp) 
	{ 
		//cout << "calling Point copy constructor()" << endl; 
	};//����Ӳ��Ӷ��Ŷ�����
	void setPoint(double x, double y);
	double getX() { return xp; };//���ﵥ��getX��getY��Ϊ�˵õ����������꣬Ҳʱ�����Line�е��󳤶ȵ�Ҫ��
	double getY() { return yp; };
	void getPoint() const;
	~Point() 
	{
		//cout << "calling Point destructor()" << endl; 
	};
};
Point::Point(double x, double y) :xp(x),yp(y) 
{//ע�⣬thisָ�벻�����ڳ�ʼ���б���Ϊ��ʼ���б������ڶ���Ĵ�������˲���ʹ��this�����������ͬ���ı�����xp(xp),yp(yp)
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
{//������ʹ�ú͹��죨���ѵ㣩
private:
	Point p1;
	Point p2;
	double lentgL;
public:
	Line();
	Line(Point p1, Point p2);
	Line(const Line& l);
	//Line(const Line& l):p1(l.p1),p2(l.p2)=default;����=default�������ڹ��캯���У��Ͳ�дһ��
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
//������еĳ�ʼ����Ҫʹ��Point������Ĺ��캯��������Ӧ��ʼ������
Line::Line(Point pA, Point pB):p1(pA),p2(pB) 
{ 
	//cout << "calling default constructor Line(Point pA, Point pB):" << endl; 
}
Line::Line(const Line& l) :p1(l.p1), p2(l.p2), lentgL(l.lentgL) 
{ 
	//cout << "calling copy constructor Line(): " << endl; 
};
//ע������������ĳ�ʼ���б��д���������й��캯���ĳ�ʼ���б��У�����ʹ��p(p)����ͬ�����������ط�Ҫ��������
void Line::getPointL()
{
	cout << "p1:";
	p1.getPoint(); 
	cout << "p2:";
	p2.getPoint();
}
void Line::setPointL(Point pA, Point pB) { p1 = pA; p2 = pB; }//ע�����ﲻ�ǹ��캯��������ʹ�ó�ʼ���б�
double Line::getLengthL()
{
	return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
}
