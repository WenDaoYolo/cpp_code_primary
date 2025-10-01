#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class test {
//private:
//	int a;
//public:
//	int GetA() 
//	{
//		return this->a;
//	}
//
//	test(int new_a) 
//	{
//		this->a = new_a;           //表示调用当前类方法的对象的地址，即当前对象
//	}
//
//	void SetA(int new_a) 
//	{
//		this->a = new_a;
//	}
//};
//
//int main() {
//	test a1(10);
//	test a2(20);
//	cout << a1.GetA() << endl;
//	a1.SetA(100);
//	cout << a1.GetA() << endl;
//}

//class test {
//private:
//	int a;
//	int b;
//public:
//	int GetA() {
//		return this->a;
//	}
//
//	void SetA(int a) {    //使用this后，变量名就可以重复了
//		this->a = a;
//	}
//};

//class test {
//private:
//	int a;
//	static int b;
//public:
//	static int GetB() {
//		return b;        //底层通过类来调用静态成员变量而非实例对象
//	}
//
//	static int GetB2() {  //❌，普通成员变量只能通过实例对象来调用，然而静态成员方法不存在this指针，无法传递实例对象的指针 
//		return a         //this->a，不存在this指针
//	}
//
//	int GetA() {
//		return a;        //普通成员变量，本质是通过this指针来进行调用的 -> return this->a;
//	}
//
//	int GetB3() {         //√，既可以通过实例对象的this指针来调用，也可以通过类来调用
//		return b;
//	}
//};
//
///*
//	 所以：
//		 静态方法只能调用静态成员
//		 普通方法既可以调用静态成员，也可以调用普通成员
//*/

//class test {
//private:
//	int a;
//	int b;
//public:
//	test(int a, int b) {
//		this->a = a;
//		this->b = b;
//	}
//
//	void PrintT() {
//		cout << "a=" << this->a << ",b=" << this->b << endl;
//	}
//
//	int GetA() {
//		return this->a;
//	}
//
//	int GetB() {
//		return this->b;
//	}
//
//	void SetA(int a) {
//		this->a = a;
//	}
//
//	void SetB(int b) {
//		this->b = b;
//	}
//	/*test testAdd2(test another) {
//		test t3(this->a + another.a, this->b + another.b);
//		return t3;
//	}*/
//
//	void testAdd3(test another) {
//		this->a += another.a;
//		this->b += another.b;
//	}
//
//	test testAdd4(test another) {
//		this->a += another.a;
//		this->b += another.b;
//		return *this;                   //this表示当前对象地址，解引用则表示当前对象
//	}
//
//	test& testAdd5(test& another) {     //返回test类对象的引用
//		this->a += another.a;
//		this->b += another.b;
//		return *this;                  //返回t1对象的引用，即返回t1对象本身
//	}
//
//};

//test testAdd(test& t1, test& t2) {
//	test t3(t1.GetA() + t2.GetA(), t2.GetA() + t2.GetB());
//	return t3;                  //会创建一个匿名对象并调用拷贝构造函数，然后返回匿名对象
//}
//
//int main() {
//	test t1(10, 20);
//	test t2(20, 30);
//	test t3 = testAdd(t1, t2);
//	t3.PrintT();
//	return 0;
//}


//
//int main() {
//	test t1(20, 30);
//	test t2(30, 40);
//	test t3 = t1.testAdd2(t2);
//	t3.PrintT();
//}




//
//int main() {
//	test t1(20, 30);
//	test t2(30, 40);
//
//	t1.testAdd3(t2);
//	t1.PrintT();
//
//	t1.testAdd4(t2);
//	t1.PrintT();
//	return 0;
//}



//int main() {
//	//返回对象本身后，就可以连续进行累加方法的调用
//	test t1(0, 0);
//	test t2(1, 1);
//	t1.testAdd5(t2).testAdd5(t2).testAdd5(t2);
//
//	t1.PrintT();
//	return 0;
//}