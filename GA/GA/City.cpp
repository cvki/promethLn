#include "City.h"

const int MAXCITY = 10;

double City::getdist(const City& c)const{
	return sqrt(pow(x - c.x, 2) + pow(y - c.y, 2));
}
const double* City::getXY(const string& name)const { //返回const，读取后及时释放内存
	return new const double[this->x, this->y];
};
bool City::setXY(string name,double x,double y) {
	if (name != this->name)
		return false;
	else {
		this->x = x;
		this->y = y;
	}
};

CityGph::CityGph(const City* c) {
	cityset = new City[MAXCITY];

};
CityGph::CityGph(const CityGph& cg) {};
CityGph::~CityGph() {};
double CityGph::getdistc(const City& c1, const City& c2);
double** CityGph::getMatrix();