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
    student(int id, const char *name);
    student(const student &another);
    ~student();

    void PrintS();
};

class aptr
{
private:
    student *ptr;

public:
    aptr(student *ptr);
    ~aptr();

    student *operator->();
    student &operator*();
};