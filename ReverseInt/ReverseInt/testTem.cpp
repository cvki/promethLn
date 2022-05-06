#include<iostream>

using namespace std;

class testConst {
	int ss1;
	const int ss2;
public:
	int getSs() { cout << "ss1: " << ss1 << "ss2: " << ss2 << endl; };
	int getSs()const { cout << "ss1: " << ss1 << "ss2: " << ss2 << endl; };
};
