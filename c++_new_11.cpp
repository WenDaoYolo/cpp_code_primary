#include<iostream>
#include<cstring>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Student{
	public:
		string name;
		Student(const char* name){
			this->name=name;
		}
		
		virtual void GotoClass()                  //由于兼容性原则，父类指针可以指向子类对象      
		{                                         //若不定义虚函数，通过父类指针只能调用父类的方法而非子类的方法
			cout<<"学生走进了教室"<<endl;
		}
};

class Student1:public Student
{
	public:
        Student1(const char* name):Student(name)
        {
			
		}

		void GotoClass()
		{
			cout<<this->name<<"走进了高一(3)班教室"<<endl;
		}
};

class Student2:public Student
{
	public:
        Student2(const char* name):Student(name)
        {
			
		}

		void GotoClass()
		{
			cout<<this->name<<"走进了高二(3)班教室"<<endl;
		}
};

class Student3:public Student
{
	public:	
        Student3(const char* name):Student(name)
        {
			
		}

		void GotoClass()
		{
			cout<<this->name<<"走进了高三(3)班教室"<<endl;
		}
};

//执行多态的全局函数
void TakingClass(Student* s)                    //兼容性原则，父类指针可以指向子类对象，定义父类指针就可以接收整个家族的对象(引用同理)
{   
	s->GotoClass();                             //若不定义虚函数，编译器会做一个安全转换，通过父类指针只能调用父类的方法，而非子类的方法
}

int main(){
	Student1* s1=new Student1("高一学生小红");
	Student2* s2=new Student2("高二学生小王");
	Student3* s3=new Student3("高三学生小李");
	
	TakingClass(s1);
	TakingClass(s2);
	TakingClass(s3);	

	delete s1;
	delete s2;
	delete s3;
	
	return 0;
}