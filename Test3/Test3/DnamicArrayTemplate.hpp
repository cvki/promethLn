#pragma once
#include<iostream>

using namespace std;

template<typename elm>
class ArrayDnmc {
	friend istream& operator>>(istream&, elm& e);
	friend ostream& operator<<(ostream&, elm& e);
private:
	elm* arr;
	int size;//从1开始
	int capacity;//从1开始
public:
	ArrayDnmc(int capacity=10):size(0){//默认构造
		if (capacity <= 10) {
			arr = new elm(10){};
			this->capacity = 10;
		}
		else
		{
			arr = new elm(capacity);
			this->capacity = capacity;
		}
	}
	ArrayDnmc(const ArraytDnmc& arrdt) :size(arrdt.size), capacity(arrdt.capacity) {//拷贝构造(深拷贝)
		this->arr = new elm(arrdt.capacity);
		//for(auto val : elm)//范围for循环，尝试怎么写
		for (int i=0;i<this->size;i++)
		{
			this->arr[i] = arrdt.arr[i];
		}
	}
	ArrayDnmc(ArraytDnmc&& arrdt):arr(arrdt.arr), size(arrdt.size),capacity(arrdt.capacity){//移动构造
		arrdt.arr = NULL;
	}
	int getSize() {
		return size;
	}
	int addDnmcArr(elm e) {
		if (this->capacity == this->size) {//此时存储空间已满，重新开辟新空间并转移数据
			ArrayDnmc arrc = new ArrayDnmc(2 * this->capacity){};//存储空间扩为原来的一倍
			arrc.size = this->size;//注意size不变
			//arrc.capacity = 2*this->capacity//不用设置，默认构造函数中已经设置了最大存储容量
			delete[] this;
			this = &arrc;//注意这里右侧是个ArrayDnmc*类型，不符合重载的“=”参数的函数，因此不会调用它。
		}
		int b=(this->arr[size] = e);
		++size;
		return b;
	}
	ArrayDnmc& operator=(const ArrayDnmc& arrtem) {
		this->size = arrtem.size;
		this->capacity = arrtem.capacity;
		this->arr = new elm(arrtem.capacity){};
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = arrtem[i];
		}
		return *this;
	}
};

template<typename elm>
istream& operator>>(istream& in, elm& e) {
	in >> capacity;
	int i = 0;
	while (in.get() != '\n') {
		in >> e[i++];
		++size;
	}
	return in;
}
template<typename elm>
ostream& operator<<(ostream& out, elm& e) {
	for (int i = 0; i < size; i++)
		out << e[i] << " ";
	out << endl;
	return out;
}
