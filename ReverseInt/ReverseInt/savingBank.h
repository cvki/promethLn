#pragma once

class Date
{//�ֿ���¼�����գ�����׼ȷ��������
	int year;
	int month;
	int day;
public:
	Date();
	Date(int y, int m, int d) :year(y), month(m), day(d) {};//���ι���
	int getyear() { return year; };
	int getmonth() { return month; };
	int getday() { return day; };
	void setDate(int y, int m, int d);//�޸����ڣ����ڴ�ȡ��������޸���Ҫ���øò�����ĸú���
};

class Savingbk {
private:
	int id;//�˻�id
	double rate;//������
	double balance;//���
	Date lastday;//ȡ������
	Date beginday;//��һ����������
public:
	Savingbk(int id,Date ds);
	double getid();//����˻�
	double getrate();//����
	void setrate(double rate);//�޸�����
	double getbalance();//�����˻����
	double saving(int id,double in, Date last, double ratem = 0.2);//���(��������������)
	double withdraw(int id, double out,Date last);//ȡ��
	double countb(int id, Date beginday, Date lastday, double ratem = 0.2);//������Ϣ
};



