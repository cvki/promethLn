#pragma once

#include"Person.h"

class Student:public Person
{
	friend istream& operator>>(istream& in, Student& s);
	friend ostream& operator<<(ostream& out, const Student& s);
private:
	unsigned id;
public:
	Student() = default;
	Student(string name,int age,unsigned id = 0):Person(name, age),id(id){}
	unsigned getId() const{ return id; }
	void setId(const unsigned id) { this->id = id; }
	void showStudent()const{}
};


