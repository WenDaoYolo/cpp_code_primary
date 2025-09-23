#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#if 0
class Test {
private:
	int age;
	char* name;
public:
	void PrintT() {
		cout << "age:" << age << ",name:" << name << endl;
	}

	Test(const Test& another) {
		age = another.age;
		name = another.name;
	}

	~Test() {
		if (name != NULL) {
			free(name);
			name = NULL;
		}
		cout << "~Test()...." << endl;
	}

	Test(int new_age, const char* new_name) {
		age = new_age;
		size_t len = strlen(new_name);
		name = (char*)malloc(sizeof(len));
		strcpy(name, new_name);
	}
};

void test1() {
	Test t1(10, "����");
	t1.PrintT();
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
	int age;
	char* name;
public:
	void PrintT() {
		cout << "age:" << age << ",name:" << name << endl;
	}

	Test(const Test& another) {               //���
		age = another.age;
		name = (char*)malloc(sizeof(strlen(name) + 1));   //strlen������\0,�ַ���ҪԤ��\0��λ��
		strcpy(name, another.name);
	}

	~Test() {
		if (name != NULL) {
			free(name);
			name = NULL;
		}
		cout << "~Test()...." << endl;
	}

	Test(int new_age, const char* new_name) {
		age = new_age;
		size_t len = strlen(new_name);
		name = (char*)malloc(sizeof(len));
		strcpy(name, new_name);
	}
};

void test1() {
	Test t1(10, "����");
	t1.PrintT();
	Test t2(t1);
}

int main() {
	test1();

	return 0;
}

#endif

