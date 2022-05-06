//二分查找最大的两个值（递归+分治）
#include<iostream>

using namespace std;

const int sizeA = 12;

void max2num(int a[], int lo, int hi, int& max1, int& max2) {
	if (lo + 1 == hi) {
		a[lo] >= a[hi] ? (max1 = a[lo], max2 = a[hi]) : (max1 = a[hi], max2 = a[lo]);//不加括号会出错。
		return;
	}
	int mid = (lo + hi) / 2;
	if (lo + 2 == hi) {
		//逻辑有问题，该逻辑只能得到最大的数，不能确定次大的数
		//int tem = a[lo] >= a[mid] ? lo : mid;
		//a[tem] >= a[hi] ? (max1 = a[tem], max2 = a[hi]) : (max1 = a[hi], max2 = a[tem]);//不加括号会出错，这里逻辑有问题
		int k1, k2;
		k1 = a[lo] >= a[mid] ? lo : mid;
		k2 = a[k1] >= a[hi] ? k1 : hi;
		max1 = a[k2];
		if (k2 == lo)
			max2 = a[mid] >= a[hi] ? a[mid] : a[hi];
		else if(k2==mid)
			max2 = a[lo] >= a[hi] ? a[lo] : a[hi];
		else
			max2 = a[mid] >= a[lo] ? a[mid] : a[lo];
		return;
	};
	int x1l, x2l; max2num(a, lo, mid, x1l, x2l);
	int x1r, x2r; max2num(a, mid + 1, hi, x1r, x2r);
	if (x1l >= x1r) {
		max1 = x1l;
		if (x2l >= x1r)
			max2 = x2l;
		else
			max2 = x1r;
	}
	else {
		max1 = x1r;
		if (x2r >= x1l)
			max2 = x2r;
		else
			max2 = x1l;
	}
}

int main() {
	int a[sizeA];
	for (int i = 0; i < sizeA; ++i)
		cin >> a[i];
	int max1, max2;
	max2num(a, 0, sizeA - 1, max1, max2);
	cout << max1 << "," << max2 << endl;
	return 0;
}





//#include <iostream>
//#include <string>
//
//using namespace std;
//int getmin(int**p) {
//    int min =**p;
//    if (*(*p + 1) < min)
//        min = *(*p+1);
//    if (*(*p + 2) < min)
//        min = *(*p + 2);
//    return min;
//}
//int main() {
//    int n;
//    int a[1000][3];
//    cin >> n;
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < 3; j++) {
//            cin >> a[i][j];
//        }
//    for (int i = 0; i < 3; i++)
//        for (int j = 0; j < n; j++) {
//
//        }
//    return 0;
//}

