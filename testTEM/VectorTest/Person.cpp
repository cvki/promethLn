#include "Person.h"

istream& operator>>(istream& in, Person& p) {
	//���������������ʽ����Ӱ��
	//getline(in, p.name,' ');//�����' '��ʾ����ո�������ֽ�������.�����ûس�,�س����������������,�Ǿ����벻��age
	//in  >> p.age;
	in >> p.name >> p.age;//ֱ���������뼴��,��ΪcinĬ�������հ׷������ַ����������
	return in;
}

ostream& operator<<(ostream& out, const Person& p) {
	//out << "name:" << p.getName() << "\t" << "age:" << p.getAge();//������һ����
	out << "name:" << p.name << "\t" << "age:" << p.age;
	return out;
}
