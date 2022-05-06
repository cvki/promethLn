#include"Student.h"
#include<vector>
#include"Point.h"

constexpr int SIZETEST = 6;

void test1() {

	Student* s1 = new Student[SIZETEST];

	//Person* s1 = new Person[SIZETEST];//也可以


	for (int i = 0; i < SIZETEST; i++) {
		cin >> s1[i];
	}

	for (int i = 0; i < SIZETEST; i++) {
		cout << s1[i]<<endl;
	}

}

void test2(){
	Point* p1 = new Point[SIZETEST];
	for (int i = 0; i < SIZETEST; i++) {
		cin >> p1[i];
	}

	for (int i = 0; i < SIZETEST; i++) {
		cout << p1[i]<<endl;
	}
}



typedef struct t1 {
	string s1;
	int a1;
}T1;
typedef struct t2 {
	int a2;
	string s2;
}T2;

istream& operator>>(istream& in, T1& p) {
	in >> p.s1 >> p.a1;
	return in;
}

ostream& operator<<(ostream& out, const T1& p) {
	out << "字符串:"<<p.s1 << "\t" <<"整数:" << p.a1;
	return out;
}

istream& operator>>(istream& in, T2& p) {
	in >> p.a2 >> p.s2;
	return in;
}

ostream& operator<<(ostream& out, const T2& p) {
	out << "整数:"<<p.a2 << "\t" <<"字符串:" << p.s2;
	return out;
}

void test3() {
	T1* p1 = new T1[SIZETEST];
	for (int i = 0; i < SIZETEST; i++) {
		cin >> p1[i];
	}

	for (int i = 0; i < SIZETEST; i++) {
		cout << p1[i] << endl;
	}
}

void test4() {
	T2* p1 = new T2[SIZETEST];
	for (int i = 0; i < SIZETEST; i++) {
		cin >> p1[i];
	}

	for (int i = 0; i < SIZETEST; i++) {
		cout << p1[i] << endl;
	}
}
int main() {
	//test1();
	//test2();
	//test3();
	//test4();


	//输入35664，输出？？？
	/*int a;
	while ((a = getchar()) != '\n') {
		switch (a - '3') {
		case 0:
		case 1:
			putchar(a + 4);
		case 2:
			putchar(a + 4);
			break;
		case 3:
			putchar(a + 3);
		default:
			putchar(a + 2);
		}
	}*/



	return 0;
}