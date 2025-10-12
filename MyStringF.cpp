#include "MyStringF.h"

MyString::MyString()
{
    this->len = 0;
    this->space = new char;
    strcpy(this->space, "");
}

MyString::MyString(const char *str)
{
    if (str == NULL)
    {
        this->len = 0;
        this->space = new char;
        strcpy(this->space, "");
        return;
    }
    this->len = strlen(str);
    this->space = new char[this->len + 1];
    strcpy(this->space, str);
}

MyString::MyString(const MyString &another)
{
    if (&another == NULL)
    {
        this->len = 0;
        this->space = new char;
        strcpy(this->space, "");
        return;
    }
    this->len = another.len;
    this->space = new char[this->len + 1];
    strcpy(this->space, another.space);
}

MyString::~MyString()
{
    if (this->space != NULL)
    {
        delete[] this->space;
        this->space = NULL;
        this->len = 0;
        // cout << "~MyString()..." << endl;
    }
}

ostream &operator<<(ostream &os, const MyString &str)
{
    cout << str.space;
    return os;
}

istream &operator>>(istream &os, MyString &str)
{
    if (str.space != NULL)
    {
        delete str.space;
        cout << "free str!" << endl;
    }

    char tmp[4096] = {0};
    cout << "Please input>";
    cin >> tmp;
    str.len = strlen(tmp);
    str.space = new char[str.len + 1];
    strcpy(str.space, tmp);
    return os;
}

MyString MyString::operator+(MyString &another)
{
    MyString tmp;
    tmp.len = this->len + another.len;
    tmp.space = new char[tmp.len + 1];
    strcpy(tmp.space, this->space);
    strcat(tmp.space, another.space);
    return tmp;
}

char &MyString::operator[](int index)
{
    return this->space[index];
}

MyString &MyString::operator=(MyString &another)
{
    if (this == &another)
    {
        return *this;
    }

    if (this->space != NULL)
    {
        delete this->space;
        this->space = NULL;
        this->len = 0;
    }

    if (this->space == NULL)
    {
        this->len = another.len;
        this->space = new char[this->len + 1];
        strcpy(this->space, another.space);
    }

    return *this;
}

bool MyString::operator==(MyString &another)
{
    if (this->len != another.len)
        return false;
    if (strcmp(this->space, another.space))
        return false;
    return true;
}

bool MyString::operator!=(MyString &another)
{
    if (this != &another)
        return true;
    else
        return false;
}