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
	Teacher() {                                  //���캯��
		strcpy(name, "����");
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
		cout << "����:" << name << endl;
		cout << "����:" << age << endl;
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

	test(int new_a, int new_b) {       //���캯��
		a = new_a;
		b = new_b;
	}

	test(const test& another) {       //�������캯��
		a = another.a;
		b = another.b;
	}
};

////�����ʹ�÷�ʽ��
//int main() {
//	test t1(10, 20);
//	test t2;
//	t2 = t1;              //t2�ڴ�������Ѿ�������ϵͳ�ṩ��Ĭ���޲ι�������˳�ʼ������ʱ���õ��Ǹ�ֵ����������(������ѧϰ)
//
//	return 0;
//}

//��ȷ��ʹ�÷�ʽ��
int main() {
	test t1(10, 20);    //��������t1�����ù��캯����ʼ��
	test t2 = t1;        //��������t2�����ÿ������캯����ͨ��t1���г�ʼ��
	test t3(t2);       //��������t3�����ÿ������캯����ͨ��t2���г�ʼ��
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

	/*                �������ṩ��Ĭ�Ͽ������캯�����Ὣ���е����г�Ա����ֵ����

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

