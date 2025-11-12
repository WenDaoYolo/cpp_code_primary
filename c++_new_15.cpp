#include<iostream>
using namespace std;

//重载
void PrintS(int a){
	cout<<a<<endl;
}

void PrintS(char c){
	cout<<c<<endl;
}

//重定义
class A{
	public:
		void printS(){
			cout<<"A"<<endl;
		}
};

class B:public A
{
	public:
		void printS(){
			cout<<"B"<<endl;
		}
};

//重写
class C{
	public:
		virtual void printS(){
			cout<<"C"<<endl;
		}
};

class D:public C
{
	public:
		virtual void printS(){           //子类中的virtual可有可无，只是为了增加代码的可读性
			cout<<"D"<<endl;
		}
};

int main(){
    
    return 0;
}