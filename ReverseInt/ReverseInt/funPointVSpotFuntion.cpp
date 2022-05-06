#include<iostream>

using namespace std;

//指针函数
int* getArray(int size)//根据所传长度返回数组（顺序表）
{
	int* p = new int[size]();//加上小括号表示需要初始化
	return p;
}

int temt()
{
	int* p1;
	int lth;
	cout << "enter the size of array:" << endl;
	cin >> lth;
	p1 = getArray(lth);
	for (int i = 0; i < lth; i++)
	{
		p1[i] = i * 1000;
		cout << *(p1 + i) << "\t";
	}
	delete[] p1;
	return 0;
}

//函数指针
//求一个数组中元素的最大值
int getMaxArr(int* a, int lth);
//求一个数组中元素的最小值
int getMinArr(int* a, int lth);
//求一个数组中元素的平均数
int getAvgArr(int* a, int lth);
//求一个数组中元素的中位数
int getMidArr(int* a, int lth);


//求一个数组中元素的最大值
int getMaxArr(int* a, int lth)
{
	int max = a[0];
	for (int i = 0; i < lth; i++)
	{
		if (max < a[i])
			max = a[i];
	}
	return max;
}
//求一个数组中元素的最小值
int getMinArr(int* a, int lth)
{
	int min = a[0];
	for (int i = 0; i < lth; i++)
	{
		if (min > a[i])
			min = a[i];
	}
	return min;
}
//求一个数组中元素的平均数
int getAvgArr(int* a, int lth)
{
	int sum = a[0];
	for (int i = 0; i < lth; i++)
	{
		sum += a[i];
	}
	return sum / lth;

}
//求一个数组中元素的中位数
int getMidArr(int* a, int lth)
{//冒泡排序
	int tem;
	for (int i = 0; i < lth; i++)
		for (int j = 0; j < lth - 1 - i; j++)
			if (a[j] > a[j + 1])
			{//升序
				tem = a[j];
				a[j] = a[j+1];
				a[j+1] = tem;
			}
	return a[lth / 2];//注意中位数的位置
}

int temt2()
{
	int (*p)(int* a, int l);//声明相当于定义？
	p = NULL;//或者p=getMinArr等任意一个，但必须初始化，否则会报错。
	int size;
	cout << "Enter the size of array:" << endl;
	cin >> size;
	int* a = new int[size];
	cout << "Enter  " << size << " integer numbers:" << endl;
	for (int j = 0; j < size; j++)
		cin >> *(a + j);
	int i;
	cout << "1.max		2.min		3.average		4.mid" << endl;
	cout << "enter the order:" << endl;
	cin >> i;
	switch (i) {
	case 1:
		p = getMaxArr;//或者用p = &getMaxArr;  一样的
		break;
	case 2:
		p = &getMinArr;
		break;
	case 3:
		p = getAvgArr;
		break;
	case 4:
		p = &getMidArr;
		break;
	default:
		cerr << "ENTER ERROR!" << endl;
		return 0;//若输出错误，则return 0；提前结束，避免指针指向问题导致意外
	}
	cout << (*p)(a, size) << endl;
	return 0;
}

