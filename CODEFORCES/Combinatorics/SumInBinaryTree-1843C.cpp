#include<bits/stdc++.h>
using namespace std;
long long solve(long long n){
    long long sum = 0;
    while(n!=0){
        sum += n;
        n = n/2LL;
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    vector<long long> v(n);
    for(auto &i : v){
        cin>>i;
    }
    for(auto &i: v){
        cout<<solve(i)<<endl;
    }
}