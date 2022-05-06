#pragma once
class FriendTest
{
private:
	int testA;
	int testB;
public:
	FriendTest(int testA=0,int testB=0);
	FriendTest(const FriendTest& fd);
	int getdata();
	void setdata(int dtA,int dtB);
	~FriendTest();
	friend int tst(FriendTest &fd1, FriendTest fd2);
	//friend ostream& operator<<(ostream& osm, FriendTest& fd);

};

