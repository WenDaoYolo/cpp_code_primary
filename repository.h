#ifndef REPOSITORY_H
#define REPOSITORY_H

#include<iostream>
#include<cstring>
#include<iomanip>
#define STYLEWIDTH 12
using namespace std;

class Information_data{
    public:
        char name[15];
        char sex[11];
        int age;
        char address[30];
};

class Information{
    private:
        Information_data data;
       
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

        void AutoCapcityIncrement();
        void LoadInformation(const char* USER_REPOSITOY_DESTINATION);
        void SaveInformation(const char* USER_REPOSITOY_DESTINATION);
        void DestoryRepository();
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

#endif