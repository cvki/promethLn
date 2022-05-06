#include<iostream>
#include"savingBank.h"

using namespace std;

Date::Date() :Date(0, 0, 0) {};//委托构造出初始化(如果不初始化，则Date对象无法使用，编译报错)
void Date::setDate(int y, int m, int d)
{
	this->year = y;
	this->month = m;
	this->day = d;
}

Savingbk::Savingbk(int id, Date ds) :id(id), beginday(Date(ds)),balance(0) {};//构造函数，部件类调用默认Date(&d)拷贝构造
double Savingbk::getid() { return id; };//存款账户
double Savingbk::getrate() { return rate; };//查看利率
void Savingbk::setrate(double r) { rate = r; }//修改利率
double Savingbk::getbalance() { return balance; };//计算账户余额
double Savingbk::saving(int id,double in, Date last,double ratem)//存款
{
	if (this->id == id)
	{//确认账户
			balance += countb(id, beginday, last);//当前余额=上次本金+上端时间产生的利息
			balance += in;//当前余额+=本次本金
			beginday = last;//现在开始，以当前余额作为本金，当前时间作为起始时间，用于计算本段时间的利息
	}
	else
	{
		cerr << "存款失败！请输入正确的账户！" << endl;
		return 0;
	}
	setrate(ratem);//如果此时存款的利率改变，则修改利率，用于下次存取款时计算利率
	return balance;//返回存款后的总金额
}
double Savingbk::withdraw(int id, double out,Date last)//取款
{
	if (id == this->id)
	{//确认账户
		balance += countb(id, beginday, last);//当前余额=上次本金+上端时间产生的利息
		if (balance >= out)//现存款项可以够所取款项
		{
			balance -= out;//当前余额-=本次取款
			beginday = last;//同理，现在开始，以当前余额作为本金，当前时间作为起始时间，用于计算本段时间的利息
			//return balance;//返回取完后的余额
		}
		else
			cerr << "取款失败，请检查账户余额！" << endl;
	}
	else
	{
		cerr << "取款失败！请输入正确的账户!" << endl;
		return 0;
	}
	return balance;//返回取完后的余额
}
double Savingbk::countb(int id,Date beginday, Date lastday,double ratem)//计算利息
{
	if (id == this->id)
	{//确认账户
		
		double tem;//存储利息。主要用于调试时，看里面利息计算的结果是否与预期一致，也可以用return直接返回
		int y = lastday.getyear() - beginday.getyear();//存储从上段时间到现在，经过的年数
		if (y >= 0)
		{//这里统一转换为天数，否则对于跨年份但不到一年存储时间的，可能会计算错误。如2020.8.5~2021.3.2。若用年份相减*365+月份相减*30+天数相减，则月份会出错，如上例，实际天数应为207天。但如果与上面那样计算：1*365+(3-8)*30+(2-5)=212天
			tem = ((y * 12 + (lastday.getmonth() - beginday.getmonth())) * 30//年份转换成月，然后*30转换为天数
				+ (lastday.getday() - beginday.getday())) * rate * balance / 365;
			//setrate(ratem);//其实这里可以不用加这一句，因为存取款中都修改了实时利率。而存取款中都调用了该函数，所以这句可省略。也或者在这里修改实时利率，那存款和取款中就不用加这一句来修改了。
			return tem;
		}
		else
		{
			cerr << "利息计算失败！请输入正确的日期！" << endl;
			return 0;
		}
	}
	else
	{
		cerr << "利息计算失败！请输入正确的账户！" << endl;
		return 0;
	}
}