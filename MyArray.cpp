#include "MyArray.h"

MyArray::MyArray() {
	this->len = 0;
	this->space = NULL;
	cout << "MyArray()..." << endl;
}

MyArray::MyArray(int new_len) {
	if (new_len < 0)
		return;
	this->len = new_len;
	this->space = new int[this->len];
	cout << "MyArray(int new_len)..." << endl;
}

MyArray::MyArray(const MyArray& array) {
	this->len = array.len;
	this->space = new int[len];
	for (int i = 0; i < this->len; i++) {
		this->space[i] = array.space[i];
	}
	cout << "MyArray(const MyArray& array)..." << endl;
}

MyArray::~MyArray() {
	if (this->space != NULL)
	{
		delete[] this->space;
		cout << "~MyArray()..." << endl;
	}
}

int MyArray::GetLen() const
{
	return this->len;
}
int MyArray::GetData(int index) const
{
	return this->space[index];
}

void MyArray::SetData(int index, int data) {
	this->space[index] = data;
}

void MyArray::PrintData() {
	for (int i = 0; i < this->len; i++)
		cout << this->space[i];
	cout << endl;
}

MyArray& MyArray::operator=(MyArray& another) {
	
	if (this == &another) {
		cout << "IsMySelf!" << endl;
		return *this;
	}

	if (this->space != NULL) {
		delete[] this->space;
		this->space = NULL;
		this->len = 0;
		cout << "clear succ!" << endl;
	}

	if (this->space == NULL) {
		this->len = another.len;
		this->space = new int[this->len];
		for (int i = 0; i < this->len; i++) {
			this->space[i] = another.space[i];
		}
	}
	return *this;
}

int& MyArray::operator[](int index) {
	return this->space[index];
}

ostream& operator<<(ostream& os, const MyArray& array){
	for (int i = 0; i < array.GetLen(); i++)
		cout << array.space[i]<<" ";
	cout << endl;
	return os;
}

istream& operator>>(istream& os, MyArray& array){
	cout << "ÇëÊäÈë" << array.GetLen() << "¸öÊý:" << endl;
	for (int i = 0; i < array.GetLen(); i++)
		cin >> array.space[i];
	return os;
}

bool operator==(const MyArray& array1, const MyArray& array2) {
	if (array1.GetLen() != array2.GetLen())
		return false;
	for (int i = 0; i < array1.GetLen(); i++)
	{
		if (array1.space[i] != array2.space[i])
			return false;
	}
	return true;
}

bool operator!=(const MyArray& array1, const MyArray& array2) {
	if (&array1 != &array2)
		return true;
	return false;
}
