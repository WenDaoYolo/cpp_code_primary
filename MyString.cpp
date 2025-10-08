//#include "MyString.h"
//
//MyString::MyString() {
//	this->len = 0;
//	this->str = NULL;
//	cout << "MyString()..." << endl;
//}
//
//MyString::MyString(const char* str) {
//	if (str == NULL) {
//		this->len = 0;
//		this->str = new char[this->len + 1];
//		strcpy(this->str,"");
//	}
//	else
//	{
//		this->len = (int)strlen(str);
//		this->str = new char[this->len + 1];
//		strcpy(this->str,str);
//	}
//	cout << "MyString(const char* str)..." << endl;
//}
//
//MyString::MyString(const MyString& another) {
//	this->len = another.len;
//	if (another.len == NULL) {
//		this->len = 0;
//		this->str = new char[this->len + 1];
//		strcpy(this->str, "");
//	}
//	else 
//	{
//		this->len = another.len;
//		this->str = new char[this->len + 1];
//		strcpy(this->str,another.str);
//	}
//	cout << "MyString(const MyString& another)..." << endl;
//}
//
//MyString::~MyString() {
//	if (this->str != NULL)
//		delete this->str;
//	cout << "~MyString()..." << endl;
//}
//
//ostream& operator<<(ostream& os, MyString s) {
//	os << s.str << endl;
//	return os;
//}
//
////分析：新输入的字符串可能比原来的字符串长，所以要将原来的字符串释放掉
////创建一个新的字符串进行输入，并且要限定该字符串的长度
//istream& operator>>(istream& os, MyString& s) {  
//	if (s.str != NULL)
//		delete s.str;
//
//	char temp[4096] = {0};
//	os >> temp;
//	s.len = (int)strlen(temp);
//	s.str = new char[s.len + 1];
//	strcpy(s.str,temp);
//	return os;
//}
//
//
////+没有赋值操作，所以应该返回匿名对象
//MyString MyString::operator+(MyString another) {
//	int len = this->len + another.len;
//	MyString temp;
//	temp.len = len;
//	temp.str = new char[temp.len +1];
//	strcpy(temp.str,this->str);
//	strcat(temp.str,another.str);
//	
//	return temp;
//}
//
//MyString& MyString::operator=(MyString another) {
//	if (this == &another)
//		return *this;
//	if (this->str != NULL)
//	{
//		delete[] this->str;
//		this->len = 0;
//	}
//
//	if (this->len == 0) {
//		this->len = another.len;
//		this->str = new char[this->len + 1];
//		strcpy(this->str,another.str);
//	}
//	
//	cout << "operator=(MyString another)..." << endl;
//	return *this;
//}
//
//char& MyString::operator[](int index) {
//	return this->str[index];
//}
//
//bool MyString::operator==(MyString another) {
//	if (this->len != another.len)
//		return false;
//	for (int i = 0; i < this->len; i++)
//	{
//		if (this->str[i] != another.str[i])
//			return false;
//	}
//	return true;
//}
//
//bool MyString::operator!=(MyString another) {
//	if (this != &another)
//		return true;
//	else
//		return false;
//}