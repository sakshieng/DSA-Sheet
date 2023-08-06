#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;

int main() {
	priority_queue<int> pq; //default max heap is created
	pq.push(5);
	pq.push(2);
	pq.push(3);
	pq.push(1);
	pq.push(6);
	//printing will be done in descending order
	while(!pq.empty()){
		cout<<pq.top()<<endl;
		pq.pop();
	}
	return 0;
}