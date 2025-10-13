#include "contact.h"
#include "other.h"

int main(){
    contact c1;
    int choose;
    bool flag=true;
    PrintMenu();
    while(flag){
        cout<<">";
        cin>>choose;
        switch(choose){
            case 1:
                c1.AddInformation();
                break;
            case 2:
                char tmp_name[20];
                cout<<"Please input the name that you want to delete>";
                cin>>tmp_name;
                c1.DeleteInformation(tmp_name);
                break;
            case 3:
                system("cls");
                PrintMenu();
                c1.DisplayAll();
                break;
            case 4:
                cout<<"SORT SUCC!"<<endl;
                break;
            case 5:
                cout<<"LOOKUP SUCC!"<<endl;
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