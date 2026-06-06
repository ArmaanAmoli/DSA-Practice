#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp;

int solve(vector<pair<int, int>> &v, pair<int, int> remaining, int idx)
{
    if (idx == v.size())
    {
        return 0;
    }

    if (dp[idx][remaining.first][remaining.second] != -1)
        return dp[idx][remaining.first][remaining.second];
    int take = 0;
    if (remaining.first >= v[idx].first && remaining.second >= v[idx].second)
    {
        take = 1 + solve(v,
                         {remaining.first - v[idx].first, remaining.second - v[idx].second},
                         idx + 1);
    }
    int notTake = solve(v, remaining, idx + 1);

    return dp[idx][remaining.first][remaining.second] = max(take, notTake);
}

int findMaxForm(vector<string> &strs, int m, int n)
{ // m-0 , n-1
    dp.assign(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
    vector<pair<int, int>> v = {};
    for (auto &s : strs)
    {
        pair<int, int> p = {0, 0};
        for (auto &c : s)
        {
            if (c == '0')
                p.first += 1;
            else
                p.second += 1;
        }
        v.push_back(p);
    }
    pair<int, int> remaining = {m, n}; // pair of remaining zeros and ones;

    return solve(v, remaining, 0);
}

int main()
{
}