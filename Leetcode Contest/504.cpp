#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int digitFrequencyScore(int n)
{
    vector<int> v;
    while (n != 0)
    {
        int i = n % 10;
        v.push_back(i);
        n = n / 10;
    }

    unordered_map<int, int> m;
    for (auto &i : v)
    {
        m[i] += 1;
    }
    int score = 0;
    for (auto &p : m)
    {
        score += p.first * p.second;
    }
    return score;
}

vector<vector<int>>dp;
int solve(vector<vector<int>> &items, vector<int> &outDegree, vector<int> offerClaimed, int budget, int count, int i)
{
    // ith outdegree k means k items comes free with that item

    if (i >= items.size())
    {
        return count;
    }
    bool offerC = offerClaimed[i];
    int buy = 0;


    if ((budget - items[i][1]) >= 0)
    {
        if (offerC || outDegree[i]==0)
        {
            buy = solve(items, outDegree, offerClaimed, budget - items[i][1], count + 1, i);
        }
        else if (!offerC && outDegree[i]!=0)
        {
            offerClaimed[i] = 1;
            buy = solve(items, outDegree, offerClaimed, budget - items[i][1], count + 1 + outDegree[i], i);
        }
    }

    int skip = solve(items, outDegree, offerClaimed, budget, count, i + 1);

    return max(skip, buy);
}

int maximumSaleItems(vector<vector<int>> &items, int budget)
{
    /*
        maintain a buyed array if buyed[i] true then already buyed and free item collected. If buyed again no free item will be provided.
        buy i:
            for each element j where j!=i and j.factor%i.factor == 0 add that to the bag
        skip
    */
   // b c i

    int n = items.size();
    vector<int> outdegree(n, 0);
    vector<int> offerClaimed(n, 0);

    for (int i = 0; i < n; i++)
    {
        int factor = items[i][0];
        for (int j = 0; j < n; j++)
        {
            if (j != i && (items[j][0] % factor==0) && (items[j][0] >= factor))
            {
                outdegree[i]++;
            }
        }
        // cout<<"outdegree"<<outdegree[i]<<endl;
    }

    return solve(items, outdegree, offerClaimed, budget, 0, 0);
}

int main()
{
    vector<vector<int>> items = {{2, 4}, {3, 2}, {4, 1} , {6,4} , {12,4}};
    cout << maximumSaleItems(items, 8);
}