#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// class Solution {
// public:

// };

// bool check(int i){
//     int bit = i%2;
//     while(i>0){
//         if(i%2 != bit) return false;
//         i = i/2;
//     }
//     return true;
// }

// int countMonobit(int n)
// {
//     if(n<=1) return n==0?1:2;
//     int ans = 2;
//     for(int i=2 ; i<=n ; i++){
//         bool is_monobit = check(i);
//         if(is_monobit) ans++;
//     }
//     return ans;
// }

// is_max-> true sorted ka left nikalo
void turn(vector<int> &nums, bool is_Max)
{
    if (nums.size() == 1)
        return;

    int max_e = INT_MIN, min_e = INT_MAX;
    int max_idx = 0, min_idx = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > max_e) {
            max_e = nums[i];
            max_idx = i;
        }
        if (nums[i] < min_e) {
            min_e = nums[i];
            min_idx = i;
        }
    }

    int target_idx = is_Max ? min_idx : max_idx;

    int left_sum = 0;
    for (int i = 0; i < target_idx; i++)
        left_sum += nums[i];

    int right_sum = 0;
    for (int i = target_idx + 1; i < nums.size(); i++)
        right_sum += nums[i];

    if (is_Max) {
        if (left_sum < right_sum)
            nums.erase(nums.begin(), nums.begin() + target_idx);
        else
            nums.erase(nums.begin() + target_idx + 1, nums.end());
    } else {
        if (left_sum < right_sum)
            nums.erase(nums.begin() + target_idx + 1, nums.end());
        else
            nums.erase(nums.begin(), nums.begin() + target_idx);
    }
}


int finalElement(vector<int>& nums) {
    int mx = INT_MIN, second = INT_MIN;

    for (int x : nums) {
        if (x > mx) {
            second = mx;
            mx = x;
        } else if (x > second) {
            second = x;
        }
    }
    return second;
}


int main()
{
    vector<int> nums = {1,5,2};
    cout<<finalElement(nums)<<endl;
    // cout<<countMonobit(4)<<endl;
    // cout<<countMonobit(6)<<endl;
}