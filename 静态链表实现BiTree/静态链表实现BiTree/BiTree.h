#pragma once
#include<iostream>
#include<string>

using namespace std;


//����������ľ�̬����ṹ

template <typename T>
struct ArrNode {
	T data;
	int left;
	int right;
};

typedef struct ArrNode<char> ANode;

template <typename T>
class BiTree{
	ANode<T>* root;
public:
	BiTree()
};