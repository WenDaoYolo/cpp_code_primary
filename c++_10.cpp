#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

#if 0
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

	void InitPoint() {
		cout << "Point x,y:" << endl;
		cin >> x >> y;
	}

	void DisplayPoint() {
		cout << "Point:(" << x << "," << y << ")" << endl;
	}
};

class Circle {
private:
	int x;
	int y;
	int r;	
public:
	void InitCircle() {
		cout << "Circle x,y:" << endl;
		cin >> x >> y;
		cout << "Circle r:" << endl;
		cin >> r;
	}

	void DisplayCircle() {
		cout << "Circle center point:(" << x << "," << y << ")" << endl;
		cout << "Circle r:" <<r  << endl;
	}

	bool JudgePoint(Point &p) {
		if (sqrt(abs((x - p.GetX()) * (x - p.GetX()) + (y - p.GetY()) * (y - p.GetY()))) <= r)
			return true;
		else
			return false;
	}
};

int main() {
	Point p;
	Circle c;
	p.InitPoint();
	c.InitCircle();

	cout << "---------------------------" << endl;

	p.DisplayPoint();
	c.DisplayCircle();
	if (c.JudgePoint(p))
		cout << "Point(" << p.GetX() << "," << p.GetY() << ") is in Circle" << endl;
	else
		cout << "Point(" << p.GetX() << "," << p.GetY() << ") is not in Circle" << endl;
	return 0;
}

#endif 

