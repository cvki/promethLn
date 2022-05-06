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


//const�ؼ��ֵĲ���
class testConst {
private:
	int ss1;
	//const ss2;const��Ա����Ҫ�ڶ���ʱ��ʼ��������ᱨ��
	const int ss2=0;
public:
	void testShow() {
		cout << "ss1:	" << ss1 << "\t" << "ss2: " << 15+ss2 <<endl;//����Ϊʲô�����ڷ�const�����е���const�����������һ����޸ģ���
	}
	void testShow() const {
		//ss2 += 1;//��������ss2Ϊconst���ͣ����ܱ��޸ġ�
		cout << "ss1:	" << ss1 << "\t" << "ss2: " << 18+ss2 <<endl;
	}
};


//����ֵΪ���ú�ָ��Ĳ���
class dynamitePoint {
private:
	Point* p;
	int size;
public:
	dynamitePoint(int size) :size(size) { p = new Point[size](); }
	dynamitePoint() :size(10) { p = new Point[size]{}; }
	Point* movedymp(int x,int y) {//�޸�ĳ�����λ��
		p->setPoint(x, y);
		return p;//���ﺯ������ֵ���Ͳ���ΪPoint&�ͣ���Ϊ����Ķ���ΪPoint*,�����õ�Ҳ��Point������˷������������Point&�Ļ���thisӦ���Ǹ�����Point������У��������Ͳ�ƥ�䡣
	}
	void dymPointVisit(const Point& p) {//���ĳ���������
		p.getPoint();//ע�⣬��getPoint()����const���ͣ���const Point p�޷����øú�����const�����޷����÷�const��������Ϊconst���������÷�const���������ܻ��ڸú����ڲ��޸�constֵ����˲��������������
		//��const������Ե���const��������Ϊ��cosnt������ֵ�ǿ��Ըı�ģ���˶Է�const������const�����ĵ��ö�����
	}
	void getdymp()
	{
		p->getPoint();
		//return p;
	}

	Point& elementDym(int index)
	{//ȡ����indexԪ�ص�ֵ
		if (index < size)
			return *(p + index );
		else
			cout << "INDEX ERROR!" << endl;
	}
	//���޸�Ϊ��
	Point* elementDym2(int index)
	{//ȡ����indexԪ�ص�ֵ
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

