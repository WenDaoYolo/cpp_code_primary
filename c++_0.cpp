//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstring>
//#include<cstdio>
//
///*
//(本次C++的学习需要有C语言的基础)
//
//C是面向过程的语言，不符合日常生活中的逻辑，而C++则是面向对象的语言，是对C的补充，C++相比C更加高效
//C++早C语言的基础上进行了扩展，C是C++的子集，C++兼容C的所有语法，而C不一定兼容C++的语法
//
//面向过程OPP：以过程为主
//例如定义一个吃的函数，然后将小明和饭作为参数传进去
//
//面向对象OOP：以对象为主
//例如定义一个对象小明，然后小明去调用吃饭这个方法
//	定义一个对象小狗，然后小狗去调用吃狗粮这个方法
//	其中吃是他们共同的行为，食物则是不同的参数
//
//面向对象编程相比于面向过程编程，可以更加高效和方便地实现更加复杂的事物和逻辑
//
//
//c语言
//编译器：gcc
//文件后缀：.c
//
//c++
//编译器：g++
//文件后缀：.cpp
//
//*/
//
//using namespace std;           //在全局中，使用std命名空间
//
//namespace A {
//	namespace B {
//		int c = 50;
//	}
//	namespace C {
//		int c = 60;
//	}
//	using namespace C;
//}
//
//using A::c;    //使用A空间中B空间中的C
//int main() {
//	cout << c << endl;
//}