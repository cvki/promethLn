// matrix multiplication test in cpu&gpu

#include<iostream>
#include<random>
#include<ctime>

using namespace std;

const int ROWA = 4;
const int COLA = 3;
const int COLB = 5;

uniform_int_distribution<int> v(1,10); //���ɾ��ȷֲ���һ�������

//vector<vector<int>> va(ROWA,vector<int>(COLA));		// Ĭ�ϳ�ʼ��0
//vector<vector<int>> vb(COLA,vector<int>(COLB));		
//vector<vector<int>> vc(ROWA,vector<int>(COLB));

//��ά������������
void randomMatirx(vector<vector<int>>& v) {
	static unsigned SEED = 0;
	srand(SEED);		//�����������һ��(time(0))����Ȼÿ���������ͬ����ÿ����������л�����ͬ
	for(auto &e:v)
		for (auto& x : e) {
			x = rand() % 6 + 1;	//����[1,6]�������
		}
	++SEED;
}

void showMatrix(const string name,const vector<vector<int>>& v) {	//��ӡ����
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
	for (int i{}; i < ROWA; ++i) {		//A��ÿ��
		for (int j{}; j < COLB; ++j) {		//B��ÿ��
			for (int k{}; k < COLA; ++k) {		//B��ÿ��,��Ŀ����A����
				vc[i][j]+= va[i][k] * vb[k][j];
			}
		}
	}
}


int main_cpu() {

	vector<vector<int>> va(ROWA, vector<int>(COLA));		// Ĭ�ϳ�ʼ��0
	vector<vector<int>> vb(COLA, vector<int>(COLB));
	vector<vector<int>> vc(ROWA, vector<int>(COLB));

	//va,vb��������
	randomMatirx(va);
	randomMatirx(vb);
	//randomMatirx(vc);

	//�鿴��������
	showMatrix("(before multiplication) va:",va);
	showMatrix("(before multiplication) vb:",vb);
	showMatrix("(before multiplication) vc:",vc);

	// ����˷�
	cpu_matrix_multiplicate(va, vb, vc);

	//�鿴��������
	showMatrix("(after multiplication) va:", va);
	showMatrix("(after multiplication) vb:", vb);
	showMatrix("(after multiplication) vc:", vc);

	return 0;
}