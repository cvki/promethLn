#pragma once
#include<iostream>

using namespace std;
enum class typeRm{DDR4=1,DDR3,DDR2};
//���������ǿö�����͸�Ϊ��ö�����ͣ������ֱ��cout���������ֻ��ǿת����ֻ��ת��Ϊint��char�ȵײ�Ϊint�ģ��޷�ת��Ϊstring���
class RamTt {
private:
	float capacity;
	typeRm trm;
	float frequency;
public:
	RamTt():RamTt(0, typeRm::DDR2, 0){cout << "������һ��Ram" << endl; }
	RamTt(float c, typeRm t, float f) :capacity(c), trm(t), frequency(f)
		{ cout << "��ʼ����һ��Ram" << endl; };
	RamTt(RamTt const& rmt) :capacity(rmt.capacity), trm(rmt.trm), frequency(rmt.frequency) 
		{ cout << "������һ��Ram" << endl; };
	void setRamTt(float c, typeRm t, float f);
	float getCapacity() { return capacity; };
	typeRm getTrm() { return trm; };
	float getFrequency() { return  frequency; };
	void getRamTt();
	~RamTt() { cout << "������һ��Ram" << endl; }
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
	Cpu():Cpu(2.5,10) { cout<<"������һ��cpu" << endl; }
	Cpu(float f, float c) :frequency(f), cache(c) { cout << "��ʼ����һ��cpu" << endl; }
	Cpu(Cpu const& c):frequency(c.frequency),cache(c.cache){ cout << "������һ��cpu" << endl; }
	~Cpu() { cout << "������һ��cpu" << endl; }
	void getCpu() { cout << "CPUfrequency:" << frequency << "\t" << "CPUcache:" << cache << endl; }
};
class Computer {
private:
	RamTt ramr;
	Cpu cpuc;
	float sizef;
public:
	Computer() { cout << "������һ��computer" << endl; };
	Computer(RamTt ramr, Cpu cpuc, float sizef)
	//Computer(RamTt ramr, Cpu cpuc, float sizef) :ramr(ramr), cpuc(cpuc), sizef(sizef)
		{ cout << "������һ��computer" << endl; }
	//Computer(Computer const& c){ cout << "������һ��computer" << endl; }
	//����Ŀ������캯����д��δ���п�������Ĳ��������δִ�в�����Ŀ������캯����������뿽�������������ִ�в����࿽�����캯��
	//���������������ִ�е��ǲ������Ĭ�Ϲ��캯����(��Ϊ��Ҫ���������࣬�����ǿ������죬�������ڴ���ʱ����Ĭ�Ϲ��������д��Ĭ�Ϲ�
	//��(�����Ƿ��в�������Ĭ�Ϲ����ѡ��)��ͬ����������Ram��CPU�Ŀ������캯����д��Ҳδ���뿽�����첿������߼�����ôҲ������ò����࿽�����죬ͬ�������Ĭ�Ϲ��캯��(�������ݲ��������������캯��))

	Computer(Computer const& c) :ramr(c.ramr), cpuc(c.cpuc), sizef(c.sizef) { cout << "������һ��computer" << endl; }
	//������ϵĿ������캯�����ú���ʵ���˿��������߼�������ʹ���˲�������Ŀ�����������˻���ò�����Ŀ������캯��

	void getComputer();
	~Computer(){ cout << "������һ��computer" << endl; }
};
void Computer::getComputer()
{
	ramr.getRamTt();
	cpuc.getCpu();
}

