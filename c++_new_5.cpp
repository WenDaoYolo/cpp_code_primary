#include<iostream>
using namespace std;

//ReView_2 for [继承方式，控制访问权限，兼容性原则]

//class Parent
class Parent{
    public:
        int a;
        void PrintP(){
            cout<<this->a<<endl;
        }
};

class Child:public Parent
{
    public:
        int b;
};

//访问控制权限与继承方式
//public继承:父类public->子类public,父类protected->子类protected,父类private->子类不可见
//protected继承:父类public->子类protected,父类protected->子类protected,父类private->子类不可见
//private继承:父类public->子类private,父类protected->子类private,父类private->子类不可见

int main(){
    //子类对象可以直接当作父类对象使用
    Child c1;
    c1.PrintP();
    //父类对象可以使用子类对象初始化
    Parent p1=c1;
    Parent p2(c1);
    //父类对象可以使用子类对象进行赋值
    Child c2;
    p1=c2;
    //父类指针可以指向子类对象
    Parent* pp=&c2;
    pp->a;
    pp->PrintP();
    //父类引用可以引用子类对象
    Parent& pp2=c2;
    pp2.a;
    pp2.PrintP();

    return 0;
}