#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char invert(char c){
    if(c == '0')return '1';
    return '0';
}

string flip(string str , int l){
    if(l>str.size()){
        return "";
    }
    int i = 0;
    int j = l-1;

    while(i<=j){
        str[i] = invert(str[i]);
        str[j] = invert(str[j]);
        char temp = str[i];
        str[i]= str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return str;
}

vector<int> solve(string a , string b , int n , vector<int> &result , int op){
    
    if(a == b){
        return result;
    }
    if(op >= 3*n){
        return {};
    }

    for(int i = 1 ; i<=n ; i++){
        string str = flip(a , i);
        if(str == a)continue;
        result.push_back(i);
        vector<int> ans = solve(str , b , n , result, op+1);
        if(!ans.empty())return ans;
        result.pop_back();
    }
    return {};
}


int main(){
    int N;
    cin >> N;
    vector<vector<int>>result(N);
    for(int i = 0 ; i<N ; i++){
        int n;
        cin>>n;
        string a;
        string b;
        cin>>a;
        cin>>b;
        vector<int> r;r = solve(a , b , n , r , 0);
        result[i] = r;
    }

    for(auto & r : result){
        for(auto & i : r){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}