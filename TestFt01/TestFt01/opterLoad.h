#pragma once

class opterLoad
{
	int hour;
	int minute;
	int second;
public:
	opterLoad(int hour = 0,int minute = 0,int second=0);
	opterLoad(const opterLoad& opd);
	opterLoad(opterLoad&& opd);
	~opterLoad();
	int getH();
	int getM();
	int getS();
	void setH(int h);
	void setM(int m);
	void setS(int s);
	opterLoad& operator++();
	opterLoad operator++(int);//ע������ķ���ֵ����Ϊ�������ͣ�����ԭ��cppʵ��
	void showTime();
};



