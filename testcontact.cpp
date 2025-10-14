#include "contact.h"

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

int main(){
    repository r1;
    int choose;
    bool flag=true;
    PrintMenu();
    while(flag){
        cout<<"[number]>";
        cin>>choose;
        switch(choose){
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
                flag=false;
                break;
            default:
                cout<<"error!"<<endl;
                break;
        }
    }
    return 0;
}