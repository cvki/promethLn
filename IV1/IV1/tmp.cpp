#include<iostream>
#include<algorithm>

using namespace std;



int main1() {
	int a[] = { 6,4,1 };
	sort(a, a + 3);
	for (int i = 0; i < 3; i++)
		cout << a[i] << " ";

	return 0;
}