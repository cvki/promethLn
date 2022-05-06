#include "Point.h"

Point::Point(double x, double y):x(x),y(y) {};
Point::Point(const Point& p):x(p.x),y(p.y) {};
const Point Point::operator+(const Point& p) const {
	return Point(this->x + p.x, this->y + p.y);
};
Point::~Point() {};
 ostream& operator<< ( ostream& out, const Point& p) {
	return out << "(" << p.x << "," << p.y << ")";
}
