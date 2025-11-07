#include<iostream>
using namespace std;

class A{
    private:
        int a;
        int b;
    public:
        A(int a,int b){
            this->a=a;
            this->b=b;
        }

        void SetA(int a){
            this->a=a;
        }
        void SetB(int b){  
            this->b=b;
        }
};

class B{
    private:
        A a;
        int c;
    private:
        //first 
        B(int c,A a1):a(a1)
        {
            this->c=c;
        }

        //second
         B(int c,int na,int nb):a(na,nb)
        {
            this->c=c;
        }

        //third
        B():a(3,3)                 //此处为初始化列表
        {
        this->a.SetA(3);           //此处为赋值并非初始化
        this->a.SetB(4);
        this->c=5;
        }
};

int main(){
        


    return 0;
}