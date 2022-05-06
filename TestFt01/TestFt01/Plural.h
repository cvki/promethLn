#include<iostream>
using namespace std;
class Plural
{
private:
	double real;//实部
	double imag;//虚部
public:
	Plural(double real = 0, double imag = 0);//默认构造
	Plural(const Plural& pl);//拷贝构造
	Plural(Plural&& pl);//移动构造
	void setReal(double real);
	void setImag(double imag);
	double getReal() const;
	double getImag() const;
	Plural operator+(const Plural& pl);//重载加号“+”运算符
	~Plural();//析构
	void test() const;//输出该对象
	friend double getplu(Plural p);
	friend ostream& operator<<(ostream& outpl, const Plural& pl);
};

Plural::Plural(double real, double imag) :real(real), imag(imag) { cout << "Plural默认构造函数" << endl; }
Plural::Plural(const Plural& pl) : real(pl.real), imag(pl.imag) { cout << "Plural拷贝构造函数" << endl; }
Plural::Plural(Plural&& pl) : real(pl.real), imag(pl.imag) { cout << "Plural移动构造函数" << endl; }//成员变量没有指针类型，不需要置空。能够实现移动构造的功能，系统自动调用，比如在执行“+”时
void Plural::setReal(double real) { this->real = real; }
void Plural::setImag(double imag) { this->imag = imag; }
double Plural::getReal() const { return real; }
double Plural::getImag() const { return imag; }
Plural Plural::operator+(const Plural& pl) {//“+”重载操作，对于加减乘除都可用相应的逻辑，注意语法
	Plural ptem;
	ptem.real = this->real + pl.real;
	ptem.imag = this->imag + pl.imag;
	cout << "&ptem:" << &ptem << endl;
	return ptem;
}
void Plural::test() const {//根据不同情况，输出复数
	if (real == 0 && imag == 0)
		cout << "0" << endl;
	else if (real == 0 && imag != 0)
		cout << getImag() << "i" << endl;
	else if (real != 0 && imag == 0)
		cout << getReal() << endl;
	else if (imag < 0)
		cout << getReal() << getImag() << "i" << endl;
	else
		cout << getReal() << "+" << getImag() << "i" << endl;
}
Plural::~Plural() { cout << "Plural析构函数" << endl; }

ostream& operator<<(ostream& outpl, const Plural& pl)
{//未解决疑问：若将该类分.h和.cpp文件，该函数的定义如果和类声明在不同文件，定义会报错，提示无法访问real和imag这两个私有变量。因此这里将cpp的内容放在了.h中，若将.h内容放在cpp中，在.h中include cpp，main中再include .h，则会出现文件重复包含的问题，因此只有放在.h中声明并定义。那为什么呢？为什么含有该函数时不能分文件呢？!而测试的其他友元函数就可以，比如一般的友元函数(没有重载，返回值为基本类型)
	//另外，如果将该类的.h和.cpp分开，可使用get函数得到私有成员而不需要友元函数，这里直接使用友元函数是为了提高效率。这个类的数据成员较少，优化影响不大，当类内私有数据成员很大时，友元函数直接访问就能看出效率的优化。
	if (pl.real == 0 && pl.imag == 0) 
		outpl << "0";
	else if (pl.real == 0 && pl.imag != 0) 
		outpl << pl.imag << "i";
	else if (pl.real != 0 && pl.imag == 0) 
		outpl << pl.real;
	else if (pl.real != 0&&pl.imag < 0)
		outpl << pl.real << pl.imag << "i";
	else
		outpl << pl.real << "+" << pl.imag << "i";
	return outpl;
}

