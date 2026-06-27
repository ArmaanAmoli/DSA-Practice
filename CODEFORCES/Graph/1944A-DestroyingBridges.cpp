#include<bits/stdc++.h>
using namespace std;

int solve(int n , int k){
    if(k >= n-1) return 1;
    return n;
}

int main(){
    int t;
    cin>>t;
    vector<int>result(t);
    for(int i = 0 ; i<t ; i++){
        int n,k;
        cin>>n;
        cin>>k;
        result[i]=solve(n , k);
    }
    for(auto & i : result){
        cout<<i<<endl;
    }
}