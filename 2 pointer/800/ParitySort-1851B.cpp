#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool is_even(int i){return i%2==0;}
string solve(vector<int>& nums) {
    int n = nums.size();
    vector<int> odds, evens;
    vector<int> odd_idx, even_idx;

    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 == 0) { evens.push_back(nums[i]); even_idx.push_back(i); }
        else                   { odds.push_back(nums[i]);  odd_idx.push_back(i);  }
    }

    sort(odds.begin(), odds.end());
    sort(evens.begin(), evens.end());

    vector<int> result(n);
    for (int i = 0; i < odd_idx.size();  i++) result[odd_idx[i]]  = odds[i];
    for (int i = 0; i < even_idx.size(); i++) result[even_idx[i]] = evens[i];

    for (int i = 0; i < n - 1; i++)
        if (result[i] > result[i+1]) return "NO";

    return "YES";
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
    vector<string>results(n);
    for(int i = 0 ; i<n ; i++){
        results[i] = solve(v[i]);
    }
    for(int i = 0 ; i<n ; i++){
        cout<<results[i]<<endl;
    }
}