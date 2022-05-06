#if 0

//3-4��
#include<iostream>
#include<algorithm>
#include<vector>

// �������
#include<string>

using namespace std;

string getSumStr2(string& s1, string& s2) {
	if (s1.empty() || s2.empty())
		return to_string(-1);   //�п�ʱ����
	int vup(0), vnow(0);  //��¼��λ�͵�ǰλ
	int id1 = s1.size() - 1, id2 = s2.size() - 1;  //s1��s2�±�
	string res;
	//�ַ�����ÿλ���в������Ӹ�λ(�洢���λ)��ʼ
	for (; id1 > -1 && id2 > -1; --id1, --id2) {
		vnow = (s1[id1] - '0') + (s2[id2] - '0');
		vnow += vup;	//���Ͻ�λ
		vup = 0;	//��λ��0
		if (vnow >= 10) {
			vup = 1;
			vnow -= 10;
		}
		res.append(to_string(vnow));
	}
	if (vup) {//���н�λʱ
		while (id1 > -1) {
			vnow = s1[id1--] - '0';
			vnow += vup;	//���Ͻ�λ
			vup = 0;	//��λ��0
			if (vnow >= 10) {
				vup = 1;
				vnow -= 10;
			}
			res.append(to_string(vnow));
		}
		while (id2 > -1) {
			vnow = s2[id2--] - '0';
			vnow += vup;	//���Ͻ�λ
			vup = 0;	//��λ��0
			if (vnow >= 10) {
				vup = 1;
				vnow -= 10;
			}
			res.append(to_string(vnow));
		}
	}
	else { //�޽�λ
		if (id1 > -1) {
			for (int i = id1; i > -1; --i)
				res += (s1.at(i));
		}
		if (id2 > -1) {
			for (int i = id2; i > -1; --i)
				res += (s2.at(i));
		}
	}
	if (vup) //���λ�Ƿ�Ϊ0
		res.append(to_string(vup));
	reverse(res.begin(), res.end()); //������ʾ
	return res;
}


//�������
#include<algorithm>

//template<class T>
//struct Idx {
//	int id;	//�±�
//	T val;	//ֵ
//
//};
//
//template<class T1>
//class compareByVal { //��ֵ����
//public:
//	bool operator()(const Idx<T1>& v1, const Idx<T1>& v2) const {
//		return v1.val < v2.val;
//	}
//};

static int countx;
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
		++countx;
	}
	a[i] = valtmp;
	return i;
}

template<class T1>
int getMidNum2(T1* a, int end, int begin = 0) { //aΪDaox����ָ�룬������a����ֹ����,��0��ʼ
	int n = end - begin;
	if (!a || n < 0)  //��a��Ԫ�ظ�������1ʱ����Ϊ�н�
		return INT_MAX; //��ʾ�޽��
	int begintmp = 0, endtmp = n;
	int idres = qsMid(a, begin, end);
	while (1) {
		if (idres == n / 2)
			break;
		if (idres < n / 2) {
			begintmp = idres+1;  //��С��������begin
		}
		else {
			endtmp = idres-1;		////��С��������end
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

	//int a4[] = { 3,22,8,5,21,1,2,45,7,9,21,0,8,62,3,11,12,21,4,15,22,24,87,34,4,1 };
	//int a4[] = { 3,8,5,1,2,7,9,0,8,3,11,12,21,4,22,24,87 };
	int a4[] = { 9,8,7,6,5 };
	vector<int> vtm(a4,a4+5);
	sort(vtm.begin(), vtm.end(), greater<int>());    //������������Ҫν�ʣ���������
	cout << "mid: " << vtm.at(vtm.size() / 2) << "\t" << "midID: " << vtm.size() / 2 << endl;
	for (auto item : vtm)
		cout << item << " ";
	cout << endl;

	int n4 = sizeof(a4) / sizeof(int) - 1;
	//int n4 = 17;
	//cout << n4;

	cout << "countx: " << countx << endl << "Mid NUM: " << getMidNum2<int>(a4, n4) << endl;  
	//ע��countxλ��,"<<"�Ǵ���������в���ģ������countx�����ܸı�����getMidNum֮�ң�������0
}


int main() {

	test();
	return 0;
}

#endif
