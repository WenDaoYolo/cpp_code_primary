#pragma once
#include<iostream>
using namespace std;

class MyArray {
private:
	int len;
	int* space;
public:
	MyArray();                                                                //无参构造
	MyArray(int new_len);                                                     //有参构造
	MyArray(const MyArray& array);                                            //拷贝构造
	~MyArray();                                                               //析构

	int GetLen() const;                                                       //获取长度
	int GetData(int index)const;                                              //获取元素值
	void SetData(int index, int data);                                        //设置元素值
	void PrintData();                                                         //打印数组

	MyArray& operator=(MyArray& another);                                     //等号赋值操作符重载
	int& operator[](int index);                                               //下标取值操作符重载

	friend istream& operator>>(istream& os, MyArray& array);
	friend bool operator==(const MyArray& array1, const MyArray& array2);
	friend ostream& operator<<(ostream& os, const MyArray& array);
};

ostream& operator<<(ostream& os, const MyArray& array);                       //左移读输出操作符重载
istream& operator>>(istream& os, MyArray& array);                             //右移写输入操作符重载
bool operator==(const MyArray& array1, const MyArray& array2);                //相等操作符重载
bool operator!=(const MyArray& array1, const MyArray& array2);                //不等操作符重载