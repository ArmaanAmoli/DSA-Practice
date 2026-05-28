#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;

    vector<int> v(n+1);
    for(int i =1 ; i<=n ; i++){
        cin >> v[i];
    }

    for(int i=1 ; i<=n ; i++){
        int f_a = v[i]; // b
        int f_b = v[f_a];
        int f_c = v[f_b];

        if(f_c == i){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}