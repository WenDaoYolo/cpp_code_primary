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

	int operator()(int value) {                    //����1
		return value * value;
	}

	int operator()(int value1, int value2) {        //����2
		return value1 * value2;
	}
};

int main() {
	Sqr q1(111);              //�˴���()Ϊ���ù��캯����ʼ��
	int res1 = q1(10);        //�˴���()Ϊ���÷º���
	int res2 = q1(10, 20);    //�˴���()Ϊ���÷º���

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
        cout << "�������޲ι��캯��" << endl;
    }

    test(int a) {
        cout << "�������вι��캯��" << endl;
        this->a = a;
    }

    ~test() {
        cout << "��������������" << endl;
    }

    void* operator new(size_t size) {       //unsigned int
        cout << "������new������" << endl;
        return malloc(size);
    }

    void* operator new[](size_t size) {     //unsigned int
        cout << "������new[]������" << endl;
        return malloc(size);
    }

    void operator delete(void* p) {
        if (p != NULL) {
            free(p);
            p = NULL;
            cout << "������delete����" << endl;
        }
    }

    void operator delete[](void* p) {
        if (p != NULL) {
            free(p);
            p = NULL;
            cout << "������delete[]����" << endl;
        }
    }
};

int main() {
    test* t1 = new test(5);      //�ײ����-> t1.operator new(sizeof(int));
    test* t2 = new test[5];      //�ײ����-> t1.operator new[](sizeof(test[5]));
    delete t1;
    delete[] t2;                 //�ײ����-> t1.operator delete(t1);
    return 0;                    //�ײ����-> t1.operator delete[](t2);
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
//    a.GetA();          //������ƥ�䣬ʵ�ʵĵײ���� -> GetA(a)��a�Ǹ߰�ȫ�ԣ���thisָ���ǵͰ�ȫ��
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
        cout << "�棬������&&����������" << endl;
    else
        cout << "�٣�������&&����������" << endl;

    if (t1 || (t2 += 10))
        cout << "�棬������||����������" << endl;
    else
        cout << "�٣�������||����������" << endl;
    
    cout << "--------------------------------" << endl;
    cout << t2 << endl;
    return 0;
}

#endif
