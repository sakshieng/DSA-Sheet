// class Hack {
// public:
//     Hack() {
//         cout << "Constructor Used" << endl;
//     }

//     ~Hack() {
//         cout << "Destructor Used" << endl;
//     }
// };

// long long main() {
//     Hack* h = new Hack[2];

//     delete[] h;

//     return 0;
// }

// long long main() {

//     long long a = 10;

//     long long b = 20;

//     const long long *i=&a;

//     i = &b;

//     cout << *i;

//     return 0;
// }

// virtual base class
//  #include<bits/stdc++.h>
//  //sakshi codes here
//  using namespace std;

// class Student {
// public:
//     long long rollNo;
//     void print_number() {
//         cout << "Roll num is " << rollNo << endl;
//     }
//     void set_number(long long a) {
//         rollNo = a;
//     }
// };

// class Test : virtual public Student {
// protected:
//     float maths, physics;
// public:
//     void set_marks(float m1, float m2) {
//         maths = m1;
//         physics = m2;
//     }
//     void print_marks() {
//         cout << "Your result is here: " << endl
//              << "Maths: " << maths << endl
//              << "Physics: " << physics << endl;
//     }
// };

// class Sports : virtual public Student {
// protected:
//     float score;
// public:
//     void set_score(float sc) {
//         score = sc;
//     }

//     void print_score() {
//         cout << "Your PT score is " << score << endl;
//     }
// };

// class Result : public Test, public Sports {
//     float total;
// public:
//     void display() {
//         total = maths + physics + score;
//         print_number();
//         print_marks();
//         print_score();
//         cout << "Your total score is: " << total << endl;
//     }
// };

// long long main() {
//     Result harry;
//     harry.set_number(4200);
//     harry.set_marks(78.9, 99.5);
//     harry.set_score(9);
//     harry.display();
//     return 0;
// }

// applications of pointers
// 1.Dynamic Memory Allocation -> realloc() malloc() calloc()
// 2.Pointer Arithmetic -> Pointers allow direct access and manipulation of memory addresses
// 3.Function Pointers -> allow func to be passed as arguments to other func, enabling callback mechanisms and dynamic func calls

// application of sizeof()
//  1. Determining Size of Data Types
//  2. Dynamic Memory Allocation
//  3. Structure Size Calculation

// Concurrency: Multiple processes/threads running on timesharing on a single-core CPU.
// Parallelism: Multiple processes/threads running simultaneously on a multi-core CPU.

// HTTP is  set of rules and standards on how the information can be transmitted on World Wide Web (WWW).  It helps web browsers and web servers for communication. It is a ‘stateless protocol’ where each command is independent with respect to previous command. -> application layer protocol built upon  TCP ->port 80

// HTTPS is an advanced and secured version of HTTP. On top of HTTP, SSL/TLS protocol is used to provide security. It enables secure transactions by encrypting communication and also helps identify network servers securely -> port 443

// In Linux, a pipe is basically a form of redirection that is used to send output of one command to another command for further processing. It simply takes output from one command and uses it as an input for another. It provides asynchronous execution of commands with help of buffered I/O routines

#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

// class Complex {
// private:
//     long long r, i;
// public:
//     // Default constructor
//     Complex() : r(0), i(0) {}

//     // Parameterized constructor
//     Complex(long long real, long long img) : r(real), i(img) {}

//     Complex operator +(Complex const &obj) {
//         Complex res;
//         res.r = r + obj.r;
//         res.i = i + obj.i;
//         return res;
//     }
//     void print() {
//         cout << r << " + i" << i << endl;
//     }
// };

// long long main() {
//     Complex c1(10, 5), c2(8, 9);
//     Complex c3 = c1 + c2;
//     c3.print();
//     return 0;
// }

// override base class method in derived class
//  class Person{
//  public:
//      virtual void greet(){
//          cout << "greet\n" << endl;
//      }
//  };
//  class Angry:public Person{
//  public:

//     void greet() override{
//         cout << "angry\n";
//     }
// };
// long long main(){
//     Person i;
//     Angry ap;
//     i.greet();
//     ap.greet();
// }

// override base class method in C++
//  class Animal {
//  public:
//      virtual void makeSound()
//      {
//          cout << "animal" << endl;
//      }
//  };
//  //derived class
//  class Horse : public Animal{
//  public:
//      void makeSound() override
//      {
//          cout << "horse" << endl;
//      }
//  };
//  long long main()
//  {
//      Horse horse;
//      horse.makeSound();
//  }

// Tree - Height Balanced or Not

// Int dfs(Node* root){
// 	if(root == null) return 0;
// Int leftH = dfs(root->left);
// 	Int rightH = dfs(root->right);
// 	if(leftH == -1 || rightH == -1) return -1;
// 	if(abs(leftH-rightH) > 1) return -1;
// 	Return max(leftH,rightH) + 1;
// }

// Int isBalanced(Node* root){
// 	if(dfs(root) == -1) return 0;
// Else Return 1;
// }

// Hussein Nasser UUID->universal unique identifier ULID->Universally unique Lexicographically sortable IDentifier
/*
why ULID?
they are sortable
they have compact string representation
timestamp make it sorted which allows the b-tree data structure db uses indexing

that's why database writes by 50% by ULID
*/

// OSI layer:

// Application Layer: DNS, FTP, HTTP, SMTP
// Presentation Layer: SSL/TLS, JPEG, GIF
// Session Layer: NetBIOS, PPTP
// Network Layer: IP, ICMP, Routing protocols (RIP, OSPF, BGP)
// Transport Layer: TCP, UDP
// Data Link Layer: Ethernet, MAC addresses
// Physical Layer: Cables, NICs

// TCP/IP layer 4 layer
//  Application Layer: DNS, FTP, HTTP, SMTP
//  Transport Layer: TCP, UDP
// Internet : IP,ICMP,IGMP
// Link :   SONET, Ethernet
// async -> used to declare func that returns promise
// await -> inside an async func to pause excution of code until a promise is resolved/rejected

// 2 ways to create a thread:
// By extending Thread class
// By implementing Runnable interface.

// hash function assigns each key to a unique bucket
// for collision resoultion separate chaining startegy has been used 
