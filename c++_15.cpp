#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#if 0
class test1 {
private:
	int a;
	int b;
public:
	test1(const test1& another) {
	}
};
int main() {
	test1 t1;
	test1 t2(t1);
	return 0;
}
#endif


#if 0
class Test {
private:
	int a;
	int b;
public:
	Test() {
		cout << "Test()..." << endl;
	}

	Test(int new_a, int new_b) {
		a = new_a;
		b = new_b;
		cout << "Test(int new_a,int new_b)..." << endl;
	}

	~Test() {
		cout << "~Test()..." << endl;
	}

	Test(const Test& another) {
		a = another.a;
		b = another.b;
		cout << "Test(const Test &another)..." << endl;
	}

	void PrintT() {
		cout << "a" << a << " " << "b" << b << endl;
	}
};

void test1() {
	Test t1(10, 20);
	Test t2(t1);
}

int main() {
	test1();

	return 0;
}

#endif 

#if 0
class Test {
private:
	int a;
	int b;
public:
	Test() {
		cout << "Test()..." << endl;
	}

	Test(int new_a, int new_b) {
		a = new_a;
		b = new_b;
		cout << "Test(int new_a,int new_b)..." << endl;
	}

	~Test() {
		cout << "~Test()..." << endl;
	}

	Test(const Test& another) {
		a = another.a;
		b = another.b;
		cout << "Test(const Test &another)..." << endl;
	}

	void operator=(const Test& another) {                       //赋值操作符函数(后续将学习)
		a = another.a;
		b = another.b;
		cout << "void operator=(const Test &another)" << endl;
	}

	void PrintT() {
		cout << "a" << a << " " << "b" << b << endl;
	}
};

void test2() {
	Test t1(10, 20);
	Test t2;
	t2 = t1;
}

int main() {
	test2();

	/*
	过程分析：
		1.调用test2函数，首先创建t1对象并调用有参构造函数
		2.创建对象t2然后调用无参构造函数，t2的成员被赋予随机值
		3.t2调用赋值操作符函数进行成员的值拷贝
		4.test2函数即将销毁，t2先进行析构，然后t1再进行析构
	*/

	return 0;
}

#endif

#if 0
class Test {
private:
	int a;
	int b;
public:
	Test() {
		cout << "Test()..." << endl;
	}

	Test(int new_a, int new_b) {
		a = new_a;
		b = new_b;
		cout << "Test(int new_a,int new_b)..." << endl;
	}

	~Test() {
		cout << "~Test()..." << endl;
	}

	Test(const Test& another) {
		a = another.a;
		b = another.b;
		cout << "Test(const Test &another)..." << endl;
	}

	void operator=(const Test& another) {                       //赋值操作符函数(后续将学习)
		a = another.a;
		b = another.b;
		cout << "void operator=(const Test &another)" << endl;
	}

	void PrintT() {
		cout << "a" << a << " " << "b" << b << endl;
	}
};

void func(Test t) {
	cout << "func begin..." << endl;
	t.PrintT();
	cout << "func end..." << endl;
}

void test3() {
	cout << "test3 begin..." << endl;
	Test t1(10, 20);
	func(t1);
	cout << "test3 end..." << endl;
}

int main() {
	test3();

	/*
	过程分析：
		1.调用test3函数，首先创建t1对象并调用有参构造函数
		2.然后调用func函数并传递t1，此时形参就发生了拷贝构造：Test t=t1  -> 类名 对象1=对象2
		3.然后对象t调用PrintT方法，func函数即将销毁，t对象先析构
		4.func函数销毁后，test3函数即将销毁，t1对象先析构
	*/

	return 0;
}

#endif