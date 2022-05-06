#include<iostream>
#include<cstring>

using namespace std;

//题目描述：输入一个二进制数，输出对应十进制数
//重点：1,输入二进制看作字符。  2.注意在数组或字符串存储时的高低位。到底应该乘以2的多少次方。
constexpr auto MAXBIT = 100;

int convertBitToDec(string s)
{
	int countTen = 0;
	char p[MAXBIT];
	strcpy_s(p, s.c_str());//注意所用函数须为C++中经过优化的安全函数，参数类型可参照strcpy_c()的API描述
	for (int i= 0; i <s.length(); i++)
	{
		if (p[i] == '1')
			countTen += pow(2, s.length()-1-i);
		else if(p[i]=='0')
		{ }
		else
		{
			cout << "Enter ERROR!" << endl;
			return 0;
		}
	}
	cout << countTen << endl;
	return 0;
}