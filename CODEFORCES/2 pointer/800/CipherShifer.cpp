#include<iostream>
#include<bits/stdc++.h>
using namespace std;


string solve(string & s)
{   
    string code = "";
    for(int i=0 ; i<s.size() ;){
        char c = s[i];
        code.push_back(c);
        int j=i+1;
        while(j<s.size() && s[j]!=c){
            j++;
        }
        i=j+1;
    }
    return code;
}
int main(){
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        cout << solve(s) << endl;
    }
}