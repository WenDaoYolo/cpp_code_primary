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

	void operator=(const Test& another) {                       //��ֵ����������(������ѧϰ)
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
	���̷�����
		1.���ȵ���test1������Ȼ�����func1�����������ֲ�����temp�������вι���
		2.���ؾֲ�����temp���������򴴽�һ������������й��ɣ���ʱ��������͵����˿�������
		3.func1�����������٣���ʱ�ֲ�����temp��������
		4.�����������󣬵�û�в���ȥ���գ�����������������������������٣�Ȼ��test1����ִ�����
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
	���̷�����
		1.���ȵ���test1������Ȼ�����func1�����������ֲ�����temp�������вι���
		2.���ؾֲ�����temp���������򴴽�һ������������й��ɣ���ʱ��������͵����˿�������
		3.func1�����������٣���ʱ�ֲ�����temp��������
		4.�����������󣬲�����t���н��գ��˿����t��ǩ�����������ת�����
		5.test1�����������٣�t����������������test1��������
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
	���̷�����ͬ�������Ѿ���ʼ����ʹ�õȺŵ��õľ��Ǹ�ֵ�������������ǿ������캯��
		1.���ȵ���test1������Ȼ�����func1�����������ֲ�����temp�������вι���
		2.���ؾֲ�����temp���������򴴽�һ������������й��ɣ���ʱ��������͵����˿�������
		3.func1�����������٣���ʱ�ֲ�����temp��������
		4.��������t������Ĭ�ϵ��޲ι��캯�����г�ʼ����Ȼ��t��ͨ�����ص��������󲢵��ø�ֵ�������������и�ֵ
		5.��������û�в������н��գ����ǵ�����������������
		6.test1�����������٣�t����������������test1��������
	*/

	return 0;
}


#endif