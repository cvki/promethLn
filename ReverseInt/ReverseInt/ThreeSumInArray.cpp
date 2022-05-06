#include<iostream>

using namespace std;

constexpr auto MAXN = 20;
/*题目描述：
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。
示例：
给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
	[-1, 0, 1],
	[-1, -1, 2]
*/

typedef struct temArray
{
	int temA;
	bool sign;
}tA;
int sum3Array(int* a)
{
	tA ttem[MAXN];
	int count = 0; static int p = 0;
	ttem->temA = 0;
	ttem->sign = 1;
	for(int i=0;i<MAXN;i++)
		for(int j=i+1;j< MAXN;j++)
			for (int k = j+1; k < MAXN; k++)
			{
				if (a[i] + a[j] + a[k] == 0)
				{
					ttem[p++].temA = a[i];
					ttem[p++].temA = a[j];
					ttem[p++].temA = a[k];
					//cout << "[" << a[i] << "," << a[j] << "," << a[k] << "]" << endl;
				}
			}
	count = p;
	//for (int i = 0; i < count-2; i+=3)
	//	{
	//	if (ttem[i].temA == ttem[i + 3].temA)
	//	{
	//		for (int j = 1; j < count - 2; j += 3)
	//		{
	//			if (ttem[i].temA == ttem[i + 3].temA)
	//			for (int k = 2; k < count - 2; k += 3)
	//		}
	//	}
	return 0;
}
