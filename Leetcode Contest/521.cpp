#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> result = {};
    sort(nums.begin(), nums.end());
    set<int> s = {};
    map<int, int> m;
    for (auto &i : nums)
    {
        s.insert(i);
        m[i] += 1;
    }
    bool allFreqZero = false;
    while (!allFreqZero)
    {
        allFreqZero = true;
        for (auto &p : m)
        {
            if (p.second != 0)
            {
                allFreqZero = false;
                p.second -= 1;
                result.push_back(p.first);
            }
        }
    }

    return result;
}

int maxNoOfAdjPairsOf(vector<int> &nums)
{
    int maxAdj = 0;
    int currentAdj = 0;

    int j = 0;

    while (j < nums.size() - 1 && nums[j] == nums[j + 1])
    {
        currentAdj++;
        j++;
    }

    if (j == nums.size() - 1)
    {
        return j;
    }

    int beingReplaced = 0;
    int replacer = 0;
    bool replacedUsed = false;
    int startIndex = j;

    for (int i = j; i < (nums.size() - 1); i++)
    {

        if (replacedUsed)
        {
            // cout << "BREAK REPLACEMENT: " << replacer << " " << beingReplaced << endl;

            if ((nums[i] == replacer || nums[i] == beingReplaced) && (nums[i + 1] == replacer || nums[i + 1] == beingReplaced))
            {
                currentAdj++;
                maxAdj = max(currentAdj, maxAdj);
                // cout << "CURRNT ADJ: " << currentAdj << endl;
            }
            else
            {
                // cout<<currentAdj<<"BREAK REPLACEMENT: "<<replacer<< " " << beingReplaced << " "<<nums[i]<<nums[i+1]<<endl;
                maxAdj = max(currentAdj, maxAdj);
                currentAdj = 0;
                replacedUsed = false;
                i = startIndex;
                continue;
            }
        }
        else if ((nums[i] == nums[i + 1]))
        {
            currentAdj++;
        }
        else
        {
            // cout << "UNEQUAL" << i << " " << endl;
            if (!replacedUsed)
            {
                replacedUsed = true;
                beingReplaced = nums[i + 1];
                replacer = nums[i];
                startIndex = i;
                // cout << "replace: " << replacer << "being replced: " << beingReplaced << endl;
                currentAdj++;
            }
            else
            {
                maxAdj = max(maxAdj, currentAdj);
                currentAdj = 0;
            }
        }
    }
   
    return max(maxAdj, 1);
}

int maxEqualAdjacentPairs(vector<int> &nums)
{
    return maxNoOfAdjPairsOf(nums);
}

int main()
{
    vector<int> nums = {8,8,4,5};
    // vector<int> result = rearrangeArray(nums);
    // for(auto & i : result){
    //     cout<<i<<endl;
    // }
    cout << maxEqualAdjacentPairs(nums);
}