#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int solve(string a , string b){
    int k =0;
    while(k<a.size() && k<b.size() && a[k] == b[k]){
        k++;
    }
    int withoutCopy = a.size() + b.size();
    int withCopy = withoutCopy - k + 1;
    return min(withoutCopy , withCopy);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
}