#include "repository.h"


Information::Information(){
    this->last=NULL;
    this->next=NULL;
    this->data.age=-1;
    strcpy(this->data.name,"NULL");
    strcpy(this->data.sex,"NULL");
    strcpy(this->data.address,"NULL");
}

//--------------------------------------------------------------

repository::repository(){
    this->count=0;
    this->head.last=NULL;
    this->head.next=NULL;
    this->head.data.age=0;
    strcpy(this->head.data.name,"NULL");
    strcpy(this->head.data.sex,"NULL");
    strcpy(this->head.data.address,"NULL");
}

void repository::AddInformation(){
    Information* i_p=new Information;
    cout<<"Please intput the information[name age sex address]>";
    cin>>i_p->data.name>>i_p->data.age>>i_p->data.sex>>i_p->data.address;

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
        <<left<<setw(STYLEWIDTH)<<h_p->data.name
        <<left<<setw(STYLEWIDTH)<<h_p->data.age
        <<left<<setw(STYLEWIDTH)<<h_p->data.sex
        <<left<<setw(STYLEWIDTH)<<h_p->data.address
        <<endl;
        
        h_p=h_p->next;
    }
    cout<<"=-------------------------------------------------------="<<endl;
}

void repository::DeleteInformation(const char* name){
    Information* h_p=this->head.next;
    while(h_p!=NULL){
        if(!strcmp(h_p->data.name,name))
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
        if(strcmp(h_p->data.name,name)==0){
            cout<<" "
                <<left<<setw(STYLEWIDTH)<<h_p->data.name
                <<left<<setw(STYLEWIDTH)<<h_p->data.age
                <<left<<setw(STYLEWIDTH)<<h_p->data.sex
                <<left<<setw(STYLEWIDTH)<<h_p->data.address
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
    tmp.data.age=i1->data.age;
    strcpy(tmp.data.sex,i1->data.sex);
    strcpy(tmp.data.address,i1->data.address);
    strcpy(tmp.data.name,i1->data.name);

    i1->data.age=i2->data.age;
    strcpy(i1->data.sex,i2->data.sex);
    strcpy(i1->data.address,i2->data.address);
    strcpy(i1->data.name,i2->data.name);

    i2->data.age=tmp.data.age;
    strcpy(i2->data.sex,tmp.data.sex);
    strcpy(i2->data.address,tmp.data.address);
    strcpy(i2->data.name,tmp.data.name);
}

//--------------------------------------------------------------

char* Information::GetName()
{
    return this->data.name;
}

char* Information::GetSex()
{
    return this->data.sex;
}

char* Information::GetAddress()
{
    return this->data.address;
}

int Information::GetAge()
{
    return this->data.age;
}

//--------------------------------------------------------------

int CmpByAgeUp(void* e1,void* e2){
    return ((Information*)e1)->GetAge()-((Information*)e2)->GetAge();
}

int CmpByNameUp(void* e1,void* e2){
    return strcmp(((Information*)e1)->GetName(),
                 ((Information*)e2)->GetName());
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

void repository::AutoCapcityIncrement(){
    Information* i_p=new Information;
    i_p->last=&(this->head);
    i_p->next=this->head.next;

    if(this->head.next != NULL) {
        this->head.next->last = i_p;
    }

    this->head.next=i_p;
    this->count++;
}

void repository::LoadInformation(const char* USER_REPOSITOY_DESTINATION)
{
    FILE* ptr=fopen(USER_REPOSITOY_DESTINATION,"rb");
    if(ptr==NULL)
    {
        perror("repository::LoadInformation(...)...");
        fclose(ptr);
        return;
    }

    do{
        this->AutoCapcityIncrement();
    }while(fread(&(this->head.next->data),sizeof(Information_data),1,ptr)==1);
    this->DeleteInformation("NULL");
    system("cls");
        
    fclose(ptr);
}

void repository::SaveInformation(const char* USER_REPOSITOY_DESTINATION)
{
    FILE* ptr=fopen(USER_REPOSITOY_DESTINATION,"wb");
    if(ptr==NULL)
    {
        fclose(ptr);
        perror("repository::SaveInformation(...)...");
        return;
    }
    Information* hp=this->head.next;
    while(hp!=NULL)
    {
        fwrite(&(hp->data),sizeof(Information_data),1,ptr);
        hp=hp->next;
    }
    fclose(ptr);
}

void repository::DestoryRepository()
{

}