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
//	osm << fd.testA << fd.testB;//Ϊʲô���
//}
//1.��int tst��Ԫ��������.h��.cpp�зֿ�ʱ���ᱨ������Ԫ����ostream operator<<()���ļ�����.h��.cpp�оͻᱨ����ʾ�޷�����˽�г�Ա
//2.��ostream operator<<()��Ԫ�������ڸ����ڣ����Ҹ��಻���ļ���ֱ����������ʱ����Ͳ��ᱨ��
//Ϊʲô�������ѵ�opertor<<���ص���Ԫ����ֻ�ܷ������һ���ļ��ڲ����𣿣���

