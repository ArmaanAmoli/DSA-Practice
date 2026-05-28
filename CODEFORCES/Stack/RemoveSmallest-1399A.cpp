#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string solve(vector<int> &nums){
    stack<int> s;
    sort(nums.begin() , nums.end());
    for(auto & i : nums){
        if(!s.empty() && (s.top() == i || abs(i - s.top()) == 1 ) ){
            s.pop();
        }
        s.push(i);
        
    }
    s.pop();
    return s.empty() ? "YES":"NO";
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> V;
    for(int i = 0 ; i<n ; i++){
        int m;
        cin >> m;
        vector<int> v(m);
        for(int j = 0 ; j<m ; j++){
            cin>>v[j];
        }
        V.push_back(v);
    }
    for(auto & v : V){
        cout<<solve(v)<<endl;
    }
}