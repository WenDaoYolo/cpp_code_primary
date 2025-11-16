#include<iostream>
using namespace std;

//多态的原理
class Parent{
    public:
        virtual void test1(){   
            cout<<"virtual void Parent::test1()..."<<endl;
        }

        void test2(){
            cout<<"void Parent::test2()..."<<endl;
        }
};

class Child:public Parent
{
    public:
        virtual void test1(){
            cout<<"virtual void Child::test1()..."<<endl;
        }

        void test2(){
            cout<<"void Child::test2()..."<<endl;
        }
};

void func(Parent* ptr)
{
    ptr->test1();
    ptr->test2();
}

int main(){
    Parent p;
    Child c;

    func(&p);
    func(&c);

    return 0;
}