#include<iostream>

using namespace std;

//斐波那契数列
int fibNs(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return fibNs(n - 1) + fibNs(n - 2);
	}
}

int comSelect(unsigned n, unsigned k)
{//递归之排列组合选举
	if (k > n)//注意判定非法情况
		return 0;
	else if (n == k || k == 0)
	{
		return 1;
	}
	else
		return comSelect(n - 1, k - 1) + comSelect(n - 1, k);
}

//汉诺塔移动
int countStep = 0;
void move(char src, char dest)
{
	cout << src << "--->" << dest << endl;
	++countStep;
}

int thanoi(char src, char mid, char dest, int num)
{//主逻辑
	if (num <= 0)
		return 0;
	else if (num == 1)
		move(src, dest);//若只有一个，则将其直接从src移动到dest上
	else
	{//核心部分
		thanoi(src, dest, mid, num - 1);//将前n-1个从src移动到mid上
		move(src, dest);//将最底一个从src移动到dest上
		thanoi(mid, src, dest, num - 1);//将mid上的n-1个移动到dest上
	}
	return countStep;
}

//引用传递交换两数的值
int swapRef(double& val1, double& val2)
{
	double tem = val1;
	val1 = val2;
	val2 = tem;
	return 0;
}

//指针传递交换两数的值
int swapPoint(double* val1, double* val2)
{
	double tem;
	tem = *val1;
	*val1 = *val2;
	*val2 = tem;
	return 0;
}

int swapNosp(double val1, double val2)
{
	double tem = val1;
	val1 = val2;
	val2 = tem;
	return 0;
}
