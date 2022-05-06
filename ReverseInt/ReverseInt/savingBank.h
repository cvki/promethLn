#pragma once

class Date
{//分开记录年月日，方便准确计算天数
	int year;
	int month;
	int day;
public:
	Date();
	Date(int y, int m, int d) :year(y), month(m), day(d) {};//含参构造
	int getyear() { return year; };
	int getmonth() { return month; };
	int getday() { return day; };
	void setDate(int y, int m, int d);//修改日期，对于存取款的日期修改需要调用该部件类的该函数
};

class Savingbk {
private:
	int id;//账户id
	double rate;//年利率
	double balance;//余额
	Date lastday;//取款日期
	Date beginday;//第一天存入的日期
public:
	Savingbk(int id,Date ds);
	double getid();//存款账户
	double getrate();//利率
	void setrate(double rate);//修改利率
	double getbalance();//计算账户余额
	double saving(int id,double in, Date last, double ratem = 0.2);//存款(存款数额，存款当日日期)
	double withdraw(int id, double out,Date last);//取款
	double countb(int id, Date beginday, Date lastday, double ratem = 0.2);//计算利息
};



