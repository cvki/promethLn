#include<iostream>
#include<string>
using namespace std;

double rateWin(double win);
int prmfct(int num);


int main() {

	/*int num;
	cin >> num;
	prmfct(num);*/

	/*cout << "小5的胜率：" << rateWin(0.3) << endl;
	cout << "小8的胜率：" << rateWin(0.35) << endl;*/

#if(0)
	//输入
	int countN = 0;
	cin >> countN;
	int(*p)[2] = new int [countN][2];
	for (int i = 0; i < countN; ++i){
		cin >> p[i][0];
	}

	for (int i = 0; i < countN; ++i) {
		cin >>p[i][1];
	}

	for (int i = 0; i < countN; ++i) {

	}
#endif

	//asdfahshdf afs @#@$@ asdfasf    asdfjw' fa'a   sadfa  .wmer af,w   afuaiosdf
	string str;

	//法1：先输入再反向遍历
	/*int lenWord = 0;
	getline(cin, str);
	for (int j = str.length() - 1; j >= 0 && str[j] != ' '; --j)
		++lenWord;
	cout << lenWord << endl;*/

	//法2：//暂时有问题
	while (cin >> str) {}
	cout << str.length() << endl;

	return 0;
}

//胜率测试
double rateWin(double win) {
	double ratetem = 1, rate = 0;
	while (ratetem > 1e-10) {
		rate += ratetem;
		ratetem *= 0.35;
	}
	return rate * win;
}

//求质因子
int prmfct(int num) {
	if (num < 2){//判断输入，不合法返回
		cout << 0;
		return 0;
	}
	int tem = num;
	cout << num << "=";//输出格式
	for (int i = 2; i<=tem/2; i++) {
		//暴力循环
		while (num % i == 0)
		{
			cout << i;
			if ((num /= i) != 1)//不是最后一个质因子时
				cout << "*";
		}
	}
	if (tem == num)//输入本身为质数时
		cout << num;
	return 0;
}

//求一串字符串的最后一个单词的长度
void getstrlastlen(string str) {
	//asdfahshdf afs @#@$@ asdfasf    asdfjw' fa'a   sadfa  .wmer af,w   afuaiosdf

	//法1：先输入再反向遍历
	/*int lenWord = 0;
	getline(cin, str);
	for (int j = str.length() - 1; j >= 0 && str[j] != ' '; --j)
		++lenWord;
	cout << lenWord << endl;*/

	//法2：
	while (cin >> str) {}
	cout << str.length() << endl;
}