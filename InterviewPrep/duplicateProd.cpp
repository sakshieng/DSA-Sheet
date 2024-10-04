#include<bits/stdc++.h>
// https://maang.in/mocks/attempts/7289?problem_id=144
//use of set to find duplicates
using namespace std;
struct tuple_hash {
    size_t operator()(const tuple<string, int, int>& t) const {
        auto hash1 = hash<string>{}(get<0>(t));
        auto hash2 = hash<int>{}(get<1>(t));
        auto hash3 = hash<int>{}(get<2>(t));
        return hash1 ^ hash2 ^ hash3;
    }
};

int solve(const vector<tuple<string, int, int>>& items) {
    unordered_set<tuple<string, int, int>, tuple_hash> seen;
    int cnt = 0;
    
    for (const auto& item : items) 
        if (!seen.insert(item).second) 
            cnt++;
    
    return cnt;
}

int main() {
    int n;
    cin >> n;
    
    vector<tuple<string, int, int>> items;
    
    for (int i = 0; i < n; ++i) {
        string name;
        int price, weight;
        cin >> name >> price >> weight;
        items.emplace_back(name, price, weight);
    }

    int result = solve(items);

    cout << result << "\n";

    return 0;
}
