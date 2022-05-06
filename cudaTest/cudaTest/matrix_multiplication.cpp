// matrix multiplication test in cpu&gpu

#include<iostream>
#include<random>
#include<ctime>

using namespace std;

const int ROWA = 4;
const int COLA = 3;
const int COLB = 5;

uniform_int_distribution<int> v(1,10); //生成均匀分布的一个随机数

//vector<vector<int>> va(ROWA,vector<int>(COLA));		// 默认初始化0
//vector<vector<int>> vb(COLA,vector<int>(COLB));		
//vector<vector<int>> vc(ROWA,vector<int>(COLB));

//二维矩阵产生随机数
void randomMatirx(vector<vector<int>>& v) {
	static unsigned SEED = 0;
	srand(SEED);		//若随机数种子一样(time(0))，虽然每个随机数不同，但每条随机数序列还是相同
	for(auto &e:v)
		for (auto& x : e) {
			x = rand() % 6 + 1;	//生成[1,6]的随机数
		}
	++SEED;
}

void showMatrix(const string name,const vector<vector<int>>& v) {	//打印矩阵
	cout << "the matrix " << name << " is:" << endl;
	for (auto& e : v) {		
		for (auto& x : e) {
			cout << x << "  ";
		}
		cout << endl;
	}
}

void cpu_matrix_multiplicate(const vector<vector<int>> &va, const vector<vector<int>> &vb, 
											 vector<vector<int>>& vc) {
	for (int i{}; i < ROWA; ++i) {		//A的每行
		for (int j{}; j < COLB; ++j) {		//B的每列
			for (int k{}; k < COLA; ++k) {		//B的每行,数目等于A的列
				vc[i][j]+= va[i][k] * vb[k][j];
			}
		}
	}
}


int main_cpu() {

	vector<vector<int>> va(ROWA, vector<int>(COLA));		// 默认初始化0
	vector<vector<int>> vb(COLA, vector<int>(COLB));
	vector<vector<int>> vc(ROWA, vector<int>(COLB));

	//va,vb填充随机数
	randomMatirx(va);
	randomMatirx(vb);
	//randomMatirx(vc);

	//查看矩阵内容
	showMatrix("(before multiplication) va:",va);
	showMatrix("(before multiplication) vb:",vb);
	showMatrix("(before multiplication) vc:",vc);

	// 矩阵乘法
	cpu_matrix_multiplicate(va, vb, vc);

	//查看矩阵内容
	showMatrix("(after multiplication) va:", va);
	showMatrix("(after multiplication) vb:", vb);
	showMatrix("(after multiplication) vc:", vc);

	return 0;
}