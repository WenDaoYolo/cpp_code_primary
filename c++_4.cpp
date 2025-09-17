#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

#if 0
#define MAX(a,b)  \
((a) > (b) ? (a) : (b))        //假设传参a++,b++,无法对参数进行检测，从而导致结果错误
//续行符
using namespace std;

int main() {
	int a = 50;
	int b = 40;
	int c = MAX(a, b);
	cout << "c:" << c << endl;
}
#endif

#if 0
void PrintAB(int a, int b) {
	cout << "a:" << a << " " << "b:" << b << endl;
}

int main() {
	int a = 10;
	int b = 20;
	for (int i = 0; i < 100; i++) {
		a++;
		b++;
		PrintAB(a, b);                //会进行100次入栈和出栈
	}
	return 0;
}
#endif

#if 0
using namespace std;

inline void PrintAB(int a, int b) {
	cout << "a:" << a << " " << "b:" << b << endl;
}

int main() {
	int a = 5;
	int b = 6;
	for (int i = 0; i < 100; i++) {
		a++;
		b++;
		PrintAB(a, b);               //  -> 编译器会对函数进行展开，将函数体直接插入函数调用处
	}
	return 0;
}

#endif

#if 0
using namespace std;

inline void PrintAB(int a, int b) {
	cout << "a:" << a << " " << "b:" << b << endl;
}


int main() {
	int a = 5;
	int b = 6;
	for (int i = 0; i < 10000; i++) {
		a++;
		b++;
		PrintAB(a, b);               //  -> 编译器会对函数进行展开，将函数体直接插入函数调用处
	}
	return 0;
}
#endif

//可以给函数的参数赋一个默认值，此时就可以无参调用，而形参则为默认值
//若有参调用，则形参会正常接收传递的实参

#if 0
using namespace std;

void test1(int a = 20) {
	cout << a << endl;;
}

int main() {
	int b = 40;
	test1();
	test1(b);

	return 0;
}

#endif

#if 0
using namespace std;

void test1(int a, int=30) {
	cout << "yes" << endl;
}

int main() {
	test1(20);
	return 0;
}
#endif