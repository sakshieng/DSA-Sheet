#include <bits/stdc++.h>
using namespace std;
/*
There are N≤5000 workers. Each worker is available during some days of this month (which has 30 days). For each worker, you are given a set of numbers, each from interval [1,30] representing his/her availability. 
You need to assign an important project to two workers but they will be able to work on the project only when they are both available. Find two workers that are best for the job — maximize the number of days when both these workers are available

intersection -> O(D/64)
the whole complexity -> O(N2⋅D/64)

*/
void printBinary(int num)
{
    if (num == 0) {
        cout << '0';
        return;
    }

    string binary;
    while (num > 0) {
        binary = to_string(num % 2) + binary;
        num /= 2;
    }

    cout << binary;
}
int main()
{
    int n;
    cin >> n;
    int masks[n];
    // calculated masks for all workers
    for (int i = 0; i < n; ++i)
    {
        int num_workers;
        cin >> num_workers;
        int mask = 0;
        for (int j = 0; j < num_workers; ++j)
        {
            int day;
            cin >> day;
            // set bit 1 to workers which are present on that day
            mask = (mask | (1 << day));
        }
        masks[i]=mask;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << masks[i] <<endl;
        printBinary(masks[i]);
    }
    int max_days = 0;
    int person1 = -1;
    int person2 = -1;
    
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            // and of ith worker and jth worker means common days they are working
            int intersection = (masks[i] & masks[j]);
            // how many bits are set in intersection those are common days
            int common_days = __builtin_popcount(intersection);
            // max_days = max(max_days,common_days);
            if(common_days > max_days){
                max_days = common_days;
                person1 = i;
                person2 = j;
            }
            cout<<i<<" "<<j<<" "<<common_days<<"\n";
        }
    }
    cout<<"maximum days are"<<" "<<person1<<" "<<person2<<" "<<max_days<<"\n";
    return 0;
}
/*
5
4 
1 4 7 9->so in binaryy of 32  0x01010010010
6
2 9 1 7 25 29
7 
1 23 4 7 9 11 29
10 
2 28 8 7 9 10 30 21 18 19
4
1 11 29 7
*/