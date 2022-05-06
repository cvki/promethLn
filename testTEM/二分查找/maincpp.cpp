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
//	cout << "��" << binSearch(a, 0, SIZE, e) << "��λ���ϵ�Ԫ��Ϊ��";//���������Ͽ�����binSearch���������ٴ�ӡe���򲻻�ı�e��ֵ��Ҳ˵��cout�Ǵ�������ı���˳��������ġ�
//	cout<<e<< endl;//Ԫ��λ�ô�0��ʼ���������޸ĵ�e
//	return 0;
//}


//���ֲ��ҸĽ���
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

			//ע�����ﴫ�ݵĲ���Ϊ0��SIZE��hi����SIZE-1
			cout << "��" << binSearchP(a, 0, SIZE, e) << "��λ���ϵ�Ԫ��Ϊ��";//���������Ͽ�����binSearch���������ٴ�ӡe���򲻻�ı�e��ֵ��Ҳ˵��cout�Ǵ�������ı���˳��������ġ�
			cout << e << endl;//Ԫ��λ�ô�0��ʼ���������޸ĵ�e
			cout << "*********************************************************************************" << endl;
			cout << "��" << binSearch(a, 0, SIZE, e) << "��λ���ϵ�Ԫ��Ϊ��";//���������Ͽ�����binSearch���������ٴ�ӡe���򲻻�ı�e��ֵ��Ҳ˵��cout�Ǵ�������ı���˳��������ġ�
			cout << e << endl;//Ԫ��λ�ô�0��ʼ���������޸ĵ�e
		}
		return 0;
	}