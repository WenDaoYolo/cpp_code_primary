#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#if 0
using namespace std;

void test(int a) {
	cout << "func1" << endl;
}

void test(int a, char b) {
	cout << "func2" << endl;
}

void test(char a, int b) {
	cout << "func3" << endl;
}

int main() {
	int a = 5, b = 6;
	char c = 'w';

	test(a);              //传递相应的实参调用相匹配的重载函数
	test(a, c);
	test(c, b);

	return 0;
}
#endif

#if 0
using namespace std;


void test(int a, int b, int c = 20) {
	cout << "func1" << endl;
}

void test(int a, int b) {
	cout << "func2" << endl;
}

main() {
	test(1, 2);        //此时就会出现歧义，两个重载函数都满足实参的传递

	return 0;
}

#endif

#if 0
using namespace std;

void test(double b) {
	cout << "func1" << endl;
}

void test(int c) {
	cout << "func2" << endl;
}

int main() {
	test(4);            //严格匹配
	test(3.5f);         //隐式转换后可以匹配,float -> double
	test('A');          //隐式转换后可以匹配,char -> int(字符的ASCLL码)
	//test("hello");      无法匹配，进行报错处理

	return 0;
}

#endif


#if 0
using namespace std;

int fun1(int a, int b) {
	cout << "fun1 " << a << " " << b << endl;
	return 0;
}

// 补充方式2：通过typedef定义
typedef int MY_FUN(int, int);        //定义一个MY_FUN的类型，他是一个函数类型，函数的返回值为int，函数的参数为int，int


int main() {

	//方式1：直接定义函数指针类型
	int(*p)(int, int) = fun1;

	//通过函数指针调用函数 -> 回顾：函数名就是函数的地址，地址就是函数名，所以可以解引用调用，也可以直接当函数名调用
	p(10, 20);
	(*p)(666, 999);

	MY_FUN* pp = fun1;                   //定义该函数类型的指针，并指向一个函数
	pp(111, 1111);
	(*pp)(222, 2222);

	return 0;
}

#endif


#if 0
using namespace std;

int test(int a) {
	cout << "func1" << endl;
	return 0;
}

int test(int a, char b) {
	cout << "func2" << endl;
	return 0;
}

int main() {
	int(*p1)(int) = test;             //p1与test(int)匹配
	int(*p2)(int,char) = test;        //p2与test(int,char)匹配

	(*p1)(10);
	p2(10, 'A');

	return 0;
}

#endif