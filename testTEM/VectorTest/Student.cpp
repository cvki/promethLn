#include "Student.h"


using namespace std;

istream& operator>>(istream& in, Student& p) {
	string s ;
	int age ;//用于存放输入流中的变量
	//getline(in, s, ' ');
	//不能直接使用p.get()作为参数,因为与函数要求的参数类型不同
	in >>s>> age>>p.id;//p.get返回值一般是临时常量const,不能作为进一步的变量放在输入流中来使用
	p.setName(s);
	p.setAge(age);
	return in;
}
ostream& operator<<(ostream& out, const Student& s) {
	return out << "name:" << s.getName() << "   " << "age:" << s.getAge() << "\t"<<"id:"<<s.id;
}
