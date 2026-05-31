#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{

    int need[26] = {};
    for (string &b : words2)
    {
        int freq[26] = {};
        for (char c : b)
            freq[c - 'a']++;
        for (int i = 0; i < 26; i++)
            need[i] = max(need[i], freq[i]); // keep the max
    }

    vector<string> ans;
    for (string &a : words1)
    {
        int freq[26] = {};
        for (char c : a)
            freq[c - 'a']++;
        bool ok = true;
        for (int i = 0; i < 26; i++)
            if (freq[i] < need[i])
            {
                ok = false;
                break;
            }
        if (ok)
            ans.push_back(a);
    }
    return ans;
}

int main()
{
}