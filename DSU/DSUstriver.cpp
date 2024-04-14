#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
//tc of union by rak and by size both are O(4 alpha) near about constant
class disjointSet
{
    vector<int> parent, rank,size;

public:
    disjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
        for (int i = 0; i <= n; ++i)
            size[i] = 1;
    }
    // give ultimate parent by path compression method
    int findPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        // ultimate parent of u,v
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
            return;
        // belong to same component
        if (rank[ulp_u] < rank[ulp_v])
        {
            // smaller goes and attched to larger
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;//larger one will grow by size 1
        }
    }
    void unionBySize(int u,int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
            return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u]; 
        }else{
            //equal or greater still attach
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main()
{
    disjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    //if 3 & 7 are belong to same parent
    if(ds.findPar(3) == ds.findPar(7))
        cout<<"Same\n";
    else
        cout<<"Not same\n";
    ds.unionByRank(3,7);
    //after combining 3 & 7 will belong to same
    if(ds.findPar(3) == ds.findPar(7))
        cout<<"Same\n";
    else
        cout<<"Not same\n";
    return 0;
}
//after path compression the height is distorted so we are using union by size 