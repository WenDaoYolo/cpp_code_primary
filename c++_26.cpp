#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#if 0
class A {
private:
	int a;
public:
	A(int new_a){
		this->a = new_a;
	}
	void friend PrintA(A &a1);
};

void PrintA(A &a1)
{
	cout << a1.a << endl;
}

int main() {
	A a1(10);
	A a2(20);

	PrintA(a1);
	PrintA(a2);

	return 0;
}
#endif 

//class A {
//private:
//	int a;
//public:
//	A() {
//		a = 666;
//	}
//	friend class B;
//};
//
//class B {
//private:
//	int b;
//public:
//	void PrintA(A &a1) {
//		cout << a1.a << endl;
//	}
//};
//
//int main() {
//	B b1;
//	b1.PrintA();
//}
#if 0
class test {
private:
	int a;
	int b;
public:
	test(int new_a, int new_b) {
		this->a = new_a;
		this->b = new_b;
	}

	friend test ComplexAdd(test& t1, test& t2);

	void PrintT() {
		cout << "a:" << this->a << ",b:" << this->b << endl;
	}
};

test ComplexAdd(test& t1, test& t2) {
	test t3(t1.a + t2.a, t1.b + t2.b);
	return t3;
}

int main() {
	test t1(333, 111);
	test t2(333, 888);
	test t3 = ComplexAdd(t1, t2);
	t3.PrintT();
	return 0;
}
#endif

#if 0
class test {
private:
	int a;
	int b;
public:
	test(int new_a, int new_b) {
		this->a = new_a;
		this->b = new_b;
	}

	test ComplexAdd(test& another) {
		test t3(this->a + another.a, this->b + another.b);
		return t3;
	}

	void PrintT() {
		cout << "a:" << this->a << ",b:" << this->b << endl;
	}
};

int main() {
	test t1(333, 111);
	test t2(333, 888);
	test t3 = t1.ComplexAdd(t2);
	t3.PrintT();
	return 0;
}
#endif

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
//	friend test operator+(test& t1, test& t2);
//
//	void PrintT() {
//		cout << "a:" << this->a << ",b:" << this->b << endl;
//	}
//};
//
//test operator+(test& t1, test& t2) {
//	test t3(t1.a + t2.a, t1.b + t2.b);
//	return t3;
//}
//
//int main() {
//	test t1(333, 111);
//	test t2(333, 888);
//
//	test t3 = t1 + t2;
//	test t4 = operator+(t1,t2);
//
//	t3.PrintT();
//	t4.PrintT();
//	return 0;
//}
//
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
//	test operator+(test& another) {
//		test t3(this->a + another.a, this->b + another.b);
//		return t3;
//	}
//
//	void PrintT() {
//		cout << "a:" << this->a << ",b:" << this->b << endl;
//	}
//};
//
//int main() {
//	test t1(333, 111);
//	test t2(333, 888);
//	//两种调用方式，是等价的    ->   底层翻译：operator(t1,t2)
//	test t3 = t1 + t2;               //方式1 操作符调用
//	test t4 = t1.operator+(t2);      //方式2 类方法调用 
//
//	t3.PrintT();
//	t4.PrintT();
//	return 0;
//}

