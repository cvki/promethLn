
#include <iostream>
#include <string>

using namespace std;



/*******
��Ŀ����
д��һ�����򣬽���һ������ĸ�����ֺͿո���ɵ��ַ�������һ����ĸ��Ȼ����������ַ����и���ĸ�ĳ��ִ����������ִ�Сд��

�������� :
��һ������һ������ĸ�������Լ��ո���ɵ��ַ������ڶ�������һ����ĸ��

������� :
��������ַ����к��и��ַ��ĸ�����

ʾ��1
����
ABCabc
A
���
2
*******/
//int main() {
//	//asfas asdfwe ASKDFFASFaf alF kfzc
//
//	string str;
//	char c;
//	int count = 0;
//	getline(cin, str);
//	cin >> c;
//	if (c >= 97)
//		c -= 32;//ͳһת��Ϊ��д
//	for (int i = str.length(); i >= 0; i--) {
//		if (str[i] == c || str[i] == c + 32)
//			++count;
//	}
//	cout << count << endl;
//	return 0;
//}




//int main(void)
//{
//    string str;
//    while (cin >> str)
//    {
//    }
//    cout << str.size() << endl;
//    return 0;
//}


//int main() {
//	int a[1001] = {0};
//	//memset(a, 0, 1001);
//	int count,tem;
//	while (cin >> count) {
//		for (int i = count; i > 0; --i)
//		{
//			cin >> tem;
//			a[tem] = 1;
//		}
//		for (int j = 1; j < 1001; ++j)
//		{
//			if (a[j])
//				cout << j << endl;
//		}
//		memset(a, 0, 1001);
//	}
//}


//int main() {
//	string str;
//	int div,rem;
//	while (getline(cin, str)) {
//		div = str.length() / 8;
//		rem = str.length() % 8;
//		for (int i = 0; i < div; ++i)
//			cout << str.substr(8 * i, 8) << endl;
//		if(rem)
//			cout << str.substr(8 * div, rem) + string(8 - rem, '0') << endl;
//	}
//	return 0;
//}

//int main() {
//	string str;
//	while (cin >> str) {
//		int res = 0, bit = 0;
//		for (int i = str.length() - 1; i > 1; --i) {
//			if (str[i] >= 'A')
//				res += pow(16, bit++) * (str[i] - 'A' + 10);
//			else
//				res += pow(16, bit++) * (str[i] - '0');
//		}
//		cout << res << endl;
//	}
//	
//	return 0;
//}


//int main() {
//	string s1 = "dafwereqw";
//	s1.replace(3, 4, "ooooo");
//	cout << s1 << endl;
//	return 0;
//}




//int main() {
//	string s;
//	while (cin >> s) {
//		int begin = -1, end = 0, lth, minlth = s.size();
//		for (int i = 0; i < s.size(); i++) {
//			if (s[i] == 'o' && begin == -1)
//				begin = i;
//			else if (s[i] == 'o') {
//				end = i;
//				lth = end - begin - 1;//������'o'
//				begin = end;
//				minlth = minlth < lth ? minlth : lth;
//			}
//		}
//		//��β
//		int j = 0; lth = 0;
//		while (s[j++] != 'o')
//			++lth;
//		j = s.size();
//		while (s[--j] != 'o')
//			++lth;
//		minlth = minlth < lth ? minlth : lth;
//		cout << minlth << endl;
//	}
//	
//	return 0;
//}



//STL�������
#include<stack>
//template<typename T>
//int main() {
//	T c;
//	stack<T> st1;
//	while (cin >> c) {
//		st1.push(c);
//	}
//	while (!st1.empty())
//		cout << st1.pop() << " ";
//	return 0;
//}

void reverseChar() {
	char c;
	stack<char> st1;
	while (cin >> c) {
		st1.push(c);
	}
	while (!st1.empty()) {
		cout << st1.top();
		st1.pop();
	}
	cout << endl;
}

void reverseString() {
	string s;
	stack<char> st1;
	getline(cin, s);
	for (int i = 0; i < s.length(); ++i) {
		st1.push(s[i]);
	}
	while (!st1.empty()) {
		cout << st1.top();
		st1.pop();
	}
	cout << endl;
}

void reverseInt() {
	int num;
	stack<int> st1;
	while(cin>>num)
		st1.push(num);
	while (!st1.empty()) {
		cout << st1.top()<<" ";
		st1.pop();
	}
	cout << endl;
}

template<typename T>
void reverseT() {
	T t;
	stack<T> st1;
	while (cin >> t)
		st1.push(t);.0
	while (!st1.empty()) {
		cout << st1.top() << " ";
		st1.pop();
	}
	cout << endl;
}

int main() {
	/*reverseString();
	reverseInt();*/
	reverseT();
	return 0;
}