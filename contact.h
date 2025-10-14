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
        friend void Swap(Information* i1,Information* i2);
        friend class repository;
        
        Information();
        char* GetName();
        char* GetSex();
        char* GetAddress();
        int GetAge();
};

class repository{
    private:
        int count;
        Information head;
    public:
        repository();
        void AddInformation();
        void DisplayAll();
        void DeleteInformation(const char* name);
        void SearchInformationByName(const char* name);
        void SortInformation(int(*cmp)(void*,void*));
};

void Swap(Information* i1,Information* i2);
void PrintMenu();

int CmpByNameUp(void* e1,void* e2);
int CmpByAgeUp(void* e1,void* e2);
int CmpByAddressUp(void* e1,void* e2);
int CmpBySexUp(void* e1,void* e2);
int CmpByNameDown(void* e1,void* e2);
int CmpByAgeDown(void* e1,void* e2);
int CmpByAddressDown(void* e1,void* e2);
int CmpBySexDown(void* e1,void* e2);