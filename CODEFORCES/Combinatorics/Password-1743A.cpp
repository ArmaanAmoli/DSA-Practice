#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    // we need to return nc2 * 6
    if(n==2)return 6;

    int n_2f = 0;
    int product = 1;

    for(int i = 1 ; i<=n ; i++){
        product *=i;
        if( i == n-2){
            n_2f = product;
        }
    }
    return (product/(n_2f * 2)) * 6;

}

int main(){
    int n;
    cin >> n;
    vector<vector<int>>v(n);
    for(int i= 0 ; i<n ; i++){
        int j;
        cin>>j;
        vector<int> V(j);
        for(auto& k : V){
            cin>>k;
        }
        v[i] = V;
    }
    for(auto& i : v){
        int n = 10 - i.size();
        cout<<solve(n)<<endl;
    }
}