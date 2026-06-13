#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &frogs)
{
    int n = frogs.size();
    vector<int> result(n+1, 0);
    unordered_map<int, int> m;
    for (auto &frog : frogs)
    {
        if(frog<=n) m[frog] += 1;
    }

    for (pair<const int, int> &p : m)
    {
        int frog = p.first;
        int freq = p.second;
        int i = 1;
        while (i * frog <= n)
        {
            result[i * frog] += freq;
            i++;
        }
    }

    int ans = INT_MIN;
    for(auto & a : result){
        ans = max(a , ans);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> V(n);
    for (vector<int> &v : V)
    {
        int k;
        cin >> k;
        v.resize(k);
        for (int &i : v)
        {
            cin >> i;
        }
    }
    vector<int> result;
    for(vector<int> &v : V){
        int ans = solve(v);
        result.push_back(ans);
    }

    for(auto & i : result){
        cout<<i<<endl;
    }
}