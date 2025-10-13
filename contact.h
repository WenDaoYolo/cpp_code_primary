#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
#define STYLEWIDTH 12

class Information{
    private:
        char name[15];
        char sex[11];
        int age;
        char address[30];
       
        Information* last;
        Information* next;
    public:
        friend class contact;
        Information();
};

class contact{
    private:
        int count;
        Information head;
    public:
        contact();
        void AddInformation();
        void DisplayAll();
        void DeleteInformation(const char* name);
};