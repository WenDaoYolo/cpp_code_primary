#include<iostream>
using namespace std;

class Parent{
	public:
		int a;
		void PrintS(){
			cout<<this->a<<endl;
		}
};

class Child:public Parent
{
	public:
		int b;
};

int main(){
	Child c;
	c.PrintS();            //子类对象c当作父类对象使用，调用父类的方法
	
    Parent p;
    
    Child s1;
	Parent p1(s1);
   
    Parent p2;
    Child s2;
    p2=s2;

    Child s3;
	Parent p3;
	Child* ps;
	Parent* pp;
	pp=&s3;
	pp->a;
	pp->PrintS();

    Child s4;
	Parent& p4=s4;
	p4.a;
	p4.PrintS();
    
	return 0;
}