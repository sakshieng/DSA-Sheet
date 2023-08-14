// Approach - Sliding Window Technique (https://www.geeksforgeeks.org/window-sliding-technique/)
// Time Complexity: O(N)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
			// Assign 1 if passing case else 0
			if(v[i] >=  k)v[i] = 1;
			else v[i] =0;
		}	
		// Total passing students - B
		int B = 0;
		for(int i:v)B += i;
		
	
		// So now this problem gets converted to find the maximum subarray if size B having maximum sum
		// And we will subtract it from B - which will indicate the minimum number of swaps required


		int cur = 0;
		int ans = 0;
		int j = 0;
		for(int i=0;i<n;i++)
		{
			cur += v[i];

			if(i >= B - 1)
			{
				ans = max(ans,cur);
				cur -= v[j++];
			}
		}
		cout << B - ans << '\n';
	}
}