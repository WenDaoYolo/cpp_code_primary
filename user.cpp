#include "user.h"

void PrintLoginIndexMenu(){
    cout<<"=-------------------------------------------------------="<<endl;
    cout<<"+                INFORMATION SYSTEM                     +"<<endl;
    cout<<"+                1.login                                +"<<endl;
    cout<<"+                2.register                             +"<<endl;
    cout<<"+                3.exit                                 +"<<endl;
    cout<<"=-------------------------------------------------------="<<endl;
}

void user::wrtie(){
    FILE* ptr=fopen("user.txt","ab");
    if(ptr==NULL)
    {
        perror("user::write()");
        return;
    }

    fwrite(this,sizeof(user),1,ptr);
    fclose(ptr);
}

bool user::read(){
    FILE* ptr=fopen("user.txt","rb");
    if(ptr==NULL)
    {
        perror("user::read()");
        return false;
    }

    user u1;
    while(fread(&u1,sizeof(user),1,ptr))
    {
        if(strcmp(this->admin,u1.admin)==0&&strcmp(this->password,u1.password)==0)
            return true;
    };
    return false;
}   

bool user::check(){
    if(strlen(this->admin)!=ADMIN_L||strlen(this->password)!=PASSWORD_L)
        return false;
    return true;
}   

istream& operator>>(istream& os,user &u1){
    os>>u1.admin>>u1.password;
    return os;
}

bool user::operator==(user &another){
    if(strcmp(this->admin,another.admin)==0&&strcmp(this->password,another.password)==0)
    {
        return true;
    }
        return false;
}

void user::CreateRepository(char* USER_REPOSITOY_DESTINATION){
    strcpy(USER_REPOSITOY_DESTINATION,strcat(this->admin,".txt"));
}