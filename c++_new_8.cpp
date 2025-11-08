#include<iostream>
using namespace std;

#if 0
class Parent{
	public:
		void PrintS(){
			cout<<"Parent"<<endl;
		}
};

class Child:public Parent
{
	public:
		void PrintS(){
			Parent::PrintS();
			cout<<"Child"<<endl;
		}
};

int main(){
	Child a;
	a.PrintS();
}

#endif

#if 0
class Parent{
	private:
		int a;
	
	public:
		Parent(){
			this->a=10;
		}
	
		int GetA(){
			return this->a;
		}
};

class Child:public Parent
{
	private:
		int a;
	public:
		Child()
		{
			this->a=100;
		}
		
		void PrintS(){
			cout<<this->a<<endl;        //Child的a
			cout<<this->GetA()<<endl;   //Parent的a
		}
};

int main(){
	Child a;
	a.PrintS();
}

#endif

// class test{
//     private:
//         static int a;
//         int b;
// };

// int test::a=100;         //静态成员变量的初始化

class Parent{
	private:
	public:
		static int a;
};

int Parent::a=100;

class Child:public Parent
{
	private:
	public:
};

int main(){
	Parent p1;
	Parent p2;
	Child c1;
	Child c2;
	
	cout<<p1.a<<endl;
	cout<<p2.a<<endl;
	cout<<c1.a<<endl;
	cout<<c2.a<<endl;
	
	Child::a=200;
	cout<<"---------"<<endl;
	
	cout<<p1.a<<endl;
	cout<<p2.a<<endl;
	cout<<c1.a<<endl;
	cout<<c2.a<<endl;

	return 0;
}