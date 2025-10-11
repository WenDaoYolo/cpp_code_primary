#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
    int len;

public:
    char *str;

    MyString()
    {
        int len = 0;
        this->str = new char;
        strcpy(this->str, "");
    }

    MyString(const char *str)
    {
        if (str == NULL)
        {
            int len = 0;
            this->str = new char;
            strcpy(this->str, "");
            return;
        }
        int len = strlen(str);
        this->len = len;
        this->str = new char[this->len + 1];
        strcpy(this->str, str);
    }

    MyString(const MyString &s)
    {
        if (s.str == NULL)
        {
            int len = 0;
            this->str = new char;
            strcpy(this->str, "");
            return;
        }
        this->len = s.len;
        this->str = new char[this->len + 1];
        strcpy(this->str, s.str);
    }

    ~MyString()
    {
        if (this->str != NULL)
        {
            delete[] this->str;
            this->str = NULL;
            cout << "~MyString()..." << endl;
        }
    }

    char &operator[](int index)
    {
        return this->str[index];
    }

    MyString &operator=(const MyString &another)
    {
        if (this == &another)
        {
            return *this;
        }

        if (this->str != NULL)
        {
            delete[] this->str;
            this->str = NULL;
        }

        if (this->str == NULL)
        {
            this->len = another.len;
            this->str = new char[this->len + 1];
            strcpy(this->str, another.str);
        }
        return *this;
    }

    // !=,==,+;
    MyString operator+(MyString another)
    {
        MyString tmp;
        tmp.len = this->len + another.len;
        tmp.str = new char[tmp.len + 1];
        strcpy(tmp.str, this->str);
        strcat(tmp.str, another.str);
        return tmp;
    }

    bool operator==(MyString &another)
    {
        if (this->len != another.len)
            return false;
        if (strcmp(this->str, another.str))
            return false;
        return true;
    }

    bool operator!=(MyString &another)
    {
        if (this != &another)
            return true;
        else
            return false;
    }

    friend ostream &operator<<(ostream &os, MyString s);
    friend istream &operator>>(istream &os, MyString s);
};

ostream &operator<<(ostream &os, MyString s)
{
    os << s.str;
    return os;
}

istream &operator>>(istream &os, MyString s)
{
    if (s.str != NULL)
    {
        delete s.str;
        s.str = NULL;
        s.len = 0;
        cout << "free!" << endl;
    }

    if (s.str == NULL)
    {
        cout << "Please input>";
        char tmp[4096] = {0};
        cin >> tmp;
        s.len = strlen(tmp);
        s.str = new char[s.len + 1];
        strcpy(s.str, tmp);
    }

    return os;
}

int main()
{
    MyString str1("Jcak");
    MyString str2;
    MyString str3("yes");
    cin >> str3;
    str1[0] = 'U';
    str2 = str1;
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    if (str1 == str2)
        cout << "==" << endl;
    if (str1 != str2)
        cout << "!=" << endl;

    cout << str1 + str2 << endl;
    return 0;
}