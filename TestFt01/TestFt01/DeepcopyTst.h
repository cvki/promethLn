#pragma once


#ifndef NULL
#define NULL 0
#endif // NULL

typedef struct ThreadNode {//����������
	int data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;
}ThreadNode,*ThreadTree;

class Innertest
{
private:
	int* xptr;
public:
	Innertest();//Ĭ�Ϲ��캯��
	Innertest(int n);//���ι��캯��
	Innertest(const Innertest& in);//�������캯��
	Innertest(Innertest&& in);//�ƶ����캯��,ע�⣬��������б��в��ܼ�const�������޷���in.xptr�ÿգ��ǽ������ָ�빲ָ��һ���ڴ������
	int* getInner();//get����
	~Innertest();//��������
};


class DeepcopyTst
{//������������������Ҫ������
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
	testOrder(int x = 0, int y = 0, Innertest in = NULL) :x(x),y(y),in(Innertest(*in.getInner())){}//���캯����ע�⣬�������ÿ�ʱ����Ҫ��NULL������ʹ��nullptr��������NULL��ʹ��ʱ��Ҫ����ͷ�ļ��������ú궨�����¶��壬��������ʱ������ʾNULLδʶ��ı�ʶ������˸��ļ���ͷ�����˺궨�塣
	int getX()const { return x; }
	int getY()const { return y; }
	Innertest* getIn() { return &in; }
};
