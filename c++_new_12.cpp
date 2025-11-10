#include<iostream>
#include<cstring>
using namespace std;

//多态的复习
class Student{
    public:
        string name;
        Student(const char* name)
        {  
            this->name=name;
        }

        virtual void GotoClass()
        {
            cout<<"学生走进了教室"<<endl;
        }
};

class Level1:public Student
{   
    public:
        Level1(const char* name):Student(name)
        {
            
        }

        void GotoClass(){
            cout<<this->name<<"走进了高一(3)班教室"<<endl;
        }
};

class Level2:public Student
{
    public:
        Level2(const char* name):Student(name)
        {
            
        }

        void GotoClass(){
            cout<<this->name<<"走进了高二(3)班教室"<<endl;
        }
};

class Level3:public Student
{
    public:
        Level3(const char* name):Student(name)
        {

        }

        void GotoClass(){
            cout<<this->name<<"走进了高三(3)班教室"<<endl;
        }
};

void TakingClass(Student* s){
    s->GotoClass();
}

int main(){
    Level1* s1=new Level1("高一学生小王");
    Level2* s2=new Level2("高二学生小红");
    Level3* s3=new Level3("高三学生小李");

    TakingClass(s1);
    TakingClass(s2);
    TakingClass(s3);

    delete s1;
    delete s2;
    delete s3;

//1.必须封装和继承
//2.父类定义多态的虚函数,子类重写虚函数
//3.执行函数中,父类指针或引用指向子类对象

    return 0;
}