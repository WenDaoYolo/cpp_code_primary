#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
class Test {
private:
	int s;
	int t;
public:
	static int a;

	Test(int n_s, int n_t) {
		s = n_s;
		t = n_t;
	}

	void printT() {
		a++;
		cout << "a:" << a << endl;
	}
};

int Test::a = 30;

int main() {
	Test t1(20, 20);
	Test t2(30, 30);
	t1.printT();
	t2.printT();

	return 0;
}

#endif

#if 0
class Test {
private:
	static int a;
	int s;
	int t;
public:
	
	Test(int n_s, int n_t) {
		s = n_s;
		t = n_t;
	}

	void printT() {
		a++;
		cout << "a:" << a << endl;
	}

	static int GetA() {    //静态成员变量在静态区，所以只能使用静态方法去进行操作
		return a;
	}

	static void SetA1(int n_a) {
		a = n_a;           //在类的类部修改值
	}

	static int &SetA2() {
		return a;          //返回a的引用，在类的外部通过引用去修改值
	}

	void SetTest(int n_a) {  //非静态方法，必须实例化对象后，再通过对象调用方法
		a = n_a;
	}

};

int Test::a = 30;         //静态成员的初始化


int main() {
	Test t1(20, 20);
	Test t2(30, 30);
	cout << Test::GetA() << endl;

	Test::SetA1(66);
	cout << Test::GetA() << endl;

	Test::SetA2() = 99;
	cout << Test::GetA() << endl;

	t1.SetTest(666);
	cout << Test::GetA();

	return 0;
}
#endif 

#if 0
class cube {
private:
	int length;
	int width;
	static int height;
public:

	cube(int n_l, int n_w) {
		length = n_l;
		width = n_w;
	}

	void PrintT() {
		int v = length * width * height;
		cout << "height:" << height << endl;
		cout << "volume:" << v << endl;
	}

	static void ChangeHeight(int n_h) {         //修改共同的高度属性
		height = n_h;
	}
};

int cube::height = 30;

int main() {
	cube c1(10, 20);
	cube c2(100, 200);
	c1.PrintT();
	c2.PrintT();

	cube::ChangeHeight(60);
	c1.PrintT();
	c2.PrintT();

	return 0;
}
#endif 