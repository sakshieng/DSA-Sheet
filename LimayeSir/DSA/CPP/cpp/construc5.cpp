#include "construc4.h"
#include <string.h>
#include <bits/stdc++.h>
// code by SAKSHI
class Employee
{
    int eno;
    char enm[15];
    int esph;
    myTime wt;
    public :
        Employee()
        {
            eno=esph=0;
            enm[0]='\0';
        }
        Employee(Employee &k)
        {
            eno=k.eno;
            esph=k.esph;
            wt=k.wt;
            strcpy(enm,k.enm);
        }
        ~Employee(){}
        void setData(int no)
        {
            eno=no;
            cout<<"\nName :";
            cin>>enm;
            cout<<"\nSalary per Hour :";
            cin>>esph;
            cout<<"\nWork Data\n";
            wt.setData();
        }
        void setData()
        {
            cout<<"\nEmployee No. :";
            cin>>eno;
            setData(eno);
        }
        int getSalary()
        {
            return esph*wt.gethr();
        }
        int getNo(){return eno;}
        int getSPH(){return esph;}
        myTime getWT()
        {
            return wt;
        }
        void display()
        {
            cout<<"\nEmployee Data :\nNo. :"<<eno<<"\nName :"<<enm;
            cout<<"\nSalary per hour :"<<esph<<"\nHour Details :";
            wt.display();
            cout<<"\nTotal Salary :"<<getSalary();
        }
};

// main()
// single employee cha data sathi
// {
//     Employee k;
//     k.setData();
//     k.display();
// }

main()
{
    // array of objects
    Employee p[5];
    int i=0;
    while(i<5)
    {
        p[i].setData();
        i++;
    }
    for(i=0;i<5;i++)
        p[i].display();
}