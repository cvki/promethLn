#include "ArrayDanymic.h"

ArrayDanymic::ArrayDanymic(int maxsize):m_size(0) {//默认构造
	//开辟堆空间并初始化
	if (maxsize <= 0) {
		arrint = new int[10]();
		m_maxsize = 10;
	}
	else {
		arrint = new int[maxsize]();
		m_maxsize = maxsize;
	}
};
ArrayDanymic::ArrayDanymic(const ArrayDanymic& arr):m_maxsize(arr.m_maxsize),m_size(arr.m_size) {//拷贝构造
	//由于类成员为指针，因此深拷贝
	this->arrint = new int[m_maxsize]();
	for (int i = 0; i < m_size; i++)
		this->arrint[i] = arr.arrint[i];
};
ArrayDanymic::ArrayDanymic(ArrayDanymic&& arr) :m_maxsize(arr.m_maxsize), m_size(arr.m_size) {//移动构造
	//在整个过程中，都未调用移动构造函数。考虑移动构造怎么显式调用，能不能显式调用，什么时候调用？
	this->arrint = arr.arrint;
	arr.arrint = NULL;
};
ArrayDanymic::~ArrayDanymic() {//析构
	delete[] arrint;
	//delete[m_maxsize] arrint;//行不行呢？
};
int ArrayDanymic::getSize() {//返回当前数数据数量
	return m_size;
};
int ArrayDanymic::getNum(int order) {//按位置查找,默认从1开始
	if (order <= 0 || order > m_size)//输入序号有误
		throw "输入有误！";//抛出异常
	else
		return arrint[order - 1];
};
bool ArrayDanymic::insertNum(int order,int num) {//按位置插入，默认从1开始
	if (order <= 0 || order > m_size+1)//输入序号有误
		throw "输入有误！";//抛出异常
	if (m_size == m_maxsize) {//已经达到最大容量时，扩容开辟新空间
		ArrayDanymic* arrtem = new ArrayDanymic(2 * this->m_maxsize);//扩为原来的两倍容量(包含开辟空间),一定要注意使用堆内存，如果开辟到了栈中，会出错！因为该函数结束后便释放了
		arrtem->m_size = this->m_size;//注意size不变
		for (int i = 0; i < m_size; i++)//拷贝数据
			arrtem->arrint[i] = this->arrint[i];
		delete[] this->arrint;//重载operator=
		*this = *arrtem;
	}
	int i=m_size-1;
	for (; i >= order-1; i--)
		arrint[i+1] = arrint[i];
	arrint[i+1] = num;
	++m_size;
	return true;
};
bool ArrayDanymic::deleteNum(int order) {//按位置删除，默认从1开始
	if (order <= 0 || order > m_size)//输入序号有误
		throw "输入有误！";//抛出异常
	else {
		for (int i = order - 1; i < m_size-1; i++)
			arrint[i] = arrint[i + 1];
	}
	--m_size;
	return true;
};
bool ArrayDanymic::modefyNum(int order,int num) {//按位置修改，默认从1开始
	if (order <= 0 || order > m_size)//输入序号有误
		throw "输入有误！";//抛出异常
	else {
		arrint[order - 1] = num;
	}
	return true;
};
bool ArrayDanymic::addNum(int num) {//添加数据(默认添加到最后)
	if (m_size == m_maxsize) {//已经达到最大容量时，扩容开辟新空间
		ArrayDanymic *arrtem=new ArrayDanymic(2 * this->m_maxsize);//扩为原来的两倍容量(包含开辟空间),一定要注意使用堆内存，如果开辟到了栈中，会出错！因为该函数结束后便释放了
		arrtem->m_size = this->m_size;//注意size不变
		for (int i = 0; i < m_size; i++)//拷贝数据
			arrtem->arrint[i] = this->arrint[i];
		delete[] this->arrint;//重载operator=
		*this=*arrtem;
	}
	arrint[m_size] = num;//插入数据
	++m_size;//别忘了数据计数加1
	return true;
};
istream& operator>>(istream& in, ArrayDanymic& arr) {
	//输入数据合法性检测
	int tem;
	in >> tem;
	if (tem > 10)
		arr.m_maxsize=tem;
	for (int i = 0; i < arr.m_maxsize; i++) {
		if (in >> arr.arrint[i])
			++arr.m_size;
		if (in.get() == '\n')
			break;
	}
	return in;
};
ostream& operator<<(ostream& out, ArrayDanymic& arr) {
		out << "当前数据总数：" << arr.m_size << endl << "当前数据：" << endl;
		for (int i = 0; i < arr.m_size; i++)
			out << arr.arrint[i] << " ";
			out << endl;
		return out;
};
const ArrayDanymic& ArrayDanymic::operator=(const ArrayDanymic& arr) {
	this->arrint = arr.arrint;
	this->m_maxsize = arr.m_maxsize;
	this->m_size = arr.m_size;
	return *this;
}