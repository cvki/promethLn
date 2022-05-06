#include"BiTree.h"

using namespace std;

int main() {
	BiTree bt1;
	bt1.preOrderTree1(bt1.getRoot());
	cout << endl<<"***************************************"<<endl;
	bt1.midOrderTree1(bt1.getRoot());
	cout << endl << "***************************************"<<endl;
	bt1.postOrderTree1(bt1.getRoot());
	cout << endl << "***************************************" <<endl;

	bt1.preOrderTree2();
	cout << endl << "***************************************" << endl;
	bt1.midOrderTree2();
	cout << endl << "***************************************" << endl;
	return 0;
}