#include"Point.h"
#include"templateTst.h"
//#include"ArrayDanymic.h"
#include"DnamicArrayTemplate.hpp"

#if(0)
class Rocket {//单例模式测试
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
		//这里要考虑多线程安全问题
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
		//同样要考虑多线程问题
		if(rocket!=NULL)
			delete rocket; 
		rocket = NULL; 
	}
};
Rocket* Rocket::rocket = NULL;

ostream& operator<<(ostream& out, const Rocket *r) {
	cout << "rocket: " << &Rocket::rocket << "\t" << "allthing: " << r->allthing << endl;
	//注意：这里使用的Rocket:rocket必须加上&表示取地址。因为传递的是r1，r2这种指针地址，其有效内容是它指向的内存单元地址。
	return cout;
}
#endif

int main() {

	//Point类运算符重载
	/*Point p1(4, 7), p2(-2, 6);
	Point p3(p1);
	Point p4 = p1 + p2 + p3;
	cout << p1 << "\t" << p2 << "\t" << p3 << "\t"<<p4<<endl;*/


	//单例模式测试
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

	
	//函数模板测试
	//cout << add(3, 6.7) << "\t"<<add(6.7,3)<<"\t"<<add('s',5)<<endl;
	////cout << add("mst", "tyy");
	//cout << compareT(2, 2, 2) << "\t" << compareT("sss", "sst", "ssu") << "\t" << compareT("eees", "eees", "eees") << "\t"
	//	<< compareT('a', 95, 95.00) << endl; //compare("a",95,95.00)会报错，因为字符串"a"无法和int"=="比较
	//cout << maxT(78, 2, 90) << "\t"<<maxT('d', 'a', 'f')<<endl;
	//// cout<<maxT("abd", "aec", "aed") 不会报错，但无法比较大小，只会返回第一个abd,为什么？const char*类型不能直接使用>=比较


	//动态数组测试
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
