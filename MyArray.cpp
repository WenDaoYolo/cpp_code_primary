//#include "MyArray.h"
//
//MyArray::MyArray() {
//	this->len = 0;
//	this->space = NULL;
//	cout << "create array succ!" << endl;
//}
//
//MyArray::MyArray(int len) {
//	if (len <= 0)
//	{
//		len = 0;
//		return;
//	}
//	else 
//	{
//		this->len = len;
//		this->space = new int[this->len];
//		cout << "create array succ!" << endl;
//	}
//}
//
//MyArray::MyArray(const MyArray& another) {           //涉及到指针的拷贝，需要深拷贝
//	this->len = another.len;
//	this->space = new int[this->len];
//	for (int i = 0; i < this->len; i++)
//		(this->space)[i] = *((another.space) + i);   //下标法和指针运算法
//	cout << "create new array succ!" << endl;
//}
//
//int MyArray::GetLen() {
//	return this->len;
//}
//
//void MyArray::SetData(int index, int data) {
//	(this->space)[index] = data;
//}
//
//int MyArray::GetData(int index) {
//	return (this->space)[index];
//}
//
//MyArray::~MyArray() {
//	if (this->space != NULL) {
//		delete[] this->space;
//		cout << "delete succ!" << endl;
//	}
//}
