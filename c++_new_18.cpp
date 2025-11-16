#include<iostream>
using namespace std;

class Parent{
	private:
		int a;
	public:
		Parent(int a)
		{
			Print();                    //调用父类构造器，此时内存布局当作父类处理，vptr指向父类虚函数表，调用的是父类的Print方法
		
			this->a=a;
			cout<<"Parent(int a)..."<<endl;
		}
		virtual void Print()
		{
			cout<<"Parent::Print()..."<<endl;
		}
};

class Child:public Parent
{
	private:
		int b;
	public:
		Child(int a,int b):Parent(a)     //调用父类的构造器，对继承的父类部分进行初始化
		{
			Print();                     //父类初始化完成，此时内存布局当作子类处理，vptr指向子类虚函数表，调用的是子类的Print方法
		
			this->b=b;
			cout<<"Child(int a,int b)"<<endl;
		}
		
		virtual void Print()
		{
			cout<<"Child::Print()..."<<endl;
		}
};

int main(){
	Child c(10,20);

	return 0;
}