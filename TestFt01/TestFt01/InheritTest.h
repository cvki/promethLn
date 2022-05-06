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
	//将指针的默认参数去掉，要求用户必须输入一个明确的指针,同时注意，带默认参数的变量必须置于参数列表的最后
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


//虚函数继承测试类
class Base1 {
private:
	int x;
public:
	Base1(int x = 0) :x(x) { std::cout << "Base1::Base1(int x=0)" << std::endl; }
	virtual void test1() const { std::cout << "Base1::virtual void test1()" << std::endl; };
	virtual void test2()  { std::cout << "Base1::virtual void test2()" << std::endl; };
	//virtual void test3() = 0;//纯虚函数，和虚函数一样，父类中定义了，子类可以不显式写出该虚函数，默认自动继承
	virtual ~Base1() { std::cout << "Base::~Base1()" << std::endl; };//有继承时，一般必须设计为虚析构函数
};
class Base1Son:public Base1 {
private: 
		int y;
public:
	Base1Son(int x = 0, int y = 0) :Base1(x), y(y) { std::cout << "Base1Son::Base1Son(int x=0,y=0)" << std::endl; }
	
	virtual void test1() const override { std::cout << "Base1Son::virtual void test1()" << std::endl; };
	virtual void test4() { std::cout << "Base1Son::virtual void test4()" << std::endl; };//子类特有函数，父类指针访问不了
	void test5() { std::cout << "Base1Son::virtual void test5()" << std::endl; };//子类特有函数，父类指针访问不了
	virtual ~Base1Son() { std::cout << "Base1Son::~Base1Son()" << std::endl; };
};

