// https://www.codingninjas.com/studio/problems/chess-tournament_8230779?challengeSlug=striver-sde-challenge
#include <bits/stdc++.h> 
using namespace std;
int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(),positions.end());
	int ans = 0;
	int low=0,high=positions[n-1]-1;
	while(low <= high){
		//aloocation for mid is posiible or not
		int mid = low + (high-low)/2;
		int cnt = 1;//allocate first room for first person
		int prevRoom = positions[0];//will store prv occupied room
		for(int i=1;i<n;++i){
			if(positions[i]-prevRoom >= mid){
				//means we have allocated room
				cnt++;
				prevRoom = positions[i];
			}
		}
		//means we can accodmadate more than c people we can at least accom c people
		if(cnt >= c){
			ans = mid;
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	return ans;
}

int main() {
    vector<int> positions = {1, 2, 4, 8, 9};
    int n = positions.size();
    int c = 3;

    int result = chessTournament(positions, n, c);
    cout << "Minimum distance required: " << result << endl;

    return 0;
}
