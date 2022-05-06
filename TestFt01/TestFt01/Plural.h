#include<iostream>
using namespace std;
class Plural
{
private:
	double real;//ʵ��
	double imag;//�鲿
public:
	Plural(double real = 0, double imag = 0);//Ĭ�Ϲ���
	Plural(const Plural& pl);//��������
	Plural(Plural&& pl);//�ƶ�����
	void setReal(double real);
	void setImag(double imag);
	double getReal() const;
	double getImag() const;
	Plural operator+(const Plural& pl);//���ؼӺš�+�������
	~Plural();//����
	void test() const;//����ö���
	friend double getplu(Plural p);
	friend ostream& operator<<(ostream& outpl, const Plural& pl);
};

Plural::Plural(double real, double imag) :real(real), imag(imag) { cout << "PluralĬ�Ϲ��캯��" << endl; }
Plural::Plural(const Plural& pl) : real(pl.real), imag(pl.imag) { cout << "Plural�������캯��" << endl; }
Plural::Plural(Plural&& pl) : real(pl.real), imag(pl.imag) { cout << "Plural�ƶ����캯��" << endl; }//��Ա����û��ָ�����ͣ�����Ҫ�ÿա��ܹ�ʵ���ƶ�����Ĺ��ܣ�ϵͳ�Զ����ã�������ִ�С�+��ʱ
void Plural::setReal(double real) { this->real = real; }
void Plural::setImag(double imag) { this->imag = imag; }
double Plural::getReal() const { return real; }
double Plural::getImag() const { return imag; }
Plural Plural::operator+(const Plural& pl) {//��+�����ز��������ڼӼ��˳���������Ӧ���߼���ע���﷨
	Plural ptem;
	ptem.real = this->real + pl.real;
	ptem.imag = this->imag + pl.imag;
	cout << "&ptem:" << &ptem << endl;
	return ptem;
}
void Plural::test() const {//���ݲ�ͬ������������
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
Plural::~Plural() { cout << "Plural��������" << endl; }

ostream& operator<<(ostream& outpl, const Plural& pl)
{//δ������ʣ����������.h��.cpp�ļ����ú����Ķ���������������ڲ�ͬ�ļ�������ᱨ����ʾ�޷�����real��imag������˽�б�����������ｫcpp�����ݷ�����.h�У�����.h���ݷ���cpp�У���.h��include cpp��main����include .h���������ļ��ظ����������⣬���ֻ�з���.h�����������塣��Ϊʲô�أ�Ϊʲô���иú���ʱ���ܷ��ļ��أ�!�����Ե�������Ԫ�����Ϳ��ԣ�����һ�����Ԫ����(û�����أ�����ֵΪ��������)
	//���⣬����������.h��.cpp�ֿ�����ʹ��get�����õ�˽�г�Ա������Ҫ��Ԫ����������ֱ��ʹ����Ԫ������Ϊ�����Ч�ʡ����������ݳ�Ա���٣��Ż�Ӱ�첻�󣬵�����˽�����ݳ�Ա�ܴ�ʱ����Ԫ����ֱ�ӷ��ʾ��ܿ���Ч�ʵ��Ż���
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

