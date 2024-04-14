// It sets given value to all elements of array
#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> vect(8);
    fill_n(vect.begin(), 8, 1);
    for (int i = 0; i < vect.size(); i++) {
        std::cout << vect[i] << ' ';
    }
    return 0;
}
