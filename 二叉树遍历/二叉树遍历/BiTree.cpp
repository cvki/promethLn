#include "BiTree.h"
#include<iostream>
#include<stack>

using namespace std;


//二叉树递归遍历

//1.先序
template<typename T>
void preOrder(BiTree<T> r) {
	while (r) {
		cout << r.a->data << endl;
		preOrder(r.a->lchild);
		preOrder(r.a->rchild);
	}
}

//1.中序
template<typename T>
void midOrder(BiTree<T> r) {
	while (r) {
		preOrder(r.a->lchild);
		cout << r.a->data << endl;
		preOrder(r.a->rchild);
	}
}

//1.后序
template<typename T>
void postOrder(BiTree<T> r) {
	while (r) {
		preOrder(r.a->lchild);
		preOrder(r.a->rchild);
		cout << r.a->data<<endl;
	}
}

//二叉树非递归遍历,需要借助堆栈

//先序
template<typename T>
void preOd(BiTree<T> r) {
	stack<BiTree<T>> st;
	BiTree<T> s=r;
	while (s || !st.empty()) {
		while (s) {
			cout << s.a->data << endl;
			st.push(s);
			s = s.a->lchild;
		}
		if (!st.empty()) {
			s = st.top();
			st.pop();
			s = s.a->rchild;
		}
	}
}

//中序
template<typename T>
void midOd(BiTree<T> r) {
	stack<BiTree<T>> st;
	BiTree<T> s = r;
	while (s || !st.empty()) {
		while (s) {
			st.push(s);
			s = s.a->lchild;
		}
		if (!st.empty()) {
			s = st.top();
			cout << s.a->data << endl;
			st.pop();
			s = s.a->rchild;
		}
	}
}
