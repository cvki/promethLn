#include<iostream>

using namespace std;

class Pluttt
{
private:
	double real;//实部
	double imag;//虚部
public:
	Pluttt(double real = 0, double imag = 0);//默认构造
	Pluttt(const Pluttt& pl);//拷贝构造
	Pluttt(Pluttt&& pl);//移动构造
	void setReal(double real);
	void setImag(double imag);
	double getReal() const;
	double getImag() const;
	Pluttt operator+(const Pluttt& pl);//重载加号“+”运算符
	~Pluttt();//析构
	void test() const;//输出该对象
	friend ostream& operator<<(ostream& outpl, const Pluttt& pl);
};
    Pluttt::Pluttt(double real, double imag) :real(real), imag(imag) { cout << "Plural默认构造函数" << endl; }
	Pluttt::Pluttt(const Pluttt& pl) : real(pl.real), imag(pl.imag) { cout << "Plural拷贝构造函数" << endl; }
	Pluttt::Pluttt(Pluttt&& pl) : real(pl.real), imag(pl.imag) { cout << "Plural移动构造函数" << endl; }
	//成员变量没有指针类型，不需要置空。能够实现移动构造的功能，系统自动调用，比如在执行“+”时
	void Pluttt::setReal(double real) { this->real = real; }
	void Pluttt::setImag(double imag) { this->imag = imag; }
	double Pluttt::getReal() const { return real; }
	double Pluttt::getImag() const { return imag; }
	Pluttt Pluttt::operator+(const Pluttt& pl) {//“+”重载操作，对于加减乘除都可用相应的逻辑，注意语法
		Pluttt ptem;
		ptem.real = this->real + pl.real;
		ptem.imag = this->imag + pl.imag;
		cout << "&ptem:" << &ptem << endl;
		return ptem;
	}
	void Pluttt::test() const {//根据不同情况，输出复数
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
	Pluttt::~Pluttt() { cout << "Plural析构函数" << endl; }

ostream& operator<<(ostream& outpl, const Pluttt& pl)
{
	outpl << pl.real << "+" << pl.imag << "i";
	return outpl;
}
