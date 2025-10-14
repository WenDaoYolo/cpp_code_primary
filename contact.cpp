#include "contact.h"

Information::Information(){
    this->last=NULL;
    this->next=NULL;
    this->age=-1;
    strcpy(this->name,"NULL");
    strcpy(this->sex,"NULL");
    strcpy(this->address,"NULL");
}

//--------------------------------------------------------------

repository::repository(){
    this->count=0;
    this->head.last=NULL;
    this->head.next=NULL;
    this->head.age=0;
    strcpy(this->head.name,"NULL");
    strcpy(this->head.sex,"NULL");
    strcpy(this->head.address,"NULL");
}

void repository::AddInformation(){
    Information* i_p=new Information;
    cout<<"Please intput the information[name age sex address]>";
    cin>>i_p->name>>i_p->age>>i_p->sex>>i_p->address;

    i_p->last=&(this->head);
    i_p->next=this->head.next;

    if(this->head.next != NULL) {
        this->head.next->last = i_p;
    }

    this->head.next=i_p;
    this->count++;
}

void repository::DisplayAll(){
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

void repository::DeleteInformation(const char* name){
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

void repository::SearchInformationByName(const char* name){
    Information* h_p=this->head.next;
    int flag=1;
    cout<<"=-------------------------------------------------------="<<endl;
    while(h_p!=NULL){
        if(strcmp(h_p->name,name)==0){
            cout<<" "
                <<left<<setw(STYLEWIDTH)<<h_p->name
                <<left<<setw(STYLEWIDTH)<<h_p->age
                <<left<<setw(STYLEWIDTH)<<h_p->sex
                <<left<<setw(STYLEWIDTH)<<h_p->address
                <<endl;
            flag=0;
        }
        h_p=h_p->next;
    }
    if(flag)
        cout<<"The name \""<<name<<"\" mabye is error or not found"<<endl;
    cout<<"=-------------------------------------------------------="<<endl;
}

void repository::SortInformation(int(*cmp)(void* e1,void* e2)){
    Information* hp1=this->head.next;
    for(int i=0;i<this->count;hp1=hp1->next,i++)
    {
        Information* hp2=this->head.next;
        for(int j=0;j<this->count-i-1;hp2=hp2->next,j++)
        {
            if(cmp(hp2,hp2->next)>0)
                Swap(hp2,hp2->next);
        }
    }
    cout<<"SORT SUCC!"<<endl;
}

//--------------------------------------------------------------

void Swap(Information* i1,Information* i2){
    Information tmp;
    tmp.age=i1->age;
    strcpy(tmp.sex,i1->sex);
    strcpy(tmp.address,i1->address);
    strcpy(tmp.name,i1->name);

    i1->age=i2->age;
    strcpy(i1->sex,i2->sex);
    strcpy(i1->address,i2->address);
    strcpy(i1->name,i2->name);

    i2->age=tmp.age;
    strcpy(i2->sex,tmp.sex);
    strcpy(i2->address,tmp.address);
    strcpy(i2->name,tmp.name);
}

//--------------------------------------------------------------

char* Information::GetName()
{
            return this->name;
}

char* Information::GetSex()
{
    return this->sex;
}

char* Information::GetAddress()
{
    return this->address;
}

int Information::GetAge()
{
    return this->age;
}

//--------------------------------------------------------------

int CmpByNameUp(void* e1,void* e2){
    return strcmp(((Information*)e1)->GetName(),
                 ((Information*)e2)->GetName());
}

int CmpByAgeUp(void* e1,void* e2){
    return ((Information*)e1)->GetAge()-((Information*)e2)->GetAge();
}

int CmpByAddressUp(void* e1,void* e2){
    return strcmp(((Information*)e1)->GetAddress(),
                 ((Information*)e2)->GetAddress());
}

int CmpBySexUp(void* e1,void* e2){
    return strcmp(((Information*)e1)->GetSex(),
                 ((Information*)e2)->GetSex());
}

//--------------------------------------------------------------

int CmpByNameDown(void* e1,void* e2){
    return strcmp(((Information*)e2)->GetName(),
                 ((Information*)e1)->GetName());
}

int CmpByAgeDown(void* e1,void* e2){
    return ((Information*)e2)->GetAge()-((Information*)e1)->GetAge();
}

int CmpByAddressDown(void* e1,void* e2){
    return strcmp(((Information*)e2)->GetAddress(),
                 ((Information*)e1)->GetAddress());
}

int CmpBySexDown(void* e1,void* e2){
    return strcmp(((Information*)e2)->GetSex(),
                 ((Information*)e1)->GetSex());
}

//--------------------------------------------------------------

void PrintMenu(){
    cout<<"=-------------------------------------------------------="<<endl;
    cout<<"+                 [INFORMATION SYSTEM]                  +"<<endl;
    cout<<"+                                                       +"<<endl;
    cout<<"+                 1.    ADD                             +"<<endl;                     
    cout<<"+                 2.    DELETE                          +"<<endl;
    cout<<"+                 3.    DISPLAY                         +"<<endl;
    cout<<"+                 4.    SORT                            +"<<endl;
    cout<<"+                 5.    SEARCH                          +"<<endl;
    cout<<"+                 6.    EXIT                            +"<<endl;
    cout<<"=-------------------------------------------------------="<<endl;
}