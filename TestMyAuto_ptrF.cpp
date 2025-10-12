#include "MyAuto_ptrF.h"

int main()
{
    aptr s_ptr(new student(33, "Lisi"));
    s_ptr->PrintS();
    (*s_ptr).PrintS();
    return 0;
}