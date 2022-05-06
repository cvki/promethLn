#include<iostream>

using namespace std;

//题目描述：寻找回文数x,且满足x^2,x^3也为回文数的x。(x从11到999)，如11，11^2=121,11^3=1331...

int getReverseX(int);//反转整数判断回文

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