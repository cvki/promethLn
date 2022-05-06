#pragma once

#include<iostream>


using namespace std;


template <typename T>
class Node {//链表结点
private:
	T data;
	Node* next;
public:
	Node(T& data = 0, Node* next = nullptr);//默认构造
	Node(const Node& node);//拷贝构造
	~Node(); //析构

	T& operator=(const Node& node);//重载赋值运算符
	const T& getData(const Node& node);
	void setData(T& t);
};
template <typename T>
Node<T>::Node(T& data, Node* next):data(data),next(next) {}

template <typename T>
Node<T>::Node(const Node& node) {
	Node* tem = new Node;
	tem->data = node.data;
	tem->next = nullptr;
}

template <typename T>
const T& Node<T>::getData(const Node& node) {
	return node.data;
}

template <typename T>
void Node<T>::setData(T& t) {
	data = t;
}

template <typename T>
T& Node<T>::operator=(const Node& node) {
	Node* tem = new Node;
	tem->data = node.data;
	tem->next = nullptr;
}

template <typename T>
Node<T>::~Node() {}

int main() {
	Node<int> node[3];
	for (int i = 0; i < 3; ++i) {
		 node[i].setData(i);
	}
	for (int i = 0; i < 3; ++i) {
		node[i].getData(i);
	}
	return 0;
}











//template<typename T>
//class Node {
//private:
//	T data;
//	Node* next;
//	Node(const Node& node);
//	Node operator=(Node node);
//public:
//	Node(T data = nullptr, Node* next = nullptr) :data(data), next(next) {}
//	bool setData(const T data) { this->data = data; }
//	T getData()const { return this->data; }
//	~Node() { delete data; next = nullptr; }
//};


