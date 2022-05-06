#include "opterLoad.h"
#include<iostream>
using namespace std;
opterLoad::opterLoad(int hour, int minute , int second ):hour(hour),minute(minute),second(second) {
	cout << "opterLoadĬ�Ϲ��캯��" << endl;
};
opterLoad::opterLoad(const opterLoad& opd):hour(opd.hour),minute(opd.minute),second(opd.second) {
	cout << "opterLoad�������캯��" << endl;
};
opterLoad::opterLoad(opterLoad&& opd):hour(opd.hour), minute(opd.minute), second(opd.second) {
	cout << "opterLoad�ƶ����캯��" << endl;
};
opterLoad::~opterLoad() {
	cout << "opterLoad��������" << endl;
};
int opterLoad::getH() { return hour; };
int opterLoad::getM() { return minute; };
int opterLoad::getS() { return second; };
void opterLoad::setH(int h) { this->hour = h; };
void opterLoad::setM(int m) { this->minute = m; };
void opterLoad::setS(int s) { this->second = s; };
opterLoad& opterLoad::operator++() { //ǰ�������
	if (second >= 0 && second < 59)
		++second;
	else if (second == 59) {
		++minute;
		second = 0;
	}
	if (minute == 60) {
		hour = (hour + 1) % 24;
		minute = 0;
	}
	return *this;
};

//opterLoad& opterLoad::operator++() { //ǰ�������,THU�ⷨ
//	second++;
//	if (second >= 60)
//	{
//		second -= 60; 
//		minute++;
//	}
//	if (minute == 60)
//	{
//		minute -= 60;
//		hour = (hour + 1) % 24;
//	}
//	return *this;
//};
opterLoad opterLoad::operator++(int) {
	//��ǰ�����������ʱ�����Ƚ����˶����������ʹ�øö�����ˣ���ʵ���߼��У����ȿ�ֱ��ʹ�øö����Լӻ��Լ���Ȼ��Ѹö��󷵻ء������ص���this��Ҳ���Ǵ��ݽ����Ķ�������ǰ����������غ������������������ؽ����ġ�
	//�����ں�������������У���Ҫ�Ƚ��иö����������������Ȼ���ٶԸö�������Լӻ��Լ��������Ҫ���浱ǰ��������Ըö�������󣬷��ز���ԭֵ����������һ����ʱ����󱣴浱ǰ�������Ϣ�������ص�Ҳ�Ǹö���(��Ϊԭ����this���ܾ��������������ѱ��޸�)�����ڷ��ص���ʱ������˵���Ͳ����������ˣ�������thisָ���ڸú�����������غ��������������ʱ����ͱ�����(��������õ����ƶ����캯��)�����������������ڵ��ڴ����ڱ����ձ�Ϊ��ȷ����ֵ���Ǵ���ġ���˲��ܷ���ָ��������ã����뷵��һ���������ݶ��󡣶������������Ǹ���ֵ������ȡ���û�ָ���ַ��
	opterLoad old(*this);
	++(*this);//����ǰ��++�����
	return old;
};

void opterLoad::showTime() {
	cout << hour << ":" << minute << ":" << second << endl;
}

