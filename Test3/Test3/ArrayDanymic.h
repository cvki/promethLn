#pragma once
#include<iostream>

using namespace std;

class ArrayDanymic
{//�����������int�洢���͵Ķ�̬����,��ʵ��������Ż�Ϊģ����
	//friend istream& operator>>(istream& in,  ArrayDanymic& arr);
	//friend ostream& operator<<(ostream& in,  ArrayDanymic& arr);
	//ע��<<��>>�������������ʽ������Ϊ������ʽ����iostream��Ĳ������������һ�²��С�
	/*istream& operator>>(istream& in,const ArrayDanymic& arr);
	ostream& operator<<(ostream& in, const ArrayDanymic& arr);*/  //�Ǵ����
private:
	int* arrint;
	int m_size;//��ǰ��������
	int m_maxsize;//�����������
public:
	ArrayDanymic(int maxsize = 10);//Ĭ�Ϲ���
	ArrayDanymic(const ArrayDanymic& arr);//��������
	ArrayDanymic(ArrayDanymic&& arr);//�ƶ�����
	~ArrayDanymic();//����
	int getSize();//���ص�ǰ��������
	int getNum(int order);//��λ�ò���
	bool insertNum(int order, int num);//��λ�ò���,�ڵ�order�ϲ���num
	bool deleteNum(int order);//��λ��ɾ��
	bool modefyNum(int order,int num);//��λ���޸�,�ڵ�orderλ�����޸�Ϊnum
	bool addNum(int num);//ֱ�����������num
	const ArrayDanymic& operator=(const ArrayDanymic&);
};
//istream& operator>>(istream& in,  ArrayDanymic& arr);
//ostream& operator<<(ostream& in,  ArrayDanymic& arr);
