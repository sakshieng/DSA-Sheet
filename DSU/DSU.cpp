#include<bits/stdc++.h>
//DSU are used in dynamic graphs
using namespace std;
const int N = 1e9+7;
int parent[N];
int size[N];
void make(int v){
    //make independent node means make will give root node
    parent[v] = v; 
}

//path compression
int find(int v){
    if(v == parent[v]) return v;
    return find(parent[v]); 
}

void Union(int a,int b){
    //replace a by root of a
    a = find(a);
    b = find(b);
    //if roots are equal a==b they lie in same grp

    if(a != b) //make b ka prent a or vice versa
    { 
        // parent[b] = a;
        // unioin by size
        if(size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
}
//when we join bigger tree to smaller we are increasing depth of tree so join trees on basis of size/rank
// amotrized TC O(alpha(n)) alpha(n)=ackerman func means func's value increases slowly

int main(){
    int n,k;
    cin>>n>>k;
    //find distinct connected compo
    for(int i=0;i<=n;++i){
        make(i);
    }
    while(k--){
        int u,v;
        cin>>u,v;
        Union(u,v);
    }
    int connectedCnt = 0;
    for(int i=1;i<=n;++i){
        if(find(i) == i) connectedCnt++;
    }
}