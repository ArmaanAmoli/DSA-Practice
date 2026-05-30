#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int solve(int n){
    int m = (n*n)/2;
    return (m/2)+1 ;
}

int main(){
    int i;
    cin>>i;
    vector<int>input(i);
    for(int j = 0 ; j<i ; j++){
        int k;
        cin>>k;
        input[j]=k;
    }
    for(auto& j: input){
        cout<<solve(j)<<endl;
    }
}