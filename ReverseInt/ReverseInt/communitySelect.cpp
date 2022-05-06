#include<iostream>

using namespace std;

//쳲���������
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
{//�ݹ�֮�������ѡ��
	if (k > n)//ע���ж��Ƿ����
		return 0;
	else if (n == k || k == 0)
	{
		return 1;
	}
	else
		return comSelect(n - 1, k - 1) + comSelect(n - 1, k);
}

//��ŵ���ƶ�
int countStep = 0;
void move(char src, char dest)
{
	cout << src << "--->" << dest << endl;
	++countStep;
}

int thanoi(char src, char mid, char dest, int num)
{//���߼�
	if (num <= 0)
		return 0;
	else if (num == 1)
		move(src, dest);//��ֻ��һ��������ֱ�Ӵ�src�ƶ���dest��
	else
	{//���Ĳ���
		thanoi(src, dest, mid, num - 1);//��ǰn-1����src�ƶ���mid��
		move(src, dest);//�����һ����src�ƶ���dest��
		thanoi(mid, src, dest, num - 1);//��mid�ϵ�n-1���ƶ���dest��
	}
	return countStep;
}

//���ô��ݽ���������ֵ
int swapRef(double& val1, double& val2)
{
	double tem = val1;
	val1 = val2;
	val2 = tem;
	return 0;
}

//ָ�봫�ݽ���������ֵ
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
