#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
class Teacher {
private:
	char name[20];
	int age;
	char* students;
public:
	Teacher() {                                  //构造函数
		strcpy(name, "张三");
		age = 22;
		students = (char*)malloc(sizeof(10));
	}

	~Teacher() {
		if (students != NULL)
		{
			free(students);
			students = NULL;
			cout << "memory free successful!" << endl;
		}
	}

	void Display() {
		cout << "姓名:" << name << endl;
		cout << "年龄:" << age << endl;
	}
};

int main() {
	Teacher t1;
	t1.Display();

	return 0;
}

#endif

#if 0
class test {
public:
	int a;
	int b;

	test(int new_a, int new_b) {       //构造函数
		a = new_a;
		b = new_b;
	}

	test(const test& another) {       //拷贝构造函数
		a = another.a;
		b = another.b;
	}
};

////错误的使用方式：
//int main() {
//	test t1(10, 20);
//	test t2;
//	t2 = t1;              //t2在创建后就已经调用了系统提供的默认无参构造完成了初始化，此时调用的是赋值操作符函数(后续将学习)
//
//	return 0;
//}

//正确的使用方式：
int main() {
	test t1(10, 20);    //创建对象t1并调用构造函数初始化
	test t2 = t1;        //创建对象t2并调用拷贝构造函数并通过t1进行初始化
	test t3(t2);       //创建对象t3并调用拷贝构造函数并通过t2进行初始化
	cout << "t1:" << t1.a << " " << t1.b << endl;
	cout << "t2:" << t2.a << " " << t2.b << endl;
	cout << "t3:" << t3.a << " " << t3.b << endl;

	return 0;
}
#endif 


#if 0
class test1 {
public:
	int a;
	int b;
	int c;

	test1(int new_a, int new_b, int new_c) {
		a = new_a;
		b = new_b;
		c = new_c;
	}

	/*                编译器提供的默认拷贝构造函数，会将类中的所有成员进行值拷贝

	test1(const test1 &another){
		a=another.a;
		b=another.b;
		c=another.c;
		...
	}

	*/
};

int main() {
	test1 t1(10, 20, 30);
	test1 t2(t1);
	cout << t1.a << " " << t1.b << " " << t1.c << endl;
	cout << t2.a << " " << t2.b << " " << t2.c << endl;

	return 0;
}

#endif 

