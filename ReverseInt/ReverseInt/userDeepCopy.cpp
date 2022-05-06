#include "userDeepCopy.h"

userDeepCopy::userDeepCopy(string name, int age, testCopyArr* pdp):name(name), age(age)
{//���ι��캯��

	pdeep = new testCopyArr(*pdp);

	//����
	/*pdeep=new testCopyArr(pdp->getSize());
	for (int i = 0; i < pdp->getSize(); i++)
		pdeep->getTa()[i] = *(pdp->getTa() + i);*/
	
	cout << "userDeepCopy���ι��캯��" << endl;
};
userDeepCopy::userDeepCopy(const userDeepCopy& udc) :name(udc.name), age(udc.age)
{//��������
	this->pdeep = new testCopyArr(*udc.pdeep);
	cout << "userDeepCopy�������캯��" << endl;
};
userDeepCopy::userDeepCopy(userDeepCopy&& udc):pdeep(udc.pdeep)
{//�ƶ�����
	udc.pdeep = nullptr;
	cout << "userDeepCopy�ƶ����캯��" << endl;
};
string userDeepCopy::getName() { return name; };
int userDeepCopy::getAge() { return age; };
testCopyArr* userDeepCopy::getPdeep() { return pdeep; };
void userDeepCopy::setName(string name) { this->name = name; };
void userDeepCopy::setAge(int age) { this->age = age; };
void userDeepCopy::setPdeep(testCopyArr* pdp) { this->pdeep = pdp; pdp = nullptr; };
userDeepCopy::~userDeepCopy() 
{//��������
	delete[] pdeep;
	pdeep->~testCopyArr();
	cout << "userDeepCopy��������" << endl;
};
