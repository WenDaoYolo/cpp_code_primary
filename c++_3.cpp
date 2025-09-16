#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

#if 0
int& ReturnB() {
	static int b = 40;        //定义静态变量，函数结束变量也不会销毁
	int& test = b;
	return test;
}

int main() {
	int& temp = ReturnB();
	ReturnB() = 50;
	cout << temp << endl;
	return 0;
}

#endif

#if 0
struct Student {
	char name[20];
	int age;
};

void ChangeStruct1(Student** s) {
	*s = (Student*)malloc(sizeof(Student));
	strcpy((*s)->name, "张三");
	(*s)->age = 40;
}

void FreeStruct1(Student** s) {
	if ((*s) != NULL)
		free(*s);
	*s = NULL;               //在函数内将实参指针置空
}

int main() {
	Student* s;
	ChangeStruct1(&s);
	cout << s->name << " " << s->age << endl;
	FreeStruct1(&s);
	return 0;
}

#endif

#if 0
struct Student {
	char name[20];
	int age;
};

void ChangeStruct1(Student*& s) {               //形参直接定义一级指针的引用
	s = (Student*)malloc(sizeof(Student));
	strcpy(s->name, "张三");
	s->age = 40;
}

void FreeStruct1(Student*& s) {
	if (s != NULL)
	free(s);
	s = NULL;                                   //在函数内将实参指针置空
}

int main() {
	Student* s;
	ChangeStruct1(s);
	cout << s->name << " " << s->age << endl;
	FreeStruct1(s);
	return 0;
}

#endif

int main() {
	int b = 60;
	const int& tb = b;        //低安全性的变量可以用高安全性的容器装载

	const int a = 50;
	const int& ta = a;       //但高安全性的变量不能用低安全性的容器装载

	cout << "a:" << a << " " << "b: " << b << endl;
	return 0;
}
