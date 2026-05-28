#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>&p){
    int n = p.size();
    int l = 0 , r = n-1;
    vector<int>result;
    
    while(l<=r){
        if(l!=r){
            result.push_back(p[l]);
            result.push_back(p[r]);
        }
        else{
            result.push_back(p[l]);
        }
        l++;
        r--;
    }
    return result;
    
}
int main(){
    int n;
    cin>>n;
    vector< vector<int> >v(n);
    for(int i=0 ; i<n ; i++){
        int size;
        cin>>size;
        vector<int> nums(size);
        for(int i = 0 ; i<size ; i++){
            cin>>nums[i];
        }
        v[i] = nums;
    }

    vector<vector<int>>results;

    for(int i =0 ; i<n ; i++){
        results.push_back(solve(v[i]));
    }

    for(int i =0 ; i<results.size() ; i++){
        for(int j =0 ; j<results[i].size() ; j++){
            cout<<results[i][j]<<' ';
        }
        cout<<endl;
    }

}