#include<iostream>
using namespace std;

#if 0
class Parent{
	public:
		int a;
		Parent(){
			this->a=0;
			cout<<"Parent()..."<<endl;
		}
		
		Parent(int a){
			this->a=a;
			cout<<"Parent(int a)..."<<endl;
		}
		
		~Parent(){
			cout<<"~Parent()..."<<endl;
		}
};

class Child:public Parent
{
	public:
		int b;
		Child()
		{
			this->b=0;
			cout<<"Child()..."<<endl;
		}
		
		Child(int b)
		{
			this->b=b;
			cout<<"Child(int b)..."<<endl;
		}
		
		~Child()
		{
			cout<<"~Child()..."<<endl;
		}
		
		void PrintS(){
			cout<<"a="<<this->a<<" b="<<this->b<<endl;
		}
};

int main(){
	Child c1;
	c1.PrintS();

	return 0;
}

#endif

class Parent{
	public:
		int a;
		Parent(){
			this->a=0;
			cout<<"Parent()..."<<endl;
		}
		
		Parent(int a){
			this->a=a;
			cout<<"Parent(int a)..."<<endl;
		}
		
		~Parent(){
			cout<<"~Parent()..."<<endl;
		}
};

class Child:public Parent
{
	public:
		int b;
		Child()
		{
			this->b=0;
			cout<<"Child()..."<<endl;
		}
		
		Child(int b,int a):Parent(a)            //显式调用父类的有参构造
		{
			this->b=b;
			cout<<"Child(int b)..."<<endl;
		}
		
		~Child()
		{
			cout<<"~Child()..."<<endl;
		}
		
		void PrintS(){
			cout<<"a="<<this->a<<" b="<<this->b<<endl;
		}
};

int main(){
	Child c2(3,4);
	c2.PrintS();

	return 0;
}
