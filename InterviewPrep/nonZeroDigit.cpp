#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
//one intersting fact to be observed is 2*5 will give u unit digit as 0
//divide each arr elmt into its shortest divisble form by 5 ++cnt
// divide each arr elmt into its shortest divisble form by 2 --cnt
//https://maang.in/mocks/attempts/2588?problem_id=119
// https://maang.in/mocks/attempts/2149?problem_id=160
int rightmostNonZeroDigit(vector<int>& a,int n) {
    int cnt5 = 0;
    for(int i=0;i<n;++i){
        while(a[i] > 0 && a[i] % 5 == 0){
            a[i] /= 5;
            cnt5++;
        }
    }
    for(int i=0;i<n;++i){
        while(a[i] > 0 && a[i]%2 == 0 && cnt5 > 0){
            a[i] /= 2;
            cnt5--;
        }
    }
    long long ans = 1;
    //do the multiplication
    for (int i = 0; i < n; i++)
    {
        ans = (ans*a[i] % 10)%10;
    }
    if(cnt5 > 0) ans = (ans*5)%10;	
    else if(ans == 0) ans = -1;
    return ans;
}   

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int result = rightmostNonZeroDigit(A, N);
    cout << result << endl;

    return 0;
}
