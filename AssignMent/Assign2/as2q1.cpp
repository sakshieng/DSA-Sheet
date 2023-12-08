#include<iostream>
#include<string>
using namespace std;

class film{
	public:
	string name;
	string lang;
	string type;
	int dur;//duration
	
	film(){
	lang="Hindi";
	dur=3;
	}
	
	void nameof(string n){
	name=n;
	}
	
	void types(string t){
	type=t;
	}
	
	void display(){
		cout<<"\nDetails of the movie :-";
		cout<<"\nName     : "<<this->name;
		cout<<"\nLanguage : "<<this->lang;
		cout<<"\nType     : "<<this->type;
		cout<<"\nDuration : "<<this->dur<<" hours";
	}
	
	~film(){
	cout<<"\nObject Destroyed"<<this->name;
	}
};

int main(){
	film a,b;
	string nam;
	cout<<"Input the name of 1st film : ";
	getline(cin>>ws,nam);
	a.nameof(nam);
	cout<<"Input the type of movie : ";
	cin>>nam;
	a.types(nam);
	cout<<"Input the name of 2nd film : ";
	getline(cin>>ws,nam);
	b.nameof(nam);
	cout<<"Input the type of movie : ";
	cin>>nam;
	b.types(nam);
	a.display();
	b.display();	
	return 0;
}
