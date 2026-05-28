#include<iostream>
#include<bits/stdc++.h>
using namespace std;

pair<long long,int> solve(vector<int>& nums) {
    int n = nums.size();
    long long maxS = 0;
    int minOp = 0;
    for(int i = 0 ; i<n ; ){
        int num = nums[i];
        if(num<0){
            long long sum_ = -1LL*num;
            int j=i+1;
            while(j<n && nums[j]<=0){
                sum_+= (-1*nums[j]);
                j++;
            }
            maxS+=sum_;
            minOp++;
            i = j;
        }
        else{
            maxS += nums[i];
            i++;
        }
    }
    return {maxS , minOp};
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
    vector<pair<long long,int>>results(n);
    for(int i = 0 ; i<n ; i++){
        results[i] = solve(v[i]);
    }
    for(int i = 0 ; i<n ; i++){
        cout<<results[i].first<< " "<<results[i].second<<endl;
    }
}