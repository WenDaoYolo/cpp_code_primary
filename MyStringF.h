#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
    int len;
    char *space;

public:
    MyString();
    MyString(const char *str);
    MyString(const MyString &another);
    ~MyString();

    MyString operator+(MyString &another);
    char &operator[](int index);
    MyString &operator=(MyString &another);
    bool operator==(MyString &another);
    bool operator!=(MyString &another);

    friend ostream &operator<<(ostream &os, const MyString &str);
    friend istream &operator>>(istream &os, MyString &str);
};