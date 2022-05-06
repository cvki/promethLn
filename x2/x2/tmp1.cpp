# if 0

//�������
#include<iostream>
#include<vector>
#include<algorithm>

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
int qsMidx(T1* a, int begin, int end) {  //����һ�ֿ���,���ݵ��±�
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
	while (1) {
		if (idres == n / 2)
			break;
		if (idres < n / 2) {
			begintmp = idres + 1;  //��С��������begin
		}
		else {
			endtmp = idres - 1;		////��С��������end
		}
		idres = qsMid(a, begintmp, endtmp);   //�õ���Ԫ������������
	}
	int v = a[idres];
	return v;
}


//test()����
void test() {

	string s3_1("19909"), s3_2("999");
	//cout << getSumStr2(s3_1, s3_2) << endl;


	//int a4[10000];// { 3,8,5,1,2 };
	//for (int i = 9999; i >= 0; --i) {
	//	a4[i] = i;
	//}

	int a6[] = { 3,22,8,5,21,1,2,45,7,9,21,0,8,62,3,11,12,21,4,15,22,24,87,34,4,1 };
	int a5[] = { 3,8,5,1,2,7,9,0,8,3,11,12,21,4,22,24,87 };
	int a4[] = { 9,8,7,6,5 };
	vector<int> vtm4(a4, a4 + 5);
	vector<int> vtm5(a5, a5 + 17);
	vector<int> vtm6(a6, a6 + 26);
	sort(vtm4.begin(), vtm4.end(), greater<int>());    //������������Ҫν�ʣ���������
	cout << "mid: " << vtm4.at(vtm4.size() / 2) << "\t" << "midID: " << vtm4.size() / 2 << endl;
	sort(vtm5.begin(), vtm5.end(), greater<int>());    //������������Ҫν�ʣ���������
	cout << "mid: " << vtm5.at(vtm5.size() / 2) << "\t" << "midID: " << vtm5.size() / 2 << endl;
	sort(vtm6.begin(), vtm6.end(), greater<int>());    //������������Ҫν�ʣ���������
	cout << "mid: " << vtm6.at(vtm6.size() / 2) << "\t" << "midID: " << vtm6.size() / 2 << endl;
	/*for (auto item : vtm4)
		cout << item << " ";
	cout << endl;*/
	for (auto num1 : vtm4)
		cout << num1 << " ";
	cout << endl;
	for (auto num1 : vtm5)
		cout << num1 << " ";
	cout << endl;
	for (auto num1 : vtm6)
		cout << num1 << " ";
	cout << endl;

	int n4 = sizeof(a4) / sizeof(int) - 1;
	int n5 = sizeof(a5) / sizeof(int) - 1;
	int n6 = sizeof(a6) / sizeof(int) - 1;
	cout << "countx: " << countx << endl << "Mid NUM: " << getMidNum2<int>(a4, n4) << endl;
	cout << "countx: " << countx << endl << "Mid NUM: " << getMidNum2<int>(a5, n5) << endl;
	cout << "countx: " << countx << endl << "Mid NUM: " << getMidNum2<int>(a6, n6) << endl;
}


int main() {

	test();
	return 0;
}

#endif