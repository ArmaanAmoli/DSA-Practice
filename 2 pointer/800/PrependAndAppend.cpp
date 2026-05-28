#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(pair<int,string>&p){
    int n = p.first;
    string s = p.second;
    int l = 0 , r = n-1;
    while(l<r){
        if(s[l] != s[r]){
            l++;
            r--;
        }
        else break;
    }
    return (r-l+1);
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,string>>v(n);
    for(int i=0 ; i<n ; i++){
        int first;
        string second;
        cin>>first;
        cin.ignore();
        getline(cin , second);
        v[i] = {first , second};
    }
    vector<int>results;

    for(auto &p: v){
        int ans = solve(p);
        results.push_back(ans);
    }

    for(auto &it : results){
        cout<<it<<endl;
    }

}