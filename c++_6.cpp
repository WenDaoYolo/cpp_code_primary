#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>

using namespace std;

#if 0

class People {
public:
	char name[20];
	char job[20];
	int age;
	void run() {
		cout << "在跑步" << endl;
	}
	void eat() {
		cout << "在吃饭" << endl;
	}

private:
	void test() {
		cout << "hello" << endl;
	}
};

//类与结构体的相似与不同

//学生，男生，女生，老板等都是人，可以创建一个人的类
//他们都会跑步，吃饭，睡觉等，于是可以在类中创建他们的函数方法


int main() {
	People student_1;
	strcpy(student_1.name, "小明");
	strcpy(student_1.job, "学生");

	People boss_1;
	strcpy(boss_1.name, "小王");
	strcpy(boss_1.job, "老板");

	cout <<student_1.job<< student_1.name;
	student_1.eat();              //学生在吃饭
	cout << endl;

	cout <<boss_1.job<< boss_1.name;
	boss_1.run();                 //老板在跑步
	cout << endl;

	return 0;
}

#endif

#if 0
class People {         //创建人类

	//控制访问权限，有public和private两种
	//public下的成员变量和方法可以在类的内部和外部访问和使用
	//private下的成员变量和方法只能在类的内部访问和使用
	//{}内称为类的内部，以外均为类的外部
public:
	//定义成员属性
	char name[20];
	int age;

	//定义成员方法
	void run() {
		cout << "在跑步" << endl;
	}
	void sleep() {
		cout << "在睡觉" << endl;
	}

private:
	char password[20];
};


class Animal {          //创建动物类
public:
	char kind[20];
	char color[20];

	void run() {
		cout << color << "的" << kind << "在跑步" << endl;        //该类的方法使用该类的成员属性
	}
	void sleep() {
		cout << color << "的" << kind << "在睡觉" << endl;
	}
};

int main() {
	Animal chicken;                  //创建动物类对象鸡
	Animal dog;                      //创建动物类对象狗

	strcpy(chicken.kind, "chicken");  //该对象的种类为鸡 
	strcpy(chicken.color, "yellow");  //该对象的颜色为黄色

	chicken.run();                    //动物类的对象鸡调用动物类的方法，鸡在跑步
	chicken.sleep();                  //鸡在睡觉

	return 0;
}

#endif 