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
//	//���ò������ķ�ʽ���е��ã���������߶�Ӧthis���󣬲������ұ߶�Ӧ�β�
//	t1 << cout;              // --> ��ԭ���﷨��Υ������󽵵��˴���ɶ���
//	//�����෽���ķ�ʽ���е��ã����������Ӧthis���󣬴��ݲ�����Ӧ�β�
//	t1.operator<<(cout);
//	cout << "qq��" << endl;
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
//	//���ò������ķ�ʽ���е��ã���������߶�Ӧthis���󣬲������ұ߶�Ӧ�β�
//	t1 >> cin;          // --> ͬ����ԭ���﷨��Υ������󽵵��˴���ɶ���
//
//	//�����෽���ķ�ʽ���е��ã����������Ӧthis���󣬴��ݲ�����Ӧ�β�
//	t2.operator>>(cin); // --> ͬ�����ô˷�ʽ���ñȽ��鷳
//
//	t1.PrintT();
//	t2.PrintT();
//	return 0;
//}