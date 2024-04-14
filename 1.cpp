#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'scatterPalindrome' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY strToEvaluate as parameter.
 */
int find(string &str){
int palCount = 0;
for (int i = 0; i < str.size(); i++)
{
    unordered_map<char, int> myMap; 
    int oddCountChar = 0;           
    for (int j = i; j < str.size(); j++)
    {
        if (j == i)
        { 
            myMap[str[j]] = 1;
            oddCountChar = 1;
        }
        else
        {
            myMap[str[j]]++;
            if (myMap[str[j]] % 2 == 0) 
                oddCountChar--;
            else
                oddCountChar++; 
        }
        if ((j - i + 1) % 2 == 0 && oddCountChar == 0) 
            palCount++;
        else if ((j - i + 1) % 2 != 0 && oddCountChar == 1) 
            palCount++;
    }
    myMap.clear();
}
return palCount;
}
vector<int> scatterPalindrome(vector<string> strToEvaluate) {
    vector<int>ans;
    for(string str:strToEvaluate){
        int res = find(str);
        ans.push_back(res);
    }
    return ans;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string strToEvaluate_count_temp;
    getline(cin, strToEvaluate_count_temp);

    int strToEvaluate_count = stoi(ltrim(rtrim(strToEvaluate_count_temp)));

    vector<string> strToEvaluate(strToEvaluate_count);

    for (int i = 0; i < strToEvaluate_count; i++) {
        string strToEvaluate_item;
        getline(cin, strToEvaluate_item);

        strToEvaluate[i] = strToEvaluate_item;
    }

    vector<int> result = scatterPalindrome(strToEvaluate);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
