/*
1. Write an algorithm to check if a string is sorted in alphabetical order and print 0 if it is. If it is not in alphabetical order, then print the index of the character where it is out of alphabetical order
*/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

bool first(string &s){
    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] > s[i + 1]) {
            cout << i + 1 << endl; 
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
/*
2. There is a set of N jars containing chocolates. Some of them may be empty. Determine the maximum number of chocolates Andrew can pick from the jars given that he cannot pick from jars next to each other
i/p:
6
5 30 99 60 5 10
o/p:114
*/
def maxSum(inputArr):
    num = len(inputArr)
    if num == 0:
        return 0
    if num == 1:
        return inputArr[0]
    dp = [0]*inputArr
    dp[0] = inputArr[0]
    dp[1] = max(inputArr[0],inputArr[1])

    #fill the dp array
    for i in range num:
        dp[i] = max(dp[i-1],dp[i-2] + inputArr[i]) 
    
    return dp[n-1]

/*
3.Given an integer X, write an algorithm to find the number of integers which are less than or equal to X and whose digits add up to Y.
i/P : 20 5
o/p: 2
X is 20 and Y is 5. There are only 2 integers <= 20, 1.e, 5 and 14 whose digits add up to 5
*/

def digitSum(n):
    return sum(int(digit) for digit in str(n))

def countNumber(x,y):
    cnt = 0
    for n in range(1,x+1):
        if digitSum(n) == y:
            cnt += 1
    
    if cnt == 0:
        return -1
    else:
        return cnt