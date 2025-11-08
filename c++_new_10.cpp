#include<iostream>
using namespace std;


class Surface{
	public:
		int m1;
};

class Sofa:public Surface
{
	public:
};

class Bed:public Surface
{
	public:
};

//沙发床
class Sofa_Bed:public Sofa,public Bed
{
	private:
    public:
};

int main(){

    Sofa_Bed sb;
    
	return 0;
}