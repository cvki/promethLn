#include<iostream>

using namespace std;

constexpr int MAXSIZE = 20;
int getSubsumMax1(int* a,int length,int& begin,int& end) {//ʱ�临�Ӷ�O(n^2)
	int sum = a[0],tem, count = 0;//sumʼ��ָ��ȫ�����к͵����ֵ
	for(int i = 0; i < length; i++) {
		tem = 0;
		for (int j = i; j < length; j++) {//temʼ�ռ���ÿ�ֵĵ�ǰ���к�
			tem += a[j]; count++;
			if (sum < tem) {
				sum = tem;
				end = j;//��������յ�index
			}
		}
	}
	//���ݼ�������������index
	tem = sum; int i = end;
	while (tem) {
		tem -= a[i--];
	}
	begin = ++i;
	cout << "max1�Ƚϴ�����" << count << endl;
	return sum;
}

int getSubsumMax2(int* a, int length,int& begin,int& end) {
	int sum = 0;

	return sum;
}

int main() {
	int a[MAXSIZE],length,sum=0,begin=0,end=0;
	while (1) {
		cout << "��������Ԫ�ظ���������Ԫ��:" << endl;
		cin >> length;
		for (int i = 0; i < length; ++i)
			cin >> a[i];
		sum = getSubsumMax1(a, length,begin,end);
		cout << "������еĺ�Ϊ��" << sum << endl<< "�������Ϊ��" << begin << "--->" << end << endl;
	}
	return 0;
}