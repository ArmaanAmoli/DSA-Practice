#include<bits/stdc++.h>

using namespace std;
int total_sum;
int target;
vector<vector<int>>dp;
int solve(int idx , int total , vector<int>&stones){
    if(idx >= stones.size() ||total>=target)return abs(total - (total_sum-total));
    if(dp[idx][total]!=-1)return dp[idx][total];
    return dp[idx][total] = min(solve(idx+1 , total + stones[idx] , stones) , solve(idx+1 , total , stones) );
}

int lastStoneWeightII(vector<int>& stones) {
    for(auto& i: stones){
        total_sum += i;
    }
    target = ceil(total_sum/2);
    dp.assign(stones.size() , vector<int>(total_sum+1 , -1));

}

int main(){

}