#include<iostream>

using namespace std;

//找到两个或三个数的最大值;

double getMaxDbl(double v1, double v2)
{//注意浮点数比较大小的方法，要用减法比较，不能直接用大于小于号。当两数的差在一定精度要求内，可认为两数相等。
	//这里用1e-10作为误差判断(精度要求)
		return v1 - v2>1e-10 ? v1 : v2;
}

int getMaxInt(int v1, int v2)
{
	return v1 > v2 ? v1 : v2;
}

double getMaxDbl(double v1, double v2, double v3)
{//同上，一定注意：浮点数比较大小或者判断相等
	double c = v1 - v2>=1e-10 ? v1 : v2;
	return c - v3>1e-10 ? c : v3;
}

int getMaxInt(int v1, int v2, int v3)
{
	int c = v1 > v2 ? v1 : v2;
	return c > v3 ? c : v3;
}

