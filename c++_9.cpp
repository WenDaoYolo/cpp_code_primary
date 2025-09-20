#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

#if 0

using namespace std;

class Cube {
private:
	int length;
	int width;
	int height;

public:
	int GetLength() {
		return length;
	}

	int GetWidth() {
		return width;
	}

	int GetHeight() {
		return height;
	}

	void SetLength(int new_length) {
		length = new_length;
	}

	void SetHeight(int new_height) {
		height = new_height;
	}

	void SetWidth(int new_width) {
		width = new_width;
	}

	int GetCubeValue() {
		int result = length * height * width;
		return result;
	}

	int GetCubeArea() {
		int result = (length * width + length * height + width * height) * 2;
		return result;
	}

	bool IsCubeValue(int CubeX) {
		if (length * height * width == CubeX)
			return true;
		else
			return false;
	}
};

int main() {
	Cube A;
	Cube B;
	A.SetLength(10);
	A.SetWidth(20);
	A.SetHeight(30);

	B.SetLength(1000);
	B.SetWidth(2);
	B.SetHeight(3);

	int A_value = A.GetCubeValue();
	int B_value = B.GetCubeValue();

	cout << "立方体A的长宽高分别为:" << A.GetLength() << "," << A.GetWidth() << "," << A.GetHeight() << "," << endl;
	cout << "立方体A的面积和体积分别为" << A.GetCubeArea() << "," << A.GetCubeValue() << endl;
	cout << "立方体B的长宽高分别为:" << B.GetLength() << "," << B.GetWidth() << "," << B.GetHeight() << "," << endl;
	cout << "立方体B的面积和体积分别为" << B.GetCubeArea() << "," << B.GetCubeValue() << endl;

	if (A.IsCubeValue(B_value))            //A调用判断函数，看是否和B相等
		cout << "两个立方体相等" << endl;
	else
		cout << "两个立方体不相等" << endl;

	return 0;
}

#endif