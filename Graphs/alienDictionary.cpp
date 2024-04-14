// https://practice.geeksforgeeks.org/problems/alien-dictionary/1
#include <bits/stdc++.h>
using namespace std;
// if larger str is before shorter & everything is matching then no valid dict
// abc bat ade a<b<a means there is cyclic dependancy hence not valid dict

class Solution
{
public:
    vector<int> topSOrt(int V, vector<int> adj[])
    {
        int indegree[V] = {0};
        // works for multiple components
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // node is in your topo sort
            // so remove it from the indegree

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return topo;
    }
    string findOrder(string dictionary[], int n, int K)
    {
        // forming a graph
        // int n = dictionary.size();
        vector<int> adj[K];
        for (int i = 0; i < n - 1; ++i)
        {
            string s1 = dictionary[i];
            string s2 = dictionary[i + 1];
            // i need to comapre every character
            int len = min(s1.size(), s2.size());
            for (int ptr = 0; ptr < len; ++ptr)
            {
                if (s1[ptr] != s2[ptr])
                { // means lexographically smaller to higher edge add to graph
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }
        // no of vertices = k
        vector<int> topo = topSOrt(K, adj);
        string ans = "";
        for (auto it : topo)
        {
            ans = ans + char(it + 'a'); // get char back so add 'a'
        }
        return ans;
    }
    // when the order is not possible
    //  1.larger string is before smaller cycle
    //  2.cyclic dependency
};
string order;
bool f(string a, string b)
{
    int p1 = 0;
    int p2 = 0;
    int len = min(a.size(), b.size());
    for (int i = 0; i < len and p1 == p2; i++)
    {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}
