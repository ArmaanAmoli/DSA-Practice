#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int solve(vector<int> & v){

    int n = v.size();
    stack<int> s;

    s.push(v[0]);
    for(int i=1 ; i<n ; i++){
        int x = v[i];
        while(!s.empty() && s.top()==x){
            x = x+1;
            s.pop();
            }
        s.push(x);
    }
    int ans = 0;
    while(s.empty()==false){
        cout<<s.top()<<endl;
        ans++;
        s.pop();
    }
    return ans;

}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto & i : v){
        cin>>i;
    }
    int ans = solve(v);
    cout<<ans;
}