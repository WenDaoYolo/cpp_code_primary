#ifndef USER_H
#define USER_H

#include<iostream>
#include<cstring>
#define IMPROVE 9
#define ADMIN_L 11
#define PASSWORD_L 11
using namespace std;

class user{
    private:
        char admin[ADMIN_L+IMPROVE];
        char password[PASSWORD_L+IMPROVE];
    public:
        friend istream& operator>>(istream& os,user &u1);
        void wrtie();
        bool read();
        bool check();
        bool operator==(user &another);
        void CreateRepository(char* USER_REPOSITOY_DESITINATION);
};

void PrintLoginIndexMenu();

#endif 