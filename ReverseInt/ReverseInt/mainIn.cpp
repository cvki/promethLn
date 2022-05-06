//#include<iostream>
//#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include"ClockTest.h"
#include"constructorFunTest.h"
//#include"classCombineTest.h"
#include"RmTest.h"
#include"testConst.h"
#include"savingBank.h"
#include"constructorFunTest.h"
#include"userDeepCopy.h"
#include<string>



using namespace std;

int reverseIntRtn(int num);//整数反转

int sum3Array(int* a);//三元组求和

int convertBitToDec(string s); //将输入二进制转换为十进制

double figurePI();//利用泰勒公式求Π的值

int searchHuiwen();//回文数题目

double getKofSinX(double r, double s);//含sinx的分段函数求值

int testRandFigure();//随机数测试；

int diceMading();//投骰子游戏；

int fibNs(int);//斐波那契数列;

int comSelect(unsigned n, unsigned k);//排列组合递归选举

int thanoi(char src, char mid, char dest, int num);//汉诺塔问题

int swapRef(double& val1, double& val2);//引用传递交换两数的值
int swapPoint(double* val1, double* val2);//指针传递交换两数的值
int swapNosp(double val1, double val2);//没有发生作用的值传递交换

//找到两个或三个数的最大值;
double getMaxDbl(double v1, double v2);
double getMaxDbl(double v1, double v2, double v3);
int getMaxInt(int v1, int v2);
int getMaxInt(int v1, int v2, int v3);


int temt();
int temt2();

constexpr auto MAXSIZE = 10;

union grade {
	//内部可以用char[](C风格字符串)，但是暂时不能使用string，因为未指定大小
	float f1;
	char c1;
	bool b1;
};

void juzhenReverse2();
void juzhenReverse2();

int main()
{
	//整数反转
	/*long long x;
	cout << "please enter x：" << endl;
	cin >> x;
	x=reverseIntRtn(x);
	cout << "The reverseX is: " << x << endl;*/


	//三元组求和(未完成)
	/*int a[MAXSIZE];
	cout << "Enter arrays integer number: " << endl;
	for (int i = 0; i < MAXSIZE; i++)
	{
		cin >> a[i];
	}
	sum3Array(a);*/


	//将输入二进制转换为十进制
	/*string str;
	cout << "Enter BitNum: " << endl;
	cin >> str;
	convertBitToDec(str);*/


	//利用泰勒公式求PI的值
	//cout << "PI= "<<figurePI() << endl;;


	//THU回文数
	//searchHuiwen();


	//求解含sinx的分段函数值
	/*double r,s;
	cout << "Enter 2 double numbers: " << endl;
	cin >> r>>s;
	cout << getKofSinX(r,s) << endl;*/

	//
	//testRandFigure();


	//投骰子游戏
	//diceMading();


	//排列组合递归选举问题
   /* unsigned n, k;
	cout << "Enter the numPeople and then numSelect: " << endl;
	cin >> n >> k;
	cout << "the count for selecting is: "<<comSelect(n, k) << endl;*/


	//斐波那契数列
	/*int num;
	cout << "Enter the number of id: " << endl;
	cin >> num;
	cout<<fibNs(num)<<endl;*/


	//汉诺塔问题
	/*int num;
	cout << "Enter the number of dishes: " << endl;
	cin >> num;
	cout << thanoi('A', 'B', 'C', num) << endl;*/


	//引用和指针交换两数的值
	//double val1, val2;
	//cout << "Enter 2 number；" << endl;
	//cin >> val1 >> val2;
	//swapRef(val1, val2);
	//cout << "After swapRef(): "<<"val1: " << val1 << "\t" << "val2: " << val2 << endl;
	//swapPoint(&val1, &val2);
	//cout << "After swapPoint(): " << "val1: " << val1 << "\t" << "val2: " << val2 << endl;
	//swapNosp( val1,  val2);//无作用的值传递；
	//cout << "After swapNosp(): " << "val1: " << val1 << "\t" << "val2: " << val2 << endl;


	//测试求两个或三个数的最大值
	//cout << getMaxDbl(52.2, 4.05, 16) << endl;//浮点数比较大小，同下
	//cout << getMaxInt(-2, 8,206) << endl;
	//cout << getMaxDbl(9.234523, 9.234524) << endl;//问题出现，浮点数的比较大小要用精度误差作为衡量
	//cout << getMaxInt(-94, -5) << endl;


	//钟表类设计
	//ClockTest ct1;
	//ct1.getClockTime();//未初始化
	//ct1.setClockTime(21,3,4);
	//ct1.getClockTime();
	//cout << 1 << endl;


	//构造函数
   /* ClockTestFun ctf1,ctf2;
	ClockTestFun ctf3(3,4,20);
	ctf1.getClockTestTime();
	ctf2.getClockTestTime();
	ctf3.getClockTestTime();*/


	//委托构造函数
	/*Point p1, p2;
	cout << "p1: ";
	p1.getPoint();
	cout <<"p2: ";
	p2.getPoint();
	p1.setPoint(3, 5);
	cout << "after setp1,p1: ";
	p1.getPoint();*/


	//拷贝构造函数
	/*Point p1;
	cout << "p1: ";
	p1.getPoint();
	p1.setPoint(3, 5);
	p1.getPoint();
	Point p2(p1);
	p2.getPoint();   */


	//组合类测试（重难点）
	/*Point p1;
	Point p2(p1);
	cout << "*******************************************" << endl;
	Point p3(3, 4);
	cout << "*******************************************" << endl;
	Line l1;
	cout << "*******************************************" << endl;
	Line l2(l1);
	cout << "*******************************************" << endl;
	Line l3(p1, p3);
	cout << "*******************************************" << endl;*/
	/*注意在这里，调用了四次Point的拷贝构造，也就是说p1和p3各调用了两次拷贝构造。为什么？第一次是在l3的传参阶段，此时调用Line的含参构造函数Line(p1,p2)，因为Line(double,double) 的参数列表是无引用，也就是值传递(必须是值传递，不能使用引用传递，否则构造好的新l3会和已知的p1，p3相关)
	* 前两次的拷贝构造发生在传参阶段，即使用l3(p1,p3)传参给pA和pB时，此时使用p1初始化未构造的新Point对象，便调用Point拷贝构造，根据p1和p3拷贝构造了pA和pB。
	* 后两次拷贝构造是因为拷贝构造函数的初始化列表赋值操作：Line::Line(Point pA, Point pB):p1(pA),p2(pB)；这里pA和pB是已经拷贝构造好的，已经存在的，但是p1和p2是l3的成员部件对象，用已知Point的赋值未知，则调用Point的拷贝构造函数。
	* 之后在赋值pA和pB后，执行函数体，打印出"Line default constructor"，然后Line的默认构造函数执行完结束，但内部还有pA和pB的内存，因此需要调用析构函数进行析构，这也是为什么调用析构函数。也是为什么析构的打印在"Line default constructor"之后，因为析构函数的调用是执行完函数的操作，当然也在函数体之后调用。
	*/
	/*Line l4(l3);
	cout << "l1.length: "<<l1.getLengthL() << endl;
	cout << "l2.length: " << l2.getLengthL() << endl;
	cout << "l3.length: " <<l3.getLengthL()<<endl;
	cout << "l4.length: " << l4.getLengthL() << endl;*/


	//联合体
	//grade g;
	//g.b1='f';
	////printf("%f,%c", g.f1, g.b1);
	//cout << g.b1<<endl<<g.f1<<endl<<g.c1<<endl;


	//枚举类型
	//enum class type{a=98,b,c};
	//enum class ype {c=11,d,e};
	//type t = type::c;//type t = a;会报错，因为a在type类型外是不可见的(可通过class关键字理解)
	//ype y = ype::e;//ype y = e;同理，也会报错
	//cout << static_cast<char>(t) << endl<<static_cast<int>(y)<<endl;//强类型枚举必须进行强制类型转换才能输出

	
	//含有枚举类的类设计
	//RamTt rt1(2048, typeRm::DDR2, 3000);
	//rt1.getRamTt();
	//RamTt rt2(rt1);
	//rt2.getRamTt();
	//rt2.setRamTt(6144.5, typeRm::DDR4, 4096);
	//rt2.getRamTt();
	//RamTt rt3(rt2);
	//rt3.getRamTt();
	//rt3.setRamTt(850.124, typeRm::DDR3, 9987);
	////rt3.getRamTt();由于typeRm未自定义枚举类型，因此返回值不能用cout输出。由于枚举类底层仍为int，故不能转化为string
	////因此也无法转换为字符串再输出，这两种方式都会报错。暂时只能使用getTrm()的输出方式。
	//rt3.getTrm();


	//组合类例题2 Computer类
	/*RamTt r1;
	r1.getRamTt();
	r1.setRamTt(512, typeRm::DDR4, 3000);
	Cpu cpu1;
	cout << ("**********************************************") << endl;
	Computer c1(r1, cpu1,20);
	cout << "c1的地址:" << &c1<<"\t" << "r1的地址:" << &r1 << "\t" << "cpu1的地址:" << &cpu1 << endl;
	cout << ("**********************************************") << endl;
	Computer c2;
	cout << ("**********************************************") << endl;
	Computer c3(c1);
	cout << ("**********************************************") << endl;
	c1.getComputer();
	c2.getComputer();
	c3.getComputer();*/

	//const作为类成员的测试
	/*testConst tss1;
	tss1.testShow();*/


	//数组初始化测试
	/*int a[10] = {3,4 };
	for(int i = 0; i < 10; i++)
	{
		cout <<setw(5)<<left<< a[i];
	}*/


	//const与指针结合的测试
#if(0)
	int* -指向int的指针
	int const* -指向const int的指针
	int* const - const指向int的指针
	int const* const - const指向const int的指针
	现在第一个const可以在类型的任何一侧，所以：
	const int* == int const*
	const int* const == int const* const
	如果你想变得非常疯狂，你可以做这样的事情：
	int** -指向int的指针
	int** const - 指向int的指针的const指针
	int* const* -指向int的const指针的指针
	int const** -指向const int指针的指针
	int* const* const - 指向int的const指针的const指针

	const int* foo; int* const bar; //note, you actually need to set the pointer 
				//here because you can't change it later ;)
	foo是一个指向常量整数的变量指针。这使您可以更改指向的内容，但不能更改指向的值。大多数情况下会看到C风格的字符串，其中有一个指向a的指针const char。您可以更改指向的字符串，但不能更改这些字符串的内容。当字符串本身位于程序的数据段中且不应更改时，这很重要。
		bar是一个指向可以更改的值的常量或固定指针。这就像没有额外语法糖的参考。因为这个事实，通常你会使用一个你将使用T* const指针的引用，除非你需要允许NULL指针.
#endif
		//int* const a； a是指向整数的常量指针，指针本身只读
		//const int* b； b是指向常量整数的指针，整数本身只读
		//const 离谁近就是修饰谁的
		//看const右侧，const* p1；则const修饰*p1，也就是p1所指向的变量，所以该变量为常量(只读)，不可更改。而X*const p1,则const修饰p1本身，而p1本身是个指针，所以指针是个常量(只读)，不可更改它的指向

		//int a = 3, b = 5, c = 10,d=20;
		//int const* pa = &a;//或const int* p
		//int* const pb = &b;
		//int const* const pc = &c;//或const int* const p
		//cout << "*pa:" << *pa << "\t" << "*pb:" << *pb << "\t" << "*pc:" << *pc << endl;
		//pa = &d;	pb = &a;	pc = &b;
		//*pa+=1;		*pb+=1;		*pc+=1;
		//cout << "*pa:" << *pa << "\t" << "*pb:" << *pb << "\t" << "*pc:" << *pc<< endl;


	//个人银行账户简单实例
	//Date today;//这里由于需要频繁使用和修改日期，因此需要一个Date对象。其实只用一个就行，d2不需要，每次使用修改today一个就够用了。在优化时，这里考虑有没有更好的方法，对于频繁使用的内容，有没有更高效简洁的设计？
	//Date d2(2021, 4, 6);

	//Savingbk sa1(1001, today);
	//today.setDate(2021, 8, 15);
	//cout << "sa1账户余额为：" << sa1.withdraw(1001, 3000, today) << endl;//测试未存款就取款
	//cout << "*******************************************" << endl;//分界线，便于调试观察

	//today.setDate(2021, 4, 16);
	//Savingbk sa2(1002, today);
	//cout << "sa2账户余额为：" << sa2.saving(1002, 5000, today) << endl;//存款，默认利率
	//cout << "*******************************************" << endl;

	//today.setDate(2021, 6, 8);
	//cout << "sa2账户余额为：" << sa2.saving(1002, 8000, today) << endl;;//存款，默认利率
	//cout << "*******************************************" << endl;

	//today.setDate(2021, 11, 16);
	//cout << "sa1账户余额为：" << sa1.saving(1001, 9000, today,0.3) << endl;//存款，修改实时利率
	//cout << "*******************************************" << endl;

	//d2.setDate(2022, 1, 3);
	//cout << "sa2账户余额为：" << sa1.saving(1002, 5000, d2) << endl;//id不符合时的测试
	//cout << "*******************************************" << endl;
	//cout << "sa1账户余额为：" << sa1.saving(1001, 5000, d2) << endl;//存款
	//cout << "*******************************************" << endl;
	//cout << "sa2账户余额为：" << sa2.saving(1002, 5000, d2, 0.3) << endl;//存款
	//cout << "*******************************************" << endl;

	//d2.setDate(2022, 11, 2);
	//cout << "sa2账户余额为：" << sa2.withdraw(1002, 9000, d2) << endl;//取款，并打印出取完之后的余额
	//cout << "*******************************************" << endl;
	//cout << "sa1账户余额为：" << sa1.withdraw(1001, 6000, d2) << endl;//取款
	//cout << "*******************************************" << endl;


	//temt();
	//temt2();

	//const testConst c1;//const 对象c1
	//c1.testShow();//默认调用const testshow()函数
	//
	//testConst c2;//非 const对象c2
	//c2.testShow();//默认调用 非testshow()函数


	//Point封装类
	/*int size,seqnc;
	cout << "Enter the size of dymPoint:" << endl;
	cin >> size;
	dynamitePoint dympt(size);
	cout << "Enter the modifying sequnceID if dymPoint:" << endl;
	cin >> seqnc;
	dympt.elementDym2(seqnc)->setPoint(-6, 90);
	dympt.elementDym(seqnc).getPoint();
	cout << "********************************************" << endl;
	for(int i=0;i<size;i++)
		dympt.elementDym(i).getPoint();
	cout << "********************************************" << endl;*/



	//深浅拷贝和组合类，string，未完成
	//testCopyArr tca1;
	//testCopyArr tca2(4),tca3(3);
	//string s = "hancheng";
	//for (int i = 0; i < 4; i++)
	//{

	//}
	//userDeepCopy u1;
	//userDeepCopy u2(s, 22, tca2);
	////userDeepCopy u2("hancheng", 22, tca2);//会报错


	//string类测试
	//string s1 = "sdascda";
	//string s2 = s1;//这里是开辟新空间，而不是s1和s2共用一份内存。string类型的数据虽然为引用类型，但它是常量(const)
	//cout << "s1的地址和内容：" << &s1 << "\t" << s1 << endl << "s2的地址和内容：" << &s2 << "\t" << s2 << endl;
	
	
	//矩阵转置
	//juzhenReverse1();//静态数组实现
	//juzhenReverse2();//动态内存分配实现



	return 0;
}


