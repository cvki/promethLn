#include"Point.h"
#include"templateTst.h"
//#include"ArrayDanymic.h"
#include"DnamicArrayTemplate.hpp"

#if(0)
class Rocket {//����ģʽ����
	friend ostream& operator<<(ostream& out, const Rocket* r);
private:
	int allthing;
	static Rocket* rocket;
	Rocket() = default; 
	Rocket(const Rocket&) = default;
	~Rocket() = default;
	void operator=(const Rocket&) {}
public:
	static Rocket* getRocket() {
		//����Ҫ���Ƕ��̰߳�ȫ����
		if (rocket == NULL)
		{
			rocket = new Rocket();
		}
		return rocket;
	}	
	void setAllthing(int s) {
		allthing = s;
	}
	int getAillthing() {

	}
	void run() {
		cout << "run()" << endl;
	}
	static void deleteRocket(){
		//ͬ��Ҫ���Ƕ��߳�����
		if(rocket!=NULL)
			delete rocket; 
		rocket = NULL; 
	}
};
Rocket* Rocket::rocket = NULL;

ostream& operator<<(ostream& out, const Rocket *r) {
	cout << "rocket: " << &Rocket::rocket << "\t" << "allthing: " << r->allthing << endl;
	//ע�⣺����ʹ�õ�Rocket:rocket�������&��ʾȡ��ַ����Ϊ���ݵ���r1��r2����ָ���ַ������Ч��������ָ����ڴ浥Ԫ��ַ��
	return cout;
}
#endif

int main() {

	//Point�����������
	/*Point p1(4, 7), p2(-2, 6);
	Point p3(p1);
	Point p4 = p1 + p2 + p3;
	cout << p1 << "\t" << p2 << "\t" << p3 << "\t"<<p4<<endl;*/


	//����ģʽ����
	/*Rocket* r1=  Rocket::getRocket();
	Rocket* r2 = Rocket::getRocket();
	Rocket* r3 = Rocket::getRocket();

	cout << r1 << r2 << r3 << endl;

	r1->setAllthing(5);
	cout << r1 << r2 << r3 << endl;

	r1->setAllthing(-4);
	cout << r1 << r2 << r3 << endl;

	Rocket::deleteRocket();
	cout << r1 << r2 << r3 << endl;

	Rocket* r5 = Rocket::getRocket();
	Rocket* r6 = Rocket::getRocket();
	cout << r5 << r6<<endl;

	r5->setAllthing(11);
	cout << r5 << r6 << endl;*/

	
	//����ģ�����
	//cout << add(3, 6.7) << "\t"<<add(6.7,3)<<"\t"<<add('s',5)<<endl;
	////cout << add("mst", "tyy");
	//cout << compareT(2, 2, 2) << "\t" << compareT("sss", "sst", "ssu") << "\t" << compareT("eees", "eees", "eees") << "\t"
	//	<< compareT('a', 95, 95.00) << endl; //compare("a",95,95.00)�ᱨ����Ϊ�ַ���"a"�޷���int"=="�Ƚ�
	//cout << maxT(78, 2, 90) << "\t"<<maxT('d', 'a', 'f')<<endl;
	//// cout<<maxT("abd", "aec", "aed") ���ᱨ�����޷��Ƚϴ�С��ֻ�᷵�ص�һ��abd,Ϊʲô��const char*���Ͳ���ֱ��ʹ��>=�Ƚ�


	//��̬�������
	/*ArrayDanymic arr1(20),arr2;
	cin >> arr1;
	cout << arr1;
	
	arr1.insertNum(3,600);
	arr1.addNum(-77);
	cout << "arr1.insertNum(3,600),addNum(-77): " << arr1 << endl;
	arr1.deleteNum(1);
	cout << "arr1.deleteNum(1): " << arr1 << endl;
	arr1.deleteNum(13);
	cout << "arr1.deleteNum(13): " << arr1 << endl;
	arr1.insertNum(1, 88);
	cout << "arr1.insertNum(1, 88): " << arr1 << endl;
	arr1.insertNum(14, -100);
	cout << "arr1.insertNum(14, -100): " << arr1 << endl;
	arr1.modefyNum(1, -300);
	cout << "arr1.modefyNum(1, -300): " << arr1 << endl;
	arr1.modefyNum(14, 66);
	cout << "arr1.modefyNum(14, 66): " << arr1 << endl;
	arr1.deleteNum(5);
	cout << "arr1.deleteNum(5): " << arr1 << endl;
	arr1.addNum(322);
	arr1.addNum(-55);
	arr1.getSize();
	cout << arr1;*/

	ArrayDnmc<int> arr1(3);
	arr1.addDnmcArr(2);
	arr1.addDnmcArr(-6);
	

	return 0;
}
