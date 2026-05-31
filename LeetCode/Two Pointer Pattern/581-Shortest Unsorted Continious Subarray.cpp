#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findUnsortedSubarray(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
        return 0;
    // Create a vector which shows the max element till now form first
    // element
    vector<int> maxV(n);
    int currentMax = nums[0];
    for (int i = 0; i < n; i++)
    {
        if (currentMax < nums[i])
        {
            currentMax = nums[i];
        }
        maxV[i] = currentMax;
    }
    // Create a vector which shows the min element till now from the last
    // element
    vector<int> minV(n);
    int currentMin = nums[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (currentMin > nums[i])
        {
            currentMin = nums[i];
        }
        minV[i] = currentMin;
    }

    int i = 0;
    int j = n - 1;

    int ans = 0;
    while (j > i)
    {
        if ((nums[i] != minV[i]) && (nums[j] != maxV[j]))
        {
            ans = (j - i + 1);
            break;
        }
        if (nums[i] == minV[i])
        {
            i++;
        }
        if (nums[j] == maxV[j])
        {
            j--;
        }
    }
    return ans;
}

int main()
{
}