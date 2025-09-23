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
	Test(30);             //创建出的匿名对象没有参数去接收，则会被立刻销毁
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
		Test(a, b, 100);       //构造的是一个匿名对象，不是同一个对象，
	}                        //构造完成后匿名对象又会立马销毁

	int GetZ() {
		return z;            //所以此时z没有初始化，存储的是随机值
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
	//开辟10个整型大小的空间
	int* p = (int*)calloc(10 , sizeof(int));
	if (p == NULL)
		perror("main");
	int i = 0;
	for (i = 0; i < 10; i++) {
		printf("%d ", *(p + i));
	}

	//释放掉不需要的内存空间
	free(p);
	//内存空间释放掉后，指针则会指向一个非法的内存空间，所以需要手动置空
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

	int* p2=(int*)malloc(sizeof(int) * 10);    //开辟十个整型大小的数组
	for (int i = 0; i < 10; i++)
		p2[i] = i;
	if (p2 != NULL) {
		free(p2);
		p2 = NULL;
	}
}

void test2() {
	int* p = new int;             //开辟一个整型大小的空间并返回指针
	*p = 666;
	if (p != NULL) {
		delete p;               //释放p指向的空间
	}

	int* p2 = new int[10];         //开辟10个整型大小的数组空间并返回指针
		for (int i = 0; i < 10; i++)
			p2[i] = i;

	if (p2 != NULL) {
		delete[] p2;            //固定语法格式，[]表明释放的是一个数组空间，与开辟形成对应
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
	Test* p = (Test*)malloc(sizeof(Test));      //无法进行有参构造的初始化
	p->SetA(20);                              //只能通过Setter方法去修改值

	p->~Test();                               //需要手动触发
	free(p);                                  //在回收之前不会调用析构
	
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
	Test* p = new Test(100);        //动态开辟一个Test类大小的空间并调用有参构造函数，然后返回指针
	Test* p2 = new Test;            //动态开辟一个Test类大小的空间并调用无参构造函数，然后返回指针
	delete p;                     //在回收之前p会调用析构
	delete p2;                    //在回收之前p2会调用析构
	p = NULL;
	p2 = NULL;

	return 0;
}

#endif