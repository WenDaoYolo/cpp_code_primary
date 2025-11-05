#include<iostream>
using namespace std;

class Parent{
	//访问控制权限
	public:          //共有，类的内部和外部都可以访问
		int a1;
	protected:      //保护，只能在类的内部访问
		int a2;
	private:         //私有，只能在类的内部访问
		int a3;
};

class Child1:public Parent   //注意区分继承方式和访问控制权限，这里的public为继承方式
{
	void test(){
		cout<<a1<<endl;      //以公有方式继承，父类中a1为共有变量，在子类中则也为公有，类的内外部均可访问       
		cout<<a2<<endl;      //以公有方式继承，父类中a2为保护变量，在子类中则也为保护，类的内部可访问，外部不可以访问       
		//cout<<a3<<endl;      //以公有方式继承，父类中a3为私有变量，在子类中则为不可见，类的内部和外部均不可访问   
	}
};

class Child2:protected Parent
{
	void test(){
		cout<<a1<<endl;      //以保护方式继承，父类中a1为公有变量，在子类中则为保护，类的内部可访问，外部不可以访问      
		cout<<a2<<endl;      //以保护方式继承，父类中a2为保护变量，在子类中则为保护，类的内部可访问，外部不可以访问       
		//cout<<a3<<endl;      //以保护方式继承，父类中a3为私有变量，在子类中则为不可见，类的内部和外部均不可访问   
	}
};

class Child3:private Parent
{
	void test(){
		cout<<a1<<endl;      //以私有方式继承，父类中a1为公有变量，在子类中则私有，类的内部可访问，外部不可以访问
		cout<<a2<<endl;      //以私有方式继承，父类中a2为保护变量，在子类中则私有，类的内部可访问，外部不可以访问       
		//cout<<a3<<endl;    //以私有方式继承，父类中a3为私有变量，在子类中则为不可见，类的内部和外部均不可访问
	}
};

int main(){
    Child1 c1;
    Child2 c2;
    Child3 c3;
    // c1.a1;
    // c1.a2;
    // c1.a3;

    // c2.a1;
    // c2.a2;
    // c2.a3;

    // c3.a1;
    // c3.a2;
    // c3.a3;

    return 0;
}