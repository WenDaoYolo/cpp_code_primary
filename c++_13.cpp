#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
int test(int a, char b) {
	cout << "p1" << endl;
	return 0;
}

class sss {
public:
	int test(int b, char a) {
		cout << "p2" << endl;
		return 0;
	}

};

int main() {
	test(3, 'w');

	return 0;
}

#endif

#if 0
struct test {
	void (*p)(int a, int b);
};

void PrintTest(int a, int b) {
	cout << "hello" << a << b << endl;
}

int main() {
	struct test t1;
	t1.p = PrintTest;
	t1.p(666, 999);

	return 0;
}
#endif

#if 0
class Test {
public:
	int x;
	int y;

	Test(int a, int b) {
		x = a;
		y = b;
	}

	Test(int a) {
		x = a;
		y = 666;
	}

	Test() {
		x = 123;
		y = 456;
	}

};

int main() {
	Test T1(111, 222);
	cout << T1.x <<" " << T1.y << endl;

	Test T2(999);
	cout << T2.x << " " << T2.y << endl;

	Test T3;
	cout << T3.x <<" "<< T3.y << endl;

	return 0;
}
#endif

#if 0
class test {
public:
	~test() {
		cout << "test" << endl;
	}
};

int main() {
	test t;
	t.~test();
	return 0;
}

#endif




