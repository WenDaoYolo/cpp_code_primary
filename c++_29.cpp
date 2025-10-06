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

	//�޲ι���
	Student() {
		this->id = -1;
		this->name = NULL;
		cout << "Student()..." << endl;
	}

	//�вι��� - ���
	Student(int new_id,const char* new_name) {
		this->id = id;
		size_t len = strlen(new_name) + 1;
		this->name = new char[len];
		strcpy(this->name, new_name);
		cout << "Student(int new_id,char* new_name)..." << endl;
	}

	//�������� - ���
	Student(const Student& another) {
		this->id = another.id;
		size_t len = strlen(another.name) + 1;
		this->name = new char[len];
		strcpy(this->name, another.name);
		cout << "Student(const Student& another)..." << endl;
	}

	//����
	~Student() {
		if (this->name != NULL) {
			delete[] this->name;
			this->name = NULL;
			cout << "delete succ!" << endl;
		}
	}

	//�ȺŸ�ֵ������������
	Student& operator=(const Student& another) {

		//�ж�����ֵ	
		if (this->name == another.name)
		{
			cout << "Is myself" << endl;
			return *this;
		}

		//����ԭ���ڴ�
		if (this->name != NULL) {
			delete[] this->name;
			this->name = NULL;
			this->id = -1;
			cout << "clear succ!" << endl;
		}

		//���
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

//���Ʋ���������
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

