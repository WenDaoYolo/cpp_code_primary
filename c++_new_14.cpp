#include<iostream>
#include<cstring>
using namespace std;

class Parent{
	private:
		char* p;
	public:
		Parent(){
			cout<<"Parent()..."<<endl;
			this->p=new char[64];
			memset(this->p,64,0);
			strcpy(this->p,"Parent string...");
		}
		
		virtual ~Parent(){                      //定义虚析构函数，实现析构的多态
			cout<<"~Parent()..."<<endl;
			if(this->p!=NULL)
				delete[] this->p;
			this->p=NULL;
		}
		
		virtual void Print(){
			cout<<"Parent:"<<this->p<<endl;
		}
};

class Child:public Parent
{
	private:
		char* p;
	public:
		Child()                         //根据子类的构造规律，先调用父类构造父类p，再构造子类p
		{
			cout<<"Child()..."<<endl;
			this->p=new char[64];
			memset(this->p,64,0);
			strcpy(this->p,"Child string...");
		}
	
		virtual ~Child()                        //根据子类的析构规律，先调用子类析构析，再调用父类析构
		{
			cout<<"~Child()..."<<endl;
			if(this->p!=NULL)
				delete[] this->p;
			this->p=NULL;
		}
		
		virtual void Print(){
			cout<<"Child:"<<this->p<<endl;
		}
};

void test(Parent* p){
	p->Print();             //发生多态
	delete p;               //delete p之前触发p的析构，若不对析构进行多态，则只会调用父类的析构，子类的部分的内存就会被泄漏
}                           //所以对析构函数也要进行多态，delete子类对象时就会调用子类的析构，子类析构完后再去析构父类

int main(){
	Parent* p=new Parent;
	Child* c=new Child;
	test(p);
    cout<<"-------------"<<endl;
	test(c);
	
	return 0;
}