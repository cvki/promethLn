#pragma once
#include<iostream>
#include<string>

using namespace	std;
class testCopyArr {
private:
	int size;
	int* ta;
public:
	testCopyArr(int size = 0)
	{ //默认构造函数(必须带参)
		ta = new int(size);
		cout << "testCopyArr默认构造函数(必须带参)" << endl;
	};
	testCopyArr(const testCopyArr& tca):size(tca.size)
	{//拷贝构造
		this->ta = new int(size);
		for (int i = 0; i < size; i++)
		{
			*(this->ta + i) = tca.ta[i];
		}
		cout << "testCopyArr拷贝构造函数" << endl;
	};
	int getSize() { return size; }
	int* getTa() { return ta; }
	int settaData(int i,int data)
	{
		if (i < this->size)
		{
			*(ta + i) = data;
			return 0;
		}
		else
			cerr << "ERROR:OUT_OF_RANGE!" << endl;
			return -1;
	}
	~testCopyArr()
	{//析构函数
		delete[] ta;
		cout << "testCopyArr析构函数" << endl;
	}
};
class userDeepCopy
{
private:
	string name;
	int age;
	testCopyArr* pdeep;
public:
	//userDeepCopy();//默认构造
	userDeepCopy(string name = "", int age = 0, testCopyArr* pdp = nullptr);//带参构造
	userDeepCopy(const userDeepCopy& udc);//拷贝构造
	userDeepCopy(userDeepCopy&& udc);//移动构造
	string getName();//get成员
	int getAge();
	testCopyArr* getPdeep();
	void setName(string name);//set成员
	void setAge(int age);
	void setPdeep(testCopyArr* pdp);
	~userDeepCopy();
};

