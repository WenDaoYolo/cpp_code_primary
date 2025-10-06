#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#if 0
class Student {
private:
	int id;
	char* name;
public:
	int GetId() {
		return this->id;
	}
	char* GetName() {
		return this->name;
	}

	//无参构造
	Student() {
		this->id = -1;
		this->name = NULL;
		cout << "Student()..." << endl;
	}

	//有参构造 - 深拷贝
	Student(int new_id,const char* new_name) {
		this->id = id;
		size_t len = strlen(new_name) + 1;
		this->name = new char[len];
		strcpy(this->name, new_name);
		cout << "Student(int new_id,char* new_name)..." << endl;
	}

	//拷贝构造 - 深拷贝
	Student(const Student& another) {
		this->id = another.id;
		size_t len = strlen(another.name) + 1;
		this->name = new char[len];
		strcpy(this->name, another.name);
		cout << "Student(const Student& another)..." << endl;
	}

	//析构
	~Student() {
		if (this->name != NULL) {
			delete[] this->name;
			this->name = NULL;
			cout << "delete succ!" << endl;
		}
	}

	//等号赋值操作符的重载
	Student& operator=(const Student& another) {

		//判断自身赋值	
		if (this->name == another.name)
		{
			cout << "Is myself" << endl;
			return *this;
		}

		//回收原先内存
		if (this->name != NULL) {
			delete[] this->name;
			this->name = NULL;
			this->id = -1;
			cout << "clear succ!" << endl;
		}

		//深拷贝
		if (this->name == NULL) {
			this->id = another.id;
			size_t len = strlen(another.name) + 1;
			this->name = new char[len];
			strcpy(this->name, another.name);
			cout << "Student operator=(const Student& another)..." << endl;
		}
		return *this;
	}

};

//左移操作符重载
ostream& operator<<(ostream& os, Student& s1) {
	os << "name:" << s1.GetName() << " id:" << s1.GetId() << endl;
	return os;
}

int main() {
	Student s1(20, "zhang3");
	Student s2(30,"li4");
	Student s3(s1);
	s3 = s3;
	s3 = s1;

	cout << s1 << s2 << s3;
	return 0;
}

#endif

