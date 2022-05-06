/**
*	IDE: VS2019
题目：
1、编写函数，判断给定的整数是否是一个2的幂
2、编写函数，输入一组数据，找出这组数中第二大的数（考虑时间复杂度，如1238846557 ，7是第二大数）
3、编写函数，输入2个字符串，字符串内容由0-9的数字组成，字符串长度不确定，计算输出2个字符串对应的数值之和对应的字符串
4、编写函数，输入一组数据，找出这组数中值处于中间的那个数并输出(举例：数组35812，值处于中间的数是3)
**/

#include<iostream>

using namespace std;

//第一题
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

//改1
#include<bitset>
bool is2power2(int val) {
	if (val <= 0)
		return false;
	bitset<32> btval(val);
	if (btval.count() == 1)  
		//或者val&(val-1),注意此时val-1越界情况
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

//第二题
#include<algorithm>

template<class T1>
int getAimNum(T1* a, int n) { //数组首地址和长度,改变了原数组
	if (!a||n < 2)
		return INT_MAX; //表示无第二大数
	sort(a, a+n, [](T1& v1, T1& v2) {return v1 > v2; });//降序
	for (int i = 0, j = 1; j < n; ++i, ++j)
		if (a[i] != a[j])
			return a[j];
	return INT_MAX;
}
/**时
间复杂度：排序：O(nlogn),查找：O(n),共O(n+nlogn)即O(n)**/


//第三题
#include<string>

string getSumStr(string& s1,string& s2) { 
	if (s1.empty() || s2.empty())
		return to_string(-1);   //有空时返回
	int v1(0),v2(0);
	//转为整数计算
	for(int id=0;id<s1.size();++id)
		v1 = v1 * 10 + (s1[id] - '0');
	for (int id = 0; id < s2.size(); ++id)
		v2 = v2 * 10 + (s2[id] - '0');
	return to_string(v1+v2);	//返回字符串
}


//第四题
#include<algorithm>

template<class T1>
int getMidNum(T1* a, int n) { //数组首地址和长度
	if (!a||n < 1)  //当a中元素个数大于1时，认为有解
		return INT_MAX; //表示无结果
	sort(a, a + n);
	return a[n / 2];
}


//3-4改
// 第三题改
#include<string>

string getSumStr2(string& s1, string& s2) {
	if (s1.empty() || s2.empty())
		return to_string(-1);   //有空时返回
	int vup(0), vnow(0);  //记录进位和当前位
	int id1 = s1.size() - 1, id2 = s2.size() - 1;  //s1和s2下标
	string res;
	//字符串按每位进行操作，从个位(存储最高位)开始
	for (; id1>-1&&id2>-1; --id1,--id2) {
		vnow = (s1[id1] - '0') + (s2[id2] - '0');
		vnow += vup;	//加上进位
		vup = 0;	//进位置0
		if (vnow >= 10) {
			vup = 1;
			vnow -= 10;
		}
		res.append(to_string(vnow));
	}
	if (vup) {//还有进位时
		while (id1 > -1) {
			vnow = s1[id1--] - '0';
			vnow += vup;	//加上进位
			vup = 0;	//进位置0
			if (vnow >= 10) {
				vup = 1;
				vnow -= 10;
			}
			res.append(to_string(vnow));
		}
		while (id2 > -1) {
			vnow = s2[id2--] - '0';
			vnow += vup;	//加上进位
			vup = 0;	//进位置0
			if (vnow >= 10) {
				vup = 1;
				vnow -= 10;
			}
			res.append(to_string(vnow));
		}
	}
	else { //无进位
		if (id1 > -1) {
			for (int i = id1; i > -1; --i)
				res+=(s1.at(i));
		}
		if (id2 > -1) {
			for (int i = id2; i > -1; --i)
				res += (s2.at(i));
		}
	}
	if (vup) //最高位是否为0
		res.append(to_string(vup));
	reverse(res.begin(), res.end()); //正常显示
	return res;	
}


//第四题改
#include<algorithm>

template<class T>
struct Idx {
	int id;
	T val;
};

template<class T1>
class compareByVal { //按值排序
public:
	bool operator()(const Idx<T1>& v1, const Idx<T1>& v2) const {
		return v1.val < v2.val;
	}
};

template<class T1>
int randId(T1* a,int begin,int end) { //数组下标
	int n = end - begin;
	srand((unsigned int)time(0));
	int midid = 0;  //记录快排基准位置
	Idx<T1> idx[3];	 //记录随机的下标和值
	for (int i = 0; i < 3; i++) {
		idx[i].id = rand() % (n+1)+ begin;	//下标
		idx[i].val = a[idx[i].id];	//值
		/*cout << idx[i].id<<endl;
		cout << idx[i].val << endl;*/
	}
	sort(idx, idx + 3, compareByVal<int>());
	return idx[1].id;  
}

template<class T1>
int qsMid(T1* a,int begin,int end,int midid) {  //进行一轮快排,传递的下标
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
int getMidNum2(T1* a, int end) { //数组首地址和起止下标,从0开始
	int n = end,begin=0;
	if (!a || n < 0)  //当a中元素个数大于1时，认为有解
		return INT_MAX; //表示无结果
	int midid = randId<int>(a,0,end);   //得到基准位置
	int idres = qsMid(a, begin, end, midid);	//得到该元素排序后的索引
	while (1) {
		if (idres == n / 2)
			break;
		if (idres < n / 2) {
			midid = randId<int>(a,idres+1,n);   //得到基准位置
			idres = qsMid(a, idres+1, n, midid);   //得到该元素排序后的索引
		}
		else {
			midid = randId<int>(a,0, idres-1);   //得到基准位置
			idres = qsMid(a, 0, idres-1, midid);   //得到该元素排序后的索引
		}
	}
	int v = a[idres];
	return v;
}


//test()测试
void testx() {
	//1. v=0，-1，1，16，1024，1073741824,2147483647
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
	// 测试结果简直太慢，应该是rand过程太慢，出现了问题
}


int main() {

	test1();
	return 0;
}