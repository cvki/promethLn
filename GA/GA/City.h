#pragma once
#include<iostream>
#include<string>

using namespace std;


class City
{
	string name;
	double x; //����
	double y; //γ��
public:
	City() = default;
	City(string name, double x, double y) :name(name), x(x), y(y) {};
	double getdist(const City& c)const;
	string getname() const{ return name; }
	const double* getXY(const string& name)const;
	bool setXY(string name,double x,double y);
};

class CityGph {
	City* cityset; //���м���
	double **citymatrix;  //���о����ڽӾ���
public:
	CityGph() = default;
	CityGph(const City* c);
	CityGph(const CityGph& cg);
	~CityGph();
	double getdistc(const City& c1, const City& c2);
	double** getMatrix();

};