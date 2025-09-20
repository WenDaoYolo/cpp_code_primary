#define _CRT_SECURE_NO_WARNINGS 1


#if 0
#include<iostream>
using namespace std;

class Point {
private:
	int x;
	int y;
public:
	int GetX() {
		return x;
	}

	int GetY() {
		return y;
	}

	void SetX(int new_x) {
		x = new_x;
	}

	void SetY(int new_y) {
		y = new_y;
	}

	double GetValue(Point& another) {
		double result = sqrt((x - another.x) * (x - another.x) + ((y - another.y)) * (y - another.y));
		return result;
	}
};

class Circle {
private:
	int x;
	int y;
	int r;
public:
	void SetXYR(int new_x, int new_y, int new_r) {
		x = new_x;
		y = new_y;
		r = new_r;
	}

	int GetR() {
		return r;
	}

	int GetX() {
		return x;
	}

	int GetY() {
		return y;
	}

};

int main() {
	Circle c1;
	Circle c2;
	Point p1;
	Point p2;

	c1.SetXYR(1, 1, 1);
	c2.SetXYR(4, 1, 1);

	p1.SetX(c1.GetX());
	p1.SetY(c1.GetY());
	p2.SetX(c2.GetX());
	p2.SetY(c2.GetY());

	double d = p1.GetValue(p2);
	if (c1.GetR() + c2.GetR() < d)
		cout << "两个圆不相交" << endl;
	else
		cout << "两个圆相交" << endl;
}

#endif 