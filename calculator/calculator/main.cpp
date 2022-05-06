#pragma once

#include<iostream>
#include <string>

using namespace std;

string exptransform(string s);//中缀表达式转后缀
int calculatorInt(string s);//整数计算器 1.直接对中缀计算
int calculator2(string s);//整数计算器 2.先转后缀再计算
double computerDouble(string s);//浮点型计算器，由于转后缀需要判断小数点，因此直接采用对中缀的计算

int main() {
	//中缀表达式转后缀表达式
	/*string s1, s2;
	cin >> s1;
	s2 = exptransform(s1);
	cout << "中缀表达式：" <<s1<< endl<<"后缀表达式: "<<s2<<endl;*/

	
	string s1,s2;
	getline(cin, s1);//对于有空白符的时候的输入
	//cin >> s1;//无空白符时可以这样输入

	//整数计算器 1.对中缀表达式直接计算
	//cout <<"1.对中缀表达式直接计算: "<< calculatorInt(s1) << endl;

	//整数计算器 2.先将表达式转换为后缀,然后对后缀表达式计算
	//s2=exptransform(s1);
	//cout << "2.先转后缀再计算: " << calculator2(s2) << endl;

	//浮点计算器
	cout << "对中缀表达式直接计算: " << computerDouble(s1) << endl;

	return 0;
}