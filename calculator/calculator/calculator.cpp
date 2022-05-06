#include<iostream>
#include<string>
#include<stack>

using namespace std;

/*�ü�����δ֧�ָ����ļ���*/

int getVp(char c) {//�ж��ַ�char������
	switch (c) {
	case '(':
		return -1;
	case ')':
		return -2;
	case '*':
		return -3;
	case '/':
		return -4;
	case '+':
		return -5;
	case '-':
		return -6;
	case ' '://1.���ڷֿ��������֣����ú�׺���ʽ��ֵʱʹ�á�2.������������Ŀո�
		return -7;
	case '.':
		return 3;//�����������С�����ж�
	default:
		return 2;
	}
}
template<typename T>
T computer(T a1,T a2,char c) {//����
	switch (c) {
		case'+':
			return a1 + a2;
		case'-':
			return a1 - a2;
		case'*':
			return a1 * a2;
		case'/': {
			if (a2)
				return a1 / a2;
			else {
				cerr << "��ĸΪ0��" << endl;
				exit(0);
			}
		}
	}
	return a1;
}
int calculatorInt(string s) {

	//���߼������string��������׺���ʽ����������Ǻ�׺���ʽ����ֻ��Ҫ���������ȡ��������У����ñȽ����ȼ���ע������

	int left_v, right_v;//���Ҳ�����
	char c;//������
	stack<int> st1; stack<char> st2;//����ջ�ֱ�������������Ͳ�����
	int lth = s.length(),tem = 0;;
	while (lth) {
		int sv = getVp(s[tem]);//�����洢ת���ַ���int�ı�־;
		if (sv ==2) {
			int value = 0;
			while (lth&&getVp(s[tem]) > 0) {//˵���Ǹ�������,ע����lth���ˣ�������ѭ��(���һ���������ַ�������ѭ��)
				int num = s[tem++] - '0';
				//ת����int����
				value *= 10;
				value += num;
				--lth;
			}
			//ѹջ
			st1.push(value);
		}
		else if (sv == -1) {//�ǲ�����'('
			st2.push(s[tem++]);//ֱ��ѹջ
			--lth;
		}
		else if (sv == -2) {//�ǲ�����')'
			while (!st2.empty() && st2.top() != '(') {//������������֮ǰ����ȡ���������㣬�����!st2.empty()�ɲ���
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//�������ѹջ
				st2.pop();//������ɺ󵯳��Ѽ���Ĳ�����
			}
			st2.pop();//�Ӳ�����ջ�е���������'('
			++tem;
			--lth;
		}
		else if (sv == -3) {//�ǲ�����'*'
			while (!st2.empty() && (st2.top() == '/' || st2.top() == '*')) {
				//��ջ�����������ȼ���ʱ��ȡ������
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//�������ѹջ
				st2.pop();//������ɺ󵯳��Ѽ���Ĳ�����
			}
			//1.����ֱ�ӽ���ѹջ��2.����������ȼ��ߵ�ջ�ڲ����������Ҳ��ֱ�ӽ���ѹջ
			st2.push(s[tem++]);
			--lth;
		}
		else if (sv == -4) {//�ǲ�����'/'
			while (!st2.empty() && (st2.top() == '/' || st2.top() == '*')) {
				//��ջ�����������ȼ���ʱ��ȡ������
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//�������ѹջ
				st2.pop();//������ɺ󵯳��Ѽ���Ĳ�����
			}
			//1.����ֱ�ӽ���ѹջ��2.����������ȼ��ߵ�ջ�ڲ����������Ҳ��ֱ�ӽ���ѹջ
			st2.push(s[tem++]);
			--lth;
		}
		else if (sv == -5) {//�ǲ�����'+'
			while (!st2.empty() && st2.top()!='(') {
				//��ջ�����������ȼ���ʱ��ȡ������
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//�������ѹջ
				st2.pop();//������ɺ󵯳��Ѽ���Ĳ�����
			}
			//1.����ֱ�ӽ���ѹջ��2.����������ȼ��ߵ�ջ�ڲ����������Ҳ��ֱ�ӽ���ѹջ
			st2.push(s[tem++]);
			--lth;
		}
		else if (sv == -6) {//�ǲ�����'-'
			while (!st2.empty() && st2.top() != '(') {
				//��ջ�����������ȼ���ʱ��ȡ������
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//�������ѹջ
				st2.pop();//������ɺ󵯳��Ѽ���Ĳ�����
			}
			//1.����ֱ�ӽ���ѹջ��2.����������ȼ��ߵ�ջ�ڲ����������Ҳ��ֱ�ӽ���ѹջ
			st2.push(s[tem++]);
			--lth;
		}
		else if (sv == -7) {//���Լ��ӵĿհ׷����' '//������
			++tem;
			--lth;
		}
	}
	while (!st2.empty()) {//��������ջ����ʱ������ȡ������
		right_v = st1.top();
		st1.pop();
		left_v = st1.top();
		st1.pop();
		c = st2.top();
		st1.push(computer(left_v, right_v, c));//�������ѹջ
		st2.pop();//������ɺ󵯳��Ѽ���Ĳ�����
	}

	left_v = st1.top();//��������ջ�գ�������ջ�ڿ϶�ֻʣһ��Ԫ�أ�����ǽ��
	return left_v;
}


int calculator2(string s) {
	//s��ת�����ĺ�׺���ʽ,���ֱ�Ӽ���,����Ҫ����������ȼ�
	stack<int>st1; //�洢����������,��Ϊ��׺���ʽֻ��Ҫ˳�����������,���Բ������������ջ
	int left_v, right_v;//���Ҳ�����
	char c;//�����
	int lth=s.length(), tem = 0;
	int sv = getVp(s[tem]);
	while (lth) {
		sv = getVp(s[tem]);
		if (sv == 2) {//�ַ�Ϊ������
			int val = 0;
			while (lth && getVp(s[tem]) == 2) {
				val *= 10;
				val+=(s[tem++] - '0');
				--lth;
			}
			st1.push(val);
		}
		else if (sv < 0&&sv!=-7) {//�ַ�Ϊ�����,�������Ǻ�׺���ʽ,���ֻ��"+_*/",û��������
			right_v = st1.top();
			st1.pop();
			left_v = st1.top();
			st1.pop();
			c = s[tem++];
			st1.push(computer(left_v, right_v, c));//�������ѹջ
			--lth;
		}
		else if (sv == -7) {//�հ׷�' 'ʱ������
			++tem;
			--lth;
		}
	}
	//������ѭ����,һ���ǲ��������겢�Ҳ�����ջ��ֻʣһ��Ԫ��,�����ս��
	return st1.top();
}


//�����ͼ�����
double computerDouble(string s) {

	//���߼������string��������׺���ʽ����������Ǻ�׺���ʽ����ֻ��Ҫ���������ȡ��������У����ñȽ����ȼ���ע������

	double left_v, right_v;//���Ҳ�����
	char c;//������
	stack<double> st1; stack<char> st2;//����ջ�ֱ�������������Ͳ�����
	int lth = s.length(), tem = 0;;
	while (lth) {
		int sv = getVp(s[tem]);//�����洢ת���ַ���int�ı�־;
		if (sv > 0) {
			double value = 0;
			while (lth && getVp(s[tem]) > 0) {//˵���Ǹ�������,ע����lth���ˣ�������ѭ��(���һ���������ַ�������ѭ��)
				if (getVp(s[tem]) ==2) {//˵��������(δ����С����˵������������)
					int num = s[tem++] - '0';
					//ת����int����
					value *= 10;
					value += num;
					--lth;
				}
				if (getVp(s[tem++]) == 3) {//˵����С����
					double index = 0.1; --lth;
					while (lth && getVp(s[tem]) == 2) {//����С������
						int tmc = s[tem++] - '0';
						value += (tmc * index);
						index *= 0.1;
						--lth;
					}
				}
				else{//����С����ʱ��Ҫ���ˣ���������������
					--tem;
				}
			}
			//ѹջ
			st1.push(value);
		}
		else if (sv == -1) {//�ǲ�����'('
			st2.push(s[tem++]);//ֱ��ѹջ
			--lth;
		}
		else if (sv == -2) {//�ǲ�����')'
			while (!st2.empty() && st2.top() != '(') {//������������֮ǰ����ȡ���������㣬�����!st2.empty()�ɲ���
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//�������ѹջ
				st2.pop();//������ɺ󵯳��Ѽ���Ĳ�����
			}
			st2.pop();//�Ӳ�����ջ�е���������'('
			++tem;
			--lth;
		}
		else if (sv == -3) {//�ǲ�����'*'
			while (!st2.empty() && (st2.top() == '/' || st2.top() == '*')) {
				//��ջ�����������ȼ���ʱ��ȡ������
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//�������ѹջ
				st2.pop();//������ɺ󵯳��Ѽ���Ĳ�����
			}
			//1.����ֱ�ӽ���ѹջ��2.����������ȼ��ߵ�ջ�ڲ����������Ҳ��ֱ�ӽ���ѹջ
			st2.push(s[tem++]);
			--lth;
		}
		else if (sv == -4) {//�ǲ�����'/'
			while (!st2.empty() && (st2.top() == '/' || st2.top() == '*')) {
				//��ջ�����������ȼ���ʱ��ȡ������
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//�������ѹջ
				st2.pop();//������ɺ󵯳��Ѽ���Ĳ�����
			}
			//1.����ֱ�ӽ���ѹջ��2.����������ȼ��ߵ�ջ�ڲ����������Ҳ��ֱ�ӽ���ѹջ
			st2.push(s[tem++]);
			--lth;
		}
		else if (sv == -5) {//�ǲ�����'+'
			while (!st2.empty() && st2.top() != '(') {
				//��ջ�����������ȼ���ʱ��ȡ������
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//�������ѹջ
				st2.pop();//������ɺ󵯳��Ѽ���Ĳ�����
			}
			//1.����ֱ�ӽ���ѹջ��2.����������ȼ��ߵ�ջ�ڲ����������Ҳ��ֱ�ӽ���ѹջ
			st2.push(s[tem++]);
			--lth;
		}
		else if (sv == -6) {//�ǲ�����'-'
			while (!st2.empty() && st2.top() != '(') {
				//��ջ�����������ȼ���ʱ��ȡ������
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//�������ѹջ
				st2.pop();//������ɺ󵯳��Ѽ���Ĳ�����
			}
			//1.����ֱ�ӽ���ѹջ��2.����������ȼ��ߵ�ջ�ڲ����������Ҳ��ֱ�ӽ���ѹջ
			st2.push(s[tem++]);
			--lth;
		}
		else if (sv == -7) {//���Լ��ӵĿհ׷����' '//������
			++tem;
			--lth;
		}
	}
	while (!st2.empty()) {//��������ջ����ʱ������ȡ������
		right_v = st1.top();
		st1.pop();
		left_v = st1.top();
		st1.pop();
		c = st2.top();
		st1.push(computer(left_v, right_v, c));//�������ѹջ
		st2.pop();//������ɺ󵯳��Ѽ���Ĳ�����
	}

	left_v = st1.top();//��������ջ�գ�������ջ�ڿ϶�ֻʣһ��Ԫ�أ�����ǽ��
	return left_v;
}
