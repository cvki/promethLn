#include "Point.h"

istream& operator>>(istream& in, Point& p) {
	in >> p.x >> p.y>>p.s;
	return in;
}

ostream& operator<<(ostream& out, const Point& p) {
	out << "(" << p.x << "," << p.getY() << ")"<<p.s;
	return out;
}


