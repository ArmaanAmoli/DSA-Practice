#include<bits/stdc++.h>
using namespace std;

int solve (int n , int m , int sum , int burned){
    if(n==0 && burned < m)return sum;

    if(n==0){
        int newBurned = burned%m;
        return solve(burned/m , m , sum , newBurned);
    }

    sum += n;

    burned += n%m;

    return solve(int(n/m), m , sum , burned);
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<<solve(n , m , 0 , 0);
}