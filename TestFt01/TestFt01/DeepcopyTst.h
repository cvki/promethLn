#pragma once


#ifndef NULL
#define NULL 0
#endif // NULL

typedef struct ThreadNode {//线索二叉树
	int data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;
}ThreadNode,*ThreadTree;

class Innertest
{
private:
	int* xptr;
public:
	Innertest();//默认构造函数
	Innertest(int n);//带参构造函数
	Innertest(const Innertest& in);//拷贝构造函数
	Innertest(Innertest&& in);//移动构造函数,注意，这里参数列表中不能加const，否则无法将in.xptr置空，那将造成两指针共指向一块内存的问题
	int* getInner();//get返回
	~Innertest();//析构函数
};


class DeepcopyTst
{//若线索化二叉树，需要用链表
public:
	ThreadNode t1;
	DeepcopyTst();
};


class testOrder {
private:
	int y;
	int x;
	Innertest in;
public:
	testOrder(int x = 0, int y = 0, Innertest in = NULL) :x(x),y(y),in(Innertest(*in.getInner())){}//构造函数；注意，当对象置空时，需要用NULL，不能使用nullptr，而这里NULL在使用时需要加入头文件，或者用宏定义重新定义，否则运行时出错，提示NULL未识别的标识符。因此该文件在头部加了宏定义。
	int getX()const { return x; }
	int getY()const { return y; }
	Innertest* getIn() { return &in; }
};
