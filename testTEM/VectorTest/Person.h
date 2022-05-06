#pragma once

#include<iostream>
#include<string>
using namespace std;

class Person
{
	//�⼸����Ԫ���غ�����ʵ�ֱ������cpp�ļ���,����.h����ᱨ��(���Ӵ���)
	friend istream& operator>>(istream& in, Person& p);
	friend ostream& operator<<(ostream& out, const Person& p);

	//friend int operator+(int x1, Person& p);
private:
	string name;//�ַ���������Ҫ����ע��
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
////��ʹ����Ϊ��Ԫ����,���������صĺ�������.h��Ҳ��������Ӵ���
//int operator-(int x1, Person& p) {
//	return p.getAge()-x1;
//}

