#include<iostream>

using namespace std;

//�ҵ������������������ֵ;

double getMaxDbl(double v1, double v2)
{//ע�⸡�����Ƚϴ�С�ķ�����Ҫ�ü����Ƚϣ�����ֱ���ô���С�ںš��������Ĳ���һ������Ҫ���ڣ�����Ϊ������ȡ�
	//������1e-10��Ϊ����ж�(����Ҫ��)
		return v1 - v2>1e-10 ? v1 : v2;
}

int getMaxInt(int v1, int v2)
{
	return v1 > v2 ? v1 : v2;
}

double getMaxDbl(double v1, double v2, double v3)
{//ͬ�ϣ�һ��ע�⣺�������Ƚϴ�С�����ж����
	double c = v1 - v2>=1e-10 ? v1 : v2;
	return c - v3>1e-10 ? c : v3;
}

int getMaxInt(int v1, int v2, int v3)
{
	int c = v1 > v2 ? v1 : v2;
	return c > v3 ? c : v3;
}

