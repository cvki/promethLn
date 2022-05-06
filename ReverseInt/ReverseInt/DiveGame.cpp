#include<iostream>

using namespace std;

int diceMading()
{
	int val1,val2,tval,seed;
	cout << "Enter the seed number:" << endl;
	cin >> seed;
	srand(seed);
	val1 = rand() % 6 + 1;
	val2 = rand() % 6 + 1;
	if (val1 + val2 == 7 || val1 + val2 == 11)
	{
		cout << "val1: " << val1 << "\t" << "val2: " << val2 << endl;
		cout << "YOU WIN!" << endl;
	}
	else if (val1 + val2 == 2 || val1 + val2 == 3 || val1 + val2 == 12)
	{
		cout << "val1: " << val1 << "\t" << "val2: " << val2 << endl;
		cout << "YOU LOSE!" << endl;
	}
	else
	{
		tval = val1 + val2;
		cout << " tval: "<<tval << endl;
		cout << "Enter the seed number:" << endl;
		cin >> seed;
		srand(seed);
		val1 = rand() % 6 + 1;
		val2 = rand() % 6 + 1;
		while (val1 != tval && val2 != tval && val1 + val2 != 7)
		{
			cout << "Enter the seed number:" << endl;
			cin >> seed;
			srand(seed);
			val1 = rand() % 6 + 1;
			val2 = rand() % 6 + 1;
		}
		if (val1 + val2 == 7)
		{
			cout << "val1: " << val1 << "\t" << "val2: " << val2 << endl;
			cout << "YOU LOSE!" << endl;
		}
		else if (val1 == tval || val2 == tval)
		{
			cout << "val1: " << val1 << "\t" << "val2: " << val2 << endl;
			cout << "YOU WIN!" << endl;
		}
	}
	return 0;
}

int testRandFigure()
{
	int a, b, c;
	cout << "Enter 2 integer number as the range of rander(a,b): (num1,num2)" << endl;
	cin >> a >> b;
	srand(time(0));//随机数种子以改变随机数
	for (int i = 0; i < 7; i++)
	{
		c = rand() % (b - a + 1) + a;//指定范围的随机数生成
		cout << c << "\t" << endl;
	}
	return 0;
}