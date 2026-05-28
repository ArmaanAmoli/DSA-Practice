#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string solve(vector<int>&p){
    int n = p.size();
    int l = p[0] , r=l , i=1;
    while(i<n){
        int pos = p[i];
        if(!(abs(pos-l) == 1 || abs(pos-r) == 1) ) return "NO";
        if(pos < l){
            l--;
        }
        else if(pos>r){
            r++;
        }
        i++;
    }
    return "YES";
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
    vector<string>result;
    for(int i =0 ; i<n ; i++){
        
        string ans = (solve(v[i]));
        result.push_back(ans);
    }

    for(auto & ans : result){
        cout<<ans<<endl;
    }

}