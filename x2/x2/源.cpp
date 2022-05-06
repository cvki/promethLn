#if 0

//3-4改
#include<iostream>
#include<algorithm>
#include<vector>

// 第三题改
#include<string>

using namespace std;

string getSumStr2(string& s1, string& s2) {
	if (s1.empty() || s2.empty())
		return to_string(-1);   //有空时返回
	int vup(0), vnow(0);  //记录进位和当前位
	int id1 = s1.size() - 1, id2 = s2.size() - 1;  //s1和s2下标
	string res;
	//字符串按每位进行操作，从个位(存储最高位)开始
	for (; id1 > -1 && id2 > -1; --id1, --id2) {
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
				res += (s1.at(i));
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

//template<class T>
//struct Idx {
//	int id;	//下标
//	T val;	//值
//
//};
//
//template<class T1>
//class compareByVal { //按值排序
//public:
//	bool operator()(const Idx<T1>& v1, const Idx<T1>& v2) const {
//		return v1.val < v2.val;
//	}
//};

static int countx;
template<class T1>
int qsMid(T1* a, int begin, int end) {  //进行一轮快排,传递的下标
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
int getMidNum2(T1* a, int end, int begin = 0) { //a为Daox对象指针，后面是a的起止坐标,从0开始
	int n = end - begin;
	if (!a || n < 0)  //当a中元素个数大于1时，认为有解
		return INT_MAX; //表示无结果
	int begintmp = 0, endtmp = n;
	int idres = qsMid(a, begin, end);
	while (1) {
		if (idres == n / 2)
			break;
		if (idres < n / 2) {
			begintmp = idres+1;  //缩小查找区间begin
		}
		else {
			endtmp = idres-1;		////缩小查找区间end
		}
		idres = qsMid(a, begintmp, endtmp);   //得到该元素排序后的索引
	}
	int v = a[idres];
	return v;
}


//test()测试
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
	sort(vtm.begin(), vtm.end(), greater<int>());    //第三个参数需要谓词，函数对象
	cout << "mid: " << vtm.at(vtm.size() / 2) << "\t" << "midID: " << vtm.size() / 2 << endl;
	for (auto item : vtm)
		cout << item << " ";
	cout << endl;

	int n4 = sizeof(a4) / sizeof(int) - 1;
	//int n4 = 17;
	//cout << n4;

	cout << "countx: " << countx << endl << "Mid NUM: " << getMidNum2<int>(a4, n4) << endl;  
	//注意countx位置,"<<"是从右往左进行插入的，如果把countx放在能改变它的getMidNum之右，则会输出0
}


int main() {

	test();
	return 0;
}

#endif
