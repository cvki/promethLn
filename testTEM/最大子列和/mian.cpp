#include<iostream>

using namespace std;

constexpr int MAXSIZE = 20;
int getSubsumMax1(int* a,int length,int& begin,int& end) {//时间复杂度O(n^2)
	int sum = a[0],tem, count = 0;//sum始终指向全局子列和的最大值
	for(int i = 0; i < length; i++) {
		tem = 0;
		for (int j = i; j < length; j++) {//tem始终计算每轮的当前子列和
			tem += a[j]; count++;
			if (sum < tem) {
				sum = tem;
				end = j;//最大子列终点index
			}
		}
	}
	//回溯计算最大子列起点index
	tem = sum; int i = end;
	while (tem) {
		tem -= a[i--];
	}
	begin = ++i;
	cout << "max1比较次数：" << count << endl;
	return sum;
}

int getSubsumMax2(int* a, int length,int& begin,int& end) {
	int sum = 0;

	return sum;
}

int main() {
	int a[MAXSIZE],length,sum=0,begin=0,end=0;
	while (1) {
		cout << "输入数组元素个数和数组元素:" << endl;
		cin >> length;
		for (int i = 0; i < length; ++i)
			cin >> a[i];
		sum = getSubsumMax1(a, length,begin,end);
		cout << "最长子序列的和为：" << sum << endl<< "最长子序列为：" << begin << "--->" << end << endl;
	}
	return 0;
}