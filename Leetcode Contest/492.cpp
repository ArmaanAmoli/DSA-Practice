#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// int minimumIndex(vector<int> &capacity, int itemSize)
// {

//     int min_idx = -1;
//     int min_cap = INT_MAX;

//     for (int i = 0; i < capacity.size(); i++)
//     {
//         if (capacity[i] >= itemSize && capacity[i] < min_cap)
//         {
//             min_cap = capacity[i];
//             min_idx = i;
//         }
//     }

//     return min_idx;
// }

int smallestBalancedIndex(vector<int>& nums)
{
    long long full_sum=0,full_product=1;

    for(int i=0 ; i<nums.size() ; i++){
        full_sum += nums[i];
        full_product *= nums[i];
    }

    long long left_sum = 0;
    long long left_product = 1;

    for(int i=0 ; i<nums.size() ; i++){
        int right_product = full_product/(left_product*nums[i]);
        if(left_sum == right_product) return i;
        left_sum += nums[i];
        left_product *= nums[i];
    }

    return -1;
}


int main()
{
    vector<int> v = {10,10,10,10,10,10,10,7,7,1,2,5};
    cout << smallestBalancedIndex(v);
}