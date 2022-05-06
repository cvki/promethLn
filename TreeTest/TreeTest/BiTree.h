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
	//���캯���������������ڵ�Ϊ��ʱ��'#'��ʾ
	//BiTree() :root(nullptr) {};
	BiTree();//TΪǰ��������С�����ǰ��������������еĶ�����
	BNode* getRoot() { return root; }

	//BiTree(const Node *&node);
	
	//�ݹ��������
	void preOrderTree1(BNode* root);
	void midOrderTree1(BNode* root);
	void postOrderTree1(BNode* root);
	
	//�ǵݹ��������
	void preOrderTree2();
	void midOrderTree2();
	void postOrderTree2();

	//��α���
	void levelOrderTree();

	//���ٶ�����
	void destoryBTree();
};

void createBiTreePre(BNode *&root) {//ע�⴫�ݵĲ������ͣ�����������Ĵ������Σ��ɶԱ�����Ĵ�����������
	char ch=getchar();
	if (ch == '#')
		root = nullptr;
	else {
		root = new BNode;//��ΪrootΪָ�룬���Ա����˿���ʵ�ʴ洢�Ŀռ�
		root->data = ch;
		createBiTreePre(root->lchild);
		createBiTreePre(root->rchild);
	}
}

BiTree::BiTree() {
		createBiTreePre(root);
};


//BiTree(const Node *&node);

//�ݹ��������
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

//�ǵݹ��������
void  BiTree::preOrderTree2() {
	if (!root)
		return;
	stack<BNode*>st1;
	BNode* tmp = root;//����root�Ƕ���ĳ�Ա������ı�root��ı�ʵ��(������������������ȶԸö���Ĳ������ᵼ�����������ɺ�root=nullptr�Ӷ��������root��ʼֵ��nullptr�Ĵ���)��������Ҫ��temp��ʱ�������Ӷ����޸�ʵ�ε�ֵ��
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

//��α���
void  BiTree::levelOrderTree() {
	if (!root)
		return;
}

//���ٶ����� 
void BiTree::destoryBTree() {
};