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

//��������1
void reverseArr1(int a[]) {
	int tem = MAXSIZEARR / 2, tc = 0;
	for (int i = 0; i < tem; ++i) {
		swap(a[i], a[MAXSIZEARR - 1 - i]);
	}
}
//��������2.1----����ݹ飺˼��ԭ��
void reverseArr2X(int a[], int begin, int end) {//�ݹ� 
	if (begin == end)
		return;
	if (begin + 1 == end)
		swap(a[begin], a[end]);
	else
		reverseArr2(a, begin + 1, end - 1);
}
//��������2.2----��ȷ�ݹ�
void reverseArr2(int a[], int begin, int end) {
	/*if (begin >= end)
		return;
	else {
		swap(a[begin], a[end]);
		reverseArr2(a, begin + 1, end - 1);
	}*/
	
	//����
	if (begin < end) {
		swap(a[begin], a[end]);
		reverseArr2(a, begin + 1, end - 1);
	}
}
//��������3��
void reverseArr3(int a[], int begin, int end) {
	while (begin < end)
		swap(a[begin++], a[end--]);
}
void swap(int& a, int& b) {
	int tem = a;
	a = b;
	b = tem;
}