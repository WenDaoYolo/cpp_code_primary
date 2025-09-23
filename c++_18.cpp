#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
class A {
private:
	int a;
	int b;
public:
	A(int new_a, int new_b) {
		a = new_a;
		b = new_b;
	}
	void PrintT() {
		cout << "a:" << a << ",b:" << b << endl;
	}

	int GetA() {
		return a;
	}

	int GetB() {
		return b;
	}
};

class B {
private:
	int a;
	A t1;                    //在创建对象后就调用默认的无参构造并完成了初始化
	A t2;
public:
	B(int new_a, A &new_t1, A &new_t2):t1(new_t1),t2(new_t2)
	{
		a = new_a;
	}
	void PrintT() {
		cout << "a:" << a << endl;
		cout << "t1:" << t1.GetA() << " " << t1.GetB() << endl;
		cout << "t2:" << t2.GetA() << " " << t2.GetB() << endl;
	}
};

int main() {
	A t1(10,20);
	A t2(30, 40);
	t1.PrintT();
	t2.PrintT();
	cout << "--------------------->" << endl;
	B test(666, t1, t2);
	test.PrintT();

	return 0;
}

#endif

#if 0
class A {
private:
	int a;
	int b;
public:
	A(int new_a, int new_b) {
		a = new_a;
		b = new_b;
	}
	void PrintT() {
		cout << "a:" << a << ",b:" << b << endl;
	}

	int GetA() {
		return a;
	}

	int GetB() {
		return b;
	}
};

class B {
private:
	int a;
	A t1;                    //在创建对象后就调用默认的无参构造并完成了初始化
	A t2;
public:

	B(int new_a, int new_t1,int new_t2,int new_a1,int new_a2) :t1(new_t1, new_t2), t2(new_a1,new_a2)
	{
		cout << "B(int,int,int,int,int)..." << endl;
		a = new_a;
	}

	~B() {
		cout << "~B()..." << endl;
	}
	void PrintT() {
		cout << "a:" << a << endl;
		cout << "t1:" << t1.GetA() << " " << t1.GetB() << endl;
		cout << "t2:" << t2.GetA() << " " << t2.GetB() << endl;
	}
};

int main() {
	A t1(10, 20);
	A t2(30, 40);
	t1.PrintT();
	t2.PrintT();
	cout << "--------------------->" << endl;
	B test(111,222,333,444,555);
	test.PrintT();

	return 0;
}

#endif

#if 0
class A {
private:
	int a;
public:
	A(int new_a) {
		a = new_a;
		cout << "A(int)..." <<a<< endl;
	}
	~A() {
		cout << "~A()..." <<a<< endl;
	}
};

class B {
private:
	int t;
	A a2;        //a2先定义，a2先构造，a1后构造  
	A a1;        //对应析构则是a1先析构，a2后析构
public:
	B(int a, int b, int c) :a1(b), a2(c)
	{
		t = a;
		cout << "B(int,int,int)..." << endl;
	}

	~B() {
		cout << "~B()..." << endl;
	}
};

void test() {
	B b1(10, 20, 30);
}

int main() {
	test();

	return 0;
}
#endif

#if 0
class A {
private:
	int a;
	int b;
public:
	A(int new_a, int new_b) {
		a = new_a;
		b = new_b;
	}
	A() {

	}
};


class B {
private:
	int a;
	A t1;                    //注意，若未定义无参构造，会出现无法匹配构造函数的语法错误
	//因为已经提供了显示的有参构造，所以系统不在提供默认的无参构造
	A t2;
public:
	B(int new_a, A& new_t1, A& new_t2)
	{
		a = new_a;

		t1 = new_t1;          //❌
		t2 = new_t2;
	}
};

int main() {
	A a1(10, 20);
	A a2(20, 30);
	B b1(20,a1,a2);

	return 0;
}
#endif