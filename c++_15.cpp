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

	void operator=(const Test& another) {                       //��ֵ����������(������ѧϰ)
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
	���̷�����
		1.����test2���������ȴ���t1���󲢵����вι��캯��
		2.��������t2Ȼ������޲ι��캯����t2�ĳ�Ա���������ֵ
		3.t2���ø�ֵ�������������г�Ա��ֵ����
		4.test2�����������٣�t2�Ƚ���������Ȼ��t1�ٽ�������
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

	void operator=(const Test& another) {                       //��ֵ����������(������ѧϰ)
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
	���̷�����
		1.����test3���������ȴ���t1���󲢵����вι��캯��
		2.Ȼ�����func����������t1����ʱ�βξͷ����˿������죺Test t=t1  -> ���� ����1=����2
		3.Ȼ�����t����PrintT������func�����������٣�t����������
		4.func�������ٺ�test3�����������٣�t1����������
	*/

	return 0;
}

#endif