#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
class Test {
private:
	int a;
public:
	Test(int new_a) {
		a = new_a;
	}
};

int main() {
	Test(30);             //����������������û�в���ȥ���գ���ᱻ��������
	return 0;
}
#endif

#if 0
class Test {
private:
	int x;
	int y;
	int z;
public:
	Test(int a, int b, int c) {
		x = a;
		y = b;
		z = c;
	}

	Test(int a, int b) {
		x = a;
		y = b;
		Test(a, b, 100);       //�������һ���������󣬲���ͬһ������
	}                        //������ɺ����������ֻ���������

	int GetZ() {
		return z;            //���Դ�ʱzû�г�ʼ�����洢�������ֵ
	}
};

int main() {
	Test t(10, 20);
	cout << t.GetZ() << endl;

	return 0;
}

#endif

#if 0
int main() {
	//����10�����ʹ�С�Ŀռ�
	int* p = (int*)calloc(10 , sizeof(int));
	if (p == NULL)
		perror("main");
	int i = 0;
	for (i = 0; i < 10; i++) {
		printf("%d ", *(p + i));
	}

	//�ͷŵ�����Ҫ���ڴ�ռ�
	free(p);
	//�ڴ�ռ��ͷŵ���ָ�����ָ��һ���Ƿ����ڴ�ռ䣬������Ҫ�ֶ��ÿ�
	p = NULL;
	return 0;
}

#endif

#if 0
int main() {
	FILE* ptr = fopen("test101.txt","r");
	char ch[20] = "test101";
	cout << strlen(ch) << endl;
	fread(&ch,strlen(ch),1, ptr);
	cout << ch << endl;

	return 0;
}
#endif

#if 0
void test() {
	int* p1 = (int*)malloc(sizeof(int));
	*p1 = 50;
	if (p1 != NULL) {
		free(p1);
		p1 = NULL;
	}

	int* p2=(int*)malloc(sizeof(int) * 10);    //����ʮ�����ʹ�С������
	for (int i = 0; i < 10; i++)
		p2[i] = i;
	if (p2 != NULL) {
		free(p2);
		p2 = NULL;
	}
}

void test2() {
	int* p = new int;             //����һ�����ʹ�С�Ŀռ䲢����ָ��
	*p = 666;
	if (p != NULL) {
		delete p;               //�ͷ�pָ��Ŀռ�
	}

	int* p2 = new int[10];         //����10�����ʹ�С������ռ䲢����ָ��
		for (int i = 0; i < 10; i++)
			p2[i] = i;

	if (p2 != NULL) {
		delete[] p2;            //�̶��﷨��ʽ��[]�����ͷŵ���һ������ռ䣬�뿪���γɶ�Ӧ
	}
}

int main() {
	test();
	test2();

	return 0;
}

#endif

#if 0
int main() {
	int* p = (int*)malloc(sizeof(int));
	delete p;
	p = NULL;

	int* p2 = new int;
	free(p2);
	p2 = NULL;

		return 0;
}
#endif




#if 0
class Test {
private:
	int a;
public:
	Test(int n_a) {
		a = n_a;
	}
	void SetA(int n_a) {
		a = n_a;
	}
};

#endif


class Test {
private:
	int a;
public:
	Test(int n_a) {
		a = n_a;
	}
	void SetA(int n_a) {
		a = n_a;
	}

	~Test() {
		cout << "~Test()..." << endl;
	}

};

int main() {
	Test* p = (Test*)malloc(sizeof(Test));      //�޷������вι���ĳ�ʼ��
	p->SetA(20);                              //ֻ��ͨ��Setter����ȥ�޸�ֵ

	p->~Test();                               //��Ҫ�ֶ�����
	free(p);                                  //�ڻ���֮ǰ�����������
	
	p = NULL;

	return 0;
}


#if 0
class Test {
private:
	int a;
public:
	Test(int n_a) {
		a = n_a;
		cout << "Test(int)..." << endl;
	}

	Test() {
		a = 666;
		cout << "Test()..." << endl;
	}

	~Test() {
		cout << "~Test()..." << endl;
	}

	void SetA(int n_a) {
		a = n_a;
	}
};

int main() {
	Test* p = new Test(100);        //��̬����һ��Test���С�Ŀռ䲢�����вι��캯����Ȼ�󷵻�ָ��
	Test* p2 = new Test;            //��̬����һ��Test���С�Ŀռ䲢�����޲ι��캯����Ȼ�󷵻�ָ��
	delete p;                     //�ڻ���֮ǰp���������
	delete p2;                    //�ڻ���֮ǰp2���������
	p = NULL;
	p2 = NULL;

	return 0;
}

#endif