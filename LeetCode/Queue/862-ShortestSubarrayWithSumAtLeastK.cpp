#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        deque<int> dq;
        int j = 0;
        int n = nums.size();
        int result = INT_MAX;
        vector<long long> cumulativeSum(n);
        while(j < n){

            if(j==0){
                cumulativeSum[0] = nums[j];
            }
            else{
                cumulativeSum[j] = cumulativeSum[j-1] + nums[j];
            }

            if(cumulativeSum[j] >= k){
                result = min(result , j+1);
            }

            while(dq.empty() == false && cumulativeSum[j] <= cumulativeSum[dq.back()]){
                dq.pop_back();
            }

            while(dq.empty() == false && cumulativeSum[j]-cumulativeSum[dq.front()] >=k){
                result = min(result , j - dq.front());
                dq.pop_front();
            }

            dq.push_back(j);
            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};

int main()
{
}