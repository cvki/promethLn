#pragma once
#include<iostream>

using namespace std;
enum class typeRm{DDR4=1,DDR3,DDR2};
//若把这里的强枚举类型改为弱枚举类型，则可以直接cout输出，否则只能强转，但只能转换为int或char等底层为int的，无法转换为string输出
class RamTt {
private:
	float capacity;
	typeRm trm;
	float frequency;
public:
	RamTt():RamTt(0, typeRm::DDR2, 0){cout << "构造了一个Ram" << endl; }
	RamTt(float c, typeRm t, float f) :capacity(c), trm(t), frequency(f)
		{ cout << "初始化了一个Ram" << endl; };
	RamTt(RamTt const& rmt) :capacity(rmt.capacity), trm(rmt.trm), frequency(rmt.frequency) 
		{ cout << "拷贝了一个Ram" << endl; };
	void setRamTt(float c, typeRm t, float f);
	float getCapacity() { return capacity; };
	typeRm getTrm() { return trm; };
	float getFrequency() { return  frequency; };
	void getRamTt();
	~RamTt() { cout << "析构了一个Ram" << endl; }
};
void RamTt::setRamTt(float c, typeRm t, float f)
{
	capacity = c;
	trm = t;
	frequency = f;
}
void RamTt::getRamTt()
{
	cout << "RamCapacity: " << capacity << "\t" << "RamType: ";
	switch (trm)
	{
	case typeRm::DDR4:
		cout << "DDR4";
		break;
	case typeRm::DDR3:
		cout << "DDR3";
		break;
	case typeRm::DDR2:
		cout << "DDR2";
		break;
	default:
		cout << "ERROR!";
		break;
	}
	cout<< "\t" << "RamFrequency: " << frequency << endl;
}

class Cpu {
private:
	float frequency;
	float cache;
public:
	Cpu():Cpu(2.5,10) { cout<<"构造了一个cpu" << endl; }
	Cpu(float f, float c) :frequency(f), cache(c) { cout << "初始化了一个cpu" << endl; }
	Cpu(Cpu const& c):frequency(c.frequency),cache(c.cache){ cout << "拷贝了一个cpu" << endl; }
	~Cpu() { cout << "析构了一个cpu" << endl; }
	void getCpu() { cout << "CPUfrequency:" << frequency << "\t" << "CPUcache:" << cache << endl; }
};
class Computer {
private:
	RamTt ramr;
	Cpu cpuc;
	float sizef;
public:
	Computer() { cout << "创建了一个computer" << endl; };
	Computer(RamTt ramr, Cpu cpuc, float sizef)
	//Computer(RamTt ramr, Cpu cpuc, float sizef) :ramr(ramr), cpuc(cpuc), sizef(sizef)
		{ cout << "创建了一个computer" << endl; }
	//Computer(Computer const& c){ cout << "拷贝了一个computer" << endl; }
	//这里的拷贝构造函数重写后未进行拷贝构造的操作，因此未执行部件类的拷贝构造函数。如果加入拷贝构造操作，则执行部件类拷贝构造函数
	//而现在这种情况，执行的是部件类的默认构造函数。(因为需要创建部件类，而不是拷贝构造，编译器在创建时调用默认构造或已重写的默认构
	//造(根据是否有参数进行默认构造的选择)。同理，如果上面的Ram和CPU的拷贝构造函数重写后也未加入拷贝构造部件类的逻辑，那么也不会调用部件类拷贝构造，同样会调用默认构造函数(或者依据参数调用其他构造函数))

	Computer(Computer const& c) :ramr(c.ramr), cpuc(c.cpuc), sizef(c.sizef) { cout << "拷贝了一个computer" << endl; }
	//相比以上的拷贝构造函数，该函数实现了拷贝构造逻辑，由于使用了部件对象的拷贝操作，因此会调用部件类的拷贝构造函数

	void getComputer();
	~Computer(){ cout << "析构了一个computer" << endl; }
};
void Computer::getComputer()
{
	ramr.getRamTt();
	cpuc.getCpu();
}

