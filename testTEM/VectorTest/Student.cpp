#include "Student.h"


using namespace std;

istream& operator>>(istream& in, Student& p) {
	string s ;
	int age ;//���ڴ���������еı���
	//getline(in, s, ' ');
	//����ֱ��ʹ��p.get()��Ϊ����,��Ϊ�뺯��Ҫ��Ĳ������Ͳ�ͬ
	in >>s>> age>>p.id;//p.get����ֵһ������ʱ����const,������Ϊ��һ���ı�����������������ʹ��
	p.setName(s);
	p.setAge(age);
	return in;
}
ostream& operator<<(ostream& out, const Student& s) {
	return out << "name:" << s.getName() << "   " << "age:" << s.getAge() << "\t"<<"id:"<<s.id;
}
