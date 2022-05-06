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
	{ //Ĭ�Ϲ��캯��(�������)
		ta = new int(size);
		cout << "testCopyArrĬ�Ϲ��캯��(�������)" << endl;
	};
	testCopyArr(const testCopyArr& tca):size(tca.size)
	{//��������
		this->ta = new int(size);
		for (int i = 0; i < size; i++)
		{
			*(this->ta + i) = tca.ta[i];
		}
		cout << "testCopyArr�������캯��" << endl;
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
	{//��������
		delete[] ta;
		cout << "testCopyArr��������" << endl;
	}
};
class userDeepCopy
{
private:
	string name;
	int age;
	testCopyArr* pdeep;
public:
	//userDeepCopy();//Ĭ�Ϲ���
	userDeepCopy(string name = "", int age = 0, testCopyArr* pdp = nullptr);//���ι���
	userDeepCopy(const userDeepCopy& udc);//��������
	userDeepCopy(userDeepCopy&& udc);//�ƶ�����
	string getName();//get��Ա
	int getAge();
	testCopyArr* getPdeep();
	void setName(string name);//set��Ա
	void setAge(int age);
	void setPdeep(testCopyArr* pdp);
	~userDeepCopy();
};

