#include<iostream>

using namespace std;

const int MAXSIZE = 100;
template<typename T>
void swapt(T& t1, T& t2) {
	T tem=t1;
	t1 = t2;
	t2 = tem;
}

template<typename T>
int mainP() {
	T t[MAXSIZE];
	//int t[MAXSIZE];
	int n, k;
	while (1)
	{
		cout << "��������Ԫ������������Ԫ�أ�" << endl;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> t[i];
		cout << "�����ƶ�λ��(����)��" << endl;
		cin >> k;
		for (int i = 0; i < (n - k) / 2; ++i) {
			swapt(t[i], t[n - k - i - 1]);
		}
		for (int i = n - k; i < n - k / 2; ++i) {
			swapt(t[i], t[2 * n - k - i - 1]);
		}
		for (int i = 0; i < n / 2; ++i) {
			swapt(t[i], t[n - i - 1]);
		}
		cout << "(����)�ƶ�" << k << "λ������Ԫ��Ϊ��" << endl;
		for (int i = 0; i < n; ++i) {
			cout << t[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}

int main() {
	mainP<int>();//����ָ��ģ�����ͣ����򱨴�
	return 0;
}