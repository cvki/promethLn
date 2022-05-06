#include<iostream>
#include<cstring>
#include<string>

using namespace std;

const int MAXS = 100;

//1.大写转小写
void uppToLow(char* str) {
	int i = 0;
	while (str[i]) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		++i;
	}
	//return str;
}

//1.小写转大写
void lowToUpp(char str[]) {
	int i = 0;
	while (str[i]) {
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		++i;
	}
	//return str;
}

//1.数字转'*' 
void digToStar1(char*& str) {
	int i = 0;
	while (str[i]) {
		if (str[i] >= '0' && str[i] <= '9')
			str[i] = '*';
		++i;
	}
	//return str;
}

void digToStar2(string& str) {
	int i = 0;
	while (str[i]) {
		if (str[i] >= '0' && str[i] <= '9')
			str[i] = '*';
		++i;
	}
	//return str;
}

int main() {//test: I Love You 1314!
	string s;
	getline(cin, s);

	char cs[MAXS];
	int i = 0,j=0;
	while (cs[j++] = s[i++]);

	char* temcs = cs;

	
	cout << "temcs: "<<temcs<<endl;
	cout << "cs: " << cs << endl;
	cout << "*******************************************************************************" << endl;

	lowToUpp(temcs);
	cout << "lowToUpp(): "  << endl;
	cout << "temcs: " << temcs << endl;
	cout << "cs: " << cs << endl;
	cout << "*******************************************************************************" << endl;

	uppToLow(temcs);
	cout << "uppToLow(): " << endl;
	cout << "temcs: " << temcs << endl;
	cout << "cs: " << cs << endl;
	cout << "*******************************************************************************" << endl;

	digToStar1(temcs);
	cout << "digToStar1(): " << endl;
	cout << "cs: " << cs << endl;
	cout << "temcs: " << temcs << endl;
	cout << "*******************************************************************************" << endl;

	digToStar2(s);
	cout << "digToStar2(): " << endl;
	cout << "string s: " << s << endl;
	cout << "*******************************************************************************" << endl;

	return 0;
}




















