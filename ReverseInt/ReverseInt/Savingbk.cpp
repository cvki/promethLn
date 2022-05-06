#include<iostream>
#include"savingBank.h"

using namespace std;

Date::Date() :Date(0, 0, 0) {};//ί�й������ʼ��(�������ʼ������Date�����޷�ʹ�ã����뱨��)
void Date::setDate(int y, int m, int d)
{
	this->year = y;
	this->month = m;
	this->day = d;
}

Savingbk::Savingbk(int id, Date ds) :id(id), beginday(Date(ds)),balance(0) {};//���캯�������������Ĭ��Date(&d)��������
double Savingbk::getid() { return id; };//����˻�
double Savingbk::getrate() { return rate; };//�鿴����
void Savingbk::setrate(double r) { rate = r; }//�޸�����
double Savingbk::getbalance() { return balance; };//�����˻����
double Savingbk::saving(int id,double in, Date last,double ratem)//���
{
	if (this->id == id)
	{//ȷ���˻�
			balance += countb(id, beginday, last);//��ǰ���=�ϴα���+�϶�ʱ���������Ϣ
			balance += in;//��ǰ���+=���α���
			beginday = last;//���ڿ�ʼ���Ե�ǰ�����Ϊ���𣬵�ǰʱ����Ϊ��ʼʱ�䣬���ڼ��㱾��ʱ�����Ϣ
	}
	else
	{
		cerr << "���ʧ�ܣ���������ȷ���˻���" << endl;
		return 0;
	}
	setrate(ratem);//�����ʱ�������ʸı䣬���޸����ʣ������´δ�ȡ��ʱ��������
	return balance;//���ش�����ܽ��
}
double Savingbk::withdraw(int id, double out,Date last)//ȡ��
{
	if (id == this->id)
	{//ȷ���˻�
		balance += countb(id, beginday, last);//��ǰ���=�ϴα���+�϶�ʱ���������Ϣ
		if (balance >= out)//�ִ������Թ���ȡ����
		{
			balance -= out;//��ǰ���-=����ȡ��
			beginday = last;//ͬ�����ڿ�ʼ���Ե�ǰ�����Ϊ���𣬵�ǰʱ����Ϊ��ʼʱ�䣬���ڼ��㱾��ʱ�����Ϣ
			//return balance;//����ȡ�������
		}
		else
			cerr << "ȡ��ʧ�ܣ������˻���" << endl;
	}
	else
	{
		cerr << "ȡ��ʧ�ܣ���������ȷ���˻�!" << endl;
		return 0;
	}
	return balance;//����ȡ�������
}
double Savingbk::countb(int id,Date beginday, Date lastday,double ratem)//������Ϣ
{
	if (id == this->id)
	{//ȷ���˻�
		
		double tem;//�洢��Ϣ����Ҫ���ڵ���ʱ����������Ϣ����Ľ���Ƿ���Ԥ��һ�£�Ҳ������returnֱ�ӷ���
		int y = lastday.getyear() - beginday.getyear();//�洢���϶�ʱ�䵽���ڣ�����������
		if (y >= 0)
		{//����ͳһת��Ϊ������������ڿ���ݵ�����һ��洢ʱ��ģ����ܻ���������2020.8.5~2021.3.2������������*365+�·����*30+������������·ݻ������������ʵ������ӦΪ207�졣������������������㣺1*365+(3-8)*30+(2-5)=212��
			tem = ((y * 12 + (lastday.getmonth() - beginday.getmonth())) * 30//���ת�����£�Ȼ��*30ת��Ϊ����
				+ (lastday.getday() - beginday.getday())) * rate * balance / 365;
			//setrate(ratem);//��ʵ������Բ��ü���һ�䣬��Ϊ��ȡ���ж��޸���ʵʱ���ʡ�����ȡ���ж������˸ú�������������ʡ�ԡ�Ҳ�����������޸�ʵʱ���ʣ��Ǵ���ȡ���оͲ��ü���һ�����޸��ˡ�
			return tem;
		}
		else
		{
			cerr << "��Ϣ����ʧ�ܣ���������ȷ�����ڣ�" << endl;
			return 0;
		}
	}
	else
	{
		cerr << "��Ϣ����ʧ�ܣ���������ȷ���˻���" << endl;
		return 0;
	}
}