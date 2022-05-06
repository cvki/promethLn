#pragma once
#include<iostream>

using namespace std;

class ArrayDanymic
{//假设这里设计int存储类型的动态数组,其实这里可以优化为模板类
	//friend istream& operator>>(istream& in,  ArrayDanymic& arr);
	//friend ostream& operator<<(ostream& in,  ArrayDanymic& arr);
	//注意<<和>>运算符的重载形式，必须为以上形式，与iostream库的插入运算符定义一致才行。
	/*istream& operator>>(istream& in,const ArrayDanymic& arr);
	ostream& operator<<(ostream& in, const ArrayDanymic& arr);*/  //是错误的
private:
	int* arrint;
	int m_size;//当前数据数量
	int m_maxsize;//最大数据容量
public:
	ArrayDanymic(int maxsize = 10);//默认构造
	ArrayDanymic(const ArrayDanymic& arr);//拷贝构造
	ArrayDanymic(ArrayDanymic&& arr);//移动构造
	~ArrayDanymic();//析构
	int getSize();//返回当前数组容量
	int getNum(int order);//按位置查找
	bool insertNum(int order, int num);//按位置插入,在第order上插入num
	bool deleteNum(int order);//按位置删除
	bool modefyNum(int order,int num);//按位置修改,在第order位置上修改为num
	bool addNum(int num);//直接在最后插入该num
	const ArrayDanymic& operator=(const ArrayDanymic&);
};
//istream& operator>>(istream& in,  ArrayDanymic& arr);
//ostream& operator<<(ostream& in,  ArrayDanymic& arr);
