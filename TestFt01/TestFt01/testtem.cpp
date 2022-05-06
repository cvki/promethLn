#include<iostream>

using namespace std;

class Pluttt
{
private:
	double real;//ʵ��
	double imag;//�鲿
public:
	Pluttt(double real = 0, double imag = 0);//Ĭ�Ϲ���
	Pluttt(const Pluttt& pl);//��������
	Pluttt(Pluttt&& pl);//�ƶ�����
	void setReal(double real);
	void setImag(double imag);
	double getReal() const;
	double getImag() const;
	Pluttt operator+(const Pluttt& pl);//���ؼӺš�+�������
	~Pluttt();//����
	void test() const;//����ö���
	friend ostream& operator<<(ostream& outpl, const Pluttt& pl);
};
    Pluttt::Pluttt(double real, double imag) :real(real), imag(imag) { cout << "PluralĬ�Ϲ��캯��" << endl; }
	Pluttt::Pluttt(const Pluttt& pl) : real(pl.real), imag(pl.imag) { cout << "Plural�������캯��" << endl; }
	Pluttt::Pluttt(Pluttt&& pl) : real(pl.real), imag(pl.imag) { cout << "Plural�ƶ����캯��" << endl; }
	//��Ա����û��ָ�����ͣ�����Ҫ�ÿա��ܹ�ʵ���ƶ�����Ĺ��ܣ�ϵͳ�Զ����ã�������ִ�С�+��ʱ
	void Pluttt::setReal(double real) { this->real = real; }
	void Pluttt::setImag(double imag) { this->imag = imag; }
	double Pluttt::getReal() const { return real; }
	double Pluttt::getImag() const { return imag; }
	Pluttt Pluttt::operator+(const Pluttt& pl) {//��+�����ز��������ڼӼ��˳���������Ӧ���߼���ע���﷨
		Pluttt ptem;
		ptem.real = this->real + pl.real;
		ptem.imag = this->imag + pl.imag;
		cout << "&ptem:" << &ptem << endl;
		return ptem;
	}
	void Pluttt::test() const {//���ݲ�ͬ������������
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
	Pluttt::~Pluttt() { cout << "Plural��������" << endl; }

ostream& operator<<(ostream& outpl, const Pluttt& pl)
{
	outpl << pl.real << "+" << pl.imag << "i";
	return outpl;
}
