#include<bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/max-xor-queries_1382020?leftPanelTab=1
/*
offline queries 
arr1 = 1 3 2 5 4
a x
3 1 3
5 2 1
3 4 0
2 5 2
we have sorted acc to x
take xor of arr[i] with x and store it
in trie we will store elmts as <=arr[i] and then check
*/

struct Node{
    Node* links[2];//1st link for 2nd for 1

    Node() {
        links[0] = links[1] = NULL;
    }

    bool containsKey(int bit){
        //for checking the bit is set or not
        return (links[bit] != NULL);
    }
    Node *get(int bit){
        return links[bit];
    }
    void put(int bit){
        links[bit] = new Node();
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node *node = root;
        for(int i=31;i >= 0;i--){
            // if bit is set
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                //doesnt contain bit
                node->put(bit);
            }
            node = node->get(bit);
        }
    } 
//we have designed a func to whom we will give num & it finds max from trie
int getMax(int num) {
    Node *node = root;
    int maxNum = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;  
        //for xor we want opposite of it
        if (node->containsKey(!bit)) {
            //it contains oppsite make this bit 1
            maxNum = maxNum | (1 << i);
            node = node->get(!bit);
        } else {
            node = node->get(bit);
        }
    }
    return maxNum;
}
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//these are online queries to make it offline we have to store the idx
	sort(arr.begin(),arr.end());
	vector<pair<int, pair<int,int>>>oQ;//offlineQuries
	int q = queries.size();
	for(int i=0;i<q;++i){
		//ai,{xi,i}c:\Users\saksh\CP\maxStrongPairXOR2.cpp
		oQ.push_back({queries[i][1],{queries[i][0],i}});
	}
	//queries are sorted in terms of ai
	sort(oQ.begin(),oQ.end());//tc qlogq
	vector<int>ans(q,0);
	int idx = 0;
	Trie *trie = new Trie();
	int n = arr.size();

	//(q*32+n*32)
	for(int i=0;i<q;++i){
		int ai = oQ[i].first;
		int xi = oQ[i].second.first;
		int qIdx = oQ[i].second.second;

		while(idx < n && arr[idx]<=ai){
			trie->insert(arr[idx]);
			idx++;
		}
		//no elmts are inserted 
		if(idx == 0) ans[qIdx] = -1;
		else ans[qIdx] = trie->getMax(xi);
	}
	return ans;
}