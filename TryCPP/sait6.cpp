#include <bits/stdc++.h>
using namespace std;

// function to return the value of X such that (X xor A) is minimum
// and the number of set bits in X is equal to the number
// of set bits in B
int minXOR(int A, int B) {
        
        int setBits = 0, ans = 0;
        setBits = __builtin_popcount(B);
        stack<short int> s;
        while(A>0)
        {
            s.push(A%2);
            A=A/2;
        }
        vector<short int> X;   
        while(!s.empty())
        {
            if(s.top()==1 && setBits>0)
            {
                X.push_back(1);
                setBits--;
            }
            else
            {
                X.push_back(0);
            }
            s.pop();
        }
        for(int i=X.size()-1;i>=0 && setBits>0;i--)
        {
            if(X[i]==0)
            {
                X[i]=1;
                setBits--;
            }
        }
        int mask;
        for(int i=X.size()-1;i>=0;i--)
        {
            mask=1<<(X.size()-i-1);
            
            ans+=X[i]*mask;
        }
        int n=X.size();
        while(setBits>0)
        {
            ans+=1<<n;
            n++;
            setBits--;
        }
        
        return ans;
    }
 

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        int A, B;
        std::cin >> A >> B;
        int X = minXOR(A, B);
        std::cout << X << std::endl;
    }

    return 0;
}
