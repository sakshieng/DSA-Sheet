#include <stdio.h>
union empAdd
{
char *ename;
char stname[20];
int pincode;
};

int main()
{
    system("cls");
 	printf("\n\n Pointer : Show a pointer to union :\n"); 
    union empAdd employee,*pt;
    employee.ename="Jhon Mc\0Donald";
    pt=&employee;
    printf(" %s %s\n\n",pt->ename,(*pt).ename);
    return 0;
}