#include "FriendTest.h"
#include<iostream>

using namespace std;

FriendTest::FriendTest(int testA,int testB) {};
FriendTest::FriendTest(const FriendTest& fd) {};
int FriendTest::getdata() { return testA; };
void FriendTest::setdata(int dtA,int dtB) {};
FriendTest::~FriendTest() {};
int tst(FriendTest& fd1, FriendTest fd2) {
	return fd1.testA + fd2.testA;
}
//ostream& operator<<(ostream& osm, FriendTest& fd)
//{
//	osm << fd.testA << fd.testB;//为什么会错？
//}
//1.当int tst友元函数放在.h和.cpp中分开时不会报错，将友元函数ostream operator<<()分文件放在.h和.cpp中就会报错，提示无法访问私有成员
//2.将ostream operator<<()友元函数放在该类内，并且该类不分文件，直接在类声明时定义就不会报错。
//为什么？？？难道opertor<<重载的友元函数只能放在类的一个文件内才行吗？？？

