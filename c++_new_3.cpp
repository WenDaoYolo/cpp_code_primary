#include<iostream>
using namespace std;

class Student{
    private:
        int id;
        string name;
    public:
        Student(int id,string name){
                this->id=id;
                this->name=name;
        };

        void PrintS(){
            cout<<"id:"<<this->id<<" name:"<<this->name<<endl;
        }
};

class Student1:public Student
{   
    private:
        int score;
    public:
        Student1(int id,string name,int score):Student(id,name)
        {   
            this->score=score;
        }

        void PrintS(){
            Student::PrintS();
            cout<<"score:"<<this->score<<endl;
        }
};

//public继承         public->public,protected->protected,private->不可见
//protected继承      public->protected,protected->protected,private->不可见
//private继承        public->private,protected->private,private->不可见

int main(){
    Student1 s1(3,"zhang3",78);
    s1.PrintS();
    
    return 0;
}
