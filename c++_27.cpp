#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class test {
//private:
//	int a;
//	int b;
//public:
//	test(int new_a, int new_b) {
//		this->a = new_a;
//		this->b = new_b;
//	}
//
//	friend test& operator+=(test& t1, test& t2);
//
//	void PrintT() {
//		cout << "a:" << this->a << " b:" << this->b << endl;
//	}
//};
//
//test& operator+=(test& t1, test& t2) {
//	t1.a += t2.a;
//	t1.b += t2.b;
//	return t1;
//}
//
//int main() {
//	test t1(10, 20);
//	test t2(20, 30);
//	(t1 += t2) += t1;
//	t1.PrintT();
//
//	return 0;
//}

//class test {
//private:
//	int a;
//	int b;
//public:
//	test(int new_a, int new_b) {
//		this->a = new_a;
//		this->b = new_b;
//	}
//
//	test& operator+=(test& another) {
//		this->a += another.a;
//		this->b += another.b;
//		return *this;
//	}
//
//	void PrintT() {
//		cout << "a:" << this->a << " b:" << this->b << endl;
//	}
//};
//
//int main() {
//	test t1(10, 20);
//	test t2(20, 30);
//	(t1 += t2) += t1;
//	t1.PrintT();
//
//	return 0;
//}

//class test {
//private:
//	int a;
//	int b;
//public:
//	test(int new_a, int new_b) {
//		this->a = new_a;
//		this->b = new_b;
//	}
//
//	friend test& operator++(test& t1);
//
//	void PrintT() {
//		cout << "a:" << this->a << " b:" << this->b << endl;
//	}
//};
//
//test& operator++(test& t1) {                      //其默认的重载方式则为前置++
//	t1.a++;
//	t1.b++;
//	return t1;
//}
//
//int main() {
//	test t1(10, 20);
//	++++t1;
//	t1.PrintT();
//
//	return 0;
//}

//class test {
//private:
//	int a;
//	int b;
//public:
//	test(int new_a, int new_b) {
//		this->a = new_a;
//		this->b = new_b;
//	}
//
//	test& operator++() {                      //其默认的重载方式则为前置++
//		this->a++;
//		this->b++;
//		return *this;
//	}
//
//	void PrintT() {
//		cout << "a:" << this->a << " b:" << this->b << endl;
//	}
//};
//
//int main() {
//	test t1(10, 20);
//	++++t1;
//	t1.PrintT();
//
//	return 0;
//}

//class test {
//private:
//	int a;
//	int b;
//public:
//	test(int new_a, int new_b) {
//		this->a = new_a;
//		this->b = new_b;
//	}
//
//	friend const test operator++(test& t1, int);
//
//	void PrintT() {
//		cout << "a:" << this->a << " b:" << this->b << endl;
//	}
//};
//
//const test operator++(test& t1, int) {                      //需要使用一个占位符
//	test tmp(t1);
//	t1.a++;
//	t1.b++;
//	return tmp;
//}
//
//int main() {
//	test t1(10, 20);
//	t1++;
//	t1.PrintT();
//
//	return 0;
//}

//class test {
//private:
//	int a;
//	int b;
//public:
//	test(int new_a, int new_b) {
//		this->a = new_a;
//		this->b = new_b;
//	}
//
//	const test operator++(int) {                      //需要使用一个占位符
//		test tmp(*this);
//		this->a++;
//		this->b++;
//		return tmp;
//	}
//
//	void PrintT() {
//		cout << "a:" << this->a << " b:" << this->b << endl;
//	}
//};
//
//int main() {
//	test t1(10, 20);
//	t1++;
//	t1.PrintT();
//
//	return 0;
//}

