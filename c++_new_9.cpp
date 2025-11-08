#include<iostream>
using namespace std;

class Sofa{
	public:
		int m1;
		void sit(){
			cout<<"��ɳ������Ϣ"<<endl;
		}
};

class Bed{
	public:
		int m1;
		void sleep(){
			cout<<"�ڴ���˯��"<<endl;
		}
};

class Sofa_Bed:public Sofa,public Bed
{
    public:
	void SitAndSleep(){
		sleep();
		sit();
	}
};

int main(){
	Sofa_Bed sb;

	sb.SitAndSleep();

	return 0;
}