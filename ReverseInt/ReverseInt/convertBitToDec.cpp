#include<iostream>
#include<cstring>

using namespace std;

//��Ŀ����������һ�����������������Ӧʮ������
//�ص㣺1,��������ƿ����ַ���  2.ע����������ַ����洢ʱ�ĸߵ�λ������Ӧ�ó���2�Ķ��ٴη���
constexpr auto MAXBIT = 100;

int convertBitToDec(string s)
{
	int countTen = 0;
	char p[MAXBIT];
	strcpy_s(p, s.c_str());//ע�����ú�����ΪC++�о����Ż��İ�ȫ�������������Ϳɲ���strcpy_c()��API����
	for (int i= 0; i <s.length(); i++)
	{
		if (p[i] == '1')
			countTen += pow(2, s.length()-1-i);
		else if(p[i]=='0')
		{ }
		else
		{
			cout << "Enter ERROR!" << endl;
			return 0;
		}
	}
	cout << countTen << endl;
	return 0;
}