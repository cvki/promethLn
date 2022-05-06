#include<iostream>
#include<cmath>

using namespace std;

constexpr auto rander = 1e-15;

int jiechengX(int x);

//����̩�չ�ʽ���㦰����=16*arctan(1/5)-4*arctan(1/239);
double figureAcrtanX(double x);

double figurePI()
{
	cout << "����10�Ľ׳ˣ�" << jiechengX(10) << endl;
	return  16.0 * figureAcrtanX(1.0 / 5) - 4.0 * figureAcrtanX(1.0 / 239);
	//һ��Ҫϸ��ע�⣬����Ĳ�������Ϊ1.0��5.0��239.0�ȸ���������������������������ֵ�൱��0
}


double figureAcrtanX(double x)
{
	double val=x,result=0,j=1;
	for (int i = 0; abs(val) >= rander; i++)
	{
		val = pow(x, 2 * i + 1) / (2 * i + 1)*j;
		j = j * (-1);
		result += val;
	}
	return result;
}

int jiechengX(int x)
{
	if (x == 1 || x == 0)
		return 1;
	else
		return x * jiechengX(x - 1);
}