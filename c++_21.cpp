#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//
//class Student {
//private:
//	int m_id;
//	double m_score;
//	static int m_count;
//	static double m_total_score;
//public:
//	Student(int n_id, double n_score) {
//		m_id = n_id;
//		m_score = n_score;
//		m_count++;
//		m_total_score += n_score;
//	};
//
//	~Student() {
//		m_count--;
//	}
//
//	int static GetCount() {
//		return m_count;
//	}
//
//	double static GetTotalScore() {
//		return m_total_score;
//	}
//
//	double static GetAvg() {
//		return Student::GetTotalScore() / Student::GetCount();
//	}
//
//};
//
//int Student::m_count = 0;
//double Student::m_total_score = 0.0;
//
//int main() {
//	Student s1(1, 80);
//	Student s2(2, 90);
//	Student s3(3, 100);
//
//	cout << "学生总人数:" << Student::GetCount() << endl;
//	cout << "平均分数:" << Student::GetAvg() << endl;
//	return 0;
//}


//struct test1 {
//	int a;               //4
//	int b;               //4
//	static int c;
//}t1;
//
//class test2 {
//private:
//	int a;              //4
//	int b;              //4
//	int c;              //4
//	static int d;
//public:
//	int testcc(){
//		cout << " yes" << endl;
//	}
//}tt1;
//
//int main() {
//	cout << "struct:" << sizeof(t1) << endl;
//	cout << "class :" << sizeof(tt1) << endl;
//
//	return 0;
//}