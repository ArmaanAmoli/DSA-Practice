#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> solve (vector<int> &nums){
    int n = nums.size();
    unordered_map<int , int>m ; // idx_num - idx_left_small
    stack<int> s;
    for(int i = 0 ; i< n ; i++){
        
        while(!s.empty() && nums[s.top()] >= nums[i]){
            s.pop();
        }

        if(s.empty()){
            m[i] = -1;
        }
        else{
            m[i] = s.top();
        }
        s.push(i);
    }
    return m;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i : v){
        cin >> i;
    }

    unordered_map<int,int> ans = solve(v);

    for(int i = 0 ; i<n ; i++){
        cout<<ans[i]+1<<" ";
    }
}