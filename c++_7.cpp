#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


#if 0
class Animal {

public:
	char kind[20];
	char color[20];
	void Produce() {
		cout << "我是小" << color << kind;
}
	void run() {
		cout << "我在跑步" << endl;
	}
	void sleep() {
		cout << "我在睡觉" << endl;
	}
};

int main() {
	Animal chicken;
	strcpy(chicken.kind, "鸡");
	strcpy(chicken.color, "黄");
	chicken.Produce();
	chicken.run();

	putchar('\n');

	Animal dog;
	strcpy(dog.kind, "狗");
	strcpy(dog.color, "绿");
	dog.Produce();
	dog.sleep();

	return 0;
}

#endif

//
//struct Date {
//	int year;
//	int month;
//	int date;
//};


#if 0
class Date {
public:
	void InputDate() {
		cout << "year,month,date" << endl;
		cin >>year;
		cin >>month;
		cin >>date;
	}

	void IsHeapYear() {
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
			cout << year << "年" << month << "月" << date << "日" << "是闰年" << endl;
		else
			cout << year << "年" << month << "月" << date << "日" << "不是是闰年" << endl;
	}

private:
	int year;
	int month;
	int date;
};

#endif 

//
//void InputDate(Date* D) {
//	cout << "year,month,date" << endl;
//	cin >> D->year;
//	cin >> D->month;
//	cin >> D->date;
//}

//void IsHeapYear(Date* D) {
//	if ((D->year % 400 == 0) || (D->year % 4 == 0 && D->year % 100 != 0))
//		cout << D->year<<"年" << D->month << "月" << D->date << "日" << "是闰年" << endl;
//	else
//		cout << D->year<<"年" << D->month << "月" << D->date << "日" << "不是是闰年" << endl;
//}


#if 0
int main() {
	Date D;
	D.InputDate();
	D.IsHeapYear();
	

	return 0;
}

#endif

