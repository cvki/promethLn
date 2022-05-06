#include "InheritTest.h"
#include<iostream>

using namespace std;

People::People(int* pt,int age) :age(age), ptest(new int(*pt)) { cout << "PeopleĬ�Ϲ��캯��" << endl; };
//�����int* ָ���Ա������ʹ��NULL����nullptr������ִ�����Ϊ��ptest��ֵʱ��ʹ��*pt��������ָ��ȡֵ���쳣����ˣ���֮���Ĭ�ϲ����б��У�ǧ��Ҫ����ָ���Ա��Ĭ�ϲ�������ʹ��ָ���ԱĬ�ϲ�������Ϊ��ָ��Ҳ�ܿ��ܻ����(ֻҪ�и�ֵǰ����*p�Ĳ���)���мǣ���
People::People(const People& p):age(p.age),ptest(new int(*(p.ptest))) { cout << "People�������캯��" << endl; };
People::~People() { delete ptest; cout << "People��������" << endl;};
int People::getAge() { return age; }
int* People::getPtest() { return ptest; };//����ָ���������Ч�ʸ��죬�����ڴ��ݵ��Ƕ�������ʱ�����⿽���������
void People::setAge(int age) { this->age = age; }
void People::setPtest(int* pt) { this->ptest = new int(*pt); }//ָ�����ͣ����������������һ��ע��
void People::breath() { cout << "People::breath()" << endl; };


Student::Student(int* p,int num):num(num),People(p) { cout << "StudentĬ�Ϲ��캯��" << endl; };
Student::Student(const Student& s):num(s.num),People(s) { cout << "Student�������캯��" << endl; };
//���࿽�����캯���У�Ҫ���ø��࿽�����쿽���̳����ĳ�Ա���������еĳ�Ա�����Լ����
int Student::getNum(){ return num; }
void Student::setNum(int num) { this->num = num; }
Student::~Student() { cout << "Student��������" << endl; };//~People();�ᷢ���������
void Student::study() { cout << "Student::study()" << endl; };
