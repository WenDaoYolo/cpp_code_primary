#define _CRT_SECURE_NO_WARNINGS 1

//#include<memory>
//#include<iostream>
//using namespace std;
//
//class test {
//private:
//	int a;
//public:
//
//	test(int a) {
//		this->a = a;
//		cout << "test(int a)..." << endl;
//	}
//
//	~test() {
//		cout << "~test()..." << endl;
//	}
//	friend void test1();
//};
//
//void test1() {
//	auto_ptr<test> t1(new test(10));
//	cout << t1->a << endl;
//	cout <<(*t1).a<< endl;
//	return;
//}
//
//int main() {
//	test1();
//
//	return 0;
//}

#include<iostream>
using namespace std;

#if 0
class student {
private:
	int id;
public:
	student(int id) {
		this->id = id;
		cout << "student(int id)..." << endl;
	}

	~student() {
		cout << "~student()..." << endl;
	}

	void PrintId() {
		cout << this->id << endl;
	}
};

class MyAuto_ptr {
private:
	student* ptr;
public:
	MyAuto_ptr(student* ptr) {
		this->ptr = ptr;
		cout << "MyAuto_ptr(student* ptr)..." << endl;
	}

	~MyAuto_ptr() {
		if (this->ptr != NULL)
			delete this->ptr;
		this->ptr = NULL;
		cout << "~MyAuto_ptr()..." << endl;
	}

	student* operator->() {      //->的重载
		return this->ptr;
	}	

	student& operator*() {       //*的重载
		return *(this->ptr);
	}
};

void test1() {
	MyAuto_ptr myptr(new student(10));
	myptr->PrintId();         //其本质:(myptr.ptr)->PrintId();
	(*myptr).PrintId();       //其本质:*(myptr.ptr).PrintId();
}

int main() {
	test1();

	return 0;
}
#endif

