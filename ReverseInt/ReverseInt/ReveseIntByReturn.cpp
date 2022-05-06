#include<iostream>

using namespace std;

//题目描述：给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
//假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231−1]。
//请根据这个假设，如果反转后整数溢出那么就返回 0。
//示例1:输入:123  输出:321			示例2：输入:-123 输出:-321		示例3: 输入:120  输出:21

int reverseIntRtn(int num)
{
	if (num <= pow(2, 31) * (-1) || num >= pow(2, 31) - 1)
		return 0;
	long long newNum = 0, remainder = 0;
	if (num > 0)
	{
		while (num != 0)
		{
			remainder = num % 10;
			num = num / 10;
			newNum = newNum * 10 + remainder;
			if (newNum <= pow(2, 31)*(-1) || newNum >= pow(2, 31) - 1)
				return 0;
		}
	}
	else if (num == 0)
		return 0;
	else if (num < 0)
	{
		num *= (-1);
		while (num != 0)
		{
			remainder = num % 10;
			num = num / 10;
			newNum = newNum * 10 + remainder;
			if (newNum <= pow(2, 31) * (-1) || newNum >= pow(2, 31) - 1)
				return 0;
		}
		newNum *= (-1);
	}
	return newNum;
}