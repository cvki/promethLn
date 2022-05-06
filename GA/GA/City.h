#pragma once
#include<iostream>
#include<string>

using namespace std;


class City
{
	string name;
	double x; //经度
	double y; //纬度
public:
	City() = default;
	City(string name, double x, double y) :name(name), x(x), y(y) {};
	double getdist(const City& c)const;
	string getname() const{ return name; }
	const double* getXY(const string& name)const;
	bool setXY(string name,double x,double y);
};

class CityGph {
	City* cityset; //城市集合
	double **citymatrix;  //城市距离邻接矩阵
public:
	CityGph() = default;
	CityGph(const City* c);
	CityGph(const CityGph& cg);
	~CityGph();
	double getdistc(const City& c1, const City& c2);
	double** getMatrix();

};