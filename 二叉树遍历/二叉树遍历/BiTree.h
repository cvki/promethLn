#pragma once

template <typename T>
 struct BTNode
{
	 T data;
	 BTNode* lchild;
	 BTNode* rchild;
};

template <typename T>
class BiTree
{
	struct BTNode<T>* a;
};

