#pragma once

#include<iostream>
#include <string>

using namespace std;

string exptransform(string s);//��׺���ʽת��׺
int calculatorInt(string s);//���������� 1.ֱ�Ӷ���׺����
int calculator2(string s);//���������� 2.��ת��׺�ټ���
double computerDouble(string s);//�����ͼ�����������ת��׺��Ҫ�ж�С���㣬���ֱ�Ӳ��ö���׺�ļ���

int main() {
	//��׺���ʽת��׺���ʽ
	/*string s1, s2;
	cin >> s1;
	s2 = exptransform(s1);
	cout << "��׺���ʽ��" <<s1<< endl<<"��׺���ʽ: "<<s2<<endl;*/

	
	string s1,s2;
	getline(cin, s1);//�����пհ׷���ʱ�������
	//cin >> s1;//�޿հ׷�ʱ������������

	//���������� 1.����׺���ʽֱ�Ӽ���
	//cout <<"1.����׺���ʽֱ�Ӽ���: "<< calculatorInt(s1) << endl;

	//���������� 2.�Ƚ����ʽת��Ϊ��׺,Ȼ��Ժ�׺���ʽ����
	//s2=exptransform(s1);
	//cout << "2.��ת��׺�ټ���: " << calculator2(s2) << endl;

	//���������
	cout << "����׺���ʽֱ�Ӽ���: " << computerDouble(s1) << endl;

	return 0;
}