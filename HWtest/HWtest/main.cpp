#include<iostream>
#include<string>
using namespace std;

double rateWin(double win);
int prmfct(int num);


int main() {

	/*int num;
	cin >> num;
	prmfct(num);*/

	/*cout << "С5��ʤ�ʣ�" << rateWin(0.3) << endl;
	cout << "С8��ʤ�ʣ�" << rateWin(0.35) << endl;*/

#if(0)
	//����
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

	//��1���������ٷ������
	/*int lenWord = 0;
	getline(cin, str);
	for (int j = str.length() - 1; j >= 0 && str[j] != ' '; --j)
		++lenWord;
	cout << lenWord << endl;*/

	//��2��//��ʱ������
	while (cin >> str) {}
	cout << str.length() << endl;

	return 0;
}

//ʤ�ʲ���
double rateWin(double win) {
	double ratetem = 1, rate = 0;
	while (ratetem > 1e-10) {
		rate += ratetem;
		ratetem *= 0.35;
	}
	return rate * win;
}

//��������
int prmfct(int num) {
	if (num < 2){//�ж����룬���Ϸ�����
		cout << 0;
		return 0;
	}
	int tem = num;
	cout << num << "=";//�����ʽ
	for (int i = 2; i<=tem/2; i++) {
		//����ѭ��
		while (num % i == 0)
		{
			cout << i;
			if ((num /= i) != 1)//�������һ��������ʱ
				cout << "*";
		}
	}
	if (tem == num)//���뱾��Ϊ����ʱ
		cout << num;
	return 0;
}

//��һ���ַ��������һ�����ʵĳ���
void getstrlastlen(string str) {
	//asdfahshdf afs @#@$@ asdfasf    asdfjw' fa'a   sadfa  .wmer af,w   afuaiosdf

	//��1���������ٷ������
	/*int lenWord = 0;
	getline(cin, str);
	for (int j = str.length() - 1; j >= 0 && str[j] != ' '; --j)
		++lenWord;
	cout << lenWord << endl;*/

	//��2��
	while (cin >> str) {}
	cout << str.length() << endl;
}