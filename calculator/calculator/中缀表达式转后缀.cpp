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
			//�����������ͣ�
			str+= s[temi++];
		}
		
		else {
			str += ' ';//�Ӹ��ո��ʾ�ò���������
			if (s[temi] == '+' || s[temi] == '-') {
				//������+-
				if (!stk.empty()) {
					//c = stk.top();
					while ((!stk.empty()) && stk.top() != '(') {//����ѷǿ���һ������ǰ�棬������������ԭ��
						//ֻҪջ�ڲ��������ţ���һ��ջ�����ȼ��ߣ��򵯳�ջ�ڶ�����������Ԫ�أ�Ȼ��ѹ��ջ��Ԫ��
						str += stk.top();
						stk.pop();
					}
				}
				stk.push(s[temi++]);//ѹ��ջ��Ԫ�أ�����ջ��ʱֱ��ѹջ
			}
			else if (s[temi] == '*' || s[temi] == '/') {
				//������*/
				if (!stk.empty()) {
					if (stk.top() == '(' || stk.top() == '+' || stk.top() == '-') {
						//ջ�����ȼ��ͣ�ֱ�ӽ�ջ��Ԫ��ѹջ
						stk.push(s[temi++]);
					}
					else {//ջ��Ԫ��Ϊ*/�������������㷨��Ӧ���ȵ���ջ������Ԫ�أ��ٽ�ջ��Ԫ��ѹջ��
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
				//����������"()"
				if (s[temi] == '(') {//��Ϊ������ֱ��ѹջ
					stk.push(s[temi++]);
				}
				else if (s[temi++] == ')') {
					//��Ϊ�����������γ�ջֱ������ջ�ڵ������ţ�ע�����������temi�±�++�������һֱ������ѭ��
					while (stk.top() != '(') {//&&(!stk.empty())
						str += stk.top();
						stk.pop();
					}
					stk.pop();//����������
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
