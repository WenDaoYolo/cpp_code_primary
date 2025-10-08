#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#if 0
class student {
private:
	int a;
public:
	int GetA() {
		return this->a;
	}
	student(int a) {
		this->a = a;
	}

	~student() {
		cout << "~student()..." << endl;
	}
};

class MyAuto_ptr {
private:
	student* ptr;
public:
	MyAuto_ptr(student* ptr) {
		this->ptr = ptr;
	}

	~MyAuto_ptr() {
		if (this->ptr != NULL)
		{
			delete this->ptr;
			cout << "~MyAuto_ptr()..." << endl;
		}
	}

	student* operator->() {
		return this->ptr;
	}

	student& operator*() {
		return *(this->ptr);
	}
};

int main() {
	MyAuto_ptr myptr(new student(10));
	cout << myptr->GetA()<< endl;
	cout << (*myptr).GetA() << endl;
	return 0;
}
#endif

//#include<iostream>
//#include<string>
//
//using namespace std;

//class test {
//private:
//	string str;
//public:
//	test(char* str) {
//		this->str = str;         //string类的内部已经封装了深拷贝的行为，所以这里可以直接等号赋值
//	}
//	                             //同理string类的内部一已封装好string对象的析构，无需再关心
//	test() {
//
//	}
//
//	string GetStr() {
//		return this->str;
//	}
//};
//
//int main() {
//	string s1 = " 3.14";
//	string s2 = "hello";
//	string s3 = s1;
//	cout << s3 << endl;
//	cout << s2 + s1 << endl;
//
//	char* a = new char[10];
//	strcpy(a,"hello world!!!");
//	test t1(a);
//	cout << t1.GetStr() << endl;
//	return 0;
//}

