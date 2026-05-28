#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(pair<pair<int,int> , string>&p){
    int n = p.first.first;
    int k = p.first.second;

    string s = p.second;
    int op = 0;
    int i = 0;
    while(i<n){
        char c = s[i];
        if(c=='B'){
            i = i+k-1;
            op++;
        }
        i++;
    }
    return op;
}
int main(){
    int n;
    cin>>n;
    vector< pair<pair<int,int> , string> >v(n);
    for(int i=0 ; i<n ; i++){
        int s;
        int k;
        string str;
        cin>>s>>k;
        cin.ignore();
        getline(cin , str);
        v[i] = {{s,k} , str};
    }

    vector<int>results;

    for(auto &p: v){
        int ans = solve(p);
        results.push_back(ans);
    }

    for(auto &it : results){
        cout<<it<<endl;
    }

}