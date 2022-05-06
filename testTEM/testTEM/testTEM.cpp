#include<iostream>
#include<iomanip>
using namespace std;

const int MAXSIZEARR = 6;

void swap(int& a, int& b);
void reverseArr1(int a[]);
void reverseArr2(int a[], int begin, int end);
void reverseArr2X(int a[], int begin, int end);
void reverseArr3(int a[], int begin, int end);
int main() {
	int a[MAXSIZEARR];
	for (int i = 0; i < MAXSIZEARR; ++i) {
		cin >> a[i];
	}

	reverseArr2(a, 0, MAXSIZEARR - 1);

	for (int i = 0; i < MAXSIZEARR; ++i) {
		cout << setw(3) << left;
		cout << a[i];
	}
	return 0;
}

//逆置数组1
void reverseArr1(int a[]) {
	int tem = MAXSIZEARR / 2, tc = 0;
	for (int i = 0; i < tem; ++i) {
		swap(a[i], a[MAXSIZEARR - 1 - i]);
	}
}
//逆置数组2.1----错误递归：思考原因
void reverseArr2X(int a[], int begin, int end) {//递归 
	if (begin == end)
		return;
	if (begin + 1 == end)
		swap(a[begin], a[end]);
	else
		reverseArr2(a, begin + 1, end - 1);
}
//逆置数组2.2----正确递归
void reverseArr2(int a[], int begin, int end) {
	/*if (begin >= end)
		return;
	else {
		swap(a[begin], a[end]);
		reverseArr2(a, begin + 1, end - 1);
	}*/
	
	//或者
	if (begin < end) {
		swap(a[begin], a[end]);
		reverseArr2(a, begin + 1, end - 1);
	}
}
//逆置数组3：
void reverseArr3(int a[], int begin, int end) {
	while (begin < end)
		swap(a[begin++], a[end--]);
}
void swap(int& a, int& b) {
	int tem = a;
	a = b;
	b = tem;
}