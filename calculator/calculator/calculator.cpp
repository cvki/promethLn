#include<iostream>
#include<string>
#include<stack>

using namespace std;

/*该计算器未支持负数的计算*/

int getVp(char c) {//判断字符char的类型
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
	case ' '://1.用于分开具体数字，在用后缀表达式求值时使用。2.用来忽略输入的空格
		return -7;
	case '.':
		return 3;//浮点计算器对小数的判断
	default:
		return 2;
	}
}
template<typename T>
T computer(T a1,T a2,char c) {//计算
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
				cerr << "分母为0！" << endl;
				exit(0);
			}
		}
	}
	return a1;
}
int calculatorInt(string s) {

	//该逻辑传入的string必须是中缀表达式，若传入的是后缀表达式，则只需要遇到运算符取数计算就行，不用比较优先级。注意区别。

	int left_v, right_v;//左右操作数
	char c;//操作符
	stack<int> st1; stack<char> st2;//两个栈分别用来存操作数和操作符
	int lth = s.length(),tem = 0;;
	while (lth) {
		int sv = getVp(s[tem]);//用来存储转换字符到int的标志;
		if (sv ==2) {
			int value = 0;
			while (lth&&getVp(s[tem]) > 0) {//说明是个操作数,注意别把lth丢了，否则死循环(最后一个操作数字符跳不出循环)
				int num = s[tem++] - '0';
				//转换成int整数
				value *= 10;
				value += num;
				--lth;
			}
			//压栈
			st1.push(value);
		}
		else if (sv == -1) {//是操作符'('
			st2.push(s[tem++]);//直接压栈
			--lth;
		}
		else if (sv == -2) {//是操作符')'
			while (!st2.empty() && st2.top() != '(') {//在遇到左括号之前依次取操作数计算，这里的!st2.empty()可不加
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//计算后结果压栈
				st2.pop();//计算完成后弹出已计算的操作符
			}
			st2.pop();//从操作符栈中弹出左括号'('
			++tem;
			--lth;
		}
		else if (sv == -3) {//是操作符'*'
			while (!st2.empty() && (st2.top() == '/' || st2.top() == '*')) {
				//当栈顶操作符优先级高时，取数计算
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//计算后结果压栈
				st2.pop();//计算完成后弹出已计算的操作符
			}
			//1.否则直接将其压栈，2.完成上面优先级高的栈内操作符计算后，也是直接将其压栈
			st2.push(s[tem++]);
			--lth;
		}
		else if (sv == -4) {//是操作符'/'
			while (!st2.empty() && (st2.top() == '/' || st2.top() == '*')) {
				//当栈顶操作符优先级高时，取数计算
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//计算后结果压栈
				st2.pop();//计算完成后弹出已计算的操作符
			}
			//1.否则直接将其压栈，2.完成上面优先级高的栈内操作符计算后，也是直接将其压栈
			st2.push(s[tem++]);
			--lth;
		}
		else if (sv == -5) {//是操作符'+'
			while (!st2.empty() && st2.top()!='(') {
				//当栈顶操作符优先级高时，取数计算
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//计算后结果压栈
				st2.pop();//计算完成后弹出已计算的操作符
			}
			//1.否则直接将其压栈，2.完成上面优先级高的栈内操作符计算后，也是直接将其压栈
			st2.push(s[tem++]);
			--lth;
		}
		else if (sv == -6) {//是操作符'-'
			while (!st2.empty() && st2.top() != '(') {
				//当栈顶操作符优先级高时，取数计算
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//计算后结果压栈
				st2.pop();//计算完成后弹出已计算的操作符
			}
			//1.否则直接将其压栈，2.完成上面优先级高的栈内操作符计算后，也是直接将其压栈
			st2.push(s[tem++]);
			--lth;
		}
		else if (sv == -7) {//是自己加的空白符标记' '//跳过它
			++tem;
			--lth;
		}
	}
	while (!st2.empty()) {//当操作符栈不空时，依次取出计算
		right_v = st1.top();
		st1.pop();
		left_v = st1.top();
		st1.pop();
		c = st2.top();
		st1.push(computer(left_v, right_v, c));//计算后结果压栈
		st2.pop();//计算完成后弹出已计算的操作符
	}

	left_v = st1.top();//最后操作符栈空，操作数栈内肯定只剩一个元素，这就是结果
	return left_v;
}


int calculator2(string s) {
	//s是转换过的后缀表达式,因此直接计算,不需要看运算符优先级
	stack<int>st1; //存储操作数即可,因为后缀表达式只需要顺序运算符计算,所以不必再用运算符栈
	int left_v, right_v;//左右操作数
	char c;//运算符
	int lth=s.length(), tem = 0;
	int sv = getVp(s[tem]);
	while (lth) {
		sv = getVp(s[tem]);
		if (sv == 2) {//字符为操作数
			int val = 0;
			while (lth && getVp(s[tem]) == 2) {
				val *= 10;
				val+=(s[tem++] - '0');
				--lth;
			}
			st1.push(val);
		}
		else if (sv < 0&&sv!=-7) {//字符为运算符,且由于是后缀表达式,因此只有"+_*/",没有括号了
			right_v = st1.top();
			st1.pop();
			left_v = st1.top();
			st1.pop();
			c = s[tem++];
			st1.push(computer(left_v, right_v, c));//计算后结果压栈
			--lth;
		}
		else if (sv == -7) {//空白符' '时跳过它
			++tem;
			--lth;
		}
	}
	//当跳出循环后,一定是操作符算完并且操作数栈中只剩一个元素,即最终结果
	return st1.top();
}


//浮点型计算器
double computerDouble(string s) {

	//该逻辑传入的string必须是中缀表达式，若传入的是后缀表达式，则只需要遇到运算符取数计算就行，不用比较优先级。注意区别。

	double left_v, right_v;//左右操作数
	char c;//操作符
	stack<double> st1; stack<char> st2;//两个栈分别用来存操作数和操作符
	int lth = s.length(), tem = 0;;
	while (lth) {
		int sv = getVp(s[tem]);//用来存储转换字符到int的标志;
		if (sv > 0) {
			double value = 0;
			while (lth && getVp(s[tem]) > 0) {//说明是个操作数,注意别把lth丢了，否则死循环(最后一个操作数字符跳不出循环)
				if (getVp(s[tem]) ==2) {//说明是数字(未经过小数点说明是整数部分)
					int num = s[tem++] - '0';
					//转换成int整数
					value *= 10;
					value += num;
					--lth;
				}
				if (getVp(s[tem++]) == 3) {//说明是小数点
					double index = 0.1; --lth;
					while (lth && getVp(s[tem]) == 2) {//计算小数部分
						int tmc = s[tem++] - '0';
						value += (tmc * index);
						index *= 0.1;
						--lth;
					}
				}
				else{//不是小数点时，要回退，避免跳过操作符
					--tem;
				}
			}
			//压栈
			st1.push(value);
		}
		else if (sv == -1) {//是操作符'('
			st2.push(s[tem++]);//直接压栈
			--lth;
		}
		else if (sv == -2) {//是操作符')'
			while (!st2.empty() && st2.top() != '(') {//在遇到左括号之前依次取操作数计算，这里的!st2.empty()可不加
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//计算后结果压栈
				st2.pop();//计算完成后弹出已计算的操作符
			}
			st2.pop();//从操作符栈中弹出左括号'('
			++tem;
			--lth;
		}
		else if (sv == -3) {//是操作符'*'
			while (!st2.empty() && (st2.top() == '/' || st2.top() == '*')) {
				//当栈顶操作符优先级高时，取数计算
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//计算后结果压栈
				st2.pop();//计算完成后弹出已计算的操作符
			}
			//1.否则直接将其压栈，2.完成上面优先级高的栈内操作符计算后，也是直接将其压栈
			st2.push(s[tem++]);
			--lth;
		}
		else if (sv == -4) {//是操作符'/'
			while (!st2.empty() && (st2.top() == '/' || st2.top() == '*')) {
				//当栈顶操作符优先级高时，取数计算
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//计算后结果压栈
				st2.pop();//计算完成后弹出已计算的操作符
			}
			//1.否则直接将其压栈，2.完成上面优先级高的栈内操作符计算后，也是直接将其压栈
			st2.push(s[tem++]);
			--lth;
		}
		else if (sv == -5) {//是操作符'+'
			while (!st2.empty() && st2.top() != '(') {
				//当栈顶操作符优先级高时，取数计算
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//计算后结果压栈
				st2.pop();//计算完成后弹出已计算的操作符
			}
			//1.否则直接将其压栈，2.完成上面优先级高的栈内操作符计算后，也是直接将其压栈
			st2.push(s[tem++]);
			--lth;
		}
		else if (sv == -6) {//是操作符'-'
			while (!st2.empty() && st2.top() != '(') {
				//当栈顶操作符优先级高时，取数计算
				right_v = st1.top();
				st1.pop();
				left_v = st1.top();
				st1.pop();
				c = st2.top();
				st1.push(computer(left_v, right_v, c));//计算后结果压栈
				st2.pop();//计算完成后弹出已计算的操作符
			}
			//1.否则直接将其压栈，2.完成上面优先级高的栈内操作符计算后，也是直接将其压栈
			st2.push(s[tem++]);
			--lth;
		}
		else if (sv == -7) {//是自己加的空白符标记' '//跳过它
			++tem;
			--lth;
		}
	}
	while (!st2.empty()) {//当操作符栈不空时，依次取出计算
		right_v = st1.top();
		st1.pop();
		left_v = st1.top();
		st1.pop();
		c = st2.top();
		st1.push(computer(left_v, right_v, c));//计算后结果压栈
		st2.pop();//计算完成后弹出已计算的操作符
	}

	left_v = st1.top();//最后操作符栈空，操作数栈内肯定只剩一个元素，这就是结果
	return left_v;
}
