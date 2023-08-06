#include <stdio.h>
#include<stdlib.h>
struct Employee
{
    int PRN, age, salary;
    char name[30];
};
int main()
{
    struct Employee e;
system("cls");
    printf("Enter the PRN of the Employee: ");
    scanf("%d", &e.PRN);
    printf("Enter the age of the Employee: ");
    scanf("%d", &e.age);
    printf("Enter the name of the Employee: ");
    getchar();
    fgets(e.name, 30, stdin);
    printf("Enter the salary of the Employee: ");
    scanf("%d", &e.salary);
    printf("\nEmployee Details:\n");
    printf("Employee PRN: %d\n", e.PRN);
    printf("Employee Name: %s", e.name);
    printf("Employee age: %d\n", e.age);
    printf("Employee salary: %d\n", e.salary);
    return 0;
}