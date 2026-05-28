#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
    int n = nums.size();
    if(n==1)return 0;
    sort(nums.begin() , nums.end());
    int i = 0;
    int j = n-1;
    int score = 0;
    while(j>i){
        score += (nums[j] - nums[i]);
        j--;
        i++;
    }
    return score;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>>v(n);
        
    for(int i = 0 ; i < n ; i++){
        int size;
        cin>>size;
        vector<int> nums(size);
        for(int j=0 ; j<size ; j++){
            cin>>nums[j];
        }
        v[i] = nums;
    }
    vector<int>results(n);
    for(int i = 0 ; i<n ; i++){
        results[i] = solve(v[i]);
    }
    for(int i = 0 ; i<n ; i++){
        cout<<results[i]<<endl;
    }
}