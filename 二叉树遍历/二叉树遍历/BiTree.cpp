#include "BiTree.h"
#include<iostream>
#include<stack>

using namespace std;


//�������ݹ����

//1.����
template<typename T>
void preOrder(BiTree<T> r) {
	while (r) {
		cout << r.a->data << endl;
		preOrder(r.a->lchild);
		preOrder(r.a->rchild);
	}
}

//1.����
template<typename T>
void midOrder(BiTree<T> r) {
	while (r) {
		preOrder(r.a->lchild);
		cout << r.a->data << endl;
		preOrder(r.a->rchild);
	}
}

//1.����
template<typename T>
void postOrder(BiTree<T> r) {
	while (r) {
		preOrder(r.a->lchild);
		preOrder(r.a->rchild);
		cout << r.a->data<<endl;
	}
}

//�������ǵݹ����,��Ҫ������ջ

//����
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

//����
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
