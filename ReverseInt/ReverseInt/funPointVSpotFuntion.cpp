#include<iostream>

using namespace std;

//ָ�뺯��
int* getArray(int size)//�����������ȷ������飨˳���
{
	int* p = new int[size]();//����С���ű�ʾ��Ҫ��ʼ��
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

//����ָ��
//��һ��������Ԫ�ص����ֵ
int getMaxArr(int* a, int lth);
//��һ��������Ԫ�ص���Сֵ
int getMinArr(int* a, int lth);
//��һ��������Ԫ�ص�ƽ����
int getAvgArr(int* a, int lth);
//��һ��������Ԫ�ص���λ��
int getMidArr(int* a, int lth);


//��һ��������Ԫ�ص����ֵ
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
//��һ��������Ԫ�ص���Сֵ
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
//��һ��������Ԫ�ص�ƽ����
int getAvgArr(int* a, int lth)
{
	int sum = a[0];
	for (int i = 0; i < lth; i++)
	{
		sum += a[i];
	}
	return sum / lth;

}
//��һ��������Ԫ�ص���λ��
int getMidArr(int* a, int lth)
{//ð������
	int tem;
	for (int i = 0; i < lth; i++)
		for (int j = 0; j < lth - 1 - i; j++)
			if (a[j] > a[j + 1])
			{//����
				tem = a[j];
				a[j] = a[j+1];
				a[j+1] = tem;
			}
	return a[lth / 2];//ע����λ����λ��
}

int temt2()
{
	int (*p)(int* a, int l);//�����൱�ڶ��壿
	p = NULL;//����p=getMinArr������һ�����������ʼ��������ᱨ��
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
		p = getMaxArr;//������p = &getMaxArr;  һ����
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
		return 0;//�����������return 0����ǰ����������ָ��ָ�����⵼������
	}
	cout << (*p)(a, size) << endl;
	return 0;
}

