#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(string s1 , string s2){
    int j = 0;
    for(int i = 0 ; i<s1.size() ; i++){
        if(j< s2.size() && s2[j] == s1[i]){
            j++;
        }
    }
    return j;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        cout << solve(b, a) << "\n";
    }
}