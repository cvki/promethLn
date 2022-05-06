#include "Person.h"

istream& operator>>(istream& in, Person& p) {
	//这样输入会对输出格式产生影响
	//getline(in, p.name,' ');//必须加' '表示输入空格代表名字结束输入.不能用回车,回车代表整个输入结束,那就输入不了age
	//in  >> p.age;
	in >> p.name >> p.age;//直接这样输入即可,因为cin默认遇到空白符即当字符串输入结束
	return in;
}

ostream& operator<<(ostream& out, const Person& p) {
	//out << "name:" << p.getName() << "\t" << "age:" << p.getAge();//与下面一样的
	out << "name:" << p.name << "\t" << "age:" << p.age;
	return out;
}
