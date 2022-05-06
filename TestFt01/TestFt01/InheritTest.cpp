#include "InheritTest.h"
#include<iostream>

using namespace std;

People::People(int* pt,int age) :age(age), ptest(new int(*pt)) { cout << "People默认构造函数" << endl; };
//这里的int* 指针成员，不管使用NULL还是nullptr都会出现错误，因为在ptest赋值时，使用*pt会引发空指针取值的异常。因此，在之后的默认参数列表中，千万不要设置指针成员的默认参数，即使将指针成员默认参数设置为空指针也很可能会出错(只要有赋值前进行*p的操作)，切记！！
People::People(const People& p):age(p.age),ptest(new int(*(p.ptest))) { cout << "People拷贝构造函数" << endl; };
People::~People() { delete ptest; cout << "People析构函数" << endl;};
int People::getAge() { return age; }
int* People::getPtest() { return ptest; };//返回指针或引用型效率更快，尤其在传递的是对象类型时，避免拷贝构造操作
void People::setAge(int age) { this->age = age; }
void People::setPtest(int* pt) { this->ptest = new int(*pt); }//指针类型，这里必须进行深拷贝，一定注意
void People::breath() { cout << "People::breath()" << endl; };


Student::Student(int* p,int num):num(num),People(p) { cout << "Student默认构造函数" << endl; };
Student::Student(const Student& s):num(s.num),People(s) { cout << "Student拷贝构造函数" << endl; };
//子类拷贝构造函数中，要调用父类拷贝构造拷贝继承来的成员变量，独有的成员变量自己解决
int Student::getNum(){ return num; }
void Student::setNum(int num) { this->num = num; }
Student::~Student() { cout << "Student析构函数" << endl; };//~People();会发生编译错误
void Student::study() { cout << "Student::study()" << endl; };
