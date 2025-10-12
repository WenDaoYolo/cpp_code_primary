#include "MyAuto_ptrF.h"

student::student()
{
    this->id = -1;
    this->name = new char[5];
    strcpy(this->name, "JACK");
}

student::student(int id, const char *name)
{
    if (name == NULL)
    {
        this->id = -1;
        this->name = new char[5];
        strcpy(this->name, "JACK");
        return;
    }

    this->id = id;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

student::student(const student &another)
{
    if (&another == NULL)
    {
        this->id = -1;
        this->name = new char[5];
        strcpy(this->name, "JACK");
        return;
    }

    this->id = another.id;
    this->name = new char[strlen(another.name) + 1];
    strcpy(this->name, another.name);
}

student::~student()
{
    if (this->name != NULL)
    {
        delete this->name;
        this->name = NULL;
        this->id = -1;
        cout << "~student()..." << endl;
    }
}

void student::PrintS()
{
    cout << "ID:" << this->id << " NAME:" << this->name << endl;
}

aptr::aptr(student *ptr)
{
    this->ptr = ptr;
}

aptr::~aptr()
{
    if (this->ptr != NULL)
    {
        delete this->ptr;
        this->ptr = NULL;
        cout << "pointer free!" << endl;
    }
}

student *aptr::operator->()
{
    return this->ptr;
}

student &aptr::operator*()
{
    return *(this->ptr);
}