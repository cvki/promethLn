#include "ArrayDanymic.h"

ArrayDanymic::ArrayDanymic(int maxsize):m_size(0) {//Ĭ�Ϲ���
	//���ٶѿռ䲢��ʼ��
	if (maxsize <= 0) {
		arrint = new int[10]();
		m_maxsize = 10;
	}
	else {
		arrint = new int[maxsize]();
		m_maxsize = maxsize;
	}
};
ArrayDanymic::ArrayDanymic(const ArrayDanymic& arr):m_maxsize(arr.m_maxsize),m_size(arr.m_size) {//��������
	//�������ԱΪָ�룬������
	this->arrint = new int[m_maxsize]();
	for (int i = 0; i < m_size; i++)
		this->arrint[i] = arr.arrint[i];
};
ArrayDanymic::ArrayDanymic(ArrayDanymic&& arr) :m_maxsize(arr.m_maxsize), m_size(arr.m_size) {//�ƶ�����
	//�����������У���δ�����ƶ����캯���������ƶ�������ô��ʽ���ã��ܲ�����ʽ���ã�ʲôʱ����ã�
	this->arrint = arr.arrint;
	arr.arrint = NULL;
};
ArrayDanymic::~ArrayDanymic() {//����
	delete[] arrint;
	//delete[m_maxsize] arrint;//�в����أ�
};
int ArrayDanymic::getSize() {//���ص�ǰ����������
	return m_size;
};
int ArrayDanymic::getNum(int order) {//��λ�ò���,Ĭ�ϴ�1��ʼ
	if (order <= 0 || order > m_size)//�����������
		throw "��������";//�׳��쳣
	else
		return arrint[order - 1];
};
bool ArrayDanymic::insertNum(int order,int num) {//��λ�ò��룬Ĭ�ϴ�1��ʼ
	if (order <= 0 || order > m_size+1)//�����������
		throw "��������";//�׳��쳣
	if (m_size == m_maxsize) {//�Ѿ��ﵽ�������ʱ�����ݿ����¿ռ�
		ArrayDanymic* arrtem = new ArrayDanymic(2 * this->m_maxsize);//��Ϊԭ������������(�������ٿռ�),һ��Ҫע��ʹ�ö��ڴ棬������ٵ���ջ�У��������Ϊ�ú�����������ͷ���
		arrtem->m_size = this->m_size;//ע��size����
		for (int i = 0; i < m_size; i++)//��������
			arrtem->arrint[i] = this->arrint[i];
		delete[] this->arrint;//����operator=
		*this = *arrtem;
	}
	int i=m_size-1;
	for (; i >= order-1; i--)
		arrint[i+1] = arrint[i];
	arrint[i+1] = num;
	++m_size;
	return true;
};
bool ArrayDanymic::deleteNum(int order) {//��λ��ɾ����Ĭ�ϴ�1��ʼ
	if (order <= 0 || order > m_size)//�����������
		throw "��������";//�׳��쳣
	else {
		for (int i = order - 1; i < m_size-1; i++)
			arrint[i] = arrint[i + 1];
	}
	--m_size;
	return true;
};
bool ArrayDanymic::modefyNum(int order,int num) {//��λ���޸ģ�Ĭ�ϴ�1��ʼ
	if (order <= 0 || order > m_size)//�����������
		throw "��������";//�׳��쳣
	else {
		arrint[order - 1] = num;
	}
	return true;
};
bool ArrayDanymic::addNum(int num) {//�������(Ĭ����ӵ����)
	if (m_size == m_maxsize) {//�Ѿ��ﵽ�������ʱ�����ݿ����¿ռ�
		ArrayDanymic *arrtem=new ArrayDanymic(2 * this->m_maxsize);//��Ϊԭ������������(�������ٿռ�),һ��Ҫע��ʹ�ö��ڴ棬������ٵ���ջ�У��������Ϊ�ú�����������ͷ���
		arrtem->m_size = this->m_size;//ע��size����
		for (int i = 0; i < m_size; i++)//��������
			arrtem->arrint[i] = this->arrint[i];
		delete[] this->arrint;//����operator=
		*this=*arrtem;
	}
	arrint[m_size] = num;//��������
	++m_size;//���������ݼ�����1
	return true;
};
istream& operator>>(istream& in, ArrayDanymic& arr) {
	//�������ݺϷ��Լ��
	int tem;
	in >> tem;
	if (tem > 10)
		arr.m_maxsize=tem;
	for (int i = 0; i < arr.m_maxsize; i++) {
		if (in >> arr.arrint[i])
			++arr.m_size;
		if (in.get() == '\n')
			break;
	}
	return in;
};
ostream& operator<<(ostream& out, ArrayDanymic& arr) {
		out << "��ǰ����������" << arr.m_size << endl << "��ǰ���ݣ�" << endl;
		for (int i = 0; i < arr.m_size; i++)
			out << arr.arrint[i] << " ";
			out << endl;
		return out;
};
const ArrayDanymic& ArrayDanymic::operator=(const ArrayDanymic& arr) {
	this->arrint = arr.arrint;
	this->m_maxsize = arr.m_maxsize;
	this->m_size = arr.m_size;
	return *this;
}