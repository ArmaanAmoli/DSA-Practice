#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int solve(string s){
    int ans = 0;
    char f = s[0];
    char se = s[1];
    int p1 = 25*(int(f)-'a');
    int p2 = ((int(se)-'a') > (int(f)-'a')) ? (int(se)-'a') : (int(se)-'a')+1;

    return (p1+p2);
    
}

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(auto &s : v){
        cin>>s;
    }
    for(auto &s : v){
        cout<<solve(s)<<endl;
    }
}