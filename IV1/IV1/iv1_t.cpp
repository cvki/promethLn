/**
*	IDE: VS2019
��Ŀ��
1����д�������жϸ����������Ƿ���һ��2����
2����д����������һ�����ݣ��ҳ��������еڶ������������ʱ�临�Ӷȣ���1238846557 ��7�ǵڶ�������
3����д����������2���ַ������ַ���������0-9��������ɣ��ַ������Ȳ�ȷ�����������2���ַ�����Ӧ����ֵ֮�Ͷ�Ӧ���ַ���
4����д����������һ�����ݣ��ҳ���������ֵ�����м���Ǹ��������(����������35812��ֵ�����м������3)
**/

#include<iostream>

using namespace std;

//��һ��
const int INTM= INT_MAX / 2 + 1;
bool is2power(int val) {
	if (val <= 0)
		return false;
	int powv=1;
	while (powv < INTM &&powv<val) {
		powv *= 2;
	}
	if(powv==val)
		return true;
	return false;
 }

//��1
#include<bitset>
bool is2power2(int val) {
	if (val <= 0)
		return false;
	bitset<32> btval(val);
	if (btval.count() == 1)  
		//����val&(val-1),ע���ʱval-1Խ�����
		return true;
	return false;
}
void test1() {
	int val;
	cin >> val;
	while (val) {
		cout << is2power2(val) << endl;
		cin >> val;
	}
	
}

//�ڶ���
#include<algorithm>

template<class T1>
int getAimNum(T1* a, int n) { //�����׵�ַ�ͳ���,�ı���ԭ����
	if (!a||n < 2)
		return INT_MAX; //��ʾ�޵ڶ�����
	sort(a, a+n, [](T1& v1, T1& v2) {return v1 > v2; });//����
	for (int i = 0, j = 1; j < n; ++i, ++j)
		if (a[i] != a[j])
			return a[j];
	return INT_MAX;
}
/**ʱ
�临�Ӷȣ�����O(nlogn),���ң�O(n),��O(n+nlogn)��O(n)**/


//������
#include<string>

string getSumStr(string& s1,string& s2) { 
	if (s1.empty() || s2.empty())
		return to_string(-1);   //�п�ʱ����
	int v1(0),v2(0);
	//תΪ��������
	for(int id=0;id<s1.size();++id)
		v1 = v1 * 10 + (s1[id] - '0');
	for (int id = 0; id < s2.size(); ++id)
		v2 = v2 * 10 + (s2[id] - '0');
	return to_string(v1+v2);	//�����ַ���
}


//������
#include<algorithm>

template<class T1>
int getMidNum(T1* a, int n) { //�����׵�ַ�ͳ���
	if (!a||n < 1)  //��a��Ԫ�ظ�������1ʱ����Ϊ�н�
		return INT_MAX; //��ʾ�޽��
	sort(a, a + n);
	return a[n / 2];
}


//3-4��
// �������
#include<string>

string getSumStr2(string& s1, string& s2) {
	if (s1.empty() || s2.empty())
		return to_string(-1);   //�п�ʱ����
	int vup(0), vnow(0);  //��¼��λ�͵�ǰλ
	int id1 = s1.size() - 1, id2 = s2.size() - 1;  //s1��s2�±�
	string res;
	//�ַ�����ÿλ���в������Ӹ�λ(�洢���λ)��ʼ
	for (; id1>-1&&id2>-1; --id1,--id2) {
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
				res+=(s1.at(i));
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

template<class T>
struct Idx {
	int id;
	T val;
};

template<class T1>
class compareByVal { //��ֵ����
public:
	bool operator()(const Idx<T1>& v1, const Idx<T1>& v2) const {
		return v1.val < v2.val;
	}
};

template<class T1>
int randId(T1* a,int begin,int end) { //�����±�
	int n = end - begin;
	srand((unsigned int)time(0));
	int midid = 0;  //��¼���Ż�׼λ��
	Idx<T1> idx[3];	 //��¼������±��ֵ
	for (int i = 0; i < 3; i++) {
		idx[i].id = rand() % (n+1)+ begin;	//�±�
		idx[i].val = a[idx[i].id];	//ֵ
		/*cout << idx[i].id<<endl;
		cout << idx[i].val << endl;*/
	}
	sort(idx, idx + 3, compareByVal<int>());
	return idx[1].id;  
}

template<class T1>
int qsMid(T1* a,int begin,int end,int midid) {  //����һ�ֿ���,���ݵ��±�
	T1 valtmp = a[midid];
	int i = begin, j = end;
	while (i<j && a[j]>valtmp) 
		--j;
	a[midid] = a[j];
	while (i < j) {
		while (i < j && a[i] <= valtmp)
			++i;
		a[j] = a[i];
		while (i<j && a[j]>valtmp)
			--j;
		a[i] = a[j];
	}
	a[i] = valtmp;
	return i;
}

template<class T1>
int getMidNum2(T1* a, int end) { //�����׵�ַ����ֹ�±�,��0��ʼ
	int n = end,begin=0;
	if (!a || n < 0)  //��a��Ԫ�ظ�������1ʱ����Ϊ�н�
		return INT_MAX; //��ʾ�޽��
	int midid = randId<int>(a,0,end);   //�õ���׼λ��
	int idres = qsMid(a, begin, end, midid);	//�õ���Ԫ������������
	while (1) {
		if (idres == n / 2)
			break;
		if (idres < n / 2) {
			midid = randId<int>(a,idres+1,n);   //�õ���׼λ��
			idres = qsMid(a, idres+1, n, midid);   //�õ���Ԫ������������
		}
		else {
			midid = randId<int>(a,0, idres-1);   //�õ���׼λ��
			idres = qsMid(a, 0, idres-1, midid);   //�õ���Ԫ������������
		}
	}
	int v = a[idres];
	return v;
}


//test()����
void testx() {
	//1. v=0��-1��1��16��1024��1073741824,2147483647
	int v1 = 8888;
	cout << is2power(v1) << endl;

	//2. a={1},{2,2},{-1,-1,-1},{ 1,2,3,8,8,4,6,5,5,7 } 
	int a2[] = { 1,2,3,8,8,4,6,5,5,7 };
	int n2 = sizeof(a2) / sizeof(int);
	cout << getAimNum<int>(a2, n2) << endl;

	//3.  s1("1"),s2("0"); s1("101"),s2("01");s1(""),s2("01");s1("909"),s2("1909")
	string s3_1("909"), s3_2("1909");
	cout << getSumStr2(s3_1, s3_2) << endl;

	//a={-1},{1,0},{-1,2,0},{1,2,1,2},{ 3,8,5,1,2}
	//int a4[] = { 3,8,5,1,2 };    // { 3,8,5,1,2 };
	//int n4 = sizeof(a4) / sizeof(int)-1;

	/*const int M = 100000;
	int a4[M];
	for (int i = 0; i < M; ++i) {
		a4[i] = i;
	}*/
	//cout << n4 << endl;
	//cout<< getMidNum2<int>(a4, n4) << endl;
	//cout<< getMidNum2<int>(a4, M-1) << endl;
	// ���Խ����ֱ̫����Ӧ����rand����̫��������������
}


int main() {

	test1();
	return 0;
}