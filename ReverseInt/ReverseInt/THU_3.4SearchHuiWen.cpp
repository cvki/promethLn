#include<iostream>

using namespace std;

//��Ŀ������Ѱ�һ�����x,������x^2,x^3ҲΪ��������x��(x��11��999)����11��11^2=121,11^3=1331...

int getReverseX(int);//��ת�����жϻ���

int searchHuiwen()
{
	for (int i = 11; i < 1000; i++)
	{
		if (i == getReverseX(i) && i * i == getReverseX(i * i) && i * i * i == getReverseX(i * i * i))
			cout << i << "\t";
	}
	cout << endl;
	return 0;
}
int getReverseX(int preX)
{
	int remainder = 0, result = 0;
	while (preX != 0)
	{
		remainder = preX % 10;
		result = result * 10 + remainder;
		preX /= 10;
	}
	return result;
}