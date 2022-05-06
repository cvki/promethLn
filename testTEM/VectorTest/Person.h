#pragma once

#include<iostream>
#include<string>
using namespace std;

class Person
{
	//这几个友元重载函数的实现必须放在cpp文件中,放在.h这里会报错(链接错误)
	friend istream& operator>>(istream& in, Person& p);
	friend ostream& operator<<(ostream& out, const Person& p);

	//friend int operator+(int x1, Person& p);
private:
	string name;//字符串的输入要尤其注意
	int age;
public:
	Person() = default;
	Person(string name, int age = 0) :name(name), age(age) {}
	string getName() const{ return name; }
	int getAge() const{ return age; }
	void setName(const string name) { this->name = name; }
	void setAge(const int age) { this->age = age; }
};

//int operator+(int x1, Person& p) {
//	return x1 + p.age;
//}
//
////即使不作为友元函数,操作符重载的函数放在.h中也会出现链接错误
//int operator-(int x1, Person& p) {
//	return p.getAge()-x1;
//}

