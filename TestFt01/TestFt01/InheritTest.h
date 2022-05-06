#pragma once
#include<iostream>

class InheritTest
{
};


class	People {
private:
	int age;
	int* ptest;
public:
	People(int* pt,int age = 0);
	//��ָ���Ĭ�ϲ���ȥ����Ҫ���û���������һ����ȷ��ָ��,ͬʱע�⣬��Ĭ�ϲ����ı����������ڲ����б�����
	People(const People& p);
	~People();
	int getAge();
	int* getPtest();
	void setAge(int age);
	void setPtest(int* ptest);
	void breath();
};

class Student:public People {
private:
	int num;
public:
	Student(int *p,int num = 0);
	Student(const Student& s);
	~Student();
	int getNum();
	void setNum(int num);
	void study();
};


//�麯���̳в�����
class Base1 {
private:
	int x;
public:
	Base1(int x = 0) :x(x) { std::cout << "Base1::Base1(int x=0)" << std::endl; }
	virtual void test1() const { std::cout << "Base1::virtual void test1()" << std::endl; };
	virtual void test2()  { std::cout << "Base1::virtual void test2()" << std::endl; };
	//virtual void test3() = 0;//���麯�������麯��һ���������ж����ˣ�������Բ���ʽд�����麯����Ĭ���Զ��̳�
	virtual ~Base1() { std::cout << "Base::~Base1()" << std::endl; };//�м̳�ʱ��һ��������Ϊ����������
};
class Base1Son:public Base1 {
private: 
		int y;
public:
	Base1Son(int x = 0, int y = 0) :Base1(x), y(y) { std::cout << "Base1Son::Base1Son(int x=0,y=0)" << std::endl; }
	
	virtual void test1() const override { std::cout << "Base1Son::virtual void test1()" << std::endl; };
	virtual void test4() { std::cout << "Base1Son::virtual void test4()" << std::endl; };//�������к���������ָ����ʲ���
	void test5() { std::cout << "Base1Son::virtual void test5()" << std::endl; };//�������к���������ָ����ʲ���
	virtual ~Base1Son() { std::cout << "Base1Son::~Base1Son()" << std::endl; };
};

