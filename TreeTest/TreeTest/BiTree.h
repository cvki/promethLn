#pragma once

#include<iostream>
#include<string>
#include<stack>

using namespace std;

template<typename T>
struct Node {
	T data;
	Node<T>* lchild;
	Node<T>* rchild;
};
typedef struct Node<char> BNode;


class BiTree
{
	BNode* root;
public:
	//构造函数创建二叉树，节点为空时用'#'表示
	//BiTree() :root(nullptr) {};
	BiTree();//T为前序遍历序列。按照前序遍历构建该序列的二叉树
	BNode* getRoot() { return root; }

	//BiTree(const Node *&node);
	
	//递归三序遍历
	void preOrderTree1(BNode* root);
	void midOrderTree1(BNode* root);
	void postOrderTree1(BNode* root);
	
	//非递归三序遍历
	void preOrderTree2();
	void midOrderTree2();
	void postOrderTree2();

	//层次遍历
	void levelOrderTree();

	//销毁二叉树
	void destoryBTree();
};

void createBiTreePre(BNode *&root) {//注意传递的参数类型，这里二叉树的创建传参，可对比链表的创建所传参数
	char ch=getchar();
	if (ch == '#')
		root = nullptr;
	else {
		root = new BNode;//因为root为指针，所以别忘了开辟实际存储的空间
		root->data = ch;
		createBiTreePre(root->lchild);
		createBiTreePre(root->rchild);
	}
}

BiTree::BiTree() {
		createBiTreePre(root);
};


//BiTree(const Node *&node);

//递归三序遍历
void  BiTree::preOrderTree1(BNode* root) {
	if (root) {
		cout << root->data << "  ";
		preOrderTree1(root->lchild);
		preOrderTree1(root->rchild);
	}
}

void  BiTree::midOrderTree1(BNode* root) {
	if (root) {
		midOrderTree1(root->lchild);
		cout << root->data << "  ";
		midOrderTree1(root->rchild);
	}
}

void  BiTree::postOrderTree1(BNode* root) {
	if (root) {
		postOrderTree1(root->lchild);
		postOrderTree1(root->rchild);
		cout << root->data << "  ";
	}
}

//非递归三序遍历
void  BiTree::preOrderTree2() {
	if (!root)
		return;
	stack<BNode*>st1;
	BNode* tmp = root;//由于root是对象的成员，这里改变root会改变实参(如果后面接上中序遍历等对该对象的操作，会导致这里遍历完成后root=nullptr从而引起后面root初始值是nullptr的错误)，所以需要用temp临时变量，从而不修改实参的值。
	while (tmp || !st1.empty())
	{
		while (tmp) {
			cout << tmp->data << "  ";
			st1.push(tmp);
			tmp = tmp->lchild;
		}
		if (tmp == nullptr) {
			tmp = st1.top();
			st1.pop();
			tmp = tmp->rchild;
		}
	}
}

void  BiTree::midOrderTree2() {
	if (!root)
		return;
	stack<BNode*>st1;
	BNode* tmp=root;
	while (tmp || !st1.empty())
	{
		while (tmp) {
			st1.push(tmp);
			tmp = tmp->lchild;
		}
		if (tmp == nullptr) {
			tmp = st1.top();
			cout << tmp->data << "  ";
			st1.pop();
			tmp = tmp->rchild;
		}
	}
}

void  BiTree::postOrderTree2() {
	if (!root)
		return;
}

//层次遍历
void  BiTree::levelOrderTree() {
	if (!root)
		return;
}

//销毁二叉树 
void BiTree::destoryBTree() {
};