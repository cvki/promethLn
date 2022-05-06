#include<iostream>

using namespace std;

const int SIZE = 6;


//template<typename T>
//int binSearch(T& a, int lo, int hi,int &e) {
//	while (lo < hi) {
//		int mid = (lo + hi) >> 1;
//		(e < a[mid]) ? hi = mid : lo = mid+1;
//	}
//	e = a[--lo];
//	return --lo;
//}
//
//int main() {
//	int a[SIZE];
//	int e;
//	for (int i = 0; i < SIZE; ++i)
//		cin >> a[i];
//	cin >> e;
//	cout << "第" << binSearch(a, 0, SIZE, e) << "个位置上的元素为：";//这里若不断开，让binSearch先运行完再打印e，则不会改变e的值。也说明cout是从右往左的变量顺序插入流的。
//	cout<<e<< endl;//元素位置从0开始，返回已修改的e
//	return 0;
//}


//二分查找改进版
template<typename T>
int binSearchP(T& a, int lo, int hi, int& e) {
	while (hi-lo>1) {
		int mid = (lo + hi) >> 1;
		(e < a[mid]) ? hi = mid : lo = mid;
	}
	return e == a[lo] ? lo : -1;
}

template<typename T>
int binSearch(T& a, int lo, int hi, int& e) {
	while (hi>lo) {
		int mid = (lo + hi) >> 1;
		(e < a[mid]) ? hi = mid : lo = mid+1;
		if (e == a[mid]) return mid;
	}
	return -1;
}

int main() {
		int a[SIZE];
		int e;
		while (1) {
			for (int i = 0; i < SIZE; ++i)
				cin >> a[i];
			cin >> e;

			//注意这里传递的参数为0和SIZE，hi不是SIZE-1
			cout << "第" << binSearchP(a, 0, SIZE, e) << "个位置上的元素为：";//这里若不断开，让binSearch先运行完再打印e，则不会改变e的值。也说明cout是从右往左的变量顺序插入流的。
			cout << e << endl;//元素位置从0开始，返回已修改的e
			cout << "*********************************************************************************" << endl;
			cout << "第" << binSearch(a, 0, SIZE, e) << "个位置上的元素为：";//这里若不断开，让binSearch先运行完再打印e，则不会改变e的值。也说明cout是从右往左的变量顺序插入流的。
			cout << e << endl;//元素位置从0开始，返回已修改的e
		}
		return 0;
	}