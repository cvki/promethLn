#pragma once
template<typename T,typename A> 
T add(T t, A a) {
	return t + a;
}

//template<class T> 
//T add(T t1, T t2){
//	return t1 + t2;//ʹ��string��Ϊʵ��ʱ������������ʹinclude<string>Ҳ����
//}

template<class T,class A,class B>
bool compareT(T t, A a, B b){
	//����ᱨ����ΪT��A��B�����ͺܿ��ܲ��������"=="�Ƚ�
	return (t == a&&a == b) ? 1 : 0;
}

template<class T>
bool compareT(T t, T a, T b) {
	return (t == a&&a == b) ? true : false;
}

//template<typename T, typename T, typename T>
// ��ģ���������������ض���T����Ȼ�����б���Ҫ�������������������һ�����ͣ�ֻ��Ҫ����һ��T
//T maxT(T t1,T t2,T t3){
//	T tem = t1 >= t2 ? t1 : t2;
//	return tem >= t3 ? tem:t3;
//}

template<typename T>//��ģ��������ȷ
T maxT(T t1, T t2, T t3) {
	T tem = t1 >= t2 ? t1 : t2;
	T tem1= tem >= t3 ? tem : t3;
	return tem1;
}
