#include<iostream>
#include<string>
using namespace std;

class sportteam{
    public:
    string name;
    int noofp;
    int avg;
    static int count;

    sportteam(string n,int np,int av){
        name=n;
        noofp=np;
        avg=av;
        count++;
    }

    void display(){
        cout<<"Team name     : "<<this->name<<endl;
        cout<<"No of players : "<<this->noofp<<endl;
        cout<<"Average age   : "<<this->avg<<endl<<endl;
    }
};

int sportteam::count=0;

int main(){
    cout<<"Enter name, number of players and average age of first team : ";
    string n;
    int np;
    int av;
    cin>>n>>np>>av;
    sportteam a(n,np,av);
    cout<<"Enter name, number of players and average age of second team : ";
    cin>>n>>np>>av;
    sportteam b(n,np,av);
    cout<<"Enter name, number of players and average age of third team : ";
    cin>>n>>np>>av;
    sportteam c(n,np,av);
    a.display();
    b.display();
    c.display();

    cout<<"Count of objects : "<<a.count<<endl;
    return 0;

}