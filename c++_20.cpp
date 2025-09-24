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

	static int GetA() {    //��̬��Ա�����ھ�̬��������ֻ��ʹ�þ�̬����ȥ���в���
		return a;
	}

	static void SetA1(int n_a) {
		a = n_a;           //������ಿ�޸�ֵ
	}

	static int &SetA2() {
		return a;          //����a�����ã�������ⲿͨ������ȥ�޸�ֵ
	}

	void SetTest(int n_a) {  //�Ǿ�̬����������ʵ�����������ͨ��������÷���
		a = n_a;
	}

};

int Test::a = 30;         //��̬��Ա�ĳ�ʼ��


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

	static void ChangeHeight(int n_h) {         //�޸Ĺ�ͬ�ĸ߶�����
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