//�������
#include<iostream>

using namespace std;

static int countx;	//����һ�¿����˶��ٴ�
template<class T1>
int qsMid(T1* a, int begin, int end) {  //����һ�ֿ���,���ݵ��±�
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
int getMidNum2(T1* a, int end, int begin = 0) { //a��������ֹ����,��0��ʼ
	int n = end - begin;
	if (!a || n < 0)  //��a��Ԫ�ظ�������1ʱ����Ϊ�н�
		return INT_MAX; //��ʾ�޽��
	int begintmp = 0, endtmp = n;
	int idres = qsMid(a, begin, end);
	n /= 2;
	while (1) {	//
		if (idres == n)
			break;
		if (idres < n) {
			begintmp = idres + 1;  //������С��������begin
		}
		else {
			endtmp = idres - 1;		////������С��������end
		}
		idres = qsMid(a, begintmp, endtmp);   //�õ���Ԫ������������
	}
	int v = a[idres];
	return v;
}


//test()����
void test() {
	int a4[] = { 8,5,2,1,3};
	int n4 = sizeof(a4) / sizeof(int) - 1;
	cout << "countx: " << countx << "\t" << "Mid NUM: " << getMidNum2<int>(a4, n4) << endl;
}


int main() {

	test();
	return 0;
}