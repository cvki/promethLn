#pragma once
#include<iostream>

using namespace std;

template<typename elm>
class ArrayDnmc {
	friend istream& operator>>(istream&, elm& e);
	friend ostream& operator<<(ostream&, elm& e);
private:
	elm* arr;
	int size;//��1��ʼ
	int capacity;//��1��ʼ
public:
	ArrayDnmc(int capacity=10):size(0){//Ĭ�Ϲ���
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
	ArrayDnmc(const ArraytDnmc& arrdt) :size(arrdt.size), capacity(arrdt.capacity) {//��������(���)
		this->arr = new elm(arrdt.capacity);
		//for(auto val : elm)//��Χforѭ����������ôд
		for (int i=0;i<this->size;i++)
		{
			this->arr[i] = arrdt.arr[i];
		}
	}
	ArrayDnmc(ArraytDnmc&& arrdt):arr(arrdt.arr), size(arrdt.size),capacity(arrdt.capacity){//�ƶ�����
		arrdt.arr = NULL;
	}
	int getSize() {
		return size;
	}
	int addDnmcArr(elm e) {
		if (this->capacity == this->size) {//��ʱ�洢�ռ����������¿����¿ռ䲢ת������
			ArrayDnmc arrc = new ArrayDnmc(2 * this->capacity){};//�洢�ռ���Ϊԭ����һ��
			arrc.size = this->size;//ע��size����
			//arrc.capacity = 2*this->capacity//�������ã�Ĭ�Ϲ��캯�����Ѿ����������洢����
			delete[] this;
			this = &arrc;//ע�������Ҳ��Ǹ�ArrayDnmc*���ͣ����������صġ�=�������ĺ�������˲����������
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
