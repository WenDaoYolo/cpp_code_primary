#define _CRT_SECURE_NO_WARNINGS 1

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
//	friend ostream& operator<<(ostream& os, test& data);
//};
//
//ostream& operator<<(ostream& os, test& data) {
//	os << "a:" << data.a << " b:" << data.b;
//	return os;
//}
//
//int main() {
//	test t1(10, 20);
//	test t2(20, 30);
//		cout << t1 << " " << t2 << endl;
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
//	ostream& operator<<(ostream& os) {
//		os << "a:" << this->a << " b:" << this->b;
//		return os;
//	}
//};
//
//int main() {
//	test t1(10, 20);
//	test t2(20, 30);
//	//采用操作符的方式进行调用：操作符左边对应this对象，操作符右边对应形参
//	t1 << cout;              // --> 与原有语法向违背，大大降低了代码可读性
//	//采用类方法的方式进行调用：主调对象对应this对象，传递参数对应形参
//	t1.operator<<(cout);
//	cout << "qq唐" << endl;
//	return 0;
//}
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
//	friend istream& operator>>(istream& os, test& data);
//	
//	void PrintT() {
//		cout << "a:" << this->a << " b:" << this->b << endl;
//	}
//
//	test() {
//		this->a = 0;
//		this->b = 0;
//	}
//
//};
//
//istream& operator>>(istream& os, test& data) {
//	os >> data.a >> data.b;
//	return os;
//}
//
//int main() {
//	test t1;
//	test t2;
//	cin >> t1 >> t2;
//	t1.PrintT();
//	t2.PrintT();
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
//	istream& operator>>(istream& os) {
//		os >> this->a >> this->b;
//		return os;
//	}
//
//	void PrintT() {
//		cout << "a:" << this->a << " b:" << this->b << endl;
//	}
//
//	test() {
//		this->a = 0;
//		this->b = 0;
//	}
//};
//
//int main() {
//	test t1;
//	test t2;
//
//	//采用操作符的方式进行调用：操作符左边对应this对象，操作符右边对应形参
//	t1 >> cin;          // --> 同理，与原有语法向违背，大大降低了代码可读性
//
//	//采用类方法的方式进行调用：主调对象对应this对象，传递参数对应形参
//	t2.operator>>(cin); // --> 同理，采用此方式调用比较麻烦
//
//	t1.PrintT();
//	t2.PrintT();
//	return 0;
//}