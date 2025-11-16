#include<iostream>
using namespace std;

class test1{
	private:
		int a;                         //4个字节
	public:
		void func(){                   //函数方法不占用内存
			cout<<"func..."<<endl;
		}
};

class test2{
	private:
		int a;                         //4个字节
	public:
		void func(){                   //函数方法不占用内存
			cout<<"func..."<<endl;
		}
};

class test3{                         //4个字节
	public:
		virtual void func(){         //定义虚函数，则同会存在vptr指针，指针大小与操作系统位数有关(例如64位，指针大小为8个字节)
			cout<<"func..."<<endl;
		}
    private:
		int a;
};

int main(){
	cout<<"test1:"<<sizeof(test1)<<endl;
	cout<<"test2:"<<sizeof(test2)<<endl;
	cout<<"test3:"<<sizeof(test3)<<endl;
    //16  为什么不是12? 原因：类和结构体一样遵守内存对齐的规则，向最大成员对齐(8个字节)
    //     c++中类和结构体本质上就是同一种东西，所以类也遵守内存的对齐规则(详见c语言篇)

	return 0;
}