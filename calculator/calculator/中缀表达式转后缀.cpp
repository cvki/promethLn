#include<iostream>
#include<string>
#include<stack>

using namespace std;

string exptransform(string s) {
	string str;
	int lths = s.length(),temi=0;
	stack<char> stk;
	//stk.top() = -1;
	while (lths--) {
		if (s[temi] >= '0' && s[temi] <= '9') {
			//操作数（整型）
			str+= s[temi++];
		}
		
		else {
			str += ' ';//加个空格表示该操作数结束
			if (s[temi] == '+' || s[temi] == '-') {
				//操作符+-
				if (!stk.empty()) {
					//c = stk.top();
					while ((!stk.empty()) && stk.top() != '(') {//必须把非空这一条件放前面，否则会出错，考虑原因。
						//只要栈内不是左括号，那一定栈内优先级高，则弹出栈内顶层所有优先元素，然后压入栈外元素
						str += stk.top();
						stk.pop();
					}
				}
				stk.push(s[temi++]);//压入栈外元素，或者栈空时直接压栈
			}
			else if (s[temi] == '*' || s[temi] == '/') {
				//操作符*/
				if (!stk.empty()) {
					if (stk.top() == '(' || stk.top() == '+' || stk.top() == '-') {
						//栈内优先级低，直接将栈外元素压栈
						stk.push(s[temi++]);
					}
					else {//栈内元素为*/，按从左到右运算法则，应该先弹出栈内优先元素，再将栈外元素压栈。
						while ((!stk.empty()) && (stk.top() == '*' || stk.top() == '/')) {
							str += stk.top();
							stk.pop();
						}
						stk.push(s[temi++]);
					}
				}
				else
					stk.push(s[temi++]);
			}
			else if (s[temi] == '(' || s[temi] == ')') {
				//操作符括号"()"
				if (s[temi] == '(') {//若为左括号直接压栈
					stk.push(s[temi++]);
				}
				else if (s[temi++] == ')') {
					//若为右括号则依次出栈直至遇到栈内的左括号，注意这里别忘记temi下标++，否则会一直右括号循环
					while (stk.top() != '(') {//&&(!stk.empty())
						str += stk.top();
						stk.pop();
					}
					stk.pop();//弹出左括号
				}
			}
		}
		
	}
	while (!stk.empty()) {
		str += stk.top();
		stk.pop();
	}
	return str;
}
