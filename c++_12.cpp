#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;

#if 0
class Rectangle {
private:
	int UpRightX;
	int UpRightY;
	int DownLeftX;
	int DownLeftY;
public:
	void SetURXY(int new_x, int new_y) {
		UpRightX = new_x;
		UpRightY = new_y;
	}

	void SetDLXY(int new_x, int new_y) {
		DownLeftX = new_x;
		DownLeftY = new_y;
	}

	int GetRectArea() {
		int result = (UpRightX - DownLeftX) * (UpRightY - DownLeftY);
		return result;
	}
};

int main() {
	Rectangle R;
	R.SetURXY(4, 4);
	R.SetDLXY(1, 2);
	cout << "矩形的面积是:" << R.GetRectArea() << endl;

	return 0;
}

#endif


#if 0
class Tree {
private:
	int ages;
public:
	void grow(int years) {
		ages += years;
	}

	void SetAges(int new_ages) {
		ages = new_ages;
	}

	int GetAges() {
		return ages;
	}

	void age() {
		cout << "tree-ages：" << ages << endl;
	}
};

int main() {
	Tree T;
	T.SetAges(22);
	T.grow(44);
	T.grow(33);
	T.age();

	return 0;
}

#endif