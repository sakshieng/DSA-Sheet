// https://www.codingninjas.com/studio/problems/reverse-words_7037425?leftPanelTabValue=PROBLEM
#include<bits/stdc++.h>
// https://unstop.com/code/practice/250162
//checkout the question
using namespace std;

string revWords(string str) {
    int size = str.size();
    vector<string>vec;//to store all individual words
    string word = "";
    for (int i = 0; i < size; i++)
    {
        if(str[i] == ' '){
            if(word.size() > 0){
                vec.push_back(word);
                word = "";//reset to empty
            }
        }else{
            word += str[i];
        }
    }
    if(word.size() > 0)
        vec.push_back(word);
    str = "";
    for (int i = vec.size()-1; i >= 0; i--)
    {
        str += vec[i];
        str += " ";
    }
    return str;
}