#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class searchAlgo
{
public:
    int searchh(vector<string> &list, string &str)
    {
        if (list.empty() || str.empty())
            return -1;
        return searchRecu(list, str, 0, str.size() - 1);
    }
    int searchRecu(vector<string> &list, string &str, int low, int high)
    {
        if (low > high)
            return -1;
        int mid = findMid(list, low, high);
        if (mid == -1)
            return -1;
        if (list[mid] == str)
            return mid;
        return str.compare(list[mid]) < 0 ? searchRecu(list, str, low, mid - 1) : searchRecu(list, str, mid + 1, high);
    }
    int findMid(vector<string> &list, int low, int high)
    {
        int mid = (low + high) / 2;
        if (list[mid].empty())
        {
            int l = mid - 1;
            int r = mid + 1;
            while (l >= low && r <= high)
            {
                if (!list[r].empty())
                {
                    mid = r;
                    break;
                }
                if (!list[l].empty())
                {
                    mid = l;
                    break;
                }
                l--;
                r++;
            }
            if (l < low || r > high)
            {
                return -1;
            } // out of bound
        }
        return mid;
    }
};
int main()
{
    searchAlgo search;
    vector<string> ans = {"at", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    string str = "ball";
    int result = search.searchh(ans, str);

    if (result != -1)
        cout << "String found at index " << result << endl;
    else
        cout << "String not found" << endl;
}