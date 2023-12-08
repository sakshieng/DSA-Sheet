#include <bits/stdc++.h>
using namespace std;
/*******************************************************************************/
class company
{
    // Company manages both Airline and Airline related side business and some of employees work at both places as per need
    // For making it easy to transfer employees as per company's needs
public:
    string name; // name of company
    int totalEmployees;
    company() {}
    company(string n, int t)
    {
        name = n;
        totalEmployees = t;
    }
};
class airlineEmp : virtual public company
{
public:
    int numA; // Employees work in airline
    airlineEmp() {}
    airlineEmp(int n)
    {
        numA = n;
    }
};
class Business : virtual public company
{
public:
    int numB;
    Business() {}
    Business(int n)
    {
        numB = n;
    }
};
// class for employees who works at both workplace
class both : public airlineEmp, public Business
{
public:
    int num_both;
    both() {}
    both(int nb, int nB, int nA, int t, string n) : airlineEmp(nA), Business(nB), company(n, t)
    {
        num_both = nb;
    }
    void display()
    {
        cout << "Name of the company :" << name << endl;
        cout << "Total number of employee in company :" << totalEmployees << endl;
        cout << "Total number of employee in Airline side of company :" << numA << endl;
        cout << "Total number of employee in Business side of company :" << numB << endl;
        cout << "Total number of employee who work in both parts of company :" << num_both << endl;
    }
};
int main()
{
    both *employee = new both(40, 60, 50, 110, "TATA ");
    employee->display();
    return 0;
}