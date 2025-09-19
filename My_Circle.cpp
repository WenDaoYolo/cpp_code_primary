#include "My_Circle.h"

//已经对函数进行了作用域的限定,所以在函数内可以直接访问类的内部
double My_Circle::GetR() {       
	return r;
}

void My_Circle::SetR(double new_r) {
	r = new_r;
}

double My_Circle::GetCircleArea() {
	double result = r * r * 3.14;
	return result;
}

double My_Circle::GetCircleLength() {
	double result = 2 * 3.14 * r;
	return result;
}
