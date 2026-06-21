#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ans;
    int n;
    int x;

    bool isValid(int &sum)
    {
        if (sum <= 9 && sum >= 0)
            return true;
        int lastDigit = sum % 10;
        int digit = log10(sum);
        int firstDigit = sum / pow(10, digit);
        return (lastDigit == firstDigit) && (lastDigit==x);
    }

    void solve(int idx, vector<int> &nums, int sum, bool ongoing)
    {
        if ((isValid(sum) && ongoing != false) || idx >= n)
        {
            if (isValid(sum))
                ans++;
            return;
        }
        // If ongoing subarray
        // choice1 -> add the element to the current subarray
        // choice2 -> break the currently going subarray.
        if (ongoing)
        {
            // pick
            solve(idx + 1, nums, sum + nums[idx], true);
            // break
            solve(idx, nums, 0, false);
        }

        // Else
        // choice1 -> start from here
        // choice2 -> skip this
        else
        {
            // start
            solve(idx + 1, nums, nums[idx], true);
            // skip
            solve(idx + 1, nums, 0, false);
        }
    }
    int countValidSubarrays(vector<int> &nums, int x)
    {
        ans = 0;
        this->x = x;
        n = nums.size();
        solve(0, nums, 0, false);
        return ans;
    }
};