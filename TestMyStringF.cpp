#include "MyStringF.h"

int main()
{
    MyString s1("Hello ");
    MyString s2("world!");
    MyString s3;
    MyString s4;

    s2[0] = 'W';
    cin >> s3;
    s4 = s3;

    cout << "------------------" << endl;
    cout << s1 + s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;

    cout << "------------------" << endl;
    if (s4 != s1)
        cout << "!=" << endl;
    if (s4 == s3)
        cout << "==" << endl;

    return 0;
}