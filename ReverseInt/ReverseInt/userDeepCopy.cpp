#include "userDeepCopy.h"

userDeepCopy::userDeepCopy(string name, int age, testCopyArr* pdp):name(name), age(age)
{//带参构造函数

	pdeep = new testCopyArr(*pdp);

	//或者
	/*pdeep=new testCopyArr(pdp->getSize());
	for (int i = 0; i < pdp->getSize(); i++)
		pdeep->getTa()[i] = *(pdp->getTa() + i);*/
	
	cout << "userDeepCopy带参构造函数" << endl;
};
userDeepCopy::userDeepCopy(const userDeepCopy& udc) :name(udc.name), age(udc.age)
{//拷贝构造
	this->pdeep = new testCopyArr(*udc.pdeep);
	cout << "userDeepCopy拷贝构造函数" << endl;
};
userDeepCopy::userDeepCopy(userDeepCopy&& udc):pdeep(udc.pdeep)
{//移动构造
	udc.pdeep = nullptr;
	cout << "userDeepCopy移动构造函数" << endl;
};
string userDeepCopy::getName() { return name; };
int userDeepCopy::getAge() { return age; };
testCopyArr* userDeepCopy::getPdeep() { return pdeep; };
void userDeepCopy::setName(string name) { this->name = name; };
void userDeepCopy::setAge(int age) { this->age = age; };
void userDeepCopy::setPdeep(testCopyArr* pdp) { this->pdeep = pdp; pdp = nullptr; };
userDeepCopy::~userDeepCopy() 
{//析构函数
	delete[] pdeep;
	pdeep->~testCopyArr();
	cout << "userDeepCopy析构函数" << endl;
};
