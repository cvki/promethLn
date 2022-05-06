#include<iostream>
#include<cmath>

using namespace std;

double jiechengX(int x);
double getSinX(double x);

double getKofSinX(double r, double s)
{
	if (r * r - s * s <= 0)
		return  sqrt(getSinX(r) * getSinX(r) + getSinX(s) * getSinX(s));
	if (r * r - s * s > 0)
		return  0.5 * getSinX(r * s);
}

double getSinX(double x)
{
	double result = 0, val = x;
	int sym = 1;
	for (int i = 0; abs(val) >= pow(10, -10); i++)
	{
		val = pow(x, 2 * i + 1) / jiechengX(2*i+1) * sym;
		sym *= (-1);
		result += val;
	}
	//cout << "sin:" << result << "\t";//ÓÃÓÚ²âÊÔsinº¯Êý
	//cout << endl;
	return result;
}

double jiechengX(int x)
{
	if (x == 0 || x == 1)
		return 1;
	else
		return x * jiechengX(x - 1);
}

