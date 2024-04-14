#include <bits/stdc++.h> 
using namespace std;
//  can also be referred as priority queue 

// if we insert an element whose priority is not in the order of its insertion then the whole heap may dissatisfy the heap property and hence this has to be rectified. The process of rectifying and restoring its property is called heapify
int main() {
	priority_queue<int, vector<int>, greater<int> > pq; //compare function min heap is created
	pq.push(5);
	pq.push(2);
	pq.push(3);
	pq.push(1);
	pq.push(6);
	//printing will be done in ascending order
	while(!pq.empty()){
		cout<<pq.top()<<endl;
		pq.pop();
	}
	return 0;
}