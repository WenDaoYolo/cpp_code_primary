#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;

#if 0
class Sqr {
private:
	int a;
public:
	Sqr(int new_a) {
		this->a = new_a;
	}

	int operator()(int value) {                    //重载1
		return value * value;
	}

	int operator()(int value1, int value2) {        //重载2
		return value1 * value2;
	}
};

int main() {
	Sqr q1(111);              //此处的()为调用构造函数初始化
	int res1 = q1(10);        //此处的()为调用仿函数
	int res2 = q1(10, 20);    //此处的()为调用仿函数

	cout << "res1:" << res1 << ",res2:" << res2 << endl;
	return 0;
}

#endif

#if 0
#include<iostream>
using namespace std;

class test {
private:
    int a;
public:
    test() {
        cout << "调用了无参构造函数" << endl;
    }

    test(int a) {
        cout << "调用了有参构造函数" << endl;
        this->a = a;
    }

    ~test() {
        cout << "调用了析构函数" << endl;
    }

    void* operator new(size_t size) {       //unsigned int
        cout << "调用了new的重载" << endl;
        return malloc(size);
    }

    void* operator new[](size_t size) {     //unsigned int
        cout << "调用了new[]的重载" << endl;
        return malloc(size);
    }

    void operator delete(void* p) {
        if (p != NULL) {
            free(p);
            p = NULL;
            cout << "调用了delete重载" << endl;
        }
    }

    void operator delete[](void* p) {
        if (p != NULL) {
            free(p);
            p = NULL;
            cout << "调用了delete[]重载" << endl;
        }
    }
};

int main() {
    test* t1 = new test(5);      //底层调用-> t1.operator new(sizeof(int));
    test* t2 = new test[5];      //底层调用-> t1.operator new[](sizeof(test[5]));
    delete t1;
    delete[] t2;                 //底层调用-> t1.operator delete(t1);
    return 0;                    //底层调用-> t1.operator delete[](t2);
}
#endif

//#include<iostream>
//using namespace std;
//
//class test{
//    private:
//        int a;
//    public:
//        test() {
//            a = 30;
//        }
//
//        int GetA() const
//        {
//            return this->a;
//        }
//};
//
//int main() {
//    const test a;
//    a.GetA();          //参数不匹配，实质的底层调用 -> GetA(a)，a是高安全性，而this指针是低安全性
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int main() {
//    int a1 = 10;
//    int b1 = 10;
//    int a2 = 0;
//    int b2 = 10;
//
//    if (a1 || (b1 = 666))
//        cout << b1 << endl;
//    else
//        cout << b1 << endl;
//
//    if (a2 && (b2 = 999))
//        cout << b2 << endl;
//    else
//        cout << b2 << endl;
//
//    return 0;
//}
#if 0
#include<iostream>
using namespace std;

class test {
private:
    int a;
public:
    test(int a) {
        this->a = a;
    }

    bool operator&&(test& another) {
        if (this->a && another.a)
            return true;
        else
            return false;
    }

    bool operator||(test& another) {
        if (this->a || another.a)
            return true;
        else
            return false;
    }

    test& operator+=(int a) {
        this->a += a;
        return *this;
    }

    friend ostream& operator<<(ostream& os, test& t);
};

ostream& operator<<(ostream& os,test& t) {
    os << "a:" << t.a;
    return os;
}

int main() {
    test t1(10);
    test t2(0);

    if (t1 && (t2 += 10))
        cout << "真，调用了&&操作符重载" << endl;
    else
        cout << "假，调用了&&操作符重载" << endl;

    if (t1 || (t2 += 10))
        cout << "真，调用了||操作符重载" << endl;
    else
        cout << "假，调用了||操作符重载" << endl;
    
    cout << "--------------------------------" << endl;
    cout << t2 << endl;
    return 0;
}

#endif
