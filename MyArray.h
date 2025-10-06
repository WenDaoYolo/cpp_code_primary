#pragma once
#include<iostream>
using namespace std;

class MyArray {
private:
	int len;
	int* space;
public:
	MyArray();                                                                //�޲ι���
	MyArray(int new_len);                                                     //�вι���
	MyArray(const MyArray& array);                                            //��������
	~MyArray();                                                               //����

	int GetLen() const;                                                       //��ȡ����
	int GetData(int index)const;                                              //��ȡԪ��ֵ
	void SetData(int index, int data);                                        //����Ԫ��ֵ
	void PrintData();                                                         //��ӡ����

	MyArray& operator=(MyArray& another);                                     //�ȺŸ�ֵ����������
	int& operator[](int index);                                               //�±�ȡֵ����������

	friend istream& operator>>(istream& os, MyArray& array);
	friend bool operator==(const MyArray& array1, const MyArray& array2);
	friend ostream& operator<<(ostream& os, const MyArray& array);
};

ostream& operator<<(ostream& os, const MyArray& array);                       //���ƶ��������������
istream& operator>>(istream& os, MyArray& array);                             //����д�������������
bool operator==(const MyArray& array1, const MyArray& array2);                //��Ȳ���������
bool operator!=(const MyArray& array1, const MyArray& array2);                //���Ȳ���������