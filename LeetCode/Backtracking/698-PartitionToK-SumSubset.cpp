#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>&V , vector<int> & nums , int idx , int& target){
    if(idx == nums.size()) return true;
    int num = nums[idx];
    for(int i = 0 ; i<V.size() ; i++){
        if(V[i] + num <=target){
            V[i] = V[i] + num;
            bool ans = solve(V , nums , idx+1 , target);
            if(ans) return true;
            V[i] = V[i] - num;
        }
        if(V[i]==0)break;
    }
    return false;
}
bool canPartitionKSubsets(vector<int>& nums , int k){
    int full_sum = 0;
    for(auto & i : nums){
        full_sum += i;
    }
    if(full_sum%k != 0) return false;
    
    int target = full_sum/k;
    sort(nums.rbegin() , nums.rend());
    vector<int> V(k , 0);
    return solve(V , nums , 0 , target);
}

int main(){

}