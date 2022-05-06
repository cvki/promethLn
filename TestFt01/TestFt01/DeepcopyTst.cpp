#include "DeepcopyTst.h"
#include<iostream>

using namespace std;

Innertest::Innertest() :xptr(new int()) { cout << "Innertest()" << endl; }
Innertest::Innertest(int n) :xptr(new int(n)) { cout << "Innertest(n)" << endl; }
Innertest::Innertest(const Innertest& in) :xptr(new int(*in.xptr)) { cout << "Innertest(const Innertest& in)" << endl; }
Innertest::Innertest( Innertest&& in) : xptr(in.xptr) { in.xptr = nullptr; cout << "Innertest(const Innertest&& in)" << endl; }
int* Innertest::getInner() { return xptr; }
Innertest::~Innertest() { delete xptr; cout << "~Innertest()" << endl;
}

