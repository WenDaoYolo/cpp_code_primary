#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include "MyArray.h"
using namespace std;


int main() {
	MyArray array1;
	MyArray array2(10);
	cin >> array2;
	array1 = array2;
	MyArray array3(array2);

	cout <<"array2:" << array2;
	cout << "------------------" << endl;
	array1[0] = 9999;
	cout<<"array1:" << array1;
	cout << "------------------" << endl;
	cout <<"array3:" << array3;

	if (array2 == array3)
		cout << "array2和array3相等" << endl;
	else
		cout << "array2和array3不相等" << endl;

	if (array1 != array2)
		cout << "array2和array3不相等" << endl;
	else
		cout << "array2和array3相等" << endl;

	return 0;
}