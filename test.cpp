#include "repository.h"
#include "user.h"

char USER_REPOSITOY_DESTINATION[ADMIN_L+4+1];
bool connect=false;

int LoginIndexChoose;
bool flag_Login=true;

repository r1;
int RepositoryChoose;
bool flag_Repository=true;

void SORT(repository &r1){

    char keyword[10],style[10];
    cout<<"KeyWord:name,age,sex,address Style:up,down"<<endl;
    cout<<"Please choose[KeyWord Style]>";
    cin>>keyword>>style;

   if(strcmp(keyword,"name")==0)
   {
        if(strcmp(style,"down")==0)
            r1.SortInformation(CmpByNameDown);
        else
            r1.SortInformation(CmpByNameUp);
   }
   else if(strcmp(keyword,"age")==0)
   {
        if(strcmp(style,"down")==0)
            r1.SortInformation(CmpByAgeDown);
        else
            r1.SortInformation(CmpByAgeUp);
   }
   else if(strcmp(keyword,"sex")==0)
   {
        if(strcmp(style,"down")==0)
            r1.SortInformation(CmpBySexDown);
        else
            r1.SortInformation(CmpBySexUp);
   }
   else if(strcmp(keyword,"address")==0)
   {
        if(strcmp(style,"down")==0)
            r1.SortInformation(CmpByAddressDown);
        else
            r1.SortInformation(CmpByAddressUp);
   }
   else
   {
        cout<<"error!"<<endl;
   }
}

void DELETE(repository& r1){
     char tmp_name[20];
    cout<<"Please input the name that you want to delete[name]>";
    cin>>tmp_name;
    r1.DeleteInformation(tmp_name);
}

void ADD(repository &r1){
    r1.AddInformation();
}

void DISPLAY(repository &r1){
    system("cls");
    PrintMenu();
    r1.DisplayAll();
}

void SEARCH(repository &r1){
    char tmp_name_2[20];
    cout<<"Please input the name that you want to search[name]>";
    cin>>tmp_name_2;
    r1.SearchInformationByName(tmp_name_2);
}

///////////////////////////////////////////////////////
void LOGIN(){
    user u1;
    cout<<"[admin passwor]>";
    cin>>u1;
    if(u1.read()&&u1.check())
    {
        cout<<"LOGIN SUCC!"<<endl;
        u1.CreateRepository(USER_REPOSITOY_DESTINATION);
        flag_Login=false;
        connect=true;
    }
    else
    {
        cout<<"the amdin or password is error or not found!"<<endl;
        return;
    }
}

void REGISTER(){
    user first,second;
    cout<<"Please input[admin(11) password(11)]>";
    cin>>first;
    if(first.check()==false)
    {
        cout<<"the length of admin or password is error!"<<endl;
        return;
    }
    else
    {
        cout<<"Please input again[admin password]>";
        cin>>second;
        if(first==second)
        {
            first.wrtie();
            cout<<"REGISTER SUCC!"<<endl;
        }
        else
        {
            cout<<"admin or password is error!"<<endl;
        }
    }
}


int main(){
//////////////////////////////////////////////////////
    
    PrintLoginIndexMenu();
    while(flag_Login){
        cout<<"[number]>";
        cin>>LoginIndexChoose;
        switch(LoginIndexChoose){
            case 1:
                LOGIN();
                break;
            case 2:
                REGISTER();
                break;
            case 3:
                flag_Login=false;
                break;
            default:
                cout<<"error!"<<endl;
        }
    }

//////////////////////////////////////////////////////

if(connect==true){
    r1.LoadInformation(USER_REPOSITOY_DESTINATION);
    PrintMenu();
    while(flag_Repository){
        cout<<"[number]>";
        cin>>RepositoryChoose;
        switch(RepositoryChoose){
            case 1:
                ADD(r1);
                break;
            case 2:
                DELETE(r1);
                break;
            case 3:
                DISPLAY(r1);
                break;
            case 4:
                SORT(r1);
                break;
            case 5:
                SEARCH(r1);
                break;
            case 6:
                flag_Repository=false;
                break;
            default:
                cout<<"error!"<<endl;
                break;
            }
        }
    r1.SaveInformation(USER_REPOSITOY_DESTINATION);
    }
    return 0;
}