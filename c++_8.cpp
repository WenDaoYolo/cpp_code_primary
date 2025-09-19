#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#if 0
class Date {
	int year;                     //默认请款下控制访问权限为private
	int date;
public:
	int GetYear() {
		return year;              //在内部通过接口方法将值返回
	}
	void SetYear(int new_year) {
		year = new_year;            //在外部传参，在内部修改
	}
};

int main() {
	Date d;
	d.SetYear(2005);
	cout << d.GetYear() << endl;

	return 0;
}
#endif

#if 0
class Dog {
public:
	char name[20];
	char* food;
};

void eat(char dog[], const char* food) {
	cout << dog << "吃" << food << endl;
}

int main() {
	Dog d;
	strcpy(d.name, "狗");
	eat(d.name, "翔");

	return 0;
}

#endif

#if 0
class Dog {
public:
	char name[20];
	char* food;

	void eat(const char* food) {
		cout << name << "吃" << food << endl;
	}
};

int main() {
	Dog d;
	strcpy(d.name, "狗");
	d.eat("翔");                  //狗.eat(翔)

	return 0;
}

#endif

#if 0
#define PI 3.14

double CircleLength(double r){
	double result = 2 * PI * r;
	return result;
}

double CircleArea(double r) {
	double result = PI * r * r;
	return result;
}

int main() {
	double r;
	cout << "Please input the r:" << endl;
	cin >> r;
	cout << "圆的面积是" << CircleArea(r) << endl;
	cout << "圆的周长是" << CircleLength(r) << endl;
}

#endif 0

#if 0
#define PI 3.14

class Circle {
public:

	void InputTheR() {
		cout << "Please input the r:" << endl;
		cin >> r;
	}

	double area() {
		double area = PI * r * r;
		cout << "圆的面积:" <<area<< endl;
		return area;
	}

	double length() {
		double length = 2 * PI * r;
		cout << "圆的周长:" << length << endl;
		return length;
	}

private:
	double r;
};

int main() {
	Circle c;
	c.InputTheR();
	c.area();
	c.length();

	return 0;
}
#endif 
