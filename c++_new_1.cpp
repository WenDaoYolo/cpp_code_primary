#include<iostream>
#include<cstring>
using namespace std;

class student{
	private:
		int id;
		string name;
	public:
		student(int id,string name){
			this->id=id;
			this->name=name;
		}
		void PrintS(){
			cout<<"id:"<<this->id<<" name:"<<this->name<<endl;
		}
};

class student2{
	private:
		int id;
		string name;
	public:
		student2(int id,string name){
			this->id=id;
			this->name=name;
		}
		void PrintS(){
			cout<<"id:"<<this->id<<" name:"<<this->name<<endl;
		}
};

//采用继承的方式，直接进行继承减少代码冗余，并且在代码维护时，父类的代码修改后无需再修改相关的子类代码
class student3:public student
{
	private:
		int score;
	public:
		student3(int id,string name,int score):student(id,name)     //调用父类的构造函数初始化原有成员属性
		{
			this->score=score;
		}
		
		void PrintS2(){
			PrintS();                                      //调用父类的函数输出原有成员属性
			cout<<"score:"<<this->score<<endl;
		}
};

int main(){
	student3 s3(3,"zhang3",59);
	s3.PrintS2();

	return 0;
}