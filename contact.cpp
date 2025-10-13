#include "contact.h"

Information::Information(){
    this->last=NULL;
    this->next=NULL;
    this->age=-1;
    strcpy(this->name,"NULL");
    strcpy(this->sex,"NULL");
    strcpy(this->address,"NULL");
}

contact::contact(){
    this->count=0;
    this->head.last=NULL;
    this->head.next=NULL;
    this->head.age=0;
    strcpy(this->head.name,"NULL");
    strcpy(this->head.sex,"NULL");
    strcpy(this->head.address,"NULL");
}

void contact::AddInformation(){
    Information* i_p=new Information;
    cout<<"(name age sex address)>";
    cin>>i_p->name>>i_p->age>>i_p->sex>>i_p->address;

    i_p->last=&(this->head);
    i_p->next=this->head.next;

    if(this->head.next != NULL) {
        this->head.next->last = i_p;
    }

    this->head.next=i_p;
    this->count++;
}

void contact::DisplayAll(){
    Information* h_p=this->head.next;
    cout<<"=-------------------------------------------------------="<<endl;
    cout<<" "<<left<<setw(STYLEWIDTH)<<"NAME"
        <<left<<setw(STYLEWIDTH)<<"AGE"
        <<left<<setw(STYLEWIDTH)<<"SEX"
        <<left<<setw(STYLEWIDTH)<<"ADDRESS"<<endl;

    while(h_p!=NULL){
    cout<<" "
        <<left<<setw(STYLEWIDTH)<<h_p->name
        <<left<<setw(STYLEWIDTH)<<h_p->age
        <<left<<setw(STYLEWIDTH)<<h_p->sex
        <<left<<setw(STYLEWIDTH)<<h_p->address
        <<endl;
        
        h_p=h_p->next;
    }
    cout<<"=-------------------------------------------------------="<<endl;
}

void contact::DeleteInformation(const char* name){
    Information* h_p=this->head.next;
    while(h_p!=NULL){
        if(!strcmp(h_p->name,name))
        {
            h_p->last->next=h_p->next;

            if(h_p->next!=NULL)
                h_p->next->last=h_p->last;

            delete h_p;
            this->count--;
            cout<<"DELETE SUCC!"<<endl;
            return;
        }
        h_p=h_p->next;
    }
    cout<<"The name \""<<name<<"\" mabye is error or not found"<<endl;
}