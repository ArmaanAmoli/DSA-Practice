#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> dp;
int maxSum = 0;
int solve(vector<int>& nums  , int target , int current_sum , int idx){
    if(idx == nums.size() ){
        return current_sum == target ? 1 : 0;
    }
    int dp_sum_idx = current_sum + maxSum;

    if(dp[idx][dp_sum_idx] != -1) return dp[idx][dp_sum_idx];
    int plus = solve(nums , target  , current_sum + nums[idx] , idx+1); //plus
    int minus = solve(nums , target  , current_sum - nums[idx] , idx+1 );//minus

    return dp[idx][dp_sum_idx] = plus + minus;
}

int findTargetSumWays(vector<int>& nums, int target) {
    maxSum = 0;
    for(int& n : nums){
        maxSum += abs(n);
    }
    if(abs(target) > maxSum) return 0;
    dp.assign(nums.size() , vector<int>(2*maxSum+1 , -1));
    return solve(nums , target  , 0 , 0);
}


int main(){

}