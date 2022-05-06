#include <iostream>
#include "DeepcopyTst.h"
#include "InheritTest.h"
//#include "Plural.h"
#include "opterLoad.h"
#include <cstring>


using namespace std;

//void testunsigned()
//{
//    unsigned int x = 10;
//    unsigned int y = 40;
//    unsigned u = x - y;
//    int z = x - y;
//    cout << "int z:" << z << "\t" << "unsigned u:" << u << endl;
//}
//
//int* testInner1() {//返回值类型
//    Innertest in1(44);
//    return in1.getInner();//注意此时返回的指针，是已被回收的内存空间，指向不确定的内容，是很危险的
//}
//Innertest testInner2()//返回值类型
//{
//    Innertest in2(66);
//    return in2;
//}


//隐形构造测试：
class testC1 {
    int x;
public:
    testC1() { cout << "testC1()" << endl; };
    testC1(char ch) :x(ch){ cout << "testC1(xxx)" << endl; };
    //这里可以将bool改为short,int,char等类型都可以,但string不行
    int getX() { return x; }
    ~testC1() { cout << "~testC1()" << endl; }
};
void test1(testC1 t) {
    cout << t.getX() << endl;
};


int main()
{
    //动态内存分配的语法测试
    //int* p1, *p2, * p3;
    //p1 = new int();
    //p2 = new int(4);//小括号表示以括号内作为值初始化。
    //p3 = new int[3];//中括号才表示开辟一个数组，大小3个单位；
    //cout << "*p1:" << *p1 << endl << "*p2:" << *p2 <<endl<< "*p3:" << *p3 << endl;

    
    //拷贝构造和移动构造测试
    //Innertest intt1, intt2(-5);
    //Innertest intt3(intt2);//调用拷贝构造函数，因为intt2不是右值(也就是它并不会在移交资源后就消亡)
    //cout << "****************************************************************************" << endl;
    //cout << "intt3:"<<*intt3.getInner()<<endl;
    //cout << "****************************************************************************" << endl;
    //cout << "testInner1():" <<*testInner1() << endl;
    //cout << "****************************************************************************" << endl;
    //cout << "testInner2():" << *(testInner2().getInner()) << endl;
    //cout << "****************************************************************************" << endl;


    //组合类的构造函数调用测试
    //Innertest in1(7);
    //cout << "********************************************************************************" << endl;
    //testOrder t0;
    //cout << "********************************************************************************" << endl;
    //testOrder t1(5, 2, in1);
    //cout << "********************************************************************************" << endl;
    //cout <<"t0:"<<endl<< t0.getX() << "\t" << t0.getY() << "\t" << *(t0.getIn()->getInner()) << endl;
    //cout << "********************************************************************************" << endl;
    //cout <<"t1:"<<endl<< t1.getX() <<"\t"<< t1.getY() <<"\t"<< *(t1.getIn()->getInner()) << endl;
    //cout << "********************************************************************************" << endl;


    //继承下的构造函数调用测试
   /* int* pt1 = new int(8);
    int a = 5;
    int* pt2 = &a;
    People p1(pt1), p2(pt1,23);
    cout << "*********************************************************************************" << endl;
    Student s1(pt1);
    cout << "*********************************************************************************" << endl;
    Student s2(pt1, 17);
    cout << "*********************************************************************************" << endl; 
    Student s3(s2);
    cout << "*********************************************************************************" << endl;
    p1.breath(); p2.breath();
    s1.breath(); s2.breath();
    s1.study(); s2.study();
    cout << "p1: "<<p1.getAge() << "\t" << *(p1.getPtest()) << endl;
    cout << "p2: " << p2.getAge() << "\t" << *(p2.getPtest()) << endl;
    cout << "s1:" << s1.getAge() << "\t" << *(s1.getPtest()) << "\t"<<s1.getNum()<<endl;
    cout << "s2:" << s2.getAge() << "\t" << *(s2.getPtest()) << "\t" << s2.getNum() << endl;
    cout << "s3:" << s3.getAge() << "\t" << *(s3.getPtest()) << "\t" << s3.getNum() << endl;
    s2.setAge(99);
    s2.setNum(102);
    s2.setPtest(pt2);
    cout << "changed s2: " << s2.getAge() << "\t" << *(s2.getPtest()) << "\t" << s2.getNum() << endl;
    cout << "s3: " << s3.getAge() << "\t" << *(s3.getPtest()) << "\t" << s3.getNum() << endl;*/


   // Plural p1, p2(3, 5), p3(3, -5);
   // cout << "*****************************************************************************************" << endl;
   // cout << "p1: "; p1.test();
   // cout << "p2: "; p2.test();
   // cout << "p3: "; p3.test();

   // cout <<"p1+p2: "; (p1+p2).test();
   //// cout << "&(p1+p2): " << &(p1 + p2) << endl;//报错，下面也是，提示&必须加在左值。很明显是传递过来的ptem，因为无法&取地址
   // cout << "p2+p3: "; (p3+p2).test();
   //// cout << "&(p2+p3): " << &(p2 + p3) << endl;
   // //cout << "&(p3+p2): " << &(p3 + p2) << endl;
   // cout << "p1: "; p1.test();
   // cout << "p2: "; p2.test();
   // cout << "p3: "; p3.test();


    //重载运算符为类内成员函数
    //opterLoad opd1;
    //opterLoad opd2(21,59,55),opd3(20,59,59);
   
    //opd1++.showTime();
    //(++opd2).showTime();//这里不加括号会报错，运算符优先级问题： .和++
    //opd3++.showTime();

    //cout << "opd1:\t" << opd1.getH() << ":" << opd1.getM() << ":" << opd1.getS() << endl;
    //cout << "opd2:\t" << opd2.getH() << ":" << opd2.getM() << ":" << opd2.getS() << endl;
    //cout << "opd3:\t" << opd3.getH() << ":" << opd3.getM() << ":" << opd3.getS() << endl;


    //重载运算符为类外非成员函数
    /*Plural p1(3, -2), p2(-5, 8),p3(0,4),p4(-2,0),p5(-6,-8),p6(0,0);
    cout << "p1: " << p1 << endl << "p2: " << p2 << endl << "p3: " << p3 << endl << "p4: " << p4 << endl << "p5: " << p5 << endl << "p6: " << p6 << endl;*/

    
    //虚函数和抽象类的继承
    /**Base1 b1(5);
    Base1* bt1;
    Base1Son bs1(6, -4);
    //bt1->test1();//运行报错，原因未初始化局部变量bt1（也就是bt1指向的对象内容没有分配内存空间）

    bt1 = &b1;
    bt1->test1();

    bt1 = &bs1;
    bt1->test1();
    bs1.test2();//这里尽管子类Base1Son中没有显式写上该函数。但它是虚函数，被自动继承下来，由于没重写，调用时使用的是父类的函数内容。这也说明，和java不同，java继承中的抽象函数必须在子类中显式写出，但在c++中，父类的虚函数可以不用显式写在子类中，子类也会自动继承，包括纯虚函数。但如果不显式写在子类中，则不会重写，也就是仍然使用默认继承下来的虚函数内容，而如果没重写父类纯虚函数(包含在子类显式写出而未重写或直接不写出)，那子类也是抽象类，是不能创建对象的，只能使用对象指针。

    //bt1->test4();//静态编译报错，bt1指针看不到test4函数，test4函数是子类Base1Son特有函数。
    //bt1->test5();//静态编译报错，原因同test4()**/


    //const与二级指针
    //const char ch = 't';//c内容不可变
    //const char* p = &ch;//const修饰*p,表示p的内容不可变，但p的指向可变，此时p承诺不修改其指向的内容，可以将ch地址赋值给它
    //char* const p = &ch;//错误。const修饰p，p本身指向不可变，但不承诺不修改其内容，将const不变的内容赋值给此时的p有安全风险，静态编译报错
    //char** q = &p;//同理，此时未将const值传给非const，非const会修改其内容，静态编译出错。
    

    //strcpy()测试
    /*#pragma warning(disable:4996)
    char ch[] = "ttuuiio";
    char* ch1 = ch;
    char* ch2 = new char[sizeof(ch) + 1];
    strcpy(ch2, ch1);
    cout << ch2 << endl;
    cout << "ch1: " << ch1 << "\t" << "ch2: " << ch2<<"\t"<<"sizeof(*ch1): "<< sizeof(ch)<<endl;
    char* cht = new char[] {"dddd"};
    cout << cht << endl;
    delete[] cht;*/

    
    //隐式构造测试
    //testC1 t1;
    //testC1 t2 = 50;
    //testC1 t3 = 't';
    //testC1 t4 = 9.9; 
    //cout << ("*************************************************");
    //test1(50);
    //test1('t');
    //test1(9.9);
    //cout << ("**************************************************");
    ////testC1 t5 = "ddd";//报错C2440	“初始化” : 无法从“char”转换为“testC1”	TestFt01
   

   
    return 0;
}


