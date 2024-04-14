// https://leetcode.com/problems/greatest-common-divisor-traversal/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
class Solution {
public:
    struct DSU {
        std::vector<int> f, siz;
        
        DSU() {}
        DSU(int n) {
            init(n);
        }
        
        void init(int n) {
            f.resize(n);
            std::iota(f.begin(), f.end(), 0);
            siz.assign(n, 1);
        }
        
        int find(int x) {
            while (x != f[x]) {
                x = f[x] = f[f[x]];
            }
            return x;
        }
        
        bool same(int x, int y) {
            return find(x) == find(y);
        }
        
        bool merge(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) {
                return false;
            }
            siz[x] += siz[y];
            f[y] = x;
            return true;
        }
        
        int size(int x) {
            return siz[find(x)];
        }

        void reset(int x) {
            f[x] = x;
            siz[x] = 1;
        }

        bool isConnected() {
            return siz[find(0)] == siz.size();
        }
    };
    //prime vectors
    vector<int>primeFactors(int num){
        vector<int>primes;
        for(int i=2;i*i <= num;++i){
            if(num % i)
                continue;
            primes.push_back(i);
            while ((num%i) == 0)
            {
                num /= i;
            }
        }
        if(num != 1)
            primes.push_back(num);
        return primes;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 1;
        DSU dsu(n);
        unordered_map<int,int>vis;
        for (int i = 0; i < n; i++)
        {
            if(nums[i] == 1)
                return 0;
            vector<int>primes = primeFactors(nums[i]);
            for(auto &e:primes){
                if(vis.count(e))
                    dsu.merge(vis[e],i);
                else
                    vis[e] = i;
            }
        }
        return dsu.isConnected();
    }
};