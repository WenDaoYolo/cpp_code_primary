#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

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

Test func1() {
	cout << "func1 begin..." << endl;
	Test temp(10, 20);
	cout << "func1 end..." << endl;
	return temp;
}

void test1() {
	cout << "test1 begin..." << endl;
	func1();
	cout << "test1 end..." << endl;
}

int main() {
	test1();

	/*
	过程分析：
		1.首先调用test1函数，然后调用func1函数，创建局部变量temp并调用有参构造
		2.返回局部变量temp，编译器则创建一个匿名对象进行过渡，此时匿名对象就调用了拷贝构造
		3.func1函数即将销毁，此时局部对象temp调用析构
		4.返回匿名对象，但没有参数去接收，于是匿名对象调用析构后立马销毁，然后test1函数执行完毕
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

Test func1() {
	cout << "func1 begin..." << endl;
	Test temp(10, 20);
	cout << "func1 end..." << endl;
	return temp;
}

void test1() {
	cout << "test1 begin..." << endl;
	Test t = func1();
	t.PrintT();
	cout << "test1 end..." << endl;
}

int main() {
	test1();

	/*
	过程分析：
		1.首先调用test1函数，然后调用func1函数，创建局部变量temp并调用有参构造
		2.返回局部变量temp，编译器则创建一个匿名对象进行过渡，此时匿名对象就调用了拷贝构造
		3.func1函数即将销毁，此时局部对象temp调用析构
		4.返回匿名对象，并创建t进行接收，此刻完成t标签与匿名对象的转交与绑定
		5.test1函数即将销毁，t对象调用析构，最后test1函数销毁
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

Test func1() {
	cout << "func1 begin..." << endl;
	Test temp(10, 20);
	cout << "func1 end..." << endl;
	return temp;
}

void test1() {
	cout << "test1 begin..." << endl;
	Test t;
	t = func1();
	t.PrintT();
	cout << "test1 end..." << endl;
}

int main() {
	test1();

	/*
	过程分析：同理，对象已经初始化再使用等号调用的就是赋值操作符函数而非拷贝构造函数
		1.首先调用test1函数，然后调用func1函数，创建局部变量temp并调用有参构造
		2.返回局部变量temp，编译器则创建一个匿名对象进行过渡，此时匿名对象就调用了拷贝构造
		3.func1函数即将销毁，此时局部对象temp调用析构
		4.创建对象t并调用默认的无参构造函数进行初始化，然后t再通过返回的匿名对象并调用赋值操作符函数进行赋值
		5.匿名对象没有参数进行接收，于是调用析构后立马销毁
		6.test1函数即将销毁，t对象调用析构，最后test1函数销毁
	*/

	return 0;
}


#endif