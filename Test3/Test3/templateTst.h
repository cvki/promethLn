#pragma once
template<typename T,typename A> 
T add(T t, A a) {
	return t + a;
}

//template<class T> 
//T add(T t1, T t2){
//	return t1 + t2;//使用string作为实例时，运算会出错，即使include<string>也不行
//}

template<class T,class A,class B>
bool compareT(T t, A a, B b){
	//这个会报错，因为T和A和B的类型很可能不允许进行"=="比较
	return (t == a&&a == b) ? 1 : 0;
}

template<class T>
bool compareT(T t, T a, T b) {
	return (t == a&&a == b) ? true : false;
}

//template<typename T, typename T, typename T>
// 该模板声明错误，属于重定义T，虽然参数列表需要三个参数，但如果都是一个类型，只需要定义一个T
//T maxT(T t1,T t2,T t3){
//	T tem = t1 >= t2 ? t1 : t2;
//	return tem >= t3 ? tem:t3;
//}

template<typename T>//该模板声明正确
T maxT(T t1, T t2, T t3) {
	T tem = t1 >= t2 ? t1 : t2;
	T tem1= tem >= t3 ? tem : t3;
	return tem1;
}
