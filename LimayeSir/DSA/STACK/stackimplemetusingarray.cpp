#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
#define M 6
// stack implementation using array for size 6 using 2 stacks in half half size
class Stack
{
    int top1;
    int top2; 
    int size;
    int arr[M]={0};    
public:
    Stack()
    {
        size=5;
        top1=-1;
        top2=(6/2);
    }
    int push1(int x);
    int push2(int x);
    int pop1();
    int pop2();
    void display();
};
int Stack::push1(int x)
{
   if(top1>0)
   {
    top1--;
    arr[top1]=x;
   }
   else
   {
    cout<<endl<<"1st stack overflow"<<"By element: "<<x<<endl;
    return 0;
   }
}
int Stack::push2(int x)
{
    if(top2<size-1)
    {
        top2++;
        arr[top2]=x;
    }
    else
    {
         cout <<endl<< "2nd stack Overflow"
                 << " By element : " << x << endl;
            return 0;
    }
}
int Stack::pop1()
{
    if(top1<0)
    {
        cout << "1st stack is empty" << endl;
        return 0;
    }
    else
    {
        int ans=arr[top1];
        arr[top1]=0;
        top1--;
        cout<<endl<<"popped element from 1st stack"<<ans<<endl;
        return ans;
    }
    
}
int Stack::pop2()
{
    if(top2<3)
    
    {
        cout << "2nd stack is empty" << endl;
        return 0;
    }
    else
    {
        int ans=arr[top2];
        arr[top2]=0;
        top2--;
        return ans;
    }
    
}
void Stack::display()
{
    for(int i=0;i<6;i++)
    {
        if(arr[i]==0){
            cout<<" ";
        }
        else{
            cout<<arr[i]<<" ";
        }
    }
}
int main()
{
   Stack s;

   s.push1(2);
    s.display();
   s.push2(3);
    s.display();
   int x1=s.pop1();
            cout<<endl<<"pushed inside element in second stack"<<endl;
    s.display();
   int x2=s.pop2();
        cout<<endl<<"popped element from 2nd stack"<<endl;
    s.display();
   return 0;
}