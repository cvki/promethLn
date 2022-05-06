//第四题改
#include<iostream>

using namespace std;

static int countx;	//测试一下快排了多少次
template<class T1>
int qsMid(T1* a, int begin, int end) {  //进行一轮快排,传递的下标
	T1 valtmp = a[begin];
	int i = begin, j = end;
	while (i < j) {
		while (i<j && a[j]>valtmp)
			--j;
		a[i] = a[j];
		while (i < j && a[i] <= valtmp)
			++i;
		a[j] = a[i];
	}
	++countx;
	a[i] = valtmp;
	return i;
}


template<class T1>
int getMidNum2(T1* a, int end, int begin = 0) { //a和它的起止坐标,从0开始
	int n = end - begin;
	if (!a || n < 0)  //当a中元素个数大于1时，认为有解
		return INT_MAX; //表示无结果
	int begintmp = 0, endtmp = n;
	int idres = qsMid(a, begin, end);
	n /= 2;
	while (1) {	//
		if (idres == n)
			break;
		if (idres < n) {
			begintmp = idres + 1;  //二分缩小查找区间begin
		}
		else {
			endtmp = idres - 1;		////二分缩小查找区间end
		}
		idres = qsMid(a, begintmp, endtmp);   //得到该元素排序后的索引
	}
	int v = a[idres];
	return v;
}


//test()测试
void test() {
	int a4[] = { 8,5,2,1,3};
	int n4 = sizeof(a4) / sizeof(int) - 1;
	cout << "countx: " << countx << "\t" << "Mid NUM: " << getMidNum2<int>(a4, n4) << endl;
}


int main() {

	test();
	return 0;
}