#include <bits/stdc++.h>
// https://leetcode.com/problems/product-of-the-last-k-numbers/
using namespace std;


class ProductOfNumbers
{
public:
    vector<int> prefProd;
    // if 0 exists in arr clear the pref arr
    ProductOfNumbers()
    {
        prefProd.push_back(1);
    }

    void add(int num)
    {

        if (num == 0)
        {
            prefProd.clear();
            prefProd.push_back(1);//we need to keep 1 and not push num as it is 0
        }
        else
        {
            prefProd.push_back(prefProd.back() * num);
        }
    }

    int getProduct(int k)
    {
        int n = prefProd.size();
        if (k >= n)
            return 0; // If k is larger than available products, return 0
        //product of last k numbers
        return prefProd.back() / prefProd[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */