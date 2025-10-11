#include <iostream>
#include <cstring>
using namespace std;

class student
{
private:
    int id;
    char *name;

public:
    student();
    student(int id, char *name);
    ~student();
    void PrintS();

    friend ostream &operator<<(ostream &os, student &s);
};

ostream &operator<<(ostream &os, student &s)
{
    os << "id:" << s.id << " name:" << s.name;
    return os;
}

void student::PrintS()
{
    cout << "id:" << this->id << " name:" << this->name << endl;
}

student::student()
{
    id = 0;
    this->name = new char[5];
    strcpy(name, "jack");
}

student::student(int id, char *name)
{
    this->id = id;
    size_t len = strlen(name);
    this->name = new char[len + 1];
    strcpy(this->name, name);
}

student::~student()
{
    if (this->name != NULL)
    {
        delete this->name;
        this->name = NULL;
        cout << "~student()..." << endl;
    }
}

class Auto_ptr
{
private:
    student *ptr;

public:
    Auto_ptr(student *ptr)
    {
        this->ptr = ptr;
    }

    ~Auto_ptr()
    {
        if (this->ptr != NULL)
        {
            delete this->ptr;
            this->ptr = NULL;
            cout << "~Auto_ptr()..." << endl;
        }
    }

    student *operator->()
    {
        return this->ptr;
    }

    student &operator*()
    {
        return *(this->ptr);
    }
};

int main()
{
    Auto_ptr s1(new student);
    s1->PrintS();
    (*s1).PrintS();

    return 0;
}